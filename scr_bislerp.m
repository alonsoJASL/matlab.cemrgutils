% Testing bislerp algorithm 

Qa = rotmat(quaternion(randn(1,4)), 'point');
Qb = rotmat(quaternion(randn(1,4)), 'point');
t = rand();
QAB = bislerp(Qa, Qb, t);