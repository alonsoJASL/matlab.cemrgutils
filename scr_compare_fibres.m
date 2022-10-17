clc;

lon27 = loadFibresLonFile('python 2.7');
lon3 = loadFibresLonFile('python 3.8');

dot_3_27 = dot(lon27', lon3')';
abs_dot_3_27 = abs(dot_3_27);



% M1dotM2 = sum(M1.*M2, 2);
%% 
subs=lon27-lon3;
subs=(lon27-lon3).*(lon27-lon3);
normsq = sum(subs, 2);
mean(normsq);
rms(subs);

%%  helper functions
function [M] = loadFibresLonFile(which_file)
[pn, fn] = cemrg_io(sprintf('Open file corresponding to [%s]', which_file), '.', '*.lon');
%[fn, pn] = uigetfile('./*.*', 'Select lon file');
fi = fopen(fullfile(pn, fn), 'r');
C = textscan(fi, '%f %f %f\n');

M = [C{1} C{2} C{3}];
end