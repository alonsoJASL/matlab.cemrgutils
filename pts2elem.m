function pts2elem(pts, elem, file2change)
%

[path, outname, outext] = fileparts(file2change);

outpath = fullfile(path, [outname '_elem' outext]);

fmesh = fopen(elem, 'r');
fpts = fopen(pts, 'r');
fi = fopen(file2change, 'r');

fo = fopen(outpath, 'w');

nElem = readlinefibres(fgetl(fmesh));
nPts = readlinefibres(fgetl(fpts));

values = zeros(nPts, 1);
for ix=1:nPts
    values(ix) = readlinefibres(fgetl(fi));
end

try
    for jx=1:nElem
        if (mod(jx, 50000)==0)
            fprintf('%d: \n', jx);
        end
        elemId = readlinefibres(fgetl(fmesh));
        elemId([1 6]) = [];
        elemId = elemId + 1;
        
        elemValue = mean(values(elemId));
        fprintf(fo, '%12.12f\n', elemValue);
    end
catch
    fprintf('ERROR at %d\n', jx);
end

fclose all;