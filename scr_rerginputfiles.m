% Create input files for registration.
%% create input files (change if the order is incorrect)
clear
mydir='/home/jsl19/data/PATIENTS';
p = dir(mydir);
p(1:2) = [];
p = {p.name}';
pre = 'PRE/ANALYSIS';
post = 'POST/ANALYSIS';

prefiles = dir(fullfile(mydir, '**', pre, 'dcm-LGE*.nii'));
postfiles = dir(fullfile(mydir, '**', post, 'dcm-LGE*.nii'));
prefiles={prefiles.name}';
postfiles={postfiles.name}';

for ix = 1:length(p)
    fi = fopen(fullfile(mydir, p{ix}, 'inputimages.lst'), 'w');
    fprintf(fi, '%s ' ,fullfile(mydir, p{ix}, post, postfiles{ix}));
    fprintf(fi, '%s ' ,fullfile(mydir, p{ix}, pre, prefiles{ix}));
    fclose(fi);
end

%% Create configuration file
clear
mydir='/home/jsl19/data/PATIENTS';
p = dir(mydir);
p(1:2) = [];
p = {p.name}';
pre = 'PRE/ANALYSIS';
post = 'POST/ANALYSIS';

regdir = '/home/jsl19/data/test_registration';

% definition of parameters
be=[1e-06 2e-05 0.0003 0.006 0.04 0.1];
le=[0 1e-06 2e-05 0.0003 0.006 0.04];
tp=[0 1e-06 2e-05 0.0003 0.006 0.04];
vp=[0 1e-06 2e-05 0.0003 0.006 0.04];
ds=[4 8 16];

%% MIRTK (v2) - newer test
ix=1;
jx=3;
kx=5;
rx=1;
qx=2;

argos.BendingEnergy = be(ix);
argos.LinearEnergy = le(jx);
argos.TopologyPreservation = tp(kx);
argos.VolumePreservation = vp(rx);
argos.ControlPointSpacing = ds(qx);

outname = sprintf('CONFIGURATION_%s_%s_%s_%s_%s_MIRTKv2.cfg', num2padstr(ix,2),...
    num2padstr(jx,2), num2padstr(kx,2), num2padstr(rx,2), num2padstr(qx,2));

createConfigurationFileNewer(fullfile(regdir, 'config', outname), argos);

%% MIRTK (v1) - older test
IX=1;
JX=3;
KX=2;
RX=1;

argos2.BendingEnergy = be(IX);
argos2.VolumePreservation = vp(JX);
argos2.ControlPointSpacing = ds(KX);
argos2.Resolution = 5;

outname = sprintf('configuration_%s_%s_%s_%s_%s_mirtkV1.cfg', num2padstr(IX,2),...
    num2padstr(JX,2), num2padstr(KX,2), num2padstr(RX,2), num2padstr(5,2));

createConfigurationFileOlder(fullfile(regdir, 'config', outname), argos2);

%% CREATE all CONFIG FILES for MIRTK v2
clear
mydir='/home/jsl19/data/PATIENTS';
p = dir(mydir);
p(1:2) = [];
p = {p.name}';
pre = 'PRE/ANALYSIS';
post = 'POST/ANALYSIS';

regdir = '/media/jsl19/Data/kcl.registration/parin';

registrationparams;

for ix=1:length(be)
    for jx=1:length(le)
        for kx=1:length(tp)
            for rx=1:length(vp)
                for qx=1:length(ds)
                    
                    argos.BendingEnergy = be(ix);
                    argos.LinearEnergy = le(jx);
                    argos.TopologyPreservation = tp(kx);
                    argos.VolumePreservation = vp(rx);
                    argos.ControlPointSpacing = ds(qx);
                    
                    outname = sprintf('CONFIGURATION_%s_%s_%s_%s_%s_MIRTKv2.cfg',...
                        num2padstr(ix,2), num2padstr(jx,2), ...
                        num2padstr(kx,2), num2padstr(rx,2), num2padstr(qx,2));
                    
                    createConfigurationFileNewer(fullfile(regdir, outname), argos);
                    
                    clear argos;
                end
            end
        end
    end
end


%% CONFIG FILE FUNCTION GENERATION TEMPLATE
% DO ONCE

clear
mydir='/home/jsl19/data/PATIENTS';

fi = fopen('/home/jsl19/data/test_registration/testparameters.cfg', 'r');
fw = fopen('createConfigurationFileTEMPLATE.m','w');

while ~feof(fi)
    tline = fgetl(fi);
    fprintf(fw, 'CHANGEME %s ALSOME\n', tline);
end
fclose(fi);
fclose(fw);
%%

fi2 = fopen('/home/jsl19/data/test_registration/orods_config.cfg', 'r');
fw2 = fopen('createConfigurationFileOlder.m','w');

while ~feof(fi2)
    tline = fgetl(fi2);
    fprintf(fw2, 'CHANGEME %s ALSOME\n', tline);
end
fclose(fi2);
fclose(fw2);

%%
