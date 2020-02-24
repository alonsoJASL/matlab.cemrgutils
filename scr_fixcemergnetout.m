V = niftiread(vinfo);
V = uint8(round(V));
vinfo.Datatype = 'uint8';
vinfo.raw.datatype = 2;
vinfo.Filename = '/media/jsl19/DATA/kcl.clinitians.testdata/DHTestNIFTI_badAI/TEST2/LA-matlab.nii';
niftiwrite(V, vinfo.Filename, vinfo);