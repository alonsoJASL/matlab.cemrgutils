function [C] = binsphere(imsize, xc, yc, zc, R)

if min(imsize) < R
    disp('Radius selected is too large');
    C = [];
end

s_x = imsize(1);
s_y = imsize(2);
s_z = imsize(3);

[X, Y, Z] = meshgrid(1:s_x, 1:s_y, 1:s_z);

C = sqrt((X-xc).^2 + (Y-yc).^2 + (Z-zc).^2);
C(C<R) = 1;
C(C>=R) = 0;