%% SOURCE (moving) / TARGET (fixed)
% tidy
source='post';
target='pre';

LGE.source = normaliseMatrix(niftiread(sprintf('~/data/tmp/LGE-%s.nii', source)));
LGE.target = normaliseMatrix(niftiread(sprintf('~/data/tmp/LGE-%s.nii', target)));
LGE.tansformedsrc = normaliseMatrix(niftiread(sprintf('~/data/tmp/LGE-%sTX.nii', source)));

LA.source = normaliseMatrix(niftiread(sprintf('~/data/tmp/LA-%s.nii',source)));
LA.target = normaliseMatrix(niftiread(sprintf('~/data/tmp/LA-%s.nii', target)));
LA.transformedsrc = normaliseMatrix(niftiread(sprintf('~/data/tmp/LA-%sTX.nii', source)));
%LA.transformedtarget = normaliseMatrix(niftiread(sprintf('~/data/tmp/LA-%sTX.nii', target)));

[nx, ny, nz] = size(LGE.source);

LGE.RGB_volume = cat(3, reshape(LGE.target, [nx ny 1 nz]), ... % RED - LGE-target
                        reshape(LGE.tansformedsrc, [nx ny 1 nz]), ... % GREEN - LGE-transformed
                        zeros([nx ny 1 nz])); % 
LGE.RGB_before = cat(3, reshape(LGE.target, [nx ny 1 nz]), ... % RED - LGE-target
                        reshape(LGE.source, [nx ny 1 nz]), ... % GREEN - LGE-source
                        zeros([nx ny 1 nz]));

LA.RGB_volume = cat(3, reshape(LA.target, [nx ny 1 nz]), ... % RED - LA-target
                       reshape(LA.transformedsrc, [nx ny 1 nz]), ... % GREEN - LA-transformed
                       zeros([nx ny 1 nz])); % 
LA.RGB_before = cat(3, reshape(LA.target, [nx ny 1 nz]),... % RED - LA-target
                       reshape(LA.source, [nx ny 1 nz]),... % GREEN - LA-source
                       zeros([nx ny 1 nz]));


%target
figure(9000) 
%ix=50;
%for ix=1:100
subplot(221)
imagesc(LGE.RGB_before(:,:,:,ix))
title(sprintf('(before) RED - %s, GREEN - %s', target, source));
subplot(222)
imagesc(LGE.RGB_volume(:,:,:,ix)); 
title(sprintf('(after TX) RED - %s, GREEN - Tx(%s)', target, source));
subplot(223)
imagesc(LA.RGB_before(:,:,:,ix))
title(sprintf('(before) RED - LA-%s, GREEN - LA-%s', target, source));
subplot(224)
imagesc(LA.RGB_volume(:,:,:,ix))
title(sprintf('(after TX) RED - LA-%s, GREEN - Tx(LA-%s)', target, source));

pause(0.2);
%end

%%
close all;
for ix=1:100
subplot(121)
imagesc(LGE.RGB_before(:,:,:,ix))
title(sprintf('(before) RED - %s, GREEN - %s', target, source));
subplot(122)
imagesc(LA.RGB_before(:,:,:,ix))
title(sprintf('(before) RED - LA-%s, GREEN - LA-%s', target, source));
pause(0.1);
end
