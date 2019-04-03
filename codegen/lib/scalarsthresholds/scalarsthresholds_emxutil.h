//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: scalarsthresholds_emxutil.h
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Apr-2019 12:46:07
//
#ifndef SCALARSTHRESHOLDS_EMXUTIL_H
#define SCALARSTHRESHOLDS_EMXUTIL_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "scalarsthresholds_types.h"

// Function Declarations
extern void emxEnsureCapacity_int16_T(emxArray_int16_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_uint16_T(emxArray_uint16_T *emxArray, int oldNumel);
extern void emxFree_int16_T(emxArray_int16_T **pEmxArray);
extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxFree_uint16_T(emxArray_uint16_T **pEmxArray);
extern void emxInit_int16_T(emxArray_int16_T **pEmxArray, int numDimensions);
extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);
extern void emxInit_uint16_T(emxArray_uint16_T **pEmxArray, int numDimensions);

#endif

//
// File trailer for scalarsthresholds_emxutil.h
//
// [EOF]
//
