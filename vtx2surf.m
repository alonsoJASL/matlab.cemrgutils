function [pointIndexVector] = vtx2surf(meshpath, opts)
% 

if nargin < 2
    lv = [1 10 2];
    rv = [5 30 4];
    apx = 3;
    cavmesh = true;
else 
    [lv, rv, apx, cavmesh] = getopts(opts);
end

[path2files, bname, ext] = fileparts(meshpath);

lvepi = lv(1);
lvendo = lv(2);
lvbase = lv(3);
rvepi = rv(1);
rvendo = rv(2);
rvbase = rv(3);
apex = apx;

labelsToFile = [lvendo lvepi lvbase rvendo rvepi rvbase apex];


if cavmesh==true
    readInMeshFile = [bname '_Cav.elem'];
else
    readInMeshFile = [bname ext];
end
readInPtsFile = [bname '.pts'];

outputBase = [path2files bname];
outputFiles = {[outputBase 'LVendo.surf'];
               [outputBase 'LVepi.surf'];
               [outputBase 'LVbase.surf']; 
               [outputBase 'RVendo.surf'];
               [outputBase 'RVepi.surf'];
               [outputBase 'RVbase.surf'];
               [outputBase 'Apex.surf']};
elemFile = fopen(fullfile(path2files, readInMeshFile), 'r');
ptsFile = fopen(fullfile(path2files, readInPtsFile), 'r');

nElem = readlinefibres(fgetl(elemFile));
nPts = readlinefibres(fgetl(ptsFile));

fclose(ptsFile);

totalTags = 7;
ptsVector = zeros(nPts, totalTags);

for iElem=1:nElem
    p = readlinefibres(fgetl(elemFile));
    currentTag = p(6);
    p([1 6]) = [];
    
    for ix=1:4
        it=1;
        while (it <= 7 && ptsVector(p(ix), it) ~= 0)
            it=it+1;
        end
        if it<=7
            ptsVector(p(ix), it) = currentTag;
        end
    end
end

fclose(elemFile);

if nargout >0
    pointIndexVector = ptsVector;
end

disp('NOt finished')
end

function [lv, rv, apx, cavmesh] = getopts(s)
lv = [1 10 2];
rv = [5 30 4];
apx = 3;
cavmesh = true;

fnames=fieldnames(s);
for ix=1:length(fnames)
    switch lower(fnames{ix})
        case 'lv'
            if length(s.(fnames{ix})) == 3
                lv = s.(fnames{ix});
            end
        case 'rv'
            if length(s.(fnames{ix})) == 3
                rv = s.(fnames{ix});
            end
        case 'apex'
            apx = s.(fnames{ix});
        case {'cav', 'cavmesh'}
            cavmesh = s.(fnames{ix});
        otherwise
            cemrg_info('[ERROR] option %s not recognised', fnames{ix});
    end
end
end
