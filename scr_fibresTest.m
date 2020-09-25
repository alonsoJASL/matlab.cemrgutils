% Tests
clc
debugvar = true;
debugiter = 100000;
%path = '/media/jsl19/DATA/KCL_EP/case02/2_mesh/myCGALMeshDir/testout';
path = 'E:\KCL_EP_WIN\case02\fibres_tests';

bname = 'mesh';

psi_fn = [bname '_psi_ab'];
phi_lv_fn = [bname '_phi_lv'];
phi_rv_fn = [bname '_phi_rv'];
phi_epi_fn = [bname '_phi_epi'];

if ~isfolder(fullfile(path, 'matlabFibres'))
    mkdir(path, 'matlabFibres');
end

outfs = 'mesh_fibres_FS.lon';

Fgrad_phi_lv = fopen(fullfile(path, [phi_lv_fn '.grad']), 'r');
Fgrad_phi_rv = fopen(fullfile(path, [phi_rv_fn '.grad']), 'r');
Fgrad_phi_epi = fopen(fullfile(path, [phi_epi_fn '.grad']), 'r');
Fgrad_psi = fopen(fullfile(path, [psi_fn '.grad']), 'r');

Fphi_epi = fopen(fullfile(path, [phi_epi_fn '_potential_elem.dat']), 'r');
Fphi_lv = fopen(fullfile(path, [phi_lv_fn '_potential_elem.dat']), 'r');
Fphi_rv = fopen(fullfile(path, [phi_rv_fn '_potential_elem.dat']), 'r');

alpha_epi = -50;
alpha_endo = 40;
beta_epi = 25;
beta_endo = -65;

Ffs = fopen(fullfile(path, 'matlabFibres', outfs), 'w');
nElem = readlinefibres(fgetl(Fgrad_phi_lv));

iter=1;
tic;
disp('Starting...');
fprintf(Ffs, '%d\n', 2);

if debugvar == true
    fprintf('Starting on %d points.\n', nElem);
end

% while ~feof(Fphi_lv)
for qx=1:nElem
    %while iter <= 2
    if (debugvar==true && mod(iter,debugiter)==0)
        disp('=========================================');
        fprintf('===================[%d]====================\n', iter);
        disp('=========================================');
    end
    phi_lv_val = fixvaluesfibres(readlinefibres(fgetl(Fphi_lv)));
    phi_rv_val = fixvaluesfibres(readlinefibres(fgetl(Fphi_rv)));
    phi_epi_val = fixvaluesfibres(readlinefibres(fgetl(Fphi_epi)));
    
    if (abs(phi_lv_val) < 1e-10 && abs(phi_rv_val) < 1e-10)
        phi_lv_val = phi_lv_val + 1e-6;
        phi_rv_val = phi_rv_val + 1e-6;
        phi_epi_val = phi_epi_val - 2e-6;
    end
    
    ratio = phi_rv_val / (phi_rv_val + phi_lv_val);
    
    % fprintf('lv:%6.6e, rv:%6.6e ratio: %6.6e | epi:%6.6e\n', ...
    %     phi_lv_val, phi_rv_val, ratio, phi_epi_val);
    
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
    
    if (debugvar==true && mod(iter,debugiter)==0)
        disp('[Qlv : Qrv = Qendo]');
        disp([Qlv Qrv Qendo]);
        disp('=========================================');
        
        disp('[Qendo : Qepi = FST]');
        disp([Qendo Qepi FST]);
        disp('=========================================');
    end
    F = FST(:,1);
    S = FST(:,2);
    %T = FST(:,3);
    
    fprintf(Ffs, '%12.12f %12.12f %12.12f\t%12.12f %12.12f %12.12f\n', ...
        F(1), F(2), F(3), S(1), S(2), S(3));
    
    if (debugvar==true && mod(iter,debugiter)==0)
        fprintf(Ffs, '%12.12f %12.12f %12.12f\t%12.12f %12.12f %12.12f\n', ...
        F(1), F(2), F(3), S(1), S(2), S(3));
        % fprintf('%12.12e %12.12e %12.12e\n', T(1), T(2), T(3));
    end
    iter = iter+1;
    
    if mod(iter, 100000)==0
        fprintf('\tIteration: %d.\n', iter);
    end
end
t = toc;
fprintf('Time taken: %f min.\n', t/60);
fprintf('Number of points: %d.\n', iter);
fclose('all');
disp('finished');
