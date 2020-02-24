% Tests
clc

path = '/media/jsl19/DATA/KCL_EP/case02/2_mesh/myCGALMeshDir/testout';

psi_fn = 'mesh_psi_ab';
phi_lv_fn = 'mesh_phi_lv';
phi_rv_fn = 'mesh_phi_rv';
phi_epi_fn = 'mesh_phi_epi';

outf = 'mesh_fibres_F.txt';
outs = 'mesh_fibres_S.txt';
outt = 'mesh_fibres_T.txt';

Fgrad_phi_lv = fopen(fullfile(path, [phi_lv_fn '.grad']), 'r');
Fgrad_phi_rv = fopen(fullfile(path, [phi_rv_fn '.grad']), 'r');
Fgrad_phi_epi = fopen(fullfile(path, [phi_epi_fn '.grad']), 'r');
Fgrad_psi = fopen(fullfile(path, [psi_fn '.grad']), 'r');

Fphi_epi = fopen(fullfile(path, [phi_epi_fn '_potential.dat']), 'r');
Fphi_lv = fopen(fullfile(path, [phi_lv_fn '_potential.dat']), 'r');
Fphi_rv = fopen(fullfile(path, [phi_rv_fn '_potential.dat']), 'r');

alpha_epi = -50;
alpha_endo = 40;
beta_epi = 25;
beta_endo = -65;

Ff = fopen(fullfile(path, 'matlabFibres', outf), 'a');
Fs = fopen(fullfile(path, 'matlabFibres', outs), 'a');
Ft = fopen(fullfile(path, 'matlabFibres', outt), 'a');

iter = 1;
while ~feof(Fphi_lv)
%while iter <= 10
   phi_lv_val = fixvaluesfibres(readlinefibres(fgetl(Fphi_lv)));
   phi_rv_val = fixvaluesfibres(readlinefibres(fgetl(Fphi_rv)));
   phi_epi_val = fixvaluesfibres(readlinefibres(fgetl(Fphi_epi))); 
   
   if (abs(phi_lv_val) < 1e-10 && abs(phi_rv_val) < 1e-10) 
       phi_lv_val = phi_lv_val + 1e-6;
       phi_rv_val = phi_rv_val + 1e-6;
       phi_epi_val = phi_epi_val - 2e-6;
   end
    
   ratio = phi_rv_val / (phi_rv_val + phi_lv_val);
   
   fprintf('lv:%6.6e, rv:%6.6e ratio: %6.6e | epi:%6.6e\n', ...   
       phi_lv_val, phi_rv_val, ratio, phi_epi_val);
      
   grad_phi_lv = readlinefibres(fgetl(Fgrad_phi_lv));
   grad_phi_rv = readlinefibres(fgetl(Fgrad_phi_rv));
   grad_phi_epi = readlinefibres(fgetl(Fgrad_phi_epi));
   grad_psi = readlinefibres(fgetl(Fgrad_psi));
      
   as = evalAlphafibres(ratio, alpha_endo); % alpha_s
   bs = evalBetafibres(ratio, beta_endo); % beta_s
      
   Qlv = orientfibres(axisfibres(grad_psi, -grad_phi_lv), as, bs); 
   Qrv = orientfibres(axisfibres(grad_psi, grad_phi_rv), as, bs); 
   
   Qendo = bislerp(Qlv, Qrv, ratio);
   
   aw = evalAlphafibres(ratio, alpha_epi); % alpha_w
   bw = evalBetafibres(ratio, beta_epi); % beta_w
   Qepi = orientfibres(axisfibres(grad_psi, grad_phi_epi), aw, bw);
   
   FST = bislerp(Qendo, Qepi, phi_epi_val);
   F = FST(:,1);
   S = FST(:,2);
   T = FST(:,3);
   
   fprintf(Ff, '%12.12e %12.12e %12.12e\n', F(1), F(2), F(3));
   fprintf(Fs, '%12.12e %12.12e %12.12e\n', S(1), S(2), S(3));
   fprintf(Ft, '%12.12e %12.12e %12.12e\n', T(1), T(2), T(3));
   
   iter = iter+1;
end
fclose('all');
disp('finished');