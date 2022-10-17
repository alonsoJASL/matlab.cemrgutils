function [pname, fname] = cemrg_io(message, dir, filter_str)

if nargin < 3
    filter_str='';
end

cemrg_info(message);
if strcmp(filter_str, 'dir') || isempty(filter_str)
    pname = uigetdir(dir, message);
    fname = '';
else
    [fname, pname] = uigetfile(fullfile(dir, filter_str), message);
end
