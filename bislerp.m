function [QAB] = bislerp(Qa, Qb, t)
% BISLERP. Implementation of bi-slerp algorithm for fibres analysis. 
% 
qa = quaternion(Qa, 'rotmat', 'point');
qb = quaternion(Qb, 'rotmat', 'point');
qm = quaternion();

maxNorm = -1;
index=-1;
for ix=1:4
    for jx=1:2
    testQ = (-1)^jx * quat_ijk(ix) * qa;
    testNorm = norm(testQ * qb);
    if testNorm > maxNorm
        maxNorm = testNorm;
        index = ix;
        qm = testQ;
    end
    end
end
QAB = rotmat(slerp(qm, qb, t), 'point');
