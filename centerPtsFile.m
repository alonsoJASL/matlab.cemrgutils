function centerPtsFile(dir, inname, fibres, outname)
% Assumes carp pts file
% do not use .pts extension
% 

if nargin < 3
    outname = ['centred_' inname];
    fibres = [];
elseif nargin < 4 
    outname = ['centred_' inname];
end

inpath=fullfile(dir, inname);
outpath=fullfile(dir, outname);

cemrg_info('Reading pts file');
[fi, numPts] = fopenWithTotals([inpath '.pts']);

C=textscan(fi, '%f %f %f\n');
D=[C{1} C{2} C{3}];

cemrg_info('Centering....');
E=D-repmat(mean(D, 1), numPts, 1);

cemrg_info('Writing to file...');
fo=fopen([outpath '.pts'], 'w');

fprintf(fo, '%d\n', numPts);
fprintf(fo, '%.12f %.12f %.12f\n', E');

copyfile([inpath '.elem'], [outpath, '.elem']);
copyfile([inpath '.lon'], [outpath, '.lon']);
cemrg_info('...done');

if ~isempty(fibres)
    [el, ~, ~] = readElementFile([inpath '.elem']);
    [cog_D] = calculateCoG(el, D);
    [cog_E] = calculateCoG(el, E);

    outfibres = [outname '_' fibres];
    cemrg_info('Moving fibre file');
    [fib, numFib] = fopenWithTotals(fullfile(dir, [fibres '.vpts']));
    F=textscan(fib, '%f %f %f\n');
    G=[F{1} F{2} F{3}];
    H=(G-cog_D) + cog_E;
    
    cemrg_info('Writing to fibres file...');
    fo=fopen(fullfile(dir, [outfibres '.vpts']), 'w');
    fprintf(fo, '%d\n', numFib);
    fprintf(fo, '%.12f %.12f %.12f\n', H');
    cemrg_info('...done');
end



fclose("all");

end 

function [f, N] = fopenWithTotals(filepath)
f=fopen(filepath, 'r');
N=str2num(fgetl(f));
end
