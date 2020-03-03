function [Q] = axisfibres(grad_psi, grad_phi)
% 
grad_psi = grad_psi(:);
grad_phi = grad_phi(:);

e0 = grad_psi ./ norm(grad_psi);
d = grad_phi - (e0'*grad_phi)*e0; 
Ce =[0 -e0(3) e0(2); e0(3) 0 -e0(1); - e0(2) e0(1) 0];

e1 = d ./ norm(d);
e2 = Ce * e1; 

Q = [e0 e1 e2];

% disp([Q Q'*Q]);