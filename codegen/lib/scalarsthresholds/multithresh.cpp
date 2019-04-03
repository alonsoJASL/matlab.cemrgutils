//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: multithresh.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 03-Apr-2019 12:46:07
//

// Include Files
#include <cmath>
#include "rt_nonfinite.h"
#include <string.h>
#include "scalarsthresholds.h"
#include "multithresh.h"
#include "scalarsthresholds_emxutil.h"
#include "any1.h"
#include "eps.h"
#include "abs.h"
#include "sort1.h"
#include "mean.h"
#include "nullAssignment.h"
#include "unique.h"
#include "sortIdx.h"
#include "isfinite.h"
#include "power.h"
#include "ndgrid.h"
#include "bsxfun.h"
#include "repmat.h"
#include "sum.h"
#include "imhist.h"
#include "im2uint8.h"

// Function Declarations
static void b_calcFullObjCriteriaMatrix(const double omega[256], const double
  mu[256], double mu_t, double sigma_b_squared[65536]);
static void b_getDegenerateThresholds(const emxArray_real_T *uniqueVals,
  emxArray_real_T *thresh);
static void calcFullObjCriteriaMatrix(const double omega[256], const double mu
  [256], double mu_t, double sigma_b_squared[256]);
static void checkForDegenerateInput(const emxArray_real_T *A, double N, bool
  *isDegenerate, emxArray_real_T *uniqueVals);
static void getDegenerateThresholds(const emxArray_real_T *uniqueVals,
  emxArray_real_T *thresh);
static void getThreshForNoPdf(double minA, double maxA, emxArray_real_T *thresh);
static void getpdf(emxArray_real_T *A, double p[256], double *minA, double *maxA,
                   bool *emptyp);

// Function Definitions

//
// Arguments    : const double omega[256]
//                const double mu[256]
//                double mu_t
//                double sigma_b_squared[65536]
// Return Type  : void
//
static void b_calcFullObjCriteriaMatrix(const double omega[256], const double
  mu[256], double mu_t, double sigma_b_squared[65536])
{
  int i;
  double b_mu[256];
  double dv1[256];
  static double mu_0_t[65536];
  static double omega1[65536];
  static double allPixC[65536];
  static double b_allPixC[65536];
  static double mu_1_t[65536];
  double dv2[256];
  double b_omega1;
  static double dv3[65536];
  double b_sigma_b_squared;
  static double c_sigma_b_squared[65536];
  double omega2_tmp;
  static double omega2[65536];
  repmat(omega, sigma_b_squared);
  for (i = 0; i < 256; i++) {
    b_mu[i] = mu[i] / omega[i];
  }

  bsxfun(mu_t, b_mu, dv1);
  repmat(dv1, mu_0_t);
  b_bsxfun(omega, omega, omega1);
  b_bsxfun(mu, mu, allPixC);
  for (i = 0; i < 65536; i++) {
    b_allPixC[i] = allPixC[i] / omega1[i];
  }

  c_bsxfun(mu_t, b_allPixC, mu_1_t);
  for (i = 0; i < 256; i++) {
    b_mu[i] = 1.0 + (double)i;
    dv2[i] = 1.0 + (double)i;
  }

  ndgrid(b_mu, dv2, b_allPixC, allPixC);
  for (i = 0; i < 65536; i++) {
    b_omega1 = omega1[i];
    b_sigma_b_squared = sigma_b_squared[i];
    if (b_allPixC[i] >= allPixC[i]) {
      b_sigma_b_squared = rtNaN;
      b_omega1 = rtNaN;
    }

    omega2_tmp = 1.0 - (b_sigma_b_squared + b_omega1);
    omega2[i] = omega2_tmp;
    if (omega2_tmp <= 0.0) {
      omega2[i] = rtNaN;
    }

    sigma_b_squared[i] = b_sigma_b_squared;
    omega1[i] = b_omega1;
  }

  power(mu_0_t, allPixC);
  power(mu_1_t, dv3);
  for (i = 0; i < 65536; i++) {
    c_sigma_b_squared[i] = sigma_b_squared[i] * mu_0_t[i] + omega1[i] * mu_1_t[i];
  }

  power(c_sigma_b_squared, b_allPixC);
  for (i = 0; i < 65536; i++) {
    sigma_b_squared[i] = (sigma_b_squared[i] * allPixC[i] + omega1[i] * dv3[i])
      + b_allPixC[i] / omega2[i];
  }
}

