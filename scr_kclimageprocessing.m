% IMAGE PROCESSING TASKS script.
% By José Alonso Solís-Lemus
% 
% Call by running on matlab prompt line 
% 
%   scr_kclimageprocessing;
% 
% The script is separated into MATLAB cells, which can also be individually
% run one after another. 
%
% The script assumes the sphere cut in TASK 4 cuts alongside plane x=0. 
%
% A DEBUG mode was programed into to visualise partial results of each task, 
% which can be enabled with variable <debugVar>, in the INITIALISATION cell,
% and allows the user to choose which plane to slice the sphere in 
% (x=0, y=0 or z=0).
% 
%% INITIALISATION / CLEARING the workspace
clear all;
close all;
clc;

% change to true if you want to visualise results in matlab.
debugVar = false;

if debugVar
    fprintf(['Running script in DEBUG mode.' ...
        'Change <debugVar> to "false" to run in normal mode.\n']);
else
    fprintf(['Running script in NORMAL mode.' ...
        'Change <debugVar> to "true" to run in debug mode.\n']);
end

% choice of Volume sizes and spacing.
nh=100; nw=100; nd=100;
voxSp = 1; % in mm
voxSpacing = voxSp/1000; % in m

%% Task 1. Empty volume

fname1 = sprintf('TASK1_emptyVol%dX%dX%d_Spacing%dmm.nii', nh,nw,nd,voxSp);
V = zeros(nh, nw, nd);
niftiwrite(V, fname1);
info = niftiinfo(fname1);
info.Description = 'Modified using MATLAB R2018b';
info.SpaceUnits = 'Millimeter';
niftiwrite(V,fname1,info);

fprintf('Finished writing output for TASK 1 filename: %s\n', fname1);
%% Task 2. Sphere

fname2 = sprintf('TASK2_sphereVol%dX%dX%d_Spacing%dmm.nii', nh,nw,nd,voxSp);

sphereradius = 20; % mm
xc = round(nh/2);
yc = round(nw/2);
zc = round(nd/2);

[X, Y, Z] = meshgrid(1:nh,1:nw,1:nd);

D = (X-xc).^2 + (Y-yc).^2 + (Z-zc).^2;
V(D<=sphereradius^2) = 1;

niftiwrite(V, fname2);
info = niftiinfo(fname2);
info.Description = 'Modified using MATLAB R2018b';
info.SpaceUnits = 'Millimeter';
niftiwrite(V,fname2,info);
fprintf('Finished writing output for TASK 2 filename: %s\n', fname2);

if debugVar
    figure(2)
    imagesc(max(V,[],3));
    axis square;
    title('Maximum intensity projection of Volume.');
end

%% Task 3. Surface mesh in VTK format
fname3 = sprintf('TASK3_fullSphereMesh.vtk');

[f,v] = isosurface(X,Y,Z,V,0.5);

if debugVar
    figure(3)
    patch('Faces', f, 'Vertices', v, 'facecolor', 'none', 'edgecolor', 'k');
    daspect([1 1 1]);
    axis([0 100 0 100 0 100])
    camlight;
    lighting gouraud;
    title('Mesh of full volume')
end

data2vtk(fname3, v, f);
fprintf('Finished writing output for TASK 3 filename: %s\n', fname3);
%% Task 4.

whichplane = 'x'; %choose 'x', 'y' or 'z'. DEFAULT 'x'.
Vhalf = V;

if debugVar
    s = input('Choose a plane to cut: "x", "y" or "z". [DEFAULT:_"x"]', 's');
    if ~isempty(s)
        whichplane = s;
    end
end

switch lower(whichplane)
    case 'x'
        Vhalf(X>xc) = 0;
    case 'y'
        Vhalf(Y>yc) = 0;
    case 'z'
        Vhalf(Z>zc) = 0;
    otherwise
        fprintf('\n[ERROR] Invalid plane chosen. Using DEFAULT: "x"\n');
        whichplane = 'x';
end
fname4 = sprintf('TASK4_halfSphereMesh_%splane.vtk', upper(whichplane));

[fh,vh] = isosurface(X,Y,Z,Vhalf,0.5);
if debugVar
    figure(4)
    clf;
    patch('Faces', fh, 'Vertices', vh, 'facecolor', 'none', 'edgecolor', 'k');
    daspect([1 1 1]);
    axis([0 100 0 100 0 100])
    grid on
    camlight;
    lighting gouraud;
    title(sprintf('Mesh of half a sphere at plane %s=0.',upper(whichplane)));
end

data2vtk(fname4, vh, fh);
fprintf('Finished writing output for TASK 4 filename: %s\n', fname4);