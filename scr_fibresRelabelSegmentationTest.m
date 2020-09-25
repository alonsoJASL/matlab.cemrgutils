%% LV fix first, RV second
% Using dilatedImageCav RV_bp=30, LV_bp=10
tidy;
caseNo = 'case04';

[path, inName, ext] = fileparts(['E:\KCL_EP_WIN\' caseNo '\seg_folder\seginputs\MASK_original.nii']);
bpName = 'dilatedImageCav';
interName = 'MASK_inter';
outName = 'MASK_relabelled';

inPath = fullfile(path, [inName ext]);
bpPath = fullfile(path, [bpName ext]);
inPath2 = fullfile(path, [interName ext]);
%%

cemrg_info('[INFO] fixing LV first - then RV');
[V1, ~, inputs1] = relabelVentricleSegmentation(inPath, bpPath, interName, lvOptions);
[V2, ~, inputs2] = relabelVentricleSegmentation(inPath2, bpPath, outName, rvOptions);