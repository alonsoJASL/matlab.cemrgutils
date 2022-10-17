%% (MATLAB) Use the PVeinsLabelled.nii created by CemrgApp when clipping
% 

clc;
mlog('Have you clipped the bloodpool? Press ENTER to confirm...'); 
pause;

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

% clip the body
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

% clip the rims of the PVs
nh2=7;
L2=imdilate(V>10, strel('sphere', nh2)); % keep rims 
L2=cast(2.*L2, 'like', AW);

AWclipped_rims = AW;
AWclipped_rims((L2.*AW)<=1)=0;

AWclipped = 2.*AWclipped_rims+AWclipped_body;
AWclipped(AWclipped==3) = 1;
AWclipped(AWclipped==2) = 3;

volumeViewer(AWclipped, 'VolumeType','Labels');

AWclipped=cast(AWclipped, vinfo.Datatype);
niftiwrite(AWclipped, fullfile(labdir, 'PVeinsCropped_AWall.nii'), vinfo);