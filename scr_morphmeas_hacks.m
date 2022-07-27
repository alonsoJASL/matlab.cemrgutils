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
[labname, labdir] = uigetfile('*.*', 'Select the PVeinsLabelled');
[awname, awdir] = uigetfile(fullfile(labdir, '*.*'), ...
    'Select the (pad) atrial wall');

[V,vinfo] = readParseNifti(fullfile(labdir, labname));
[AW, awinfo] = readParseNifti(fullfile(awdir, awname));

% check the labels
volumeViewer(V, 'VolumeType', 'Labels');

%% 3.1 change the next lines to the labels
laa_rim = 20;
ls_rim = 11;
li_rim = 13;
rs_rim = 15;
ri_rim = 17;
laa = 2;
ls = 3;
li = 4;
rs = 6;
ri = 5;

L=V;
L(V>10)=0; % remove rims
L(V==1)=0; % remove body

nh = 9;

L=L>0;
L=imdilate(L, strel('sphere',nh));
L=cast(2.*L, 'like', AW);

AWc = AW;
AWc((L.*AW)>1)=0;
AWc(bwlabeln(AWc)>1) = 0;

volshow(AWc>0);
%% 
L2=imdilate(V>10, strel('sphere', nh)); % keep rims 
L2=cast(2.*L2, 'like', AW);

AWc2 = AW;
AWc2((L2.*AW)<=1)=0;

volumeViewer(2.*AWc2+AWc+V, 'VolumeType','Labels')

%% Helper functions

function padAndSaveNifti(fpath, pad)
[dir,fname,ext] = fileparts(fpath);
[padV, ~, vinfo] = padNiftiFromFile(fpath, pad);

cemrg_info(fullfile(dir, [fname '_pad' ext]));
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
