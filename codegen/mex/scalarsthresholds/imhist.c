/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imhist.c
 *
 * Code generation for function 'imhist'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "imhist.h"
#include "libmwgetnumcores.h"

/* Variable Definitions */
static emlrtRSInfo hc_emlrtRSI = { 121,/* lineNo */
  "imhist",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/imhist.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 191,/* lineNo */
  "imhist",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/imhist.m"/* pathName */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  796,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  784,                                 /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  783,                                 /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  782,                                 /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  781,                                 /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void imhist(const emlrtStack *sp, const uint8_T varargin_1_data[], const int32_T
            varargin_1_size[1], real_T yout[256])
{
  real_T out;
  real_T localBins1[256];
  real_T localBins2[256];
  real_T localBins3[256];
  int32_T i;
  int32_T yout_tmp;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &hc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  out = 1.0;
  getnumcores(&out);
  b_st.site = &ic_emlrtRSI;
  memset(&yout[0], 0, sizeof(real_T) << 8);
  memset(&localBins1[0], 0, sizeof(real_T) << 8);
  memset(&localBins2[0], 0, sizeof(real_T) << 8);
  memset(&localBins3[0], 0, sizeof(real_T) << 8);
  for (i = 1; i + 3 <= varargin_1_size[0]; i += 4) {
    if ((i < 1) || (i > varargin_1_size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, varargin_1_size[0], &k_emlrtBCI, &b_st);
    }

    yout_tmp = i + 1;
    if ((yout_tmp < 1) || (yout_tmp > varargin_1_size[0])) {
      emlrtDynamicBoundsCheckR2012b(yout_tmp, 1, varargin_1_size[0], &j_emlrtBCI,
        &b_st);
    }

    yout_tmp = i + 2;
    if ((yout_tmp < 1) || (yout_tmp > varargin_1_size[0])) {
      emlrtDynamicBoundsCheckR2012b(yout_tmp, 1, varargin_1_size[0], &i_emlrtBCI,
        &b_st);
    }

    yout_tmp = i + 3;
    if ((yout_tmp < 1) || (yout_tmp > varargin_1_size[0])) {
      emlrtDynamicBoundsCheckR2012b(yout_tmp, 1, varargin_1_size[0], &h_emlrtBCI,
        &b_st);
    }

    yout_tmp = varargin_1_data[i - 1];
    localBins1[yout_tmp]++;
    localBins2[varargin_1_data[i]]++;
    yout_tmp = varargin_1_data[i + 1];
    localBins3[yout_tmp]++;
    yout_tmp = varargin_1_data[i + 2];
    yout[yout_tmp]++;
  }

  while (i <= varargin_1_size[0]) {
    if ((i < 1) || (i > varargin_1_size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, varargin_1_size[0], &g_emlrtBCI, &b_st);
    }

    yout_tmp = varargin_1_data[i - 1];
    yout[yout_tmp]++;
    i++;
  }

  for (i = 0; i < 256; i++) {
    yout[i] = ((yout[i] + localBins1[i]) + localBins2[i]) + localBins3[i];
  }
}

/* End of code generation (imhist.c) */
