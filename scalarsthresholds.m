function [cq] = scalarsthresholds(c)
% 

ot1 = multithresh(c(c>0));
levs = multithresh(c(c>ot1),2);

cq=zeros(size(c));

levq = 1:length(levs);

for ix=1:length(levs)
    cq(c>levs(ix)) = levq(ix);
end

    
