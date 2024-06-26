%% Read
tidy
if strcmp(chooseplatform, 'linux')
    path2data = '~/data/exampledata2/';
else
    path2data = uigetdir('~');
end
disp('hello')

celldata = readtable(fullfile(path2data,'eg_celldata.csv'));
pointdata = readtable(fullfile(path2data,'eg_pointdata.csv'));
%% Create tables and variables
strscalars = celldata.Properties.VariableNames{...
    contains(lower(celldata.Properties.VariableNames), 'scalars')};

f = [celldata.PointIndex0 celldata.PointIndex1 celldata.PointIndex2];
v = [pointdata.Points_0 pointdata.Points_1 pointdata.Points_2];
scalars = celldata.(strscalars);%./max(celldata.(scalars)(:));

idx = celldata.CellID + 1;

F = f+1;
S.Vertices = v;
S.Faces = F;
S.CData = scalars;
S.FaceColor = 'flat';
S.EdgeColor = 'none';
S.FaceNormals = [celldata.Normals_0 celldata.Normals_1 celldata.Normals_2];


%% Paint
figure(100)
p = patch(S);
axis equal;

view(-166, 6.35)

%% Get Otsus

ot1 = multithresh(scalars(scalars>0));
cq1 = colorquantise(scalars,ot1);
ot2 = multithresh(scalars(scalars>0), 2);
cq2 = colorquantise(scalars,ot2);
ots = multithresh(scalars(scalars>ot1), 2);
cqs = colorquantise(scalars,ots);

S1 = S;
S2 = S;
Ss = S;

S3 = S;

S1.CData = cq1;
S2.CData = cq2;
Ss.CData = cqs;

figure(1)
p1 = patch(S1);
title('One threshold')
view(-166, 6.35)

figure(2)
p2 = patch(S2);
title('Two thresholds')
view(-166, 6.35)


figure(5)
ps = patch(Ss);
title('Special double threshold')
view(-166, 6.35)
%% Hysteresis threshold through adjacency matrix

thisS = Ss;
thresh = ots;
scalars = S.CData;

tic;
adjlow = faceadjacency(F, find(scalars>=thresh(1)));
toc

Glowt = digraph(adjlow);
%[bins, binsize] = conncomp(Glowt, 'Type', 'weak');

[lowT, binsize] = conncomp(Glowt);
lowT(scalars<thresh(1)) = 0;
lowT = lowT';

tokeep = unique(lowT.*(scalars>=thresh(2)));

thisS.CData = single(ismember(lowT, tokeep(2:end)));

figure(200)
patch(thisS);
view(-166, 6.35);
title('Hysteresis threshold');


%% Area at a specific level

thisS = Ss;
faces = thisS.Faces(thisS.CData==2,:);
verts = thisS.Vertices;

a = verts(faces(:, 2), :) - verts(faces(:, 1), :);
b = verts(faces(:, 3), :) - verts(faces(:, 1), :);

scalars = cross(a, b, 2);

area = 1/2 * sum(sqrt(sum(scalars.^2, 2)));
fprintf('\nThe surface area is %f\n\n', area);

%% face adjacency (little by little)
% qq=sparse(length(idx), length(idx),0);
% F = S.Faces;
% 
% fend = size(F,1);
% 
% tic
% for fx=1:(size(F,1)-1)
%     face = F(fx,:);
%     qq = qq + sparse(fx, (fx+1):fend, ...
%         sum(ismember(F((fx+1):fend,:), face), 2)', ...
%         fend, fend);
% end
% adjmatrix = qq+qq';
% stadj = adjmatrix==2; % strong adjacency
% toc

% also use
tic;
adjmatrix = faceadjacency(F);
toc
% 



