function [cog] = calculateCoG(elems, pts)
%

nElem = size(elems, 1);
cog = zeros(nElem, 3);
for ix=1:nElem
    cog(ix, :) = mean(pts(elems(ix,:), :));
end