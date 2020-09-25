function [options] = getVentricleSegmentationOptions(whichVentricle)
%

switch lower(whichVentricle)
    case 'lv'
        options.bpLabel=10; %LV
        options.swapL=[5 1];
        options.seDiameter=0;
        options.saveResizedBP=false;
    case 'rv'
        options.bpLabel=30; % RV
        options.swapL=[1 5];
        options.seDiameter=2;
        options.saveResizedBP=false;
    otherwise
        options = [];
end
