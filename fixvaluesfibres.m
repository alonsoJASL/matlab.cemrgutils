function [recval] = fixvaluesfibres(val)

if val < 0
    recval = 0;
elseif val > 1
    recval = 1;
else
    recval = val;
end