% Check UAC landmarks
% Script created to check the landmark file order of the RA UAC
% 18/03/22
%

%% Load data 
p2gt = uigetdir('~', 'Choose Ground Truth Mesh you know is correct');
gtMesh = 'Labelled.pts';
Labelled = readPointsFile(fullfile(p2gt, gtMesh)); 

p2test = uigetdir(p2gt, 'Choose mesh you want to test');
testMesh = 'clean-Labelled-refined.pts';
cleanLabelledrefined = readPointsFile(fullfile(p2test, testMesh));

lndmrkFilename = 'prodRaLandmarks.txt';
regionFilename = 'prodRaRegion.txt';
%%  
lndmrk_gt = readmatrix(fullfile(p2gt, lndmrkFilename), 'Delimiter', ',');
region_gt = readmatrix(fullfile(p2gt, regionFilename), 'Delimiter', ',');
lndmrk_test = readmatrix(fullfile(p2test, lndmrkFilename), 'Delimiter', ',');
region_test = readmatrix(fullfile(p2test, regionFilename), 'Delimiter', ',');

%% Scatter plots of everything 
close all
whichPoint= 4; % whichPoint
file_gt = lndmrk_gt; % lndmrk or region
file_test = lndmrk_test; % lndmrk or region

figure(1)
set(gcf, 'Position', [1 278 1290 664]);
subplot(121)
scatter3(Labelled(1:10:end,1), ...
         Labelled(1:10:end,2), ...
         Labelled(1:10:end,3), 18, ".");
hold on
scatter3(file_gt(whichPoint,1).*1000, ...
         file_gt(whichPoint,2).*1000, ...
         file_gt(whichPoint,3).*1000, 100, 'm','filled')
title('Ground truth (original)')

subplot(122)
scaleF = 1000;
scatter3(cleanLabelledrefined(1:10:end,1),...
         cleanLabelledrefined(1:10:end,2), ...
         cleanLabelledrefined(1:10:end,3), 18, ".");
hold on
scatter3(file_test(whichPoint,1).*scaleF, ...
         file_test(whichPoint,2).*scaleF, ...
         file_test(whichPoint,3).*scaleF, 100, 'm','filled')
title('Test point')