//
// Arguments    : const emxArray_real_T *uniqueVals
//                emxArray_real_T *thresh
// Return Type  : void
//
static void b_getDegenerateThresholds(const emxArray_real_T *uniqueVals,
  emxArray_real_T *thresh)
{
  int i5;
  emxArray_real_T *threshL;
  double threshCandidate;
  int loop_ub;
  int q;
  double y_data[2];
  emxArray_real_T *r5;
  emxArray_real_T *b_uniqueVals;
  double d2;
  int tmp_size[1];
  bool tmp_data[53008];
  if (uniqueVals->size[1] == 0) {
    i5 = thresh->size[0] * thresh->size[1];
    thresh->size[0] = 1;
    thresh->size[1] = 2;
    emxEnsureCapacity_real_T(thresh, i5);
    thresh->data[0] = 1.0;
    thresh->data[1] = 2.0;
  } else if (2 - uniqueVals->size[1] > 0) {
    emxInit_real_T(&threshL, 2);
    if (uniqueVals->data[0] > 1.0) {
      threshCandidate = std::ceil(uniqueVals->data[0]);
      if ((2.0 - (double)uniqueVals->size[1] < threshCandidate - 1.0) || rtIsNaN
          (threshCandidate - 1.0)) {
        threshCandidate = 2.0 - (double)uniqueVals->size[1];
      } else {
        threshCandidate--;
      }

      if (rtIsNaN(threshCandidate)) {
        q = 1;
        y_data[0] = rtNaN;
      } else if (threshCandidate < 1.0) {
        q = 0;
      } else if (rtIsInf(threshCandidate) && (1.0 == threshCandidate)) {
        q = 1;
        y_data[0] = rtNaN;
      } else {
        q = (int)(threshCandidate - 1.0) + 1;
        loop_ub = (int)(threshCandidate - 1.0);
        for (i5 = 0; i5 <= loop_ub; i5++) {
          y_data[i5] = 1.0 + (double)i5;
        }
      }

      i5 = threshL->size[0] * threshL->size[1];
      threshL->size[0] = 1;
      threshL->size[1] = q + uniqueVals->size[1];
      emxEnsureCapacity_real_T(threshL, i5);
      for (i5 = 0; i5 < q; i5++) {
        threshL->data[i5] = y_data[i5];
      }

      loop_ub = uniqueVals->size[1];
      for (i5 = 0; i5 < loop_ub; i5++) {
        threshL->data[i5 + q] = uniqueVals->data[i5];
      }
    } else {
      i5 = threshL->size[0] * threshL->size[1];
      threshL->size[0] = 1;
      threshL->size[1] = uniqueVals->size[1];
      emxEnsureCapacity_real_T(threshL, i5);
      loop_ub = uniqueVals->size[0] * uniqueVals->size[1];
      for (i5 = 0; i5 < loop_ub; i5++) {
        threshL->data[i5] = uniqueVals->data[i5];
      }
    }

    if (2 - threshL->size[1] > 0) {
      q = 2 - threshL->size[1];
      i5 = thresh->size[0] * thresh->size[1];
      thresh->size[0] = 1;
      thresh->size[1] = threshL->size[1] + q;
      emxEnsureCapacity_real_T(thresh, i5);
      loop_ub = threshL->size[1];
      for (i5 = 0; i5 < loop_ub; i5++) {
        thresh->data[i5] = threshL->data[i5];
      }

      for (i5 = 0; i5 < q; i5++) {
        thresh->data[i5 + threshL->size[1]] = 0.0;
      }

      threshCandidate = std::floor(uniqueVals->data[0]);
      if (!(threshCandidate > 0.0)) {
        threshCandidate = 0.0;
      }

      q = 1;
      emxInit_real_T(&r5, 1);
      emxInit_real_T(&b_uniqueVals, 1);
      while (q <= 2 - threshL->size[1]) {
        threshCandidate++;
        i5 = b_uniqueVals->size[0];
        b_uniqueVals->size[0] = uniqueVals->size[1];
        emxEnsureCapacity_real_T(b_uniqueVals, i5);
        loop_ub = uniqueVals->size[1];
        for (i5 = 0; i5 < loop_ub; i5++) {
          b_uniqueVals->data[i5] = uniqueVals->data[i5] - threshCandidate;
        }

        b_abs(b_uniqueVals, r5);
        d2 = eps(threshCandidate);
        tmp_size[0] = r5->size[0];
        loop_ub = r5->size[0];
        for (i5 = 0; i5 < loop_ub; i5++) {
          tmp_data[i5] = (r5->data[i5] < d2);
        }

        if (!any(tmp_data, tmp_size)) {
          thresh->data[threshL->size[1]] = threshCandidate;
          q = 2;
        }
      }

      emxFree_real_T(&b_uniqueVals);
      emxFree_real_T(&r5);
      sort(thresh);
    } else {
      i5 = thresh->size[0] * thresh->size[1];
      thresh->size[0] = 1;
      thresh->size[1] = threshL->size[1];
      emxEnsureCapacity_real_T(thresh, i5);
      loop_ub = threshL->size[0] * threshL->size[1];
      for (i5 = 0; i5 < loop_ub; i5++) {
        thresh->data[i5] = threshL->data[i5];
      }
    }

    emxFree_real_T(&threshL);
  } else {
    i5 = thresh->size[0] * thresh->size[1];
    thresh->size[0] = 1;
    thresh->size[1] = uniqueVals->size[1];
    emxEnsureCapacity_real_T(thresh, i5);
    loop_ub = uniqueVals->size[0] * uniqueVals->size[1];
    for (i5 = 0; i5 < loop_ub; i5++) {
      thresh->data[i5] = uniqueVals->data[i5];
    }
  }
}

