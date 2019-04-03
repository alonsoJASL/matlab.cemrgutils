function [adjmat] = faceadjacency(F, clix)
% ADJACENCY MATRIX OF FACES. F = faces, clix = classes indices.
% 

%F = S.Faces;
if nargin < 2
    clix = 1:(size(F,1)-1);
end

fend = size(F,1);
qq=sparse(fend,fend,0);

for ixx=1:length(clix)
    fx = clix(ixx);
    face = F(fx,:);
    try 
    qq = qq + sparse(fx, (fx+1):fend, ...
        sum(ismember(F((fx+1):fend,:), face), 2)', ...
        fend, fend);
    catch
        disp('oops');
    end
end
adjmat = qq+qq';