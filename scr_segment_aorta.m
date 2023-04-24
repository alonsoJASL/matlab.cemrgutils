%%

% p2f='/Volumes/sandisk/09-dnav_vs_inav/carmaf/carmaf_cemrg/2020092901/CEMRG/dNav';
% mraname = 'dcm-MRA-16_ce-mra_90secs_after_contrast_ti200.nii';
% lgename = 'dcm-LGE-34_3d_lge_20mins_post_contrast_same_trig_pulse_as_tiscout.nii';
% segname = 'PVeinsCroppedImage_new.nii';

p2f = '/Volumes/SD128/09-dnav_vs_inav/kcl/irum/ANALYSIS_Adv_Comp/dNav';
mraname = 'dcm-MRA-22_ce-mra_90secs_after_contrast_ti200.nii';
lgename = 'dcm-LGE-3DLGE20minspostcontrast,sameTrigpulseasTIscout.nii';
segname = 'PVeinsCroppedImage.nii';

%% load

[l, linfo] = readParseNifti(fullfile(p2f, lgename));
[m, minfo] = readParseNifti(fullfile(p2f, mraname));
[s, sinfo] = readParseNifti(fullfile(p2f, segname));

%% test images
close all;

method = 'PhaseCode'; % 'TwoStage', 'PhaseCode'

% tx=1;
aorta = zeros(size(m));
aorta_errs = zeros(size(m));
sure_centres = -1 .* ones(size(m,3), 2);
sure_radii = -1 .* ones(size(m,3), 1);
for tx=1:size(m,3)
    t = m(:,:,tx);

    [C, rad, met] = imfindcircles(t, [10 19], 'Method',method);
    if length(rad) > 1
        for qx=1:length(rad)
            aorta_errs(:,:,tx) = or(aorta_errs(:,:,tx), imcircle(t, C(qx,:), rad(qx)));
        end
    elseif length(rad) == 1
        aorta(:,:,tx) = imcircle(t, C, rad);
        sure_centres(tx, :) = C;
        sure_radii(tx) = rad;
    end
end

aorta = cast(aorta, 'like', s);
aorta_errs = cast(aorta_errs, 'like', s);

sure_centres(sure_centres(:,1)==-1, :) = [];
assumed_centre = median(sure_centres);
half_radii = median(sure_radii) /2;

% repmat image with circle, compare to aorta_errs
mean_aorta_single = imcircle(t, assumed_centre, half_radii);
mean_aorta = cast(repmat(mean_aorta_single, [1 1 size(m,3)]), 'like', s);

[labelled_errs, n] = bwlabeln(aorta_errs>0);
new_errs = zeros(size(labelled_errs));
for ix=1:n
    test_im = and(labelled_errs==ix, mean_aorta>0);
    if sum(test_im(:)) > 0
        new_errs(labelled_errs==ix) = 1;
    end
end

aorta = aorta + cast(new_errs, 'like', s);
aorta = imclose(aorta, strel('sphere', 3));
volshow(aorta>0);

%% helper functions

function [circle] = imcircle(im, centre, radius)
% define the radius and center coordinates of the circle
center_x = centre(1);
center_y = centre(2);

% create a meshgrid based on the size of the reference image
[x,y] = meshgrid(1:size(im,2), 1:size(im,1));

% calculate the distance of each point in the meshgrid from the center
dist = sqrt((x-center_x).^2 + (y-center_y).^2);

% create a binary image of the circle
circle = dist <= radius;
end