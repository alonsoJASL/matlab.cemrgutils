%

[pname, fname] = cemrg_io('Choose the nifti file', '.', '*.nii');
[V, vinfo] = readParseNifti(fullfile(pname, fname));

changeNiftiDataType(V, vinfo, fullfile(pname, fname), 'uint8');