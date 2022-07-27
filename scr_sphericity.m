%% Calculate sphericity from a mesh
% Loads a mesh (in CARP format) into the points (pts) and triangulation
% (elems) and calculates thesphericity of the mesh as in CemrgApp 
% 
% Author: José Alonso Solís Lemus
% 

%% Read in mesh
clear all;
close all;
clc;

fprintf('Loading mesh in CARP format');
p2f='/Volumes/sandisk/01_atrialfibres/06_Reproducibility/05_UserProjects/004_jose/05_pre_sims_tests/PATIENT_4434030'; % path to folder 
msh='clean-Labelled-reg-reg-refined'; % mesh name (no extension)
[pts, nPts] = readParsePts(fullfile(p2f, [msh '.pts']));
[el, nElem, region] = readParseElem(fullfile(p2f, [msh '.elem']));

% Calculations
TiMC = GetCentreOfMassOfEachT(pts, el);
[TiA, LACA] = GetArea(pts, el);
[LAC_mc] = GetCentreOfMass(TiMC, TiA, LACA);
[AR] = GetAverageRadius(TiMC, TiA, nElem, LAC_mc, LACA);

[Sphericity, sph_sigma] = LASphericity(TiMC, TiA, nElem, LAC_mc, LACA, AR);


fprintf('\nSphericity = %.2f%% \n', Sphericity);

%% functions for sphericity
function [timc] = GetCentreOfMassOfEachT(pts, elems)
%

fprintf('Calculating centre of mass per triangle in mesh\n');
nElem = size(elems, 1);
timc = zeros(nElem, 3);
for ix=1:nElem
    timc(ix, :) = mean(pts(elems(ix,:), :));
end
end

function [tia, laca] = GetArea(pts, elems)

fprintf('Calculating area per triangle in mesh\n');
nElem=size(elems, 1);
tia = zeros(nElem, 1);
for ix=1:nElem
    p1=pts(elems(ix,1), :);
    p2=pts(elems(ix,2), :);
    p3=pts(elems(ix,3), :);
    
    tia(ix) = 0.5 * norm(cross(p1-p2, p2-p3));
end
laca = sum(tia);
end

function [lac_mc] = GetCentreOfMass(timc, tia, laca)
fprintf('Calculating centre of mass of whole mesh\n');
lac_mc_vector = (tia ./ laca) .* timc;
lac_mc = sum(lac_mc_vector);
end

function [ar] = GetAverageRadius(timc, tia, nElems, lac_mc, laca)
fprintf('Calculating average radius\n');
a_b = repmat(lac_mc, nElems, 1) - timc;
norm_ab = sqrt(a_b(:,1).^2+a_b(:,2).^2+a_b(:,3).^2);
ar_vector = (tia ./ laca) .* norm_ab;

ar = sum(ar_vector);
end

function [sphrcty, sph_sgm] = LASphericity(timc, tia, nElems, lac_mc, laca, ar)
fprintf('Calculating sphericity\n');
contrib = tia./laca; 
a_b = repmat(lac_mc, nElems, 1) - timc;
norm_ab = sqrt(a_b(:,1).^2+a_b(:,2).^2+a_b(:,3).^2);
phi_vector = norm_ab - repmat(ar, nElems, 1);

eps_vector = contrib .* (phi_vector.^2);
sph_sgm = sqrt(sum(eps_vector));

cvs = sph_sgm/ar;
sphrcty = 100*(1-cvs);

end

%% helper functions
function [pts, nPts] = readParsePts(fname)
% Read pts file
% [vector] = readParsePts(fname)
%
[path, bname, ext] = fileparts(fname);
fi = fopen(fname);
nPts = 0;

if contains(ext, '.pts')
    nPts = readsingleline(fgetl(fi));
end

if nPts > 0
    pts = zeros(nPts, 3);
    for ix=1:nPts
        pts(ix,:) = readsingleline(fgetl(fi));
    end
else 
    iter=1;
    while ~feof(fi)
        pts(iter,:) = readsingleline(fgetl(fi));
        iter = iter+1;
    end
end
end

function [el,nElem, region] = readParseElem(elemPath, nIter)
% 

if nargin < 2
    nIter=0;
end

fElem = fopen(elemPath, 'r');
nElem = readsingleline(fgetl(fElem));

cemrg_info(sprintf('Elements: %d', nElem));
if nIter==0
    nIter = nElem;
end
[firstline, elemtype] = readsingleline(fgetl(fElem));
elemtype = elemtype{1};

cemrg_info(sprintf('Element Type: %s', elemtype));
switch elemtype
    case {'Tt', 'Qd'}
        formatSpec = [elemtype 32 '%d %d %d %d %d'];
        %el_cell = textscan(fElem, 'Tt %d %d %d %d %d', nIter-1);
        el_cell = textscan(fElem, formatSpec, nIter-1);
        nCols = 4;
    case 'Tr'
        el_cell = textscan(fElem, 'Tr %d %d %d %d', nIter-1);
        nCols = 3;
    otherwise
        cemrg_info(sprintf('Element type: %s not supported', elemtype));
        el = [];
        nElem = [];
        region=[];
        return;
end
el = [];
for ix=1:nCols
    el = [el el_cell{ix}];
end
el = [firstline(1:nCols);el];
el = el+1;

if nargout > 2
    region = [firstline(nCols+1);el_cell{nCols+1}];
end
fclose(fElem);
end

function [numbersInLine, charsInLine] = readsingleline(line)
% 

spl = strsplit(line, ' ');
b = zeros(1, length(spl));
total = length(spl);
for ix=1:total
    if isempty(spl{ix})
       b(ix) = 1;
    end
end
spl(cast(b, 'logical')) = [];
       
numbersInLine = zeros(1, length(spl));
for ix=1:length(numbersInLine)
    numbersInLine(ix) = str2double(spl{ix});
end

if nargout > 1
    numbersInLine(isnan(str2double(spl))) = [];
    charsInLine = spl(isnan(str2double(spl)));
end
end