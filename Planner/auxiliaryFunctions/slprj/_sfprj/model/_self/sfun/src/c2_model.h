#ifndef __c2_model_h__
#define __c2_model_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_sTXaXgTBgcsTeEwtC20RoaB
#define struct_sTXaXgTBgcsTeEwtC20RoaB

struct sTXaXgTBgcsTeEwtC20RoaB
{
  real_T m;
  real_T Iz;
  real_T Iw;
  real_T lF;
  real_T lR;
  real_T h;
  real_T R;
  real_T B;
  real_T C;
  real_T maxDelta;
  real_T maxTb;
  real_T maxThb;
  real_T maxTm;
  real_T gammaB;
  real_T gammaM;
  real_T g;
  real_T mu;
  real_T muRoll;
  real_T b;
  real_T fric;
  real_T FzF;
  real_T FzR;
  real_T Dz1;
  real_T Dz2;
  real_T T;
  real_T WF0;
  real_T WR0;
  real_T Ux0;
  real_T Uy0;
  real_T r0;
  real_T x0;
  real_T _y0;
  real_T ksi0;
  real_T Press2TorF;
  real_T Press2TorR;
  real_T maxPress;
  real_T press2torF;
  real_T press2torR;
};

#endif                                 /*struct_sTXaXgTBgcsTeEwtC20RoaB*/

#ifndef typedef_c2_sTXaXgTBgcsTeEwtC20RoaB
#define typedef_c2_sTXaXgTBgcsTeEwtC20RoaB

typedef struct sTXaXgTBgcsTeEwtC20RoaB c2_sTXaXgTBgcsTeEwtC20RoaB;

#endif                                 /*typedef_c2_sTXaXgTBgcsTeEwtC20RoaB*/

#ifndef typedef_SFc2_modelInstanceStruct
#define typedef_SFc2_modelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_model;
  c2_sTXaXgTBgcsTeEwtC20RoaB c2_params;
} SFc2_modelInstanceStruct;

#endif                                 /*typedef_SFc2_modelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_model_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_model_get_check_sum(mxArray *plhs[]);
extern void c2_model_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
