MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/jsl19/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for scalarsthresholds" > scalarsthresholds_mex.mki
echo "CC=$CC" >> scalarsthresholds_mex.mki
echo "CFLAGS=$CFLAGS" >> scalarsthresholds_mex.mki
echo "CLIBS=$CLIBS" >> scalarsthresholds_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> scalarsthresholds_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> scalarsthresholds_mex.mki
echo "CXX=$CXX" >> scalarsthresholds_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> scalarsthresholds_mex.mki
echo "CXXLIBS=$CXXLIBS" >> scalarsthresholds_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> scalarsthresholds_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> scalarsthresholds_mex.mki
echo "LDFLAGS=$LDFLAGS" >> scalarsthresholds_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> scalarsthresholds_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> scalarsthresholds_mex.mki
echo "Arch=$Arch" >> scalarsthresholds_mex.mki
echo "LD=$LD" >> scalarsthresholds_mex.mki
echo OMPFLAGS= >> scalarsthresholds_mex.mki
echo OMPLINKFLAGS= >> scalarsthresholds_mex.mki
echo "EMC_COMPILER=gcc" >> scalarsthresholds_mex.mki
echo "EMC_CONFIG=optim" >> scalarsthresholds_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f scalarsthresholds_mex.mk
