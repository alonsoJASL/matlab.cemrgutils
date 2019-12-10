function createConfigurationFileOlder(path2file, argos)
% CREATE MIRTK (v1.0) REGISTER CONFIGURATION FILE. 
% USAGE: createConfigurationFileOlder(path2file)
%
% USAGE: createConfigurationFileOlder(path2file, argos)
% Structure arguments with default values:
%       argos.BendingEnergy = 1e-3;
%       argos.VolumePreservation = 0;
%       argos.ControlPointSpacing = 4;
%       argos.Sparsity = 0.04;
%       argos.Resolution = 5; 
%
if nargin < 2
    be = 1e-3;
    vp = 0;
    s = 0.04;
    rs = 5;
    ds = 4;
else
    [be,vp, s, rs, ds] = getArgs(argos);
end

FID = fopen(path2file, 'w');
fprintf(FID, '[ input ] \n');
fprintf(FID, 'Padding value                      = -1024\n\n');

fprintf(FID, '[ transformation ] \n');
fprintf(FID, 'Transformation model               = FFD\n');
fprintf(FID, 'Control point spacing in T         = %d\n\n', ds);

fprintf(FID, '[ optimization ] \n');
fprintf(FID, 'Energy preconditioning             = 0.001\n');
fprintf(FID, 'Divide data terms by initial value = No\n');
fprintf(FID, 'Interpolation mode                 = Linear\n');
fprintf(FID, 'Epsilon                            = -1e-6\n');
fprintf(FID, 'Image (dis-)similarity measure     = SSD\n\n');

if rs == 1
    blurr = [0.5 0 0 0];
else
    blurr = [3 5 10 20];
end

for ix=1:4
    fprintf(FID, '[ Level %d ] \n', ix);
    fprintf(FID, 'Blurring [mm]                      = %3.1f\n', blurr(ix));
    fprintf(FID, 'Resolution [mm]                    = %d %d %d\n', ...
        (2^(ix-1))*rs,(2^(ix-1))*rs,(2^(ix-1))*rs);
    fprintf(FID, 'Minimum length of steps            = 0.01\n');
    fprintf(FID, 'Maximum length of steps            = 4\n');
end

fprintf(FID, '[ Grid Search ] \n');
fprintf(FID, 'Bending energy weight              = %f\n', be);
fprintf(FID, 'Sparsity weight                    = %f\n', s);
fprintf(FID, 'Volume preservation weight        = %f\n', vp);

fclose(FID);
end

function [be,vp,s, rs, ds] = getArgs(ss)
be = 1e-3;
vp = 0;
s = 0.04;
rs = 5;
ds = 4;

fnames = fieldnames(ss);
for ix=1:length(fnames)
    switch lower(fnames{ix})
        case {'be', lower('BendingEnergy')}
            be = ss.(fnames{ix});
        case {'vp', lower('VolumePreservation')}
            vp = ss.(fnames{ix});
        case {'ds', lower('ControlPointSpacing')}
            ds = ss.(fnames{ix});
        case {'s', lower('Sparsity')}
            s = ss.(fnames{ix});
        case {'rs', lower('Resolution')}
            rs = ss.(fnames{ix});
        otherwise
            fprintf('%s: ERROR, option %s not recognised.', ...
                mfilename, upper(fnames{ix}));
    end
end
end
