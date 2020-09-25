path = 'C:\Users\alons\Dropbox\case02\2_mesh\CGALMeshDir\';
basename = 'CGALMesh_';
surfnames = {'Apex', 'LVbase', 'LVendo', 'LVepi', 'RVbase', 'RVendo', 'RVepi'}';
ext = '.surf';
carpext = '.surf.vtx';

% read in our generated surface files:
totals = zeros(length(surfnames), 1);
totalsCarp = zeros(length(surfnames), 1);
%for ix=1:length(surfnames)
for ix=1
    myfilename = fullfile(path, [basename surfnames{ix} ext]);
    carpfilename = fullfile(path, [basename surfnames{ix} carpext]);
    
    myf = fopen(myfilename);
    carpf = fopen(carpfilename);
    
    N = readlinefibres(fgetl(myf));
    carpN = readlinefibres(fgetl(carpf));
    
    totals(ix) = N;
    totalsCarp(ix) = carpN;
    
    if(N ~= carpN)
        fprintf('Different sizes in files:\n%s :    %d\n%s : %d\n', ...
            myfilename, N, carpfilename, carpN);
    end
    
    myV = zeros(N,1);
    carpV = zeros(carpN,1);
    for jx=1:N
        myV(jx) = readlinefibres(fgetl(myf));
    end
    for kx=1:carpN
        carpV(kx) = readlinefibres(fgetl(carpf));
    end
    
%     disp(sort(myV, 'ascend'));    
%     pause;
    fclose(myf);
    fclose(carpf);
end

