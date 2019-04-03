/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * find.h
 *
 * Code generation for function 'find'
 *
 */

#ifndef FIND_H
#define FIND_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "scalarsthresholds_types.h"

/* Function Declarations */
extern void eml_find(const emlrtStack *sp, const boolean_T x[65536],
                     emxArray_int32_T *i, emxArray_int32_T *j);

#endif

/* End of code generation (find.h) */