//
// Arguments    : const double omega[256]
//                const double mu[256]
//                double mu_t
//                double sigma_b_squared[256]
// Return Type  : void
//
static void calcFullObjCriteriaMatrix(const double omega[256], const double mu
  [256], double mu_t, double sigma_b_squared[256])
{
  int k;
  double d0;
  for (k = 0; k < 256; k++) {
    d0 = mu_t * omega[k] - mu[k];
    sigma_b_squared[k] = d0 * d0 / (omega[k] * (1.0 - omega[k]));
  }
}

//
// Arguments    : const emxArray_real_T *A
//                double N
//                bool *isDegenerate
//                emxArray_real_T *uniqueVals
// Return Type  : void
//
static void checkForDegenerateInput(const emxArray_real_T *A, double N, bool
  *isDegenerate, emxArray_real_T *uniqueVals)
{
  emxArray_real_T *b;
  emxArray_int32_T *idx;
  int na;
  unsigned short A_idx_0;
  int nMInf;
  int khi;
  int nNaN;
  int nb;
  double x;
  bool tmp_data[53008];
  int tmp_size[2];
  bool b_tmp_data[53008];
  bool c_tmp_data[53008];
  emxInit_real_T(&b, 1);
  emxInit_int32_T(&idx, 1);
  na = A->size[0];
  sortIdx(A, idx);
  A_idx_0 = (unsigned short)A->size[0];
  nMInf = b->size[0];
  b->size[0] = A_idx_0;
  emxEnsureCapacity_real_T(b, nMInf);
  for (khi = 0; khi < na; khi++) {
    b->data[khi] = A->data[idx->data[khi] - 1];
  }

  emxFree_int32_T(&idx);
  count_nonfinites(b, A->size[0], &nMInf, &khi, &na, &nNaN);
  nb = -1;
  if (nMInf > 0) {
    nb = 0;
  }

  khi += nMInf;
  while (nMInf + 1 <= khi) {
    x = b->data[nMInf];
    do {
      nMInf++;
    } while (!((nMInf + 1 > khi) || ((!(std::abs(x - b->data[nMInf]) < eps(x /
                  2.0))) && ((!rtIsInf(b->data[nMInf])) || (!rtIsInf(x)) ||
                             ((b->data[nMInf] > 0.0) != (x > 0.0))))));

    nb++;
    b->data[nb] = x;
  }

  if (na > 0) {
    nb++;
    b->data[nb] = b->data[khi];
  }

  nMInf = khi + na;
  for (khi = 0; khi < nNaN; khi++) {
    nb++;
    b->data[nb] = b->data[nMInf + khi];
  }

  if (1 > nb + 1) {
    b->size[0] = 0;
  } else {
    nMInf = b->size[0];
    b->size[0] = nb + 1;
    emxEnsureCapacity_real_T(b, nMInf);
  }

  nMInf = uniqueVals->size[0] * uniqueVals->size[1];
  uniqueVals->size[0] = 1;
  uniqueVals->size[1] = b->size[0];
  emxEnsureCapacity_real_T(uniqueVals, nMInf);
  khi = b->size[0];
  for (nMInf = 0; nMInf < khi; nMInf++) {
    uniqueVals->data[nMInf] = b->data[nMInf];
  }

  emxFree_real_T(&b);
  na = uniqueVals->size[1];
  khi = uniqueVals->size[0] * uniqueVals->size[1];
  for (nMInf = 0; nMInf < khi; nMInf++) {
    tmp_data[nMInf] = rtIsInf(uniqueVals->data[nMInf]);
  }

  khi = uniqueVals->size[0] * uniqueVals->size[1];
  for (nMInf = 0; nMInf < khi; nMInf++) {
    b_tmp_data[nMInf] = rtIsNaN(uniqueVals->data[nMInf]);
  }

  tmp_size[0] = 1;
  tmp_size[1] = na;
  for (nMInf = 0; nMInf < na; nMInf++) {
    c_tmp_data[nMInf] = (tmp_data[nMInf] || b_tmp_data[nMInf]);
  }

  nullAssignment(uniqueVals, c_tmp_data, tmp_size);
  *isDegenerate = (uniqueVals->size[1] <= N);
}

