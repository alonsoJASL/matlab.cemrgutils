function data2vtk(outname, v, f, s)
% DATA TO VTK FORMAT. Simple routine to convert the volume described in
% vertexes (v) and faces (f) into the XML file compatible with VTK.
%
% USAGE:       data2vtk(outname, v, f)
% INPUT:       outname := string with name or path to file
%                (v,f) := vertexes and faces from isosurface
%
%

%
% Function based on Chaoyuan Yeh's open source project vtkwrite:
% <https://github.com/joe-of-all-trades/vtkwrite>
%

if nargin < 4
    s = [];
end

if ~contains(outname, '.vtk')
    outname = strcat(outname, '.vtk');
end
numPoints = size(v,1);
% pad with zeros if size is not divisible by 3.
if mod(numPoints,3)==1
    v = [v;zeros(2,3)];
    numPoints = numPoints +2;
elseif mod(numPoints,3)==2
    v = [v;zeros(1,3)];
    numPoints = numPoints + 1;
end
x = v(:,1);
y = v(:,2);
z = v(:,3);

spec = [repmat(['%0.5f '], 1, 9), '\n'];

output = [x(1:3:end-2), y(1:3:end-2), z(1:3:end-2),...
    x(2:3:end-1), y(2:3:end-1), z(2:3:end-1),...
    x(3:3:end), y(3:3:end), z(3:3:end)]';

numfaces = length(f);


% CREATE FILE.

fid = fopen(outname, 'w');
% VTK DataFile Version
fprintf(fid, '# vtk DataFile Version 2.0\n');
fprintf(fid, 'VTK from Matlab\n');
fprintf(fid, 'ASCII\n');
fprintf(fid, 'DATASET POLYDATA\n');

fprintf(fid, 'POINTS %d float \n', numPoints);
fprintf(fid, spec, output);

fprintf(fid,'\nPOLYGONS %d %d\n',numfaces,4*numfaces);
fprintf(fid,'3 %d %d %d\n',(f-1)');

if ~isempty(s)
    spec2 = [repmat(['%d '], 1, 9), '\n'];
    rem9 = mod(numfaces, 9);
    nfdiv9 = (numfaces - rem9);
    output2 = reshape(s(1:nfdiv9), nfdiv9/9, 9);
    rem = s((nfdiv9+1):end);
    
    fprintf(fid, '\nCELL_DATA %d\n', numfaces);
    fprintf(fid, 'SCALARS scalars float\n');
    fprintf(fid, 'LOOKUP_TABLE default\n');
    fprintf(fid, spec2, output2);
    
    for ix=1:rem9
        fprintf(fid, '%d ', rem(ix));
    end
    fprintf(fid, '\n');
end
fprintf('%s. File created succesfully.\n', mfilename)
