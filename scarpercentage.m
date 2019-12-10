function [perc, csvTable] = scarpercentage(dataIn, thr)
%

if nargin < 2
    thr = 0 ;
end

T = dataIn;

if ~any(contains(T.Properties.VariableNames, 'is_scar'))
    
    width = zeros(size(T,1),1);
    is_scar = zeros(size(T,1),1);
    
    for ix=1:size(T,1)
        if T.MeshScalar(ix) > thr
            is_scar(ix) = 1;
            width(ix) = distance;
        else
            is_scar(ix) = 0;
            width(ix) = 0;
        end
    end
    T = [T table(width, is_scar)];
end
perc = 100*(sum(T.is_scar > 0)./size(T,1));

if nargout > 1
    csvTable = T;
end