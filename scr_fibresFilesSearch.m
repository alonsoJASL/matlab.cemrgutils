clc
debugvar = false;
%path = '/media/jsl19/DATA/KCL_EP/case02/2_mesh/myCGALMeshDir/testout';
path = 'E:\KCL_EP_WIN\m3d_tests\CGALMeshDir\fibresOut';

psi_fn = 'mesh_psi_ab';
phi_lv_fn = 'mesh_phi_lv';
phi_rv_fn = 'mesh_phi_rv';
phi_epi_fn = 'mesh_phi_epi';

if ~isfolder(fullfile(path, 'matlabFibres'))
    mkdir(path, 'matlabFibres');
end

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

iter = 1;
tic;
while ~feof(Fphi_lv)
    phi_lv_val = fixvaluesfibres(readlinefibres(fgetl(Fphi_lv)));
    phi_rv_val = fixvaluesfibres(readlinefibres(fgetl(Fphi_rv)));
    phi_epi_val = fixvaluesfibres(readlinefibres(fgetl(Fphi_epi)));
    
    if (abs(phi_lv_val) < 1e-10 && abs(phi_rv_val) < 1e-10)
        phi_lv_val = phi_lv_val + 1e-6;
        phi_rv_val = phi_rv_val + 1e-6;
        phi_epi_val = phi_epi_val - 2e-6;
    end
    
    grad_phi_lv = readlinefibres(fgetl(Fgrad_phi_lv));
    grad_phi_rv = readlinefibres(fgetl(Fgrad_phi_rv));
    grad_phi_epi = readlinefibres(fgetl(Fgrad_phi_epi));
    grad_psi = readlinefibres(fgetl(Fgrad_psi));
    
 

end