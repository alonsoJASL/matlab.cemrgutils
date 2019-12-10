function createConfigurationFileNewer(path2file, argos)
% CREATE MIRTK (v2.0) REGISTER CONFIGURATION FILE. 
% USAGE: createConfigurationFileOlder(path2file)
%
% USAGE: createConfigurationFileOlder(path2file, argos)
% Structure arguments with default values:
%       argos.BendingEnergy = 1e-3;
%       argos.LinearEnergy = 0;
%       argos.TopologyPreservation = 0;
%       argos.VolumePreservation = 0;
%       argos.ControlPointSpacing = 4;
%
if nargin < 2
    be = 1e-3;
    le = 0;
    tp = 0;
    vp = 0;
    ds = 4;
else
    [be, le, tp,vp, ds] = getArgs(argos);
end

FID = fopen(path2file,'w');

fprintf(FID, '## Version  (rev 0, built on Aug  8 2019)\n');
fprintf(FID, '\n');
fprintf(FID, '[default]\n');
fprintf(FID, 'Maximum no. of line search iterations    = 12\n');
fprintf(FID, 'Bending energy weight                    = %9.8f\n', be);
fprintf(FID, 'Linear energy weight                     = %9.8f\n', le);
fprintf(FID, 'Topology preservation weight             = %9.8f\n', tp);
fprintf(FID, 'Volume preservation weight               = %9.8f\n', vp);
fprintf(FID, 'Reuse previous step length               = Yes\n');
fprintf(FID, 'Strict step length range                 = Yes\n');
fprintf(FID, 'Maximum streak of rejected steps         = 3\n');
fprintf(FID, 'Transformation model                     = Rigid+BSplineFFD\n');
fprintf(FID, 'Multi-level transformation               = Default\n');
fprintf(FID, 'Merge global and local transformation    = No\n');
fprintf(FID, 'Dirichlet boundary condition             = No\n');
fprintf(FID, 'Optimization method                      = ConjugateGradientDescent\n');
fprintf(FID, 'No. of resolution levels                 = 4\n');
fprintf(FID, 'Final level                              = 1\n');
fprintf(FID, 'Precompute image derivatives             = Yes\n');
fprintf(FID, 'Maximum rescaled intensities             = inf\n');
fprintf(FID, 'Normalize weights of energy terms        = Yes\n');
fprintf(FID, 'Downsample images with padding           = Yes\n');
fprintf(FID, 'Crop/pad images                          = Yes\n');
fprintf(FID, 'Crop/pad lattice                         = Yes\n');
fprintf(FID, 'Adaptive surface remeshing               = No\n');
fprintf(FID, 'Background value                         = -1\n');
fprintf(FID, 'Image interpolation                      = Default\n');
fprintf(FID, 'Image extrapolation                      = Default\n');
fprintf(FID, 'Use Gaussian image resolution pyramid    = Yes\n');
fprintf(FID, 'Control point spacing [mm]               = %d\n', ds);
fprintf(FID, '\n');

fprintf(FID, '[level 1]\n');
fprintf(FID, 'Minimum length of steps                  = 0.01\n');
fprintf(FID, 'Maximum length of steps                  = 1\n');
fprintf(FID, 'Resolution [mm]                          = 1 1 1\n');
fprintf(FID, 'Blurring [mm]                            = 0.5\n');
fprintf(FID, '\n');
fprintf(FID, '[level 2]\n');
fprintf(FID, 'Minimum length of steps                  = 0.01\n');
fprintf(FID, 'Maximum length of steps                  = 2\n');
fprintf(FID, 'Resolution [mm]                          = 2 2 2\n');
fprintf(FID, 'Blurring [mm]                            = 0\n');
fprintf(FID, '\n');
fprintf(FID, '[level 3]\n');
fprintf(FID, 'Minimum length of steps                  = 0.01\n');
fprintf(FID, 'Maximum length of steps                  = 4\n');
fprintf(FID, 'Resolution [mm]                          = 4 4 4\n');
fprintf(FID, 'Blurring [mm]                            = 0\n');
fprintf(FID, '\n');
fprintf(FID, '[level 4]\n');
fprintf(FID, 'Minimum length of steps                  = 0.01\n');
fprintf(FID, 'Maximum length of steps                  = 8\n');
fprintf(FID, 'Resolution [mm]                          = 8 8 8\n');
fprintf(FID, 'Blurring [mm]                            = 0\n');

fclose(FID);
end

function [be, le, tp,vp, ds] = getArgs(s)
be = 1e-3;
le = 0;
tp = 0;
vp = 0;
ds = 4;

fnames = fieldnames(s);
for ix=1:length(fnames)
    switch lower(fnames{ix})
        case {'be', 'bendingenergy'}
            be = s.(fnames{ix});
        case {'le', 'linearenergy'}
            le = s.(fnames{ix});
        case {'tp', 'topologypreservation'}
            tp = s.(fnames{ix});
        case {'vp', 'volumepreservation'}
            vp = s.(fnames{ix});
        case {'ds', 'controlpointspacing'}
            ds = s.(fnames{ix});
        otherwise
            fprintf('%s: ERROR, option %s not recognised.', ...
                mfilename, upper(fnames{ix}));
    end
end
end

