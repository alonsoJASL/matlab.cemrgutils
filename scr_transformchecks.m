%% 
clear
mydir='/home/jsl19/data/PATIENTS';
p = dir(mydir);
p(1:2) = [];
p = {p.name}';
pre = 'PRE/ANALYSIS';
post = 'POST/ANALYSIS';

regdir = '/media/jsl19/Data/kcl.registration/';
trdir = fullfile(regdir, 'transform');
imcomparedir = fullfile(regdir, 'imcompare');

txnames = dir(fullfile(trdir,'*.nii'));
txnames = {txnames.name}';
%
Vpre = niftiread(fullfile(regdir, 'LGE-pre.nii'));
Vpost = niftiread(fullfile(regdir, 'LGE-post.nii'));
Vpre = double(Vpre)./max(double(Vpre(:)));
Vpost = double(Vpost)./max(double(Vpost(:)));

[nx, ny, nz] = size(Vpre);
VV = cat(3, reshape(Vpre, [nx ny 1 nz]), reshape(Vpost, [nx ny 1 nz]), zeros(nx,ny,1,nz));

GT = niftiread(fullfile(regdir, 'LA-pre.nii'));

% definition of parameters
registrationparams;
tots = numel(be)*numel(le)*numel(tp)*numel(vp)*numel(ds);
RESULTS.Jaccard = zeros(tots,1);
RESULTS.Precision = zeros(tots,1);
RESULTS.Recall = zeros(tots,1);
RESULTS.Accuracy = zeros(tots,1);
RESULTS.indx = zeros(tots,5);

for index=1:length(txnames)
    thisFilename = txnames{index};
    disp(thisFilename);
    
    [ix, jx, kx, rx, qx] = getPointFromStr(thisFilename);
    
    BW = niftiread(fullfile(trdir, thisFilename));
    [T, stats] = compareWithGT(BW, GT);
    
    niftiwrite(T, fullfile(imcomparedir, thisFilename));
    
    RESULTS.Jaccard(index) = stats.jaccard;
    RESULTS.Precision(index) = stats.precision;
    RESULTS.Recall(index) = stats.recall;
    RESULTS.Accuracy(index) = stats.accuracy;
    RESULTS.indx(index,:) = [ix jx kx rx qx];
   
end

%% CREATE all CONFIG FILES for MIRTK v2
clear
mydir='/home/jsl19/data/PATIENTS';
p = dir(mydir);
p(1:2) = [];
p = {p.name}';
pre = 'PRE/ANALYSIS';
post = 'POST/ANALYSIS';

regdir = '/media/jsl19/Data/kcl.registration/';

Vpre = niftiread(fullfile(regdir, 'LGE-pre.nii'));
Vpost = niftiread(fullfile(regdir, 'LGE-post.nii'));
Vpre = double(Vpre)./max(double(Vpre(:)));
Vpost = double(Vpost)./max(double(Vpost(:)));

[nx, ny, nz] = size(Vpre);
VV = cat(3, reshape(Vpre, [nx ny 1 nz]), reshape(Vpost, [nx ny 1 nz]), zeros(nx,ny,1,nz));

GT = niftiread(fullfile(regdir, 'LA-pre.nii'));

% definition of parameters
registrationparams;

for ix=1:length(be)
    for jx=1:length(le)
        for kx=1:length(tp)
            for rx=1:length(vp)
                for qx=1:length(ds)
                    gridstr = gridPointString([ix jx kx rx qx]);
                    inName = strcat('TX-', gridstr, '.nii');
                    disp(fullfile(regdir, 'transform', inName));
                end
            end
        end
    end
end

%% 
function [gridpointSTR] = gridPointString(v)
% v = [I J K R Q]
gridpointSTR = '';
for index=1:length(v)
    gridpointSTR = strcat(gridpointSTR, num2padstr(v(index), 2));
    if index ~= length(v)
        gridpointSTR = strcat(gridpointSTR, '_');
    end
end
end

function [I, J, K, R, Q] = getPointFromStr(str)
ss2 = strsplit(str, {'-', '.', '_'});
v = zeros(1,5);
realindx = 0;
for index=1:length(ss2)
    num = str2num(ss2{index});
    if ~isempty(num)
        realindx = realindx+1;
        v(realindx) = num;
    end 
end
I = v(1);
J = v(2);
K = v(3);
R = v(4);
Q = v(5);
end