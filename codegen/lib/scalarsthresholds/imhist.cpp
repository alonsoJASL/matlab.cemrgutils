//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: imhist.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Apr-2019 12:46:07
//

// Include Files
#include <string.h>
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "imhist.h"

// Function Definitions

//
// Arguments    : const unsigned char varargin_1_data[]
//                const int varargin_1_size[1]
//                double yout[256]
// Return Type  : void
//
void imhist(const unsigned char varargin_1_data[], const int varargin_1_size[1],
            double yout[256])
{
  double localBins1[256];
  double localBins2[256];
  double localBins3[256];
  int i;
  int localBins2_tmp;
  memset(&yout[0], 0, sizeof(double) << 8);
  memset(&localBins1[0], 0, sizeof(double) << 8);
  memset(&localBins2[0], 0, sizeof(double) << 8);
  memset(&localBins3[0], 0, sizeof(double) << 8);
  for (i = 0; i + 4 <= varargin_1_size[0]; i += 4) {
    localBins1[varargin_1_data[i]]++;
    localBins2_tmp = varargin_1_data[i + 1];
    localBins2[localBins2_tmp]++;
    localBins2_tmp = varargin_1_data[i + 2];
    localBins3[localBins2_tmp]++;
    localBins2_tmp = varargin_1_data[i + 3];
    yout[localBins2_tmp]++;
  }

  while (i + 1 <= varargin_1_size[0]) {
    yout[varargin_1_data[i]]++;
    i++;
  }

  for (i = 0; i < 256; i++) {
    yout[i] = ((yout[i] + localBins1[i]) + localBins2[i]) + localBins3[i];
  }
}

//
// File trailer for imhist.cpp
//
// [EOF]
//