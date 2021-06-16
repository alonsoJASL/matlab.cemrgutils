function [str] = quickcatcolour(range, one) 
% 
switchCase = find(range==one);
switch switchCase
    case 1 
        str = 'k';
    case 2
        str = 'b';
    case 3
        str = 'g';
    case 4
        str = 'm';
    case 5 
        str = 'c';
    case 6
        str = 'y';
    otherwise 
        str = 'r';
end
        
        