//
// Arguments    : const emxArray_real_T *uniqueVals
//                emxArray_real_T *thresh
// Return Type  : void
//
static void getDegenerateThresholds(const emxArray_real_T *uniqueVals,
  emxArray_real_T *thresh)
{
  int i1;
  int loop_ub;
  if (uniqueVals->size[1] == 0) {
    i1 = thresh->size[0] * thresh->size[1];
    thresh->size[0] = 1;
    thresh->size[1] = 1;
    emxEnsureCapacity_real_T(thresh, i1);
    thresh->data[0] = 1.0;
  } else {
    i1 = thresh->size[0] * thresh->size[1];
    thresh->size[0] = 1;
    thresh->size[1] = uniqueVals->size[1];
    emxEnsureCapacity_real_T(thresh, i1);
    loop_ub = uniqueVals->size[0] * uniqueVals->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      thresh->data[i1] = uniqueVals->data[i1];
    }
  }
}

//
// Arguments    : double minA
//                double maxA
//                emxArray_real_T *thresh
// Return Type  : void
//
static void getThreshForNoPdf(double minA, double maxA, emxArray_real_T *thresh)
{
  int q;
  double threshL_data[2];
  double threshCandidate;
  emxArray_real_T *r6;
  bool x;
  int loop_ub;
  if (rtIsNaN(minA)) {
    minA = 1.0;
    maxA = 1.0;
  }

  if (minA == maxA) {
    if (minA > 1.0) {
      threshL_data[0] = 1.0;
      threshL_data[1] = minA;
      q = thresh->size[0] * thresh->size[1];
      thresh->size[0] = 1;
      thresh->size[1] = 2;
      emxEnsureCapacity_real_T(thresh, q);
      for (q = 0; q < 2; q++) {
        thresh->data[q] = threshL_data[q];
      }
    } else {
      threshL_data[0] = minA;
      q = thresh->size[0] * thresh->size[1];
      thresh->size[0] = 1;
      thresh->size[1] = 2;
      emxEnsureCapacity_real_T(thresh, q);
      for (q = 0; q < 1; q++) {
        thresh->data[0] = threshL_data[0];
      }

      thresh->data[1] = 0.0;
      threshCandidate = std::floor(minA);
      if (!(threshCandidate > 0.0)) {
        threshCandidate = 0.0;
      }

      q = 1;
      while (q <= 1) {
        threshCandidate++;
        x = (std::abs(minA - threshCandidate) < eps(threshCandidate));
        if (!x) {
          thresh->data[1] = threshCandidate;
          q = 2;
        }
      }

      emxInit_real_T(&r6, 2);
      q = r6->size[0] * r6->size[1];
      r6->size[0] = 1;
      r6->size[1] = thresh->size[1];
      emxEnsureCapacity_real_T(r6, q);
      loop_ub = thresh->size[0] * thresh->size[1];
      for (q = 0; q < loop_ub; q++) {
        r6->data[q] = thresh->data[q];
      }

      sort(r6);
      q = thresh->size[0] * thresh->size[1];
      thresh->size[0] = 1;
      thresh->size[1] = r6->size[1];
      emxEnsureCapacity_real_T(thresh, q);
      loop_ub = r6->size[0] * r6->size[1];
      for (q = 0; q < loop_ub; q++) {
        thresh->data[q] = r6->data[q];
      }

      emxFree_real_T(&r6);
    }
  } else {
    q = thresh->size[0] * thresh->size[1];
    thresh->size[0] = 1;
    thresh->size[1] = 2;
    emxEnsureCapacity_real_T(thresh, q);
    thresh->data[0] = minA;
    thresh->data[1] = maxA;
  }
}

