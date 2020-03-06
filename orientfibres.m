function [Qout] = orientfibres(Qin, al, bet)
%
ca = cosd(al);
sa = sind(al);
cb = cosd(bet);
sb = sind(bet);

AB = [ca -sa*cb -sa*sb;
      sa  ca*cb  ca*sb;
      0    -sb    cb];
% disp('(alpha, beta) : (ca, sa, cb, sb)');
% disp([al bet ca sa cb sb]);
% disp('[A*B]');
% disp([AB]);

Qout = Qin*AB;

% disp('[Qorient]');
% disp([Qout]);
