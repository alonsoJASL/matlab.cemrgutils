% Helper script for model reproducibility paper
% 

tidy;
load mri;

clear D;
map = uint16(map.*65535);

switch chooseplatform
    case 'win'
        baseDirectory = 'D:/';
    case 'mac'
        baseDirectory = '/Volumes/sandisk';
    case 'linux'
        baseDirectory = '/media/jsl19/sandisk';
end

baseDirectory = fullfile(baseDirectory, '01_atrialfibres', '06_Reproducibility');
figpath = fullfile(baseDirectory, '07_paper_figures', '01_matlab');

usr = '004_jose';
casespath = fullfile(baseDirectory, '05_UserProjects', usr, '03_completed');
cases = dir(fullfile(casespath,'PATIENT_*' ));
cases = {cases.name};

ix=10; % 1..length(cases)

p2f = fullfile(casespath, cases{ix});
isAuto = isCaseAutomatic(p2f);

cemrg_info('Loading images')
if isAuto==true
    mrapath = searchForPath(p2f, 'dcm-MRA');
    lgepath = searchForPath(p2f, 'dcm-LGE');
    segpath = searchForPath(p2f, 'labelled.nii');

    [mra, mrainfo] = readParseNifti(mrapath);
    [lge, lgeinfo] = readParseNifti(lgepath);
    [seg, seginfo] = readParseNifti(segpath);
else
    cemrg_info('Not auto')

end
%% fig1. Show LGE and MRA scans for graphical abstracts

figure(1) 
subplot(121)
imagescSlide(mra, 67);
subplot(122)
imagescSlide(lge, 67);

% large screen position
set(gcf, 'Position', [205 169 1472 633]);
tightfig


disp(fullfile(figpath, '01_graphicalabstract_input'))

%% fig2. Five slides from cases 
figure(2)
r=2;
c=5;
tot=r*c;

sl=20:15:90;

for ix=1:c
    subplot(c,r,(2*ix-1))
    imagescSlide(mra, sl(ix));
    subplot(c,r,(2*ix))
    imagescSlide(lge, sl(ix));
end

% large screen position
set(gcf, 'Position', [1577 38 575 1281]);
tightfig 

disp(fullfile(figpath, '02_data'))

%% fig3. Automatic pipeline showcase
% this just creates the steps for the automatic pipeline

exdir = fullfile(figpath, 'ex');
mkdir(exdir);

% 1. cemrgnet
[s1, sinfo] = readParseNifti(searchForPath(p2f, 'LA-cemrgnet.nii'));
niftiwrite(s1, fullfile(exdir, 's1.nii'));

% 2. clean 'prodClean.nii'
s2 = seg;
s2(s2>0) = 1;
niftiwrite(s2, fullfile(exdir, 's2.nii'));

% 3. pvs and mvs/clean
s3 = seg;
s3(s3>1) = 2;
s3(s1==3) = 3; 
s3 = s3.*cast(s2, 'like', s3);
niftiwrite(s3, fullfile(exdir, 's3.nii'));

% 4. naive pv/laa 
s4 = seg;
s4(s4==1) = 0;
niftiwrite(s4, fullfile(exdir, 's4.nii'));

% 5. naive labelled - seg
s5 = seg;
s5(s3==3) = 10;
niftiwrite(s5, fullfile(exdir, 's5.nii'));

%% 
imagescWithBoundaries(lge, seg, 67);

%% Helper functions
function [pathsearched] = searchForPath(d, beginsWith)
aa = dir(fullfile(d, [beginsWith '*']));
name = aa.name;
pathsearched = fullfile(d, name);
end

function [isAuto] = isCaseAutomatic(d)
p = searchForPath(d, 'auto.txt');
isAuto = ~isempty(p);
end

function imagescWithBoundaries(V, BW, indx)
A = V(:,:,indx)';
bw = BW(:,:,indx)';

l=unique(bw);
l(l==0) = [];
mrkr = {'r', 'y', 'm', 'g', 'b'};

plotBoundariesAndPoints(A, bwboundaries(bw==1));
for ix=2:length(l)
    plotBoundariesAndPoints([], [], bwboundaries(bw==l(ix)), mrkr{ix});
end
end

function imagescSlide(V, indx)
A = V(:,:,indx)';
imagesc(A);
colormap bone;
axis square;
xticks([]);
yticks([]);
end