//
// Arguments    : emxArray_real_T *A
//                double p[256]
//                double *minA
//                double *maxA
//                bool *emptyp
// Return Type  : void
//
static void getpdf(emxArray_real_T *A, double p[256], double *minA, double *maxA,
                   bool *emptyp)
{
  int idx;
  int n;
  int i2;
  int k;
  bool exitg1;
  double b_maxA;
  int end;
  bool nans_data[53008];
  emxArray_uint16_T *r3;
  emxArray_real_T *b_A;
  unsigned char Auint8_data[53008];
  int Auint8_size[1];
  *emptyp = true;
  idx = 0;
  while ((idx + 1 <= A->size[0]) && (!b_isfinite(A->data[idx]))) {
    idx++;
  }

  if (idx + 1 <= A->size[0]) {
    *minA = A->data[idx];
    *maxA = A->data[idx];
    i2 = A->size[0];
    for (k = idx + 2; k <= i2; k++) {
      if ((A->data[k - 1] < *minA) && b_isfinite(A->data[k - 1])) {
        *minA = A->data[k - 1];
      } else {
        if ((A->data[k - 1] > *maxA) && b_isfinite(A->data[k - 1])) {
          *maxA = A->data[k - 1];
        }
      }
    }

    if (!(*minA == *maxA)) {
      b_maxA = *maxA - *minA;
      i2 = A->size[0];
      emxEnsureCapacity_real_T(A, i2);
      idx = A->size[0];
      for (i2 = 0; i2 < idx; i2++) {
        A->data[i2] = (A->data[i2] - *minA) / b_maxA;
      }

      k = A->size[0];
      idx = A->size[0];
      for (i2 = 0; i2 < idx; i2++) {
        nans_data[i2] = rtIsNaN(A->data[i2]);
      }

      end = (unsigned short)k;
      idx = 0;
      for (n = 0; n < end; n++) {
        if (!nans_data[n]) {
          idx++;
        }
      }

      if (idx != 0) {
        end = (unsigned short)k - 1;
        idx = 0;
        for (n = 0; n <= end; n++) {
          if (!nans_data[n]) {
            idx++;
          }
        }

        emxInit_uint16_T(&r3, 1);
        i2 = r3->size[0];
        r3->size[0] = idx;
        emxEnsureCapacity_uint16_T(r3, i2);
        idx = 0;
        for (n = 0; n <= end; n++) {
          if (!nans_data[n]) {
            r3->data[idx] = (unsigned short)(n + 1);
            idx++;
          }
        }

        emxInit_real_T(&b_A, 1);
        i2 = b_A->size[0];
        b_A->size[0] = r3->size[0];
        emxEnsureCapacity_real_T(b_A, i2);
        idx = r3->size[0];
        for (i2 = 0; i2 < idx; i2++) {
          b_A->data[i2] = A->data[r3->data[i2] - 1];
        }

        emxFree_uint16_T(&r3);
        im2uint8(b_A, Auint8_data, Auint8_size);
        imhist(Auint8_data, Auint8_size, p);
        b_maxA = sum(p);
        emxFree_real_T(&b_A);
        for (i2 = 0; i2 < 256; i2++) {
          p[i2] /= b_maxA;
        }

        *emptyp = false;
      }
    }
  } else {
    n = A->size[0];
    if (A->size[0] <= 2) {
      if (A->size[0] == 1) {
        *minA = A->data[0];
      } else if ((A->data[0] > A->data[1]) || (rtIsNaN(A->data[0]) && (!rtIsNaN
                   (A->data[1])))) {
        *minA = A->data[1];
      } else {
        *minA = A->data[0];
      }
    } else {
      if (!rtIsNaN(A->data[0])) {
        idx = 1;
      } else {
        idx = 0;
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= A->size[0])) {
          if (!rtIsNaN(A->data[k - 1])) {
            idx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }

      if (idx == 0) {
        *minA = A->data[0];
      } else {
        *minA = A->data[idx - 1];
        i2 = idx + 1;
        for (k = i2; k <= n; k++) {
          if (*minA > A->data[k - 1]) {
            *minA = A->data[k - 1];
          }
        }
      }
    }

    n = A->size[0];
    if (A->size[0] <= 2) {
      if (A->size[0] == 1) {
        *maxA = A->data[0];
      } else if ((A->data[0] < A->data[1]) || (rtIsNaN(A->data[0]) && (!rtIsNaN
                   (A->data[1])))) {
        *maxA = A->data[1];
      } else {
        *maxA = A->data[0];
      }
    } else {
      if (!rtIsNaN(A->data[0])) {
        idx = 1;
      } else {
        idx = 0;
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= A->size[0])) {
          if (!rtIsNaN(A->data[k - 1])) {
            idx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }

      if (idx == 0) {
        *maxA = A->data[0];
      } else {
        *maxA = A->data[idx - 1];
        i2 = idx + 1;
        for (k = i2; k <= n; k++) {
          if (*maxA < A->data[k - 1]) {
            *maxA = A->data[k - 1];
          }
        }
      }
    }
  }
}

