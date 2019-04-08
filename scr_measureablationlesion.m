%% MEASURE ABLATION LESION SIZE
%% READ
tidy
if strcmp(chooseplatform, 'linux')
    path2data = '~/data/exampledata2/';
else
    path2data = uigetdir('~');
end
disp('hello')

celldata = readtable(fullfile(path2data,'eg_celldata.csv'));
pointdata = readtable(fullfile(path2data,'eg_pointdata.csv'));

%% CREATE TABLES AND STRUCTURE FOR PATCH
strscalars = celldata.Properties.VariableNames{...
    contains(lower(celldata.Properties.VariableNames), 'scalars')};

faceIdx = [celldata.PointIndex0 celldata.PointIndex1 celldata.PointIndex2];
vertices = [pointdata.Points_0 pointdata.Points_1 pointdata.Points_2];
scalars = celldata.(strscalars);%./max(celldata.(scalars)(:));

idx = celldata.CellID + 1;

F = faceIdx+1;
S.Vertices = vertices;
S.Faces = F;
S.CData = scalars;
S.FaceColor = 'flat';
S.EdgeColor = 'none';
S.FaceNormals = [celldata.Normals_0 celldata.Normals_1 celldata.Normals_2];

%% SPECIAL DOUBLE THRESHOLD
% 1.1: Otsu separating the intensities higher than zero.
% 1.2: Two-level Otsu separating intensities higher than first otsu.
% 1.3: (optional) Quantise the levels (for visualisation)
%
ot1 = multithresh(scalars(scalars>0));
thresh = multithresh(scalars(scalars>ot1), 2);

% cqs = colorquantise(c,thresh);

%% HYSTERESIS PROCESS
% 2.1: Create adjacency matrix of FACES whose scalars are higher than
% the first Otsu level.
% 2.2: Create a directed graph out of the adjacency matrix
% 2.3: Find and label the connected graphs of the matrix (optional, ask for 
% weak connections)
% 2.4: find which labels are also part of the higher threshold.
adjlow = faceadjacency(F, find(scalars>=thresh(1)));
Glowt = digraph(adjlow);

[lowT] = conncomp(Glowt);
%[lowT] = conncomp(Glowt, 'Type', 'weak');

lowT(scalars<thresh(1)) = 0;
lowT = lowT';

tokeep = unique(lowT.*(scalars>=thresh(2)));

%% THRESHOLDING OUTPUTS
binscalars =single(ismember(lowT, tokeep(2:end)));

adjhyst = faceadjacency(F, find(binscalars>0));
labeledscalars = conncomp(digraph(adjhyst));
labeledscalars(binscalars==0) = 0;
labeledscalars = labeledscalars';

labs = unique(labeledscalars);
labs(1) = [];
numtri = zeros(size(labs));
for ix=1:length(labs)
numtri(ix) = sum(labeledscalars==labs(ix));
end
[b,idx] = sort(numtri, 'descend');
for ix=1:length(b)
labeledscalars(labeledscalars==labs(idx(ix))) = ix;
end

outS = S;

%% 
figure(200)
subplot(121)
outS.CData = binscalars;
patch(outS);
view(-166, 6.35);
title('Hysteresis threshold');

subplot(122)
outS.CData = labeledscalars;
patch(outS);
view(-166, 6.35);
title('Labelled lesions');

%% 


