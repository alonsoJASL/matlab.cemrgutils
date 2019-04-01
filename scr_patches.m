%% Read
tidy 

celldata = readtable('~/data/exampledata2/eg_celldata.csv');
pointdata = readtable('~/data/exampledata2/eg_pointdata.csv');

scalars = celldata.Properties.VariableNames{...
    contains(lower(celldata.Properties.VariableNames), 'scalars')};

f = [celldata.PointIndex0 celldata.PointIndex1 celldata.PointIndex2];
v = [pointdata.Points_0 pointdata.Points_1 pointdata.Points_2];
c = celldata.(scalars);%./max(celldata.(scalars)(:));

F = f+1;
S.Vertices = v;
S.Faces = F;
S.CData = c;
S.FaceColor = 'flat';
S.EdgeColor = 'none';
S.FaceNormals = [celldata.Normals_0 celldata.Normals_1 celldata.Normals_2];


%% Paint
figure(100)
p = patch(S);
axis equal;

view(-166, 6.35)

%% Get Otsus
ot1 = multithresh(c(c>0));
cq1 = colorquantise(c,ot1);
ot2 = multithresh(c(c>0), 2);
cq2 = colorquantise(c,ot2);
ots = multithresh(c(c>ot1), 2);
cqs = colorquantise(c,ots);

S1 = S;
S2 = S; 
Ss = S;

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

%% Area at a specific level

thisS = Ss;
faces = thisS.Faces(thisS.CData==2,:);
verts = thisS.Vertices;

a = verts(faces(:, 2), :) - verts(faces(:, 1), :);
b = verts(faces(:, 3), :) - verts(faces(:, 1), :);

c = cross(a, b, 2);

area = 1/2 * sum(sqrt(sum(c.^2, 2)));
fprintf('\nThe surface area is %f\n\n', area);



