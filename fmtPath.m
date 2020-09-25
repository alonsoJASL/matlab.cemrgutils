function [str] = fmtPath(somepath)
% 

stspl = strsplit(somepath, '\');
str = strjoin(stspl, '\\\');
