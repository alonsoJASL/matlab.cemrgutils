% Return mesh to original coordinates.
%
tidy
mycase = 'case02';
filespath = ['E:\KCL_EP_WIN\' mycase '\carputils_tests\'];
imName = 'MASK.nii';
ptsName = 'CGALMesh.pts';

ptsPath = fullfile(filespath, ptsName);
imgPath = fullfile(filespath, imName);

fpts = fopen(ptsPath);
nPts = str2num(fgetl(fpts));
spacing = 100;
vector = 1:spacing:nPts;

[V, vinfo] = readParseNifti(imgPath);
transfMat = vinfo.Transform.T;

onePt = zeros(3,1);
pts = ones(3, length(vector));
ptsTr = ones(3, length(vector));

idx = 1;

for count=1:nPts
    if(count == vector(idx))

        pts(:, idx) = readlinefibres(fgetl(fpts))';
        
        
        ptsTr(:,idx) = transfMat'*pts(:, idx);
        
        idx = idx+1;
        if(idx>length(vector))
            break;
        end 
    end
end

fclose(fpts);

disp([mean(pts, 2) mean(ptsTr, 2) mean(ptsTr, 2).*1000]);

%% 
filespath = 'E:\KCL_EP_WIN\case02\carputils_tests\';
imName = 'MASK.nii';
ptsName = 'GT_CGALMesh_shift.pts';

ptsPath = fullfile(filespath, ptsName);

fpts = fopen(ptsPath);
nPts = str2num(fgetl(fpts));
spacing = 100;
vector = 1:spacing:nPts;

idx = 1;

ptsShft = ones(4, length(vector));
for count=1:nPts
    if(count == vector(idx))

        ptsShft(1:3, idx) = readlinefibres(fgetl(fpts))';
        
        idx = idx+1;
        if(idx>length(vector))
            break;
        end 
    end
end
fclose(fpts);

disp([mean(ptsShft, 2)]);
