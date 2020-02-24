function [QAB] = bislerp(Qa, Qb, t)
% BISLERP. Implementation of bi-slerp algorithm for fibres analysis. 
% 
qa = quaternion(Qa, 'rotmat', 'point');
qb = quaternion(Qb, 'rotmat', 'point');

v = qa.compact;
vb = qb.compact;

maxNorm = -1;
vm = zeros(1,4);
for ix=1:2
    for jx=1:2
        for kx=1:2
            for wx=1:2
                auxV = [(-1)^ix*v(1) (-1)^jx*v(2) (-1)^kx*v(3) (-1)^wx*v(4)];
                testNorm = norm(vb.*auxV);
                if testNorm>maxNorm
                    maxNorm = testNorm;
                    vm = auxV;
                end
            end
        end
    end
end

qm = quaternion(vm);
QAB = rotmat(slerp(qm, qb, t), 'point'); 
