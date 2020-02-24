% SCRIPT TO VISUALISE 3D LABELLED VENTRICLES
%
%% Read filename to visualise potential problems
%fname = '/media/jsl19/DATA/KCL_EP/1_seg/works/MASK.nii';
fname = '/media/jsl19/DATA/KCL_EP/case02/1_seg/mhd/MASK.nii';

vinfo = niftiinfo(fname);
V = niftiread(vinfo);
regs = regionprops3(V>0);

regs1 = regionprops3(V==1, 'all');
regs2 = regionprops3(V==2, 'all');
regs3 = regionprops3(V==3, 'all');
regs4 = regionprops3(V==4, 'all');
regs5 = regionprops3(V==5, 'all');

V1 = V==1;
V2 = V==2;
V3 = V==3;
V4 = V==4;
V5 = V==5;

%% 
tidy;

path = '/home/jsl19/Dropbox/case02/2_mesh/CGALMeshDir';
if(~exist(path, 'dir'))
    path = uigetdir('~/Documents', 'Select the directory');
end
base = 'CGALMesh_Cav';
elemname = [base,'.csv'];
ptsname = [base '_pts.csv'];

T = readtable(fullfile(path,elemname), 'Delimiter',',','Format','%s%d%d%d%d%d');
T.Properties.VariableNames = {'type', 'i0', 'i1','i2','i3', 'label'};
numelem = str2num(T.type{1});
T(1,:) = [];
disp(T(1:10,:));

Tpts = readtable(fullfile(path,ptsname), 'Delimiter',',','Format','%f%f%f');
Tpts.Properties.VariableNames = {'x', 'y', 'z'};
numpts = Tpts.x(1);
Tpts(1,:) = [];
disp(Tpts(1:10,:));

%% Cesare's parser

tidy;
fname = '/media/jsl19/DATA/KCL_EP/case02/2_mesh/myCGALMeshDir/testout/mesh';

M = io_readCARPMesh(fname);

%% 
S.Vertices = M.Pts;
S.Faces = M.Tet(:,1:4);
S.CData = M.Tet(:,5);
S.FaceColor = 'flat';
S.EdgeColor = 'none';
S.FaceAlpha = 0.5;
%
patch(S);

%% 
