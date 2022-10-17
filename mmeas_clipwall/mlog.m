function mlog(msg, condition2print)
if nargin < 2
    condition2print = true;
end

if condition2print == true
    fprintf([msg '\n']);
end
end