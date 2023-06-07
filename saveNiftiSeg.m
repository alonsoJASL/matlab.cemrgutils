function saveNiftiSeg(seg, name, vinfo)

[a,~,b] = fileparts(vinfo.Filename);
sinfo=vinfo;
sinfo.Filename = fullfile(a, name, b);

niftiwrite(seg, sinfo.Filename, sinfo);

