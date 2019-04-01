function [cq] = colorquantise(c, levs)
% 

numlevs = length(levs);
cq=zeros(size(c));

levq = 1:length(levs);

for ix=1:length(levs)
    cq(c>levs(ix)) = levq(ix);
end

    
