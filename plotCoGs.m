function plotCoGs(cog, region, space)

if nargin < 3
    space = 50;
end
nElem = size(cog,1);
regions = [1 11 13 15 17 19];

hold on;
for ix=1:space:nElem
    plot3(cog(ix,1), cog(ix,2), cog(ix,3), [quickcatcolour(regions, region(ix)) '.']);
end
hold off;
