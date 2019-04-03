/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * multithresh.c
 *
 * Code generation for function 'multithresh'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "multithresh.h"
#include "scalarsthresholds_emxutil.h"
#include "power.h"
#include "ndgrid.h"
#include "bsxfun.h"
#include "repmat.h"
#include "eps.h"
#include "any.h"
#include "abs.h"
#include "sort1.h"
#include "warning.h"
#include "mean.h"
#include "find.h"
#include "eml_int_forloop_overflow_check.h"
#include "nullAssignment.h"
#include "indexShapeCheck.h"
#include "unique.h"
#include "sortIdx.h"
#include "isfinite.h"
#include "im2uint8.h"
#include "sum.h"
#include "imhist.h"
#include "scalarsthresholds_data.h"

/* Variable Definitions */
static emlrtRSInfo c_emlrtRSI = { 14,  /* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 15,  /* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 24,  /* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 28,  /* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 89,  /* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 91,  /* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 93,  /* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 95,  /* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 137, /* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 139, /* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 140, /* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 143, /* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 650, /* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 651, /* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 660, /* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 28,  /* lineNo */
  "sort",                              /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/datafun/sort.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 385,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 537,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 542,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo mc_emlrtRSI = { 44, /* lineNo */
  "unique",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo nc_emlrtRSI = { 152,/* lineNo */
  "unique",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo oc_emlrtRSI = { 154,/* lineNo */
  "unique",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo pc_emlrtRSI = { 163,/* lineNo */
  "unique",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo qc_emlrtRSI = { 181,/* lineNo */
  "unique",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo rc_emlrtRSI = { 188,/* lineNo */
  "unique",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo sc_emlrtRSI = { 201,/* lineNo */
  "unique",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo tc_emlrtRSI = { 212,/* lineNo */
  "unique",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo uc_emlrtRSI = { 220,/* lineNo */
  "unique",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo vc_emlrtRSI = { 226,/* lineNo */
  "unique",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo gd_emlrtRSI = { 29, /* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo hd_emlrtRSI = { 84, /* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo id_emlrtRSI = { 86, /* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo jd_emlrtRSI = { 600,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo kd_emlrtRSI = { 37, /* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo pd_emlrtRSI = { 20, /* lineNo */
  "cat",                               /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtRSInfo qd_emlrtRSI = { 100,/* lineNo */
  "cat",                               /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtRTEInfo d_emlrtRTEI = { 164,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 82,/* lineNo */
  13,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 129,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 145,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 1, /* lineNo */
  29,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 667,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 618,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 213,/* lineNo */
  13,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 179,/* lineNo */
  36,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 225,/* lineNo */
  15,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 44,/* lineNo */
  13,                                  /* colNo */
  "unique",                            /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/unique.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 44,/* lineNo */
  9,                                   /* colNo */
  "unique",                            /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/unique.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 537,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 537,/* lineNo */
  18,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 152,/* lineNo */
  1,                                   /* colNo */
  "unique",                            /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/unique.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 29,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 86,/* lineNo */
  25,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 86,/* lineNo */
  13,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 84,/* lineNo */
  14,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 84,/* lineNo */
  20,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 29,/* lineNo */
  17,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 634,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 631,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 662,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 643,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 650,/* lineNo */
  24,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 650,/* lineNo */
  20,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 604,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 600,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 28,/* lineNo */
  5,                                   /* colNo */
  "sort",                              /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/datafun/sort.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 660,/* lineNo */
  23,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  155,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  199,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  225,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  190,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  196,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  197,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo ac_emlrtRTEI = { 219,/* lineNo */
  1,                                   /* colNo */
  "unique",                            /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/unique.m"/* pName */
};

static emlrtECInfo emlrtECI = { 2,     /* nDims */
  542,                                 /* lineNo */
  16,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo cc_emlrtRTEI = { 281,/* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  155,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  655,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

/* Function Declarations */
static void b_calcFullObjCriteriaMatrix(scalarsthresholdsStackData *SD, const
  real_T omega[256], const real_T mu[256], real_T mu_t, real_T sigma_b_squared
  [65536]);
static void b_getDegenerateThresholds(const emlrtStack *sp, const
  emxArray_real_T *uniqueVals, emxArray_real_T *thresh);
static void calcFullObjCriteriaMatrix(const real_T omega[256], const real_T mu
  [256], real_T mu_t, real_T sigma_b_squared[256]);
static void checkForDegenerateInput(const emlrtStack *sp, const emxArray_real_T *
  A, real_T N, boolean_T *isDegenerate, emxArray_real_T *uniqueVals);
static void getDegenerateThresholds(const emlrtStack *sp, const emxArray_real_T *
  uniqueVals, emxArray_real_T *thresh);
static void getThreshForNoPdf(const emlrtStack *sp, real_T minA, real_T maxA,
  emxArray_real_T *thresh);
static void getpdf(const emlrtStack *sp, emxArray_real_T *A, real_T p[256],
                   real_T *minA, real_T *maxA, boolean_T *emptyp);

/* Function Definitions */
static void b_calcFullObjCriteriaMatrix(scalarsthresholdsStackData *SD, const
  real_T omega[256], const real_T mu[256], real_T mu_t, real_T sigma_b_squared
  [65536])
{
  int32_T i;
  real_T b_mu[256];
  real_T dv1[256];
  real_T dv2[256];
  real_T omega1;
  real_T b_sigma_b_squared;
  real_T omega2_tmp;
  repmat(omega, sigma_b_squared);
  for (i = 0; i < 256; i++) {
    b_mu[i] = mu[i] / omega[i];
  }

  bsxfun(mu_t, b_mu, dv1);
  repmat(dv1, SD->f0.mu_0_t);
  b_bsxfun(omega, omega, SD->f0.omega1);
  b_bsxfun(mu, mu, SD->f0.allPixC);
  for (i = 0; i < 65536; i++) {
    SD->f0.b_allPixC[i] = SD->f0.allPixC[i] / SD->f0.omega1[i];
  }

  c_bsxfun(mu_t, SD->f0.b_allPixC, SD->f0.mu_1_t);
  for (i = 0; i < 256; i++) {
    b_mu[i] = 1.0 + (real_T)i;
    dv2[i] = 1.0 + (real_T)i;
  }

  ndgrid(b_mu, dv2, SD->f0.b_allPixC, SD->f0.allPixC);
  for (i = 0; i < 65536; i++) {
    omega1 = SD->f0.omega1[i];
    b_sigma_b_squared = sigma_b_squared[i];
    if (SD->f0.b_allPixC[i] >= SD->f0.allPixC[i]) {
      b_sigma_b_squared = rtNaN;
      omega1 = rtNaN;
    }

    omega2_tmp = 1.0 - (b_sigma_b_squared + omega1);
    SD->f0.omega2[i] = omega2_tmp;
    if (omega2_tmp <= 0.0) {
      SD->f0.omega2[i] = rtNaN;
    }

    sigma_b_squared[i] = b_sigma_b_squared;
    SD->f0.omega1[i] = omega1;
  }

  power(SD->f0.mu_0_t, SD->f0.allPixC);
  power(SD->f0.mu_1_t, SD->f0.dv3);
  for (i = 0; i < 65536; i++) {
    SD->f0.sigma_b_squared[i] = sigma_b_squared[i] * SD->f0.mu_0_t[i] +
      SD->f0.omega1[i] * SD->f0.mu_1_t[i];
  }

  power(SD->f0.sigma_b_squared, SD->f0.b_allPixC);
  for (i = 0; i < 65536; i++) {
    sigma_b_squared[i] = (sigma_b_squared[i] * SD->f0.allPixC[i] + SD->
                          f0.omega1[i] * SD->f0.dv3[i]) + SD->f0.b_allPixC[i] /
      SD->f0.omega2[i];
  }
}

static void b_getDegenerateThresholds(const emlrtStack *sp, const
  emxArray_real_T *uniqueVals, emxArray_real_T *thresh)
{
  int32_T i5;
  emxArray_real_T *threshL;
  real_T threshCandidate;
  int32_T q;
  int32_T loop_ub;
  emxArray_real_T *r5;
  emxArray_real_T *b_uniqueVals;
  real_T d2;
  int32_T tmp_size[1];
  boolean_T tmp_data[53008];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  if (uniqueVals->size[1] == 0) {
    i5 = thresh->size[0] * thresh->size[1];
    thresh->size[0] = 1;
    thresh->size[1] = 2;
    emxEnsureCapacity_real_T(sp, thresh, i5, &j_emlrtRTEI);
    thresh->data[0] = 1.0;
    thresh->data[1] = 2.0;
  } else if (2 - uniqueVals->size[1] > 0) {
    emxInit_real_T(sp, &threshL, 2, &db_emlrtRTEI, true);
    if (uniqueVals->data[0] > 1.0) {
      threshCandidate = muDoubleScalarMin(2.0 - (real_T)uniqueVals->size[1],
        muDoubleScalarCeil(uniqueVals->data[0]) - 1.0);
      q = !(threshCandidate < 1.0);
      i5 = threshL->size[0] * threshL->size[1];
      threshL->size[0] = 1;
      threshL->size[1] = q + uniqueVals->size[1];
      emxEnsureCapacity_real_T(sp, threshL, i5, &db_emlrtRTEI);
      for (i5 = 0; i5 < q; i5++) {
        threshL->data[0] = 1.0;
      }

      loop_ub = uniqueVals->size[1];
      for (i5 = 0; i5 < loop_ub; i5++) {
        threshL->data[i5 + q] = uniqueVals->data[i5];
      }
    } else {
      i5 = threshL->size[0] * threshL->size[1];
      threshL->size[0] = 1;
      threshL->size[1] = uniqueVals->size[1];
      emxEnsureCapacity_real_T(sp, threshL, i5, &cb_emlrtRTEI);
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
      emxEnsureCapacity_real_T(sp, thresh, i5, &fb_emlrtRTEI);
      loop_ub = threshL->size[1];
      for (i5 = 0; i5 < loop_ub; i5++) {
        thresh->data[i5] = threshL->data[i5];
      }

      for (i5 = 0; i5 < q; i5++) {
        thresh->data[i5 + threshL->size[1]] = 0.0;
      }

      threshCandidate = muDoubleScalarMax(muDoubleScalarFloor(uniqueVals->data[0]),
        0.0);
      q = 1;
      emxInit_real_T(sp, &r5, 1, &hb_emlrtRTEI, true);
      emxInit_real_T(sp, &b_uniqueVals, 1, &gb_emlrtRTEI, true);
      while (q <= 2 - threshL->size[1]) {
        threshCandidate++;
        i5 = b_uniqueVals->size[0];
        b_uniqueVals->size[0] = uniqueVals->size[1];
        emxEnsureCapacity_real_T(sp, b_uniqueVals, i5, &gb_emlrtRTEI);
        loop_ub = uniqueVals->size[1];
        for (i5 = 0; i5 < loop_ub; i5++) {
          b_uniqueVals->data[i5] = uniqueVals->data[i5] - threshCandidate;
        }

        st.site = &o_emlrtRSI;
        b_abs(&st, b_uniqueVals, r5);
        st.site = &p_emlrtRSI;
        d2 = eps(threshCandidate);
        tmp_size[0] = r5->size[0];
        loop_ub = r5->size[0];
        for (i5 = 0; i5 < loop_ub; i5++) {
          tmp_data[i5] = (r5->data[i5] < d2);
        }

        st.site = &o_emlrtRSI;
        if (!any(tmp_data, tmp_size)) {
          i5 = thresh->size[1];
          q = threshL->size[1] + 1;
          if ((q < 1) || (q > i5)) {
            emlrtDynamicBoundsCheckR2012b(q, 1, i5, &n_emlrtBCI, sp);
          }

          thresh->data[q - 1] = threshCandidate;
          q = 2;
        }
      }

      emxFree_real_T(&b_uniqueVals);
      emxFree_real_T(&r5);
      st.site = &q_emlrtRSI;
      b_st.site = &w_emlrtRSI;
      sort(&b_st, thresh);
    } else {
      i5 = thresh->size[0] * thresh->size[1];
      thresh->size[0] = 1;
      thresh->size[1] = threshL->size[1];
      emxEnsureCapacity_real_T(sp, thresh, i5, &eb_emlrtRTEI);
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
    emxEnsureCapacity_real_T(sp, thresh, i5, &i_emlrtRTEI);
    loop_ub = uniqueVals->size[0] * uniqueVals->size[1];
    for (i5 = 0; i5 < loop_ub; i5++) {
      thresh->data[i5] = uniqueVals->data[i5];
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void calcFullObjCriteriaMatrix(const real_T omega[256], const real_T mu
  [256], real_T mu_t, real_T sigma_b_squared[256])
{
  int32_T k;
  real_T d0;
  for (k = 0; k < 256; k++) {
    d0 = mu_t * omega[k] - mu[k];
    sigma_b_squared[k] = d0 * d0 / (omega[k] * (1.0 - omega[k]));
  }
}

static void checkForDegenerateInput(const emlrtStack *sp, const emxArray_real_T *
  A, real_T N, boolean_T *isDegenerate, emxArray_real_T *uniqueVals)
{
  emxArray_real_T *b;
  emxArray_int32_T *idx;
  int32_T na;
  uint16_T A_idx_0;
  int32_T nMInf;
  int32_T khi;
  int32_T nInf;
  int32_T nNaN;
  int32_T nb;
  real_T x;
  int32_T exitg1;
  boolean_T overflow;
  int32_T iv3[2];
  boolean_T tmp_data[53008];
  boolean_T b_tmp_data[53008];
  int32_T iv4[2];
  int32_T tmp_size[2];
  boolean_T c_tmp_data[53008];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b, 1, &r_emlrtRTEI, true);
  emxInit_int32_T(sp, &idx, 1, &s_emlrtRTEI, true);
  st.site = &kc_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  na = A->size[0];
  c_st.site = &nc_emlrtRSI;
  sortIdx(&c_st, A, idx);
  A_idx_0 = (uint16_T)A->size[0];
  nMInf = b->size[0];
  b->size[0] = A_idx_0;
  emxEnsureCapacity_real_T(&b_st, b, nMInf, &o_emlrtRTEI);
  c_st.site = &oc_emlrtRSI;
  for (khi = 0; khi < na; khi++) {
    b->data[khi] = A->data[idx->data[khi] - 1];
  }

  emxFree_int32_T(&idx);
  count_nonfinites(b, A->size[0], &nMInf, &khi, &nInf, &nNaN);
  nb = 0;
  if (nMInf > 0) {
    nb = 1;
    c_st.site = &pc_emlrtRSI;
    if (nMInf > 2147483646) {
      d_st.site = &t_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
  }

  khi += nMInf;
  while (nMInf + 1 <= khi) {
    x = b->data[nMInf];
    na = nMInf;
    do {
      exitg1 = 0;
      nMInf++;
      if (nMInf + 1 > khi) {
        exitg1 = 1;
      } else {
        c_st.site = &qc_emlrtRSI;
        if ((muDoubleScalarAbs(x - b->data[nMInf]) < eps(x / 2.0)) ||
            (muDoubleScalarIsInf(b->data[nMInf]) && muDoubleScalarIsInf(x) &&
             ((b->data[nMInf] > 0.0) == (x > 0.0)))) {
          overflow = true;
        } else {
          overflow = false;
        }

        if (!overflow) {
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);

    nb++;
    b->data[nb - 1] = x;
    c_st.site = &rc_emlrtRSI;
    overflow = ((na + 1 <= nMInf) && (nMInf > 2147483646));
    if (overflow) {
      d_st.site = &t_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
  }

  if (nInf > 0) {
    nb++;
    b->data[nb - 1] = b->data[khi];
    c_st.site = &sc_emlrtRSI;
    if (nInf > 2147483646) {
      d_st.site = &t_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
  }

  nMInf = khi + nInf;
  c_st.site = &tc_emlrtRSI;
  overflow = ((1 <= nNaN) && (nNaN > 2147483646));
  if (overflow) {
    d_st.site = &t_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (khi = 0; khi < nNaN; khi++) {
    nb++;
    b->data[nb - 1] = b->data[nMInf + khi];
  }

  if (nb > A->size[0]) {
    emlrtErrorWithMessageIdR2018a(&b_st, &ac_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (1 > nb) {
    nb = 0;
  }

  iv3[0] = 1;
  iv3[1] = nb;
  c_st.site = &uc_emlrtRSI;
  indexShapeCheck(&c_st, b->size[0], iv3);
  nMInf = b->size[0];
  b->size[0] = nb;
  emxEnsureCapacity_real_T(&b_st, b, nMInf, &p_emlrtRTEI);
  c_st.site = &vc_emlrtRSI;
  nMInf = uniqueVals->size[0] * uniqueVals->size[1];
  uniqueVals->size[0] = 1;
  uniqueVals->size[1] = b->size[0];
  emxEnsureCapacity_real_T(sp, uniqueVals, nMInf, &q_emlrtRTEI);
  khi = b->size[0];
  for (nMInf = 0; nMInf < khi; nMInf++) {
    uniqueVals->data[nMInf] = b->data[nMInf];
  }

  emxFree_real_T(&b);
  na = uniqueVals->size[1];
  khi = uniqueVals->size[0] * uniqueVals->size[1];
  for (nMInf = 0; nMInf < khi; nMInf++) {
    tmp_data[nMInf] = muDoubleScalarIsInf(uniqueVals->data[nMInf]);
  }

  nInf = uniqueVals->size[1];
  khi = uniqueVals->size[0] * uniqueVals->size[1];
  for (nMInf = 0; nMInf < khi; nMInf++) {
    b_tmp_data[nMInf] = muDoubleScalarIsNaN(uniqueVals->data[nMInf]);
  }

  iv3[0] = 1;
  iv4[0] = 1;
  iv3[1] = na;
  iv4[1] = nInf;
  if (na != nInf) {
    emlrtSizeEqCheckNDR2012b(&iv3[0], &iv4[0], &emlrtECI, sp);
  }

  tmp_size[0] = 1;
  tmp_size[1] = na;
  for (nMInf = 0; nMInf < na; nMInf++) {
    c_tmp_data[nMInf] = (tmp_data[nMInf] || b_tmp_data[nMInf]);
  }

  st.site = &lc_emlrtRSI;
  nullAssignment(&st, uniqueVals, c_tmp_data, tmp_size);
  *isDegenerate = (uniqueVals->size[1] <= N);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void getDegenerateThresholds(const emlrtStack *sp, const emxArray_real_T *
  uniqueVals, emxArray_real_T *thresh)
{
  int32_T i1;
  int32_T loop_ub;
  if (uniqueVals->size[1] == 0) {
    i1 = thresh->size[0] * thresh->size[1];
    thresh->size[0] = 1;
    thresh->size[1] = 1;
    emxEnsureCapacity_real_T(sp, thresh, i1, &j_emlrtRTEI);
    thresh->data[0] = 1.0;
  } else {
    i1 = thresh->size[0] * thresh->size[1];
    thresh->size[0] = 1;
    thresh->size[1] = uniqueVals->size[1];
    emxEnsureCapacity_real_T(sp, thresh, i1, &i_emlrtRTEI);
    loop_ub = uniqueVals->size[0] * uniqueVals->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      thresh->data[i1] = uniqueVals->data[i1];
    }
  }
}

static void getThreshForNoPdf(const emlrtStack *sp, real_T minA, real_T maxA,
  emxArray_real_T *thresh)
{
  int32_T i6;
  real_T threshL_data[2];
  real_T threshCandidate;
  int32_T q;
  emxArray_real_T *x;
  boolean_T b_x;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  if (muDoubleScalarIsNaN(minA)) {
    minA = 1.0;
    maxA = 1.0;
  }

  if (minA == maxA) {
    st.site = &jd_emlrtRSI;
    if (minA > 1.0) {
      threshL_data[0] = 1.0;
      threshL_data[1] = minA;
      i6 = thresh->size[0] * thresh->size[1];
      thresh->size[0] = 1;
      thresh->size[1] = 2;
      emxEnsureCapacity_real_T(&st, thresh, i6, &jb_emlrtRTEI);
      for (i6 = 0; i6 < 2; i6++) {
        thresh->data[i6] = threshL_data[i6];
      }
    } else {
      threshL_data[0] = minA;
      i6 = thresh->size[0] * thresh->size[1];
      thresh->size[0] = 1;
      thresh->size[1] = 2;
      emxEnsureCapacity_real_T(&st, thresh, i6, &jb_emlrtRTEI);
      for (i6 = 0; i6 < 1; i6++) {
        thresh->data[i6] = threshL_data[i6];
      }

      thresh->data[1] = 0.0;
      threshCandidate = muDoubleScalarMax(muDoubleScalarFloor(minA), 0.0);
      q = 1;
      while (q <= 1) {
        threshCandidate++;
        b_st.site = &p_emlrtRSI;
        b_x = (muDoubleScalarAbs(minA - threshCandidate) < eps(threshCandidate));
        if (!b_x) {
          i6 = thresh->size[1];
          if (2 > i6) {
            emlrtDynamicBoundsCheckR2012b(2, 1, i6, &n_emlrtBCI, &st);
          }

          thresh->data[1] = threshCandidate;
          q = 2;
        }
      }

      emxInit_real_T(&st, &x, 2, &lb_emlrtRTEI, true);
      b_st.site = &q_emlrtRSI;
      i6 = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = thresh->size[1];
      emxEnsureCapacity_real_T(&b_st, x, i6, &kb_emlrtRTEI);
      q = thresh->size[0] * thresh->size[1];
      for (i6 = 0; i6 < q; i6++) {
        x->data[i6] = thresh->data[i6];
      }

      c_st.site = &w_emlrtRSI;
      sort(&c_st, x);
      i6 = thresh->size[0] * thresh->size[1];
      thresh->size[0] = 1;
      thresh->size[1] = x->size[1];
      emxEnsureCapacity_real_T(&st, thresh, i6, &jb_emlrtRTEI);
      q = x->size[0] * x->size[1];
      for (i6 = 0; i6 < q; i6++) {
        thresh->data[i6] = x->data[i6];
      }

      emxFree_real_T(&x);
    }
  } else {
    i6 = thresh->size[0] * thresh->size[1];
    thresh->size[0] = 1;
    thresh->size[1] = 2;
    emxEnsureCapacity_real_T(sp, thresh, i6, &ib_emlrtRTEI);
    thresh->data[0] = minA;
    thresh->data[1] = maxA;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void getpdf(const emlrtStack *sp, emxArray_real_T *A, real_T p[256],
                   real_T *minA, real_T *maxA, boolean_T *emptyp)
{
  int32_T idx;
  boolean_T exitg1;
  int32_T i2;
  int32_T n;
  int32_T a;
  int32_T k;
  real_T b_maxA;
  boolean_T nans_data[53008];
  emxArray_uint16_T *r3;
  emxArray_real_T *b_A;
  uint8_T Auint8_data[53008];
  int32_T Auint8_size[1];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  *emptyp = true;
  idx = 1;
  exitg1 = false;
  while ((!exitg1) && (idx <= A->size[0])) {
    i2 = A->size[0];
    if ((idx < 1) || (idx > i2)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, i2, &d_emlrtBCI, sp);
    }

    if (!b_isfinite(A->data[idx - 1])) {
      idx++;
    } else {
      exitg1 = true;
    }
  }

  if (idx <= A->size[0]) {
    i2 = A->size[0];
    if ((idx < 1) || (idx > i2)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, i2, &e_emlrtBCI, sp);
    }

    *minA = A->data[idx - 1];
    i2 = A->size[0];
    if (idx > i2) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, i2, &f_emlrtBCI, sp);
    }

    *maxA = A->data[idx - 1];
    a = idx + 1;
    idx = A->size[0];
    for (k = a; k <= idx; k++) {
      i2 = A->size[0];
      if ((k < 1) || (k > i2)) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i2, &b_emlrtBCI, sp);
      }

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
      emxEnsureCapacity_real_T(sp, A, i2, &l_emlrtRTEI);
      idx = A->size[0];
      for (i2 = 0; i2 < idx; i2++) {
        A->data[i2] = (A->data[i2] - *minA) / b_maxA;
      }

      n = A->size[0];
      idx = A->size[0];
      for (i2 = 0; i2 < idx; i2++) {
        nans_data[i2] = muDoubleScalarIsNaN(A->data[i2]);
      }

      a = (uint16_T)n;
      for (k = 0; k < a; k++) {
        if (!nans_data[k]) {
          i2 = A->size[0];
          idx = k + 1;
          if (idx > i2) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, i2, &c_emlrtBCI, sp);
          }
        }
      }

      a = (uint16_T)n;
      idx = 0;
      for (k = 0; k < a; k++) {
        if (!nans_data[k]) {
          idx++;
        }
      }

      if (idx != 0) {
        a = (uint16_T)n - 1;
        idx = 0;
        for (k = 0; k <= a; k++) {
          if (!nans_data[k]) {
            idx++;
          }
        }

        emxInit_uint16_T(sp, &r3, 1, &m_emlrtRTEI, true);
        i2 = r3->size[0];
        r3->size[0] = idx;
        emxEnsureCapacity_uint16_T(sp, r3, i2, &m_emlrtRTEI);
        idx = 0;
        for (k = 0; k <= a; k++) {
          if (!nans_data[k]) {
            r3->data[idx] = (uint16_T)(k + 1);
            idx++;
          }
        }

        emxInit_real_T(sp, &b_A, 1, &n_emlrtRTEI, true);
        i2 = b_A->size[0];
        b_A->size[0] = r3->size[0];
        emxEnsureCapacity_real_T(sp, b_A, i2, &n_emlrtRTEI);
        idx = r3->size[0];
        for (i2 = 0; i2 < idx; i2++) {
          b_A->data[i2] = A->data[r3->data[i2] - 1];
        }

        emxFree_uint16_T(&r3);
        im2uint8(b_A, Auint8_data, Auint8_size);
        st.site = &vb_emlrtRSI;
        imhist(&st, Auint8_data, Auint8_size, p);
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
      } else if ((A->data[0] > A->data[1]) || (muDoubleScalarIsNaN(A->data[0]) &&
                  (!muDoubleScalarIsNaN(A->data[1])))) {
        *minA = A->data[1];
      } else {
        *minA = A->data[0];
      }
    } else {
      if (!muDoubleScalarIsNaN(A->data[0])) {
        idx = 1;
      } else {
        idx = 0;
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= A->size[0])) {
          if (!muDoubleScalarIsNaN(A->data[k - 1])) {
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
        a = idx + 1;
        for (k = a; k <= n; k++) {
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
      } else if ((A->data[0] < A->data[1]) || (muDoubleScalarIsNaN(A->data[0]) &&
                  (!muDoubleScalarIsNaN(A->data[1])))) {
        *maxA = A->data[1];
      } else {
        *maxA = A->data[0];
      }
    } else {
      if (!muDoubleScalarIsNaN(A->data[0])) {
        idx = 1;
      } else {
        idx = 0;
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= A->size[0])) {
          if (!muDoubleScalarIsNaN(A->data[k - 1])) {
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
        a = idx + 1;
        for (k = a; k <= n; k++) {
          if (*maxA < A->data[k - 1]) {
            *maxA = A->data[k - 1];
          }
        }
      }
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void b_multithresh(scalarsthresholdsStackData *SD, const emlrtStack *sp, const
                   emxArray_real_T *varargin_1, real_T thresh[2])
{
  emxArray_real_T *threshRaw;
  emxArray_real_T *b_varargin_1;
  int32_T i4;
  int32_T varargin_1_size[2];
  emxArray_real_T varargin_1_data;
  int32_T idx;
  real_T p[256];
  real_T minA;
  real_T maxA;
  boolean_T emptyp;
  real_T omega[256];
  emxArray_real_T *r4;
  int32_T k;
  real_T mu[256];
  boolean_T exitg1;
  real_T maxval;
  emxArray_real_T *uniqueVals;
  real_T d1;
  emxArray_int32_T *ii;
  emxArray_int32_T *jj;
  emxArray_real_T *b_ii;
  real_T dv0[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &threshRaw, 2, &e_emlrtRTEI, true);
  if (varargin_1->size[0] == 0) {
    st.site = &c_emlrtRSI;
    warning(&st, 2.0);
    varargin_1_size[0] = 1;
    varargin_1_size[1] = 0;
    varargin_1_data.size = &varargin_1_size[0];
    varargin_1_data.allocatedSize = 0;
    varargin_1_data.numDimensions = 2;
    varargin_1_data.canFreeData = false;
    st.site = &d_emlrtRSI;
    b_getDegenerateThresholds(&st, &varargin_1_data, threshRaw);
    thresh[0] = threshRaw->data[0];
    thresh[1] = threshRaw->data[1];
  } else {
    emxInit_real_T(sp, &b_varargin_1, 1, &d_emlrtRTEI, true);
    i4 = b_varargin_1->size[0];
    b_varargin_1->size[0] = varargin_1->size[0];
    emxEnsureCapacity_real_T(sp, b_varargin_1, i4, &d_emlrtRTEI);
    idx = varargin_1->size[0];
    for (i4 = 0; i4 < idx; i4++) {
      b_varargin_1->data[i4] = varargin_1->data[i4];
    }

    st.site = &e_emlrtRSI;
    getpdf(&st, b_varargin_1, p, &minA, &maxA, &emptyp);
    emxFree_real_T(&b_varargin_1);
    if (emptyp) {
      emxInit_real_T(sp, &r4, 2, &bb_emlrtRTEI, true);
      st.site = &f_emlrtRSI;
      warning(&st, 2.0);
      st.site = &gd_emlrtRSI;
      getThreshForNoPdf(&st, minA, maxA, r4);
      i4 = threshRaw->size[0] * threshRaw->size[1];
      threshRaw->size[0] = 1;
      threshRaw->size[1] = r4->size[1];
      emxEnsureCapacity_real_T(sp, threshRaw, i4, &v_emlrtRTEI);
      idx = r4->size[0] * r4->size[1];
      for (i4 = 0; i4 < idx; i4++) {
        threshRaw->data[i4] = r4->data[i4];
      }

      emxFree_real_T(&r4);
      i4 = threshRaw->size[1];
      if (1 > i4) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i4, &l_emlrtBCI, sp);
      }

      thresh[0] = threshRaw->data[0];
      i4 = threshRaw->size[1];
      if (2 > i4) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i4, &l_emlrtBCI, sp);
      }

      thresh[1] = threshRaw->data[1];
    } else {
      memcpy(&omega[0], &p[0], sizeof(real_T) << 8);
      for (k = 0; k < 255; k++) {
        omega[k + 1] += omega[k];
      }

      for (i4 = 0; i4 < 256; i4++) {
        mu[i4] = p[i4] * (1.0 + (real_T)i4);
      }

      for (k = 0; k < 255; k++) {
        mu[k + 1] += mu[k];
      }

      b_calcFullObjCriteriaMatrix(SD, omega, mu, mu[255], SD->f1.sigma_b_squared);
      if (!muDoubleScalarIsNaN(SD->f1.sigma_b_squared[0])) {
        idx = 1;
      } else {
        idx = 0;
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k < 65537)) {
          if (!muDoubleScalarIsNaN(SD->f1.sigma_b_squared[k - 1])) {
            idx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }

      if (idx == 0) {
        maxval = SD->f1.sigma_b_squared[0];
      } else {
        maxval = SD->f1.sigma_b_squared[idx - 1];
        i4 = idx + 1;
        for (k = i4; k < 65537; k++) {
          d1 = SD->f1.sigma_b_squared[k - 1];
          if (maxval < d1) {
            maxval = d1;
          }
        }
      }

      emxInit_real_T(sp, &uniqueVals, 2, &h_emlrtRTEI, true);
      if (b_isfinite(maxval)) {
        st.site = &hd_emlrtRSI;
        for (i4 = 0; i4 < 65536; i4++) {
          SD->f1.b_sigma_b_squared[i4] = (SD->f1.sigma_b_squared[i4] == maxval);
        }

        emxInit_int32_T(&st, &ii, 1, &y_emlrtRTEI, true);
        emxInit_int32_T(&st, &jj, 1, &ab_emlrtRTEI, true);
        b_st.site = &kd_emlrtRSI;
        eml_find(&b_st, SD->f1.b_sigma_b_squared, ii, jj);
        st.site = &id_emlrtRSI;
        b_st.site = &pd_emlrtRSI;
        c_st.site = &qd_emlrtRSI;
        emptyp = true;
        if (jj->size[0] != ii->size[0]) {
          emptyp = false;
        }

        if (!emptyp) {
          emlrtErrorWithMessageIdR2018a(&c_st, &cc_emlrtRTEI,
            "MATLAB:catenate:matrixDimensionMismatch",
            "MATLAB:catenate:matrixDimensionMismatch", 0);
        }

        emxInit_real_T(&c_st, &b_ii, 2, &w_emlrtRTEI, true);
        i4 = b_ii->size[0] * b_ii->size[1];
        b_ii->size[0] = ii->size[0];
        b_ii->size[1] = 2;
        emxEnsureCapacity_real_T(sp, b_ii, i4, &w_emlrtRTEI);
        idx = ii->size[0];
        for (i4 = 0; i4 < idx; i4++) {
          b_ii->data[i4] = ii->data[i4];
        }

        emxFree_int32_T(&ii);
        idx = jj->size[0];
        for (i4 = 0; i4 < idx; i4++) {
          b_ii->data[i4 + b_ii->size[0]] = jj->data[i4];
        }

        emxFree_int32_T(&jj);
        mean(b_ii, dv0);
        i4 = threshRaw->size[0] * threshRaw->size[1];
        threshRaw->size[0] = 1;
        threshRaw->size[1] = 2;
        emxEnsureCapacity_real_T(sp, threshRaw, i4, &x_emlrtRTEI);
        emxFree_real_T(&b_ii);
        threshRaw->data[0] = dv0[0] - 1.0;
        threshRaw->data[1] = dv0[1] - 1.0;
        maxA -= minA;
        i4 = threshRaw->size[0] * threshRaw->size[1];
        idx = threshRaw->size[0] * threshRaw->size[1];
        threshRaw->size[0] = 1;
        emxEnsureCapacity_real_T(sp, threshRaw, idx, &f_emlrtRTEI);
        idx = i4 - 1;
        for (i4 = 0; i4 <= idx; i4++) {
          threshRaw->data[i4] = minA + threshRaw->data[i4] / 255.0 * maxA;
        }
      } else {
        st.site = &g_emlrtRSI;
        checkForDegenerateInput(&st, varargin_1, 2.0, &emptyp, uniqueVals);
        if (emptyp) {
          st.site = &h_emlrtRSI;
          warning(&st, 2.0);
        } else {
          st.site = &i_emlrtRSI;
          b_warning(&st);
        }

        st.site = &j_emlrtRSI;
        b_getDegenerateThresholds(&st, uniqueVals, threshRaw);
        st.site = &k_emlrtRSI;
        checkForDegenerateInput(&st, varargin_1, 2.0, &emptyp, uniqueVals);
        if (emptyp) {
          st.site = &l_emlrtRSI;
          warning(&st, 2.0);
          st.site = &m_emlrtRSI;
          b_getDegenerateThresholds(&st, uniqueVals, threshRaw);
        } else {
          st.site = &n_emlrtRSI;
          b_warning(&st);
          maxA -= minA;
          i4 = threshRaw->size[0] * threshRaw->size[1];
          idx = threshRaw->size[0] * threshRaw->size[1];
          threshRaw->size[0] = 1;
          emxEnsureCapacity_real_T(sp, threshRaw, idx, &g_emlrtRTEI);
          idx = i4 - 1;
          for (i4 = 0; i4 <= idx; i4++) {
            threshRaw->data[i4] = minA + threshRaw->data[i4] / 255.0 * maxA;
          }
        }
      }

      emxFree_real_T(&uniqueVals);
      i4 = threshRaw->size[1];
      if (1 > i4) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i4, &m_emlrtBCI, sp);
      }

      thresh[0] = threshRaw->data[0];
      i4 = threshRaw->size[1];
      if (2 > i4) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i4, &m_emlrtBCI, sp);
      }

      thresh[1] = threshRaw->data[1];
    }
  }

  emxFree_real_T(&threshRaw);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

real_T multithresh(const emlrtStack *sp, const emxArray_real_T *varargin_1)
{
  real_T thresh;
  emxArray_real_T *b_varargin_1;
  emxArray_real_T *sd_emlrtRSI;
  int32_T i0;
  int32_T varargin_1_size[2];
  int32_T idx;
  emxArray_real_T varargin_1_data;
  real_T sigma_b_squared[256];
  real_T maxA;
  boolean_T emptyp;
  real_T omega[256];
  int32_T k;
  real_T mu[256];
  boolean_T exitg1;
  real_T maxval;
  emxArray_real_T *threshRaw;
  emxArray_real_T *uniqueVals;
  real_T idxSum;
  real_T idxNum;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  if (varargin_1->size[0] == 0) {
    emxInit_real_T(sp, &sd_emlrtRSI, 2, &h_emlrtRTEI, true);
    st.site = &c_emlrtRSI;
    warning(&st, 1.0);
    varargin_1_size[0] = 1;
    varargin_1_size[1] = 0;
    varargin_1_data.size = &varargin_1_size[0];
    varargin_1_data.allocatedSize = 0;
    varargin_1_data.numDimensions = 2;
    varargin_1_data.canFreeData = false;
    st.site = &d_emlrtRSI;
    getDegenerateThresholds(&st, &varargin_1_data, sd_emlrtRSI);
    thresh = 1.0;
    emxFree_real_T(&sd_emlrtRSI);
  } else {
    emxInit_real_T(sp, &b_varargin_1, 1, &d_emlrtRTEI, true);
    i0 = b_varargin_1->size[0];
    b_varargin_1->size[0] = varargin_1->size[0];
    emxEnsureCapacity_real_T(sp, b_varargin_1, i0, &d_emlrtRTEI);
    idx = varargin_1->size[0];
    for (i0 = 0; i0 < idx; i0++) {
      b_varargin_1->data[i0] = varargin_1->data[i0];
    }

    st.site = &e_emlrtRSI;
    getpdf(&st, b_varargin_1, sigma_b_squared, &thresh, &maxA, &emptyp);
    emxFree_real_T(&b_varargin_1);
    if (emptyp) {
      st.site = &f_emlrtRSI;
      warning(&st, 1.0);
      if (muDoubleScalarIsNaN(thresh)) {
        thresh = 1.0;
      }
    } else {
      memcpy(&omega[0], &sigma_b_squared[0], sizeof(real_T) << 8);
      for (k = 0; k < 255; k++) {
        omega[k + 1] += omega[k];
      }

      for (i0 = 0; i0 < 256; i0++) {
        mu[i0] = sigma_b_squared[i0] * (1.0 + (real_T)i0);
      }

      for (k = 0; k < 255; k++) {
        mu[k + 1] += mu[k];
      }

      calcFullObjCriteriaMatrix(omega, mu, mu[255], sigma_b_squared);
      if (!muDoubleScalarIsNaN(sigma_b_squared[0])) {
        idx = 1;
      } else {
        idx = 0;
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k < 257)) {
          if (!muDoubleScalarIsNaN(sigma_b_squared[k - 1])) {
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

      emxInit_real_T(sp, &threshRaw, 2, &e_emlrtRTEI, true);
      emxInit_real_T(sp, &uniqueVals, 2, &h_emlrtRTEI, true);
      if (b_isfinite(maxval)) {
        idxSum = 0.0;
        idxNum = 0.0;
        for (idx = 0; idx < 256; idx++) {
          if (sigma_b_squared[idx] == maxval) {
            idxSum += 1.0 + (real_T)idx;
            idxNum++;
          }
        }

        i0 = threshRaw->size[0] * threshRaw->size[1];
        threshRaw->size[0] = 1;
        threshRaw->size[1] = 1;
        emxEnsureCapacity_real_T(sp, threshRaw, i0, &e_emlrtRTEI);
        threshRaw->data[0] = idxSum / idxNum - 1.0;
        idxSum = maxA - thresh;
        i0 = threshRaw->size[0] * threshRaw->size[1];
        idx = threshRaw->size[0] * threshRaw->size[1];
        threshRaw->size[0] = 1;
        emxEnsureCapacity_real_T(sp, threshRaw, idx, &f_emlrtRTEI);
        idx = i0 - 1;
        for (i0 = 0; i0 <= idx; i0++) {
          threshRaw->data[i0] = thresh + threshRaw->data[i0] / 255.0 * idxSum;
        }
      } else {
        st.site = &g_emlrtRSI;
        checkForDegenerateInput(&st, varargin_1, 1.0, &emptyp, uniqueVals);
        if (emptyp) {
          st.site = &h_emlrtRSI;
          warning(&st, 1.0);
        } else {
          st.site = &i_emlrtRSI;
          b_warning(&st);
        }

        st.site = &j_emlrtRSI;
        getDegenerateThresholds(&st, uniqueVals, threshRaw);
        st.site = &k_emlrtRSI;
        checkForDegenerateInput(&st, varargin_1, 1.0, &emptyp, uniqueVals);
        if (emptyp) {
          st.site = &l_emlrtRSI;
          warning(&st, 1.0);
          st.site = &m_emlrtRSI;
          getDegenerateThresholds(&st, uniqueVals, threshRaw);
        } else {
          st.site = &n_emlrtRSI;
          b_warning(&st);
          idxSum = maxA - thresh;
          i0 = threshRaw->size[0] * threshRaw->size[1];
          idx = threshRaw->size[0] * threshRaw->size[1];
          threshRaw->size[0] = 1;
          emxEnsureCapacity_real_T(sp, threshRaw, idx, &g_emlrtRTEI);
          idx = i0 - 1;
          for (i0 = 0; i0 <= idx; i0++) {
            threshRaw->data[i0] = thresh + threshRaw->data[i0] / 255.0 * idxSum;
          }
        }
      }

      emxFree_real_T(&uniqueVals);
      i0 = threshRaw->size[1];
      if (1 > i0) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i0, &emlrtBCI, sp);
      }

      thresh = threshRaw->data[0];
      emxFree_real_T(&threshRaw);
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return thresh;
}

/* End of code generation (multithresh.c) */
