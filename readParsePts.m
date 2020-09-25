function [vector] = readParsePts(fname)
% Read pts file
[path, bname, ext] = fileparts(fname);
fi = fopen(fname);
nPts = 0;

if contains(ext, '.pts')
    nPts = readlinefibres(fgetl(fi));
end

if nPts > 0
    vector = zeros(nPts, 1);
    for ix=1:nPts
        vector(ix) = readlinefibres(fgetl(fi));
    end
else 
    iter=1;
    while ~feof(fi)
        vector(iter) = readlinefibres(fgetl(fi));
        iter = iter+1;
    end
end
        
    