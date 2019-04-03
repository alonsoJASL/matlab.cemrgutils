//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: scalarsthresholds_types.h
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Apr-2019 12:46:07
//
#ifndef SCALARSTHRESHOLDS_TYPES_H
#define SCALARSTHRESHOLDS_TYPES_H

// Include Files
#include "rtwtypes.h"

// Type Definitions
struct emxArray_int16_T
{
  short *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  bool canFreeData;
};

struct emxArray_int32_T
{
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  bool canFreeData;
};

struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  bool canFreeData;
};

struct emxArray_uint16_T
{
  unsigned short *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  bool canFreeData;
};

#endif

//
// File trailer for scalarsthresholds_types.h
//
// [EOF]
//
