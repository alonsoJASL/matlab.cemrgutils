function [outputImage, outputImageInfo, inputsStruct] = relabelVentricleSegmentation(input, bloodpool, output, opts)
% RELABEL VENTRICLE SEGMENTATION FOR FIBRES CALCULATION.
%
% USAGE:
%   [V, vinfo] = relabelVentricleSegmentation(input, bloodpool, bloodPoolLabel, swapLabels, seD, output)
%
%           bloodPoolLabel = bloodpool label (default=30)
%             swapLabels = swap labels swapLabels(1) for swapLabels(2) (default=[1 5])
%            seD = diameter of structuring element sphere (default=1])
%
% Set variable output='' to avoid saving to disk

cemrg_info('\nStarting...')
if nargin < 3
    output = '';
    [bpLabel, swapL, seDiameter, saveResizedBP] = getOptions([]);
elseif nargin < 4
    [bpLabel, swapL, seDiameter, saveResizedBP] = getOptions([]);
else
    [bpLabel, swapL, seDiameter, saveResizedBP] = getOptions(opts);
end

cemrg_info(sprintf('Parameters used:\nbloodPoolLabel=%d, swapLabels=[%d %d], seD=%d',...
    bpLabel, swapL(1), swapL(2), seDiameter));

cemrg_info(sprintf('Reading images from paths:\n\tINPUT:%s\n\tBLOODPOOL:%s', ...
    fmtPath(input), fmtPath(bloodpool)));

[outputImage, inputImageInfo] = readParseNifti(input);
[bloodpoolImage, ~] = readParseNifti(bloodpool);
datatype = inputImageInfo.Datatype;

cemrg_info('Resizing bloodpool volume');
bloodpoolImage = cast(imresize3(bloodpoolImage, size(outputImage), 'nearest'), datatype);

if saveResizedBP==true
    [bppath,~,ext] = fileparts(inputImageInfo.Filename);
    bpImageInfo = inputImageInfo;
    bpImageInfo.Filename = fullfile(bppath, ['dilatedImageCav_resized' ext]);
    
    cemrg_info(sprintf('Saving...\n\tRESIZED_BP: %s', fmtPath(bpImageInfo.Filename)));
    niftiwrite(bloodpoolImage, bpImageInfo.Filename, bpImageInfo);
end

cemrg_info('Dilating bloodpool and extracting corresponding segment in input.');
if seDiameter==0
    se=1;
else
    se = strel('sphere', seDiameter);
end

dilatedBloodpool = cast(imdilate(bloodpoolImage==bpLabel, se), datatype);
imageFragment = dilatedBloodpool.*outputImage;

if saveResizedBP==true
    bpImageInfo.Filename = fullfile(bppath, ['dilatedImageCav_Dilated' ext]);
    
    cemrg_info(sprintf('Saving...\n\tDILATED_BP: %s', fmtPath(bpImageInfo.Filename)));
    niftiwrite(dilatedBloodpool, bpImageInfo.Filename, bpImageInfo);
end

cemrg_info(sprintf('Relabelling %d to %d', swapL(1), swapL(2)));
outputImage(imageFragment==swapL(1)) = swapL(2);

outputImageInfo = inputImageInfo;
if ~isempty(output)
    [outpath,~,ext] = fileparts(inputImageInfo.Filename);
    outputImageInfo = inputImageInfo;
    outputImageInfo.Filename = fullfile(outpath, [output ext]);
    
    cemrg_info(sprintf('Saving...\n\tOUTPUT: %s', fmtPath(outputImageInfo.Filename)));
    niftiwrite(outputImage, outputImageInfo.Filename, outputImageInfo);
end

if nargout > 2
    [inV, ininfo] = readParseNifti(input);
    inputsStruct.image = inV;
    inputsStruct.imageInfo = ininfo;
    inputsStruct.bloodpool = bloodpoolImage;
end

end

function [bpLabel, swapL, seDiameter, saveResizedBP] = getOptions(opts)
bpLabel = 30;
swapL = [1 5];
seDiameter = 1;
saveResizedBP = false;

if ~isempty(opts)
    fnames = fieldnames(opts);
    for ix=1:length(fnames)
        switch fnames{ix}
            case {'bpLabel', 'bplabel', 'bloodPoolLabel', 'bloodPoolLabel'}
                bpLabel = opts.(fnames{ix});
            case {'swapL', 'swapl', 'swapLabels', 'swapLabels'}
                swapL = opts.(fnames{ix});
            case {'seDiameter', 'seD', 'sed', 'sediameter'}
                seDiameter = opts.(fnames{ix});
            case {'saveBP', 'saveResizedBP', 'saveBloodpool'}
                saveResizedBP = opts.(fnames{ix});
            otherwise
                cemrg_info(sprintf('Parameter: %s not found.', fnames{ix}));
        end
    end
end
end
