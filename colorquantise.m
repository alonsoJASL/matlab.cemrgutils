function [cq] = colorquantise(c, levs)
% 

if nargin < 2
    ot1 = multithresh(c(c>0));
    levs = multithresh(c(c>ot1));
end

cq=zeros(size(c));

levq = 1:length(levs);

for ix=1:length(levs)
    cq(c>levs(ix)) = levq(ix);
end

    
