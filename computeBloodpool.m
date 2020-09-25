function [Vout] = computeBloodpool(V)

Vinner = zeros(size(V));
Vout = zeros(size(V));
for ix=1:size(V, 3)
A = imclearborder(squeeze(V(:,:,ix)==0));
Vinner(:,:,ix) = Vinner(:,:,ix) + reshape(A, size(V(:,:,ix)));
end
for ix=1:size(V, 2)
A = imclearborder(squeeze(V(:,ix,:)==0));
Vinner(:,ix,:) = Vinner(:,ix,:) + reshape(A, size(V(:,ix,:)));
end
for ix=1:size(V, 1)
A = imclearborder(squeeze(V(ix,:,:)==0));
Vinner(ix,:,:) = Vinner(ix,:,:) + reshape(A, size(V(ix,:,:)));
end

Vinner = uint16(Vinner);
VpartialFill = Vinner + V;
VpartialFill(VpartialFill > 0) = 1;
for ix=1:size(V, 3)
A = uint16(imclearborder(squeeze(VpartialFill(:,:,ix)==0)));
Vinner(:,:,ix) = Vinner(:,:,ix) + reshape(A, size(V(:,:,ix)));
end
for ix=1:size(V, 2)
A = uint16(imclearborder(squeeze(VpartialFill(:,ix,:)==0)));
Vinner(:,ix,:) = Vinner(:,ix,:) + reshape(A, size(V(:,ix,:)));
end
for ix=1:size(V, 1)
A = uint16(imclearborder(squeeze(VpartialFill(ix, :,:)==0)));
Vinner(ix, :,:) = Vinner(ix, :,:) + reshape(A, size(V(ix, :,:)));
end

Linner = bwlabeln(Vinner);

regs3 = regionprops3(Vinner>0, 'Volume');
ventrVolumes = regs3.Volume;
[aa, bb] = sort(ventrVolumes, 'descend');
aa(3:end) = []; bb(3:end) = [];

Vout = 30.*(Linner==bb(1)) + 10.*(Linner==bb(2));