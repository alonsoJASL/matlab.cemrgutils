function px = patchquantise(S, numlevs, mini)
% 

if nargin < 3
    mini = -inf;
elseif nargin < 2
    numlevs = 1;
    mini = -inf;
end

Sx = S;
c = S.CData;
otx = multithresh(c(c>mini), numlevs);
cqx = colorquantise(c,ot1);

Sx.CData = cqx;

px = patch(Sx);
title(sprintf('Num thresholds = %d, min intensity = %2.2f', numlevs, mini));
view(-166, 6.35)

