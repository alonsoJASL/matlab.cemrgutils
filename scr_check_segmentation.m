
[filename, path2file] = uigetfile({'*.nii', '*.nrrd'}, 'Select your segmentation file');
[V, vinfo] = readParseNifti(fullfile(path2file, filename));

disp("Values found in segmentation are:")
disp(unique(V(:)));

str=input("Do you want to binarise (turn to 1s and 0s)? [y/n] [Default=y]", 's');
if isempty(str)
    str='y';
end

switch lower(str)
    case 'y'
        fprintf('Saving file with name Bin_%s\n', filename);
        V(V>0) = 1;
        niftiwrite(V, fullfile(path2file, sprintf('Bin_%s', filename)),vinfo);
        disp('done');
    case 'n'
        disp('OK, bye');
end


%% helper functions
function [Vol, volInfo] = readParseNifti(inputname)
% READ AND PARSE NIFTI FILES. 
% 

inputImageInfo = niftiinfo(inputname);
Vol = niftiread(inputImageInfo);

if nargout > 1
    volInfo = inputImageInfo;
end

end