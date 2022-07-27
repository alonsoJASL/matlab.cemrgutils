% Afib - distribute test files amongst users
% Creates four separate folders with cases
% 

p2f = uigetdir('.','Open folder with files');

%% 
subfolders = dir(p2f);
subfolders(1:2) = []; % delete '.', '..' directories
subfolders(~[subfolders.isdir]) = [];
subfolders = {subfolders.name}';
%%
unusables = [13]'; % write all the unusable cases
numUnusables = length(unusables);
numPatients = length(subfolders);
indices = (1:numPatients)';

%% 

numUsers = 4;
numCasesPerUser = floor((numPatients - numUnusables)/4);
indices(unusables) = [];

numRepeats=2;
numCasesRepeats=5;
numCasesNonRepeats=numCasesPerUser-numCasesRepeats;

repeats = randperm(numPatients, numRepeats*numCasesRepeats)';
nonrepeats = indices(~ismember(indices, repeats));

finalListUsers=[];
for ix=1:numUsers
    userCaseIdx = randperm(length(nonrepeats), numCasesNonRepeats)';
    finalListUsers=[finalListUsers userCaseIdx];
    nonrepeats(userCaseIdx) = [];
end

repeats = repmat(repeats, numRepeats,1);
repeats = repeats(randperm(length(repeats)));


finalListUsers = [finalListUsers; reshape(repeats, length(repeats)/numUsers, numUsers)];
%% 
casesAllocated = subfolders(finalListUsers);
for ix=1:numUsers
    fo = fopen(fullfile(p2f, ['user_' num2padstr(ix) '.txt']), 'w');
    for jx=1:numCasesPerUser
        fprintf(fo, '%s', casesAllocated{jx, ix});
        if jx<numCasesPerUser
            fprintf(fo, '\n');
        end
    end
    fclose(fo);
end
