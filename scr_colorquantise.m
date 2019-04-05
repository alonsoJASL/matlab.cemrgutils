, if strcmp(chooseplatform, 'linux')
    path2data = '~/data/exampledata2/';
else
    path2data = uigetdir('~');
end

celldata = readtable(fullfile(path2data,'eg_celldata.csv'));
pointdata = readtable(fullfile(path2data,'eg_pointdata.csv'));
%%
scalars = celldata.Properties.VariableNames{...
    contains(lower(celldata.Properties.VariableNames), 'scalars')};

f = [celldata.PointIndex0 celldata.PointIndex1 celldata.PointIndex2];
v = [pointdata.Points_0 pointdata.Points_1 pointdata.Points_2];
c = celldata.(scalars);%./max(celldata.(scalars)(:));

idx = celldata.CellID + 1;

%ot1 = multithresh(c(c>0), 1);
%ots = multithresh(c(c>ot1), 2);
cqs = scalarsthresholds(c);

