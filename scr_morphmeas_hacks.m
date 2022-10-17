%% 

%% 0. (CemrgApp) Convert NRRD to NIFTI in CemrgApp 
% before starting, files need to be converted to nifti

%% 1. (MATLAB) Padding images. Do on both wall and bloodpool

[bpname, bpdir] = uigetfile('*.*', 'Select the bloodpool');
[awname, awdir] = uigetfile(fullfile(bpdir, '*.*'), 'Select the atrial wall');
padding=1;

padAndSaveNifti(fullfile(bpdir,bpname), padding);
padAndSaveNifti(fullfile(awdir, awname), padding);

%% 2. (CemrgApp) Clip the PVs in CemrgApp
% Process the newly created padded images, the ones with '_pad' in the name
% Check the PVeinsLabelled.nii file
% 

%% 3. (MATLAB) Use the PVeinsLabelled.nii created by CemrgApp when clipping
% 
mlog('Select the PVeinsLabelled.nii'); pause(0.5);
[labname, labdir] = uigetfile('*.*', 'Select the PVeinsLabelled');

mlog('Select the (pad) atrial wall'); pause(0.5);
[awname, awdir] = uigetfile(fullfile(labdir, '*.*'), ...
    'Select the (pad) atrial wall');

[V,vinfo] = readParseNifti(fullfile(labdir, labname));
[AW, awinfo] = readParseNifti(fullfile(awdir, awname));

% check the labels
mlog('Check the labels'); pause(0.5);
volumeViewer(V, 'VolumeType', 'Labels');

%% clip the body
L=V;
L(V>10)=0; % remove rims
L(V==1)=0; % remove body

nh = 9;

L=L>0;
L=imdilate(L, strel('sphere',nh));
L=cast(2.*L, 'like', AW);

AWclipped_body = AW;
AWclipped_body((L.*AW)>1)=0;
AWclipped_body(bwlabeln(AWclipped_body)>1) = 0;

%volshow(AWc>0);

%% clip the rims of the PVs

nh2=7;
L2=imdilate(V>10, strel('sphere', nh2)); % keep rims 
L2=cast(2.*L2, 'like', AW);

AWclipped_rims = AW;
AWclipped_rims((L2.*AW)<=1)=0;

AWclipped = 2.*AWclipped_rims+AWclipped_body;
AWclipped(AWclipped==3) = 1;
AWclipped(AWclipped==2) = 3;

volumeViewer(AWclipped, 'VolumeType','Labels');

niftiwrite(AWclipped, fullfile(labdir, 'PVeinsCropped_AWall.nii'), vinfo);

%% Helper functions

function padAndSaveNifti(fpath, pad)
[dir,fname,ext] = fileparts(fpath);
[padV, ~, vinfo] = padNiftiFromFile(fpath, pad);

mlog(fullfile(dir, [fname '_pad' ext]));
niftiwrite(padV, fullfile(dir, [fname '_pad' ext]), vinfo);
end

function [padV, V, vinfo] = padNiftiFromFile(fpath, pad)

[V,vinfo] = readParseNifti(fpath);
[m,n,p] = size(V);

padV = zeros([m n p]+(2*pad), 'like',V);
xstart=1+pad;
ystart=1+pad;
zstart=1+pad;
xend=xstart+m-1;
yend=ystart+n-1;
zend=zstart+p-1;

vinfo.ImageSize = size(padV);

padV(xstart:xend, ystart:yend, zstart:zend) = V;
end

function mlog(msg, condition2print)
if nargin < 2
    condition2print = true;
end

if condition2print == true
    fprintf([msg '\n']);
end
end