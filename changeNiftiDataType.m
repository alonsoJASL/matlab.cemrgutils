function [Vo, vo] = changeNiftiDataType(V, vinfo, filepath, dtype)

types = {'double', 'single', 'int8', 'uint8', 'int16', 'uint16', ...
    'int32', 'uint32', 'int64', 'uint64', 'boolean'};

if ~ismember(types, dtype)
   cemrg_info(sprintf('Type [%s] not known', dtype));
   return;
end

vinfo.Datatype = dtype;
V=cast(V,dtype);

if nargout > 0
    Vo=V;
    if nargout > 1
        vo=vinfo;
    end
end

