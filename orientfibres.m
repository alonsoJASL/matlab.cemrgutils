function [Qout] = orientfibres(Qin, al, bet)
% 
ca = cosd(al);
sa = sind(al);
cb = cosd(bet);
sb = sind(bet);

AB = [ca -sa*cb sa*sb; sa  ca*cb -ca*sb; 0 sb cb];

Qout = Qin*AB;
