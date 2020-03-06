function [qt] = quat_ijk(indx)
% 

binA = double(indx==1); 
binB = double(indx==2);
binC = double(indx==3);
binD = double(indx==4);

qt = quaternion(binA, binB, binC, binD);