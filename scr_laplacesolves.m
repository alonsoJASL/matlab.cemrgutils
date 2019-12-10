tidy
load tetmesh
model = createpde();
geometryFromMesh(model, X', tet');
specifyCoefficients(model, 'm', 0, 'd', 0, 'a', 0, 'c', -1, 'f', 0);

figure(1)
pdegplot(model,'FaceLabels','on','FaceAlpha',0.5);

%%
applyBoundaryCondition(model, 'dirichlet', 'Face', 4, 'u', 0);
applyBoundaryCondition(model, 'dirichlet', 'Face', 6, 'u', 1);
res = solvepde(model);

figure(2) 
pdeplot3D(model,'ColorMapData',res.NodalSolution, 'FaceAlpha',0.5);
K = assembleFEMatrices(model, 'nullspace');