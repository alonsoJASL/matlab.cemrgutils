tidy;
[optimizer, metric] = imregconfig('multimodal');
try 
    datapath = '~/data/TESTs_LA-reg/';
catch 
    datapath = uigetdir('~/data');
end

pnames = dir(datapath);
pnames(1:2) = [];
pnames = pnames([pnames.isdir]);
pnames = {pnames.name}';

mra = 'dcm-MRA-cspline.nii';
lge = 'dcm-LGE-cspline.nii';
la = 'LA.nii';
lareg = 'LA-reg-matlab.nii';

N = length(pnames);


%% GENERATE REGISTRATIONS for ALL
for ix=1:N
    pt(ix).moving = niftiread(fullfile(datapath,pnames{ix}, mra));
    pt(ix).fixed = niftiread(fullfile(datapath,pnames{ix}, lge));
    pt(ix).LA = niftiread(fullfile(datapath,pnames{ix}, la));
    pt(ix).dof = imregtform(pt(ix).moving, pt(ix).fixed, 'rigid', optimizer, metric);
    
    pt(ix).LA_reg = imwarp(pt(ix).LA, pt(ix).dof,'OutputView',imref3d(size(pt(ix).fixed)));
    niftiwrite(pt(ix).LA_reg, fullfile(datapath,pnames{ix}, lareg));
    
    disp(sprintf('Finished %s', pnames{ix}));
end

%% LOAD matlab registrations - create label for comparison

whichlareg = 'LA-reg-multilevel.nii';
outlareg = 'ogVSmultilevel.nii';

for ix=1:N
    try 
    pt2(ix).LA = niftiread(fullfile(datapath,pnames{ix}, la));
    pt2(ix).LA_reg = niftiread(fullfile(datapath,pnames{ix}, whichlareg));
    
    niftiwrite(pt2(ix).LA+2.*pt2(ix).LA_reg, fullfile(datapath,pnames{ix},outlareg));
    disp(sprintf('Finished %s - successfully', pnames{ix}));
    catch 
    disp(sprintf('Finished %s - could not match sizes', pnames{ix}));
    end
end
