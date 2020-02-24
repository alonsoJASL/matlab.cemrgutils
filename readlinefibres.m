function [a] = readlinefibres(line)
% 

spl = strsplit(line, ' ');
a = zeros(1, length(spl));
for ix=1:length(a)
    a(ix) = str2double(spl{ix});
end

