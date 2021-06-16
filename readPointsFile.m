function [pts, nPts] = readPointsFile(ptsPath)
% [pts, nPts] = readPointsFile(ptsPath)

fPts = fopen(ptsPath, 'r');
nPts = readlinefibres(fgetl(fPts));

cemrg_info(sprintf('Points: %d', nPts));
pts_cell = textscan(fPts, '%f %f %f', nPts);

pts = [pts_cell{1} pts_cell{2} pts_cell{3}];
fclose(fPts);