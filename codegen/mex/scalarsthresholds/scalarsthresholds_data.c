/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * scalarsthresholds_data.c
 *
 * Code generation for function 'scalarsthresholds_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "scalarsthresholds.h"
#include "scalarsthresholds_data.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
covrtInstance emlrtCoverageInstance;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131467U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "scalarsthresholds",                 /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 1858410525U, 2505464270U, 328108647U, 1256672073U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo s_emlrtRSI = { 74,         /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pathName */
};

emlrtRSInfo t_emlrtRSI = { 21,         /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

emlrtRSInfo u_emlrtRSI = { 12,         /* lineNo */
  "any",                               /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/ops/any.m"/* pathName */
};

emlrtRSInfo v_emlrtRSI = { 146,        /* lineNo */
  "allOrAny",                          /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/allOrAny.m"/* pathName */
};

emlrtRSInfo ib_emlrtRSI = { 587,       /* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

emlrtRSInfo jb_emlrtRSI = { 589,       /* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

emlrtRSInfo kb_emlrtRSI = { 617,       /* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

emlrtRSInfo mb_emlrtRSI = { 506,       /* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

emlrtRSInfo rb_emlrtRSI = { 198,       /* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

emlrtRSInfo sb_emlrtRSI = { 216,       /* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

emlrtRSInfo tb_emlrtRSI = { 217,       /* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

emlrtRSInfo ub_emlrtRSI = { 384,       /* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

emlrtRSInfo wb_emlrtRSI = { 13,        /* lineNo */
  "min",                               /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/datafun/min.m"/* pathName */
};

emlrtRSInfo xb_emlrtRSI = { 19,        /* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

emlrtRSInfo yb_emlrtRSI = { 44,        /* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

emlrtRSInfo ac_emlrtRSI = { 114,       /* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

emlrtRSInfo bc_emlrtRSI = { 852,       /* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

emlrtRSInfo cc_emlrtRSI = { 910,       /* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

emlrtRSInfo dc_emlrtRSI = { 13,        /* lineNo */
  "max",                               /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/lib/matlab/datafun/max.m"/* pathName */
};

emlrtRSInfo ec_emlrtRSI = { 39,        /* lineNo */
  "im2uint8",                          /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/im2uint8.m"/* pathName */
};

emlrtRSInfo fc_emlrtRSI = { 138,       /* lineNo */
  "im2uint8",                          /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/im2uint8.m"/* pathName */
};

emlrtRSInfo gc_emlrtRSI = { 19,        /* lineNo */
  "grayto8",                           /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/private/grayto8.m"/* pathName */
};

emlrtRSInfo jc_emlrtRSI = { 154,       /* lineNo */
  "imhist",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/images/images/eml/imhist.m"/* pathName */
};

emlrtRSInfo xc_emlrtRSI = { 112,       /* lineNo */
  "mergesort",                         /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pathName */
};

emlrtRSInfo yc_emlrtRSI = { 31,        /* lineNo */
  "safeEq",                            /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/safeEq.m"/* pathName */
};

emlrtRSInfo dd_emlrtRSI = { 168,       /* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

emlrtRSInfo ed_emlrtRSI = { 171,       /* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

emlrtRSInfo fd_emlrtRSI = { 131,       /* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

emlrtRTEInfo yb_emlrtRTEI = { 46,      /* lineNo */
  19,                                  /* colNo */
  "allOrAny",                          /* fName */
  "/usr/local/MATLAB/R2018b/toolbox/eml/eml/+coder/+internal/allOrAny.m"/* pName */
};

/* End of code generation (scalarsthresholds_data.c) */
