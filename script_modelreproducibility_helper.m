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
figpath = fullfile(baseDirectory, '07_paper_figures');

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