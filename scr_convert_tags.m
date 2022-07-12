
p2f='/media/jsl19/sandisk/01_atrialfibres/11_tiffany/segmentations_tiffany/';
name='segmentation_final.nii';
oname='seg_tagged.nii';

[V, vinfo] = readParseNifti(fullfile(p2f, name));

cemrg_info('File loaded')

MV_e=1; MV_c=3; % mv
Wall=2; Bp=4;  
RI_e=5; RI_c=6; 
LI_e=7; LI_c=8; 
RS_e=9; RS_c=10; 
A_e=11; A_c=12; 
LS_e=14; LS_c=13;

MV=3; 
LA=1; 
LSPV=11; 
LIPV=13; 
RSPV=15; 
RIPV=17; 
LAA=19;

vtag=V;

vtag(V==MV_c)=MV; vtag(V==MV_e)=MV;
vtag(V==Wall)=LA; vtag(V==Bp)=LA;

vtag(V==LS_c)=LSPV; vtag(V==LS_e)=LSPV;
vtag(V==LI_c)=LIPV; vtag(V==LI_e)=LIPV;

vtag(V==RS_c)=RSPV; vtag(V==RS_e)=RSPV;
vtag(V==RI_c)=RIPV; vtag(V==RI_e)=RIPV;

vtag(V==A_c)=LAA; vtag(V==A_e)=LAA;

cemrg_info('Image re-tagged')

vtag=cast(vtag, 'like', V);

niftiwrite(vtag, fullfile(p2f, oname), vinfo);

cemrg_info('Saved')

%% 
% pv/mv/laa extended

oname='seg_tag_ext.nii';
vbin=cast(V>0, 'like', V);

r=5;
mv=extractTag(vtag, MV, r)+1;
lspv=extractTag(vtag, LSPV, r);
lipv=extractTag(vtag, LIPV, r);
rspv=extractTag(vtag, RSPV, r);
ripv=extractTag(vtag, RIPV, r);
laa=extractTag(vtag, LAA, r);

cemrg_info('extracted extended tags');

vtest=vbin + lspv + lipv + rspv + ripv + laa;
vbin(mod(vtest,2)==0) = 0;

cemrg_info('tags integrated to body');
%
niftiwrite(vbin, fullfile(p2f, oname), vinfo);
niftiwrite(mv, fullfile(p2f, 'prodMVI.nii'), vinfo);

cemrg_info('saved');

function [tag] = extractTag(v,t,r)
if nargin < 3
    r=3;
end
tag=cast(imdilate(v==t, strel('sphere',r)).*(t-1), 'like', v);
end