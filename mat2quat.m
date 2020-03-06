function [q] = mat2quat(Q)
% matrix to quaternion
% q is a 1x4 vector, Q is a 3x3 matrix
%

q=zeros(1,4);
tr=trace(Q);
test1 = Q(2,2) > -Q(3,3) && Q(1,1) > -Q(2,2) && Q(1,1) > -Q(3,3);
test2 = Q(2,2) < -Q(3,3) && Q(1,1) >  Q(2,2) && Q(1,1) >  Q(3,3);
test3 = Q(2,2) >  Q(3,3) && Q(1,1) <  Q(2,2) && Q(1,1) < -Q(3,3);
test4 = Q(2,2) <  Q(3,3) && Q(1,1) < -Q(2,2) && Q(1,1) <  Q(3,3);

disp([test1 test2 test3 test4]);

if test1==true
    S = sqrt(1+tr);
    a = S;
    b = (Q(2,3)-Q(3,2))/S;
    c = (Q(3,1)-Q(1,3))/S;
    d = (Q(1,2)-Q(2,1))/S;
elseif test2==true
    S = sqrt(1+Q(1,1)-Q(2,2)-Q(3,3));
    a = (Q(2,3)-Q(3,2))/S;
    b = S;
    c = (Q(1,2)+Q(2,1))/S;
    d = (Q(3,1)+Q(1,3))/S;
elseif test3==true
    S = sqrt(1-Q(1,1)+Q(2,2)-Q(3,3));
    a = (Q(3,1)-Q(1,3))/S;
    b = (Q(1,2)+Q(2,1))/S;
    c = S;
    d = (Q(2,3)+Q(3,2))/S;
elseif test4 == true
    S = sqrt(1-Q(1,1)-Q(2,2)+Q(3,3));
    a = (Q(1,2)-Q(2,1))/S;
    b = (Q(3,1)+Q(1,3))/S;
    c = (Q(2,3)+Q(3,2))/S;
    d = S;
end

q = 0.5 .* [a b c d];


