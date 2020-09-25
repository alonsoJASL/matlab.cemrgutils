function [a] = readlinefibres(line)
% 

spl = strsplit(line, ' ');
b = zeros(1, length(spl));
total = length(spl);
for ix=1:total
    if isempty(spl{ix})
       b(ix) = 1;
    end
end
spl(find(b)) = [];
       
a = zeros(1, length(spl));
for ix=1:length(a)
    a(ix) = str2double(spl{ix});
end