//
// Arguments    : const emxArray_real_T *varargin_1
//                double thresh[2]
// Return Type  : void
//
void b_multithresh(const emxArray_real_T *varargin_1, double thresh[2])
{
  emxArray_real_T *threshRaw;
  emxArray_real_T *b_varargin_1;
  int varargin_1_size[2];
  int jj;
  emxArray_real_T varargin_1_data;
  int ii;
  double p[256];
  double minA;
  double maxA;
  bool emptyp;
  double omega[256];
  emxArray_real_T *r4;
  double mu[256];
  static double sigma_b_squared[65536];
  int idx;
  bool exitg1;
  double maxval;
  emxArray_real_T *uniqueVals;
  double d1;
  emxArray_int32_T *i;
  emxArray_int16_T *j;
  bool guard1 = false;
  emxArray_real_T *b_i;
  double dv0[2];
  emxInit_real_T(&threshRaw, 2);
  if (varargin_1->size[0] == 0) {
    varargin_1_size[0] = 1;
    varargin_1_size[1] = 0;
    varargin_1_data.size = &varargin_1_size[0];
    varargin_1_data.allocatedSize = 0;
    varargin_1_data.numDimensions = 2;
    varargin_1_data.canFreeData = false;
    b_getDegenerateThresholds(&varargin_1_data, threshRaw);
    thresh[0] = threshRaw->data[0];
    thresh[1] = threshRaw->data[1];
  } else {
    emxInit_real_T(&b_varargin_1, 1);
    jj = b_varargin_1->size[0];
    b_varargin_1->size[0] = varargin_1->size[0];
    emxEnsureCapacity_real_T(b_varargin_1, jj);
    ii = varargin_1->size[0];
    for (jj = 0; jj < ii; jj++) {
      b_varargin_1->data[jj] = varargin_1->data[jj];
    }

    getpdf(b_varargin_1, p, &minA, &maxA, &emptyp);
    emxFree_real_T(&b_varargin_1);
    if (emptyp) {
      emxInit_real_T(&r4, 2);
      getThreshForNoPdf(minA, maxA, r4);
      jj = threshRaw->size[0] * threshRaw->size[1];
      threshRaw->size[0] = 1;
      threshRaw->size[1] = r4->size[1];
      emxEnsureCapacity_real_T(threshRaw, jj);
      ii = r4->size[0] * r4->size[1];
      for (jj = 0; jj < ii; jj++) {
        threshRaw->data[jj] = r4->data[jj];
      }

      emxFree_real_T(&r4);
      thresh[0] = threshRaw->data[0];
      thresh[1] = threshRaw->data[1];
    } else {
      memcpy(&omega[0], &p[0], sizeof(double) << 8);
      for (ii = 0; ii < 255; ii++) {
        omega[ii + 1] += omega[ii];
      }

      for (jj = 0; jj < 256; jj++) {
        mu[jj] = p[jj] * (1.0 + (double)jj);
      }

      for (ii = 0; ii < 255; ii++) {
        mu[ii + 1] += mu[ii];
      }

      b_calcFullObjCriteriaMatrix(omega, mu, mu[255], sigma_b_squared);
      if (!rtIsNaN(sigma_b_squared[0])) {
        idx = 1;
      } else {
        idx = 0;
        ii = 2;
        exitg1 = false;
        while ((!exitg1) && (ii < 65537)) {
          if (!rtIsNaN(sigma_b_squared[ii - 1])) {
            idx = ii;
            exitg1 = true;
          } else {
            ii++;
          }
        }
      }

      if (idx == 0) {
        maxval = sigma_b_squared[0];
      } else {
        maxval = sigma_b_squared[idx - 1];
        jj = idx + 1;
        for (ii = jj; ii < 65537; ii++) {
          d1 = sigma_b_squared[ii - 1];
          if (maxval < d1) {
            maxval = d1;
          }
        }
      }

      emxInit_real_T(&uniqueVals, 2);
      if (b_isfinite(maxval)) {
        emxInit_int32_T(&i, 1);
        emxInit_int16_T(&j, 1);
        idx = 0;
        jj = i->size[0];
        i->size[0] = 65536;
        emxEnsureCapacity_int32_T(i, jj);
        jj = j->size[0];
        j->size[0] = 65536;
        emxEnsureCapacity_int16_T(j, jj);
        ii = 1;
        jj = 1;
        exitg1 = false;
        while ((!exitg1) && (jj <= 256)) {
          guard1 = false;
          if (sigma_b_squared[(ii + ((jj - 1) << 8)) - 1] == maxval) {
            idx++;
            i->data[idx - 1] = ii;
            j->data[idx - 1] = (short)jj;
            if (idx >= 65536) {
              exitg1 = true;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1) {
            ii++;
            if (ii > 256) {
              ii = 1;
              jj++;
            }
          }
        }

        if (1 > idx) {
          i->size[0] = 0;
          j->size[0] = 0;
        } else {
          jj = i->size[0];
          i->size[0] = idx;
          emxEnsureCapacity_int32_T(i, jj);
          jj = j->size[0];
          j->size[0] = idx;
          emxEnsureCapacity_int16_T(j, jj);
        }

        emxInit_real_T(&b_i, 2);
        jj = b_i->size[0] * b_i->size[1];
        b_i->size[0] = i->size[0];
        b_i->size[1] = 2;
        emxEnsureCapacity_real_T(b_i, jj);
        ii = i->size[0];
        for (jj = 0; jj < ii; jj++) {
          b_i->data[jj] = i->data[jj];
        }

        emxFree_int32_T(&i);
        ii = j->size[0];
        for (jj = 0; jj < ii; jj++) {
          b_i->data[jj + b_i->size[0]] = j->data[jj];
        }

        emxFree_int16_T(&j);
        mean(b_i, dv0);
        jj = threshRaw->size[0] * threshRaw->size[1];
        threshRaw->size[0] = 1;
        threshRaw->size[1] = 2;
        emxEnsureCapacity_real_T(threshRaw, jj);
        emxFree_real_T(&b_i);
        threshRaw->data[0] = dv0[0] - 1.0;
        threshRaw->data[1] = dv0[1] - 1.0;
        maxA -= minA;
        jj = threshRaw->size[0] * threshRaw->size[1];
        ii = threshRaw->size[0] * threshRaw->size[1];
        threshRaw->size[0] = 1;
        emxEnsureCapacity_real_T(threshRaw, ii);
        ii = jj - 1;
        for (jj = 0; jj <= ii; jj++) {
          threshRaw->data[jj] = minA + threshRaw->data[jj] / 255.0 * maxA;
        }
      } else {
        checkForDegenerateInput(varargin_1, 2.0, &emptyp, uniqueVals);
        b_getDegenerateThresholds(uniqueVals, threshRaw);
        checkForDegenerateInput(varargin_1, 2.0, &emptyp, uniqueVals);
        if (emptyp) {
          b_getDegenerateThresholds(uniqueVals, threshRaw);
        } else {
          maxA -= minA;
          jj = threshRaw->size[0] * threshRaw->size[1];
          ii = threshRaw->size[0] * threshRaw->size[1];
          threshRaw->size[0] = 1;
          emxEnsureCapacity_real_T(threshRaw, ii);
          ii = jj - 1;
          for (jj = 0; jj <= ii; jj++) {
            threshRaw->data[jj] = minA + threshRaw->data[jj] / 255.0 * maxA;
          }
        }
      }

      emxFree_real_T(&uniqueVals);
      thresh[0] = threshRaw->data[0];
      thresh[1] = threshRaw->data[1];
    }
  }

  emxFree_real_T(&threshRaw);
}

//
// Arguments    : const emxArray_real_T *varargin_1
// Return Type  : double
//
double multithresh(const emxArray_real_T *varargin_1)
{
  double thresh;
  emxArray_real_T *b_varargin_1;
  int i0;
  int idx;
  double sigma_b_squared[256];
  double maxA;
  bool emptyp;
  double omega[256];
  int k;
  double mu[256];
  bool exitg1;
  double maxval;
  emxArray_real_T *threshRaw;
  emxArray_real_T *uniqueVals;
  double idxSum;
  double idxNum;
  if (varargin_1->size[0] == 0) {
    thresh = 1.0;
  } else {
    emxInit_real_T(&b_varargin_1, 1);
    i0 = b_varargin_1->size[0];
    b_varargin_1->size[0] = varargin_1->size[0];
    emxEnsureCapacity_real_T(b_varargin_1, i0);
    idx = varargin_1->size[0];
    for (i0 = 0; i0 < idx; i0++) {
      b_varargin_1->data[i0] = varargin_1->data[i0];
    }

    getpdf(b_varargin_1, sigma_b_squared, &thresh, &maxA, &emptyp);
    emxFree_real_T(&b_varargin_1);
    if (emptyp) {
      if (rtIsNaN(thresh)) {
        thresh = 1.0;
      }
    } else {
      memcpy(&omega[0], &sigma_b_squared[0], sizeof(double) << 8);
      for (k = 0; k < 255; k++) {
        omega[k + 1] += omega[k];
      }

      for (i0 = 0; i0 < 256; i0++) {
        mu[i0] = sigma_b_squared[i0] * (1.0 + (double)i0);
      }

      for (k = 0; k < 255; k++) {
        mu[k + 1] += mu[k];
      }

      calcFullObjCriteriaMatrix(omega, mu, mu[255], sigma_b_squared);
      if (!rtIsNaN(sigma_b_squared[0])) {
        idx = 1;
      } else {
        idx = 0;
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k < 257)) {
          if (!rtIsNaN(sigma_b_squared[k - 1])) {
            idx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }

      if (idx == 0) {
        maxval = sigma_b_squared[0];
      } else {
        maxval = sigma_b_squared[idx - 1];
        i0 = idx + 1;
        for (k = i0; k < 257; k++) {
          idxSum = sigma_b_squared[k - 1];
          if (maxval < idxSum) {
            maxval = idxSum;
          }
        }
      }

      emxInit_real_T(&threshRaw, 2);
      emxInit_real_T(&uniqueVals, 2);
      if (b_isfinite(maxval)) {
        idxSum = 0.0;
        idxNum = 0.0;
        for (idx = 0; idx < 256; idx++) {
          if (sigma_b_squared[idx] == maxval) {
            idxSum += 1.0 + (double)idx;
            idxNum++;
          }
        }

        i0 = threshRaw->size[0] * threshRaw->size[1];
        threshRaw->size[0] = 1;
        threshRaw->size[1] = 1;
        emxEnsureCapacity_real_T(threshRaw, i0);
        threshRaw->data[0] = idxSum / idxNum - 1.0;
        idxSum = maxA - thresh;
        i0 = threshRaw->size[0] * threshRaw->size[1];
        idx = threshRaw->size[0] * threshRaw->size[1];
        threshRaw->size[0] = 1;
        emxEnsureCapacity_real_T(threshRaw, idx);
        idx = i0 - 1;
        for (i0 = 0; i0 <= idx; i0++) {
          threshRaw->data[i0] = thresh + threshRaw->data[i0] / 255.0 * idxSum;
        }
      } else {
        checkForDegenerateInput(varargin_1, 1.0, &emptyp, uniqueVals);
        getDegenerateThresholds(uniqueVals, threshRaw);
        checkForDegenerateInput(varargin_1, 1.0, &emptyp, uniqueVals);
        if (emptyp) {
          getDegenerateThresholds(uniqueVals, threshRaw);
        } else {
          idxSum = maxA - thresh;
          i0 = threshRaw->size[0] * threshRaw->size[1];
          idx = threshRaw->size[0] * threshRaw->size[1];
          threshRaw->size[0] = 1;
          emxEnsureCapacity_real_T(threshRaw, idx);
          idx = i0 - 1;
          for (i0 = 0; i0 <= idx; i0++) {
            threshRaw->data[i0] = thresh + threshRaw->data[i0] / 255.0 * idxSum;
          }
        }
      }

      emxFree_real_T(&uniqueVals);
      thresh = threshRaw->data[0];
      emxFree_real_T(&threshRaw);
    }
  }

  return thresh;
}

//
// File trailer for multithresh.cpp
//
// [EOF]
//
