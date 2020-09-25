function [Q] = axisfibres(grad_psi, grad_phi)
%
grad_psi = grad_psi(:);
grad_phi = grad_phi(:);

if norm(cross(grad_phi, grad_psi))<1e-12
    % disp([grad_phi grad_psi]);
    grad_phi(1) = grad_phi(1) + 1e-10;
    grad_psi(2) = grad_psi(2) + 1e-10;
end

e0 = grad_psi ./ norm(grad_psi);
d = grad_phi - (e0'*grad_phi)*e0;
Ce =[0    -e0(3)  e0(2);
    e0(3)   0    -e0(1);
   -e0(2)  e0(1)    0];

e1 = d ./ norm(d);
e2 = Ce * e1;

Q = [e0 e1 e2];

% disp('[Qaxis]');
% disp([Q]);
