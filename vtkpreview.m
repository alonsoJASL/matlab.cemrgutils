function vtkpreview(vtkpath, toConsole)

if nargin < 2
    toConsole = false;
end
[path2file, name, ext] = fileparts(vtkpath);

fi = fopen(vtkpath, 'r');
fo = fopen(fullfile(path2file, [name '_preview' ext]), 'w');

while ~feof(fi)
    str = fgetl(fi);
    if(contains(str, 'float', 'IgnoreCase', true))
        
    else
        
    end 
end
    