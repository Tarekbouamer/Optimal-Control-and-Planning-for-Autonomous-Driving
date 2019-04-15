#ifndef __c3_finding_drag_h__
#define __c3_finding_drag_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_snXp3ygPcVyeDzfVLtVbyQF
#define struct_snXp3ygPcVyeDzfVLtVbyQF

struct snXp3ygPcVyeDzfVLtVbyQF
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
};

#endif                                 /*struct_snXp3ygPcVyeDzfVLtVbyQF*/

#ifndef typedef_c3_snXp3ygPcVyeDzfVLtVbyQF
#define typedef_c3_snXp3ygPcVyeDzfVLtVbyQF

typedef struct snXp3ygPcVyeDzfVLtVbyQF c3_snXp3ygPcVyeDzfVLtVbyQF;

#endif                                 /*typedef_c3_snXp3ygPcVyeDzfVLtVbyQF*/

#ifndef typedef_SFc3_finding_dragInstanceStruct
#define typedef_SFc3_finding_dragInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_isStable;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_finding_drag;
  c3_snXp3ygPcVyeDzfVLtVbyQF c3_params;
} SFc3_finding_dragInstanceStruct;

#endif                                 /*typedef_SFc3_finding_dragInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_finding_drag_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_finding_drag_get_check_sum(mxArray *plhs[]);
extern void c3_finding_drag_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
