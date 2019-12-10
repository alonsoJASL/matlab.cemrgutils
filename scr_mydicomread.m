fname = '/Volumes/JASL2_/F-II-2-02/PRE/DATA/Cardiac_General_Cardiac_Protocols - 1/';
details = dicomCollection(fname, 'IncludeSubfolders', true);

[Vlge, sp_lge, dim_lge] = dicomreadVolume(details, 's2');
[Vmra, sp_mra, dim_mra] = dicomreadVolume(details, 's1');

