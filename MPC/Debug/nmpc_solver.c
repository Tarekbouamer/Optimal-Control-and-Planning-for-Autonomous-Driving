/*
 *    This file was auto-generated using the ACADO Toolkit.
 *    
 *    While ACADO Toolkit is free software released under the terms of
 *    the GNU Lesser General Public License (LGPL), the generated code
 *    as such remains the property of the user who used ACADO Toolkit
 *    to generate this code. In particular, user dependent data of the code
 *    do not inherit the GNU LGPL license. On the other hand, parts of the
 *    generated code that are a direct copy of source code from the
 *    ACADO Toolkit or the software tools it is based on, remain, as derived
 *    work, automatically covered by the LGPL license.
 *    
 *    ACADO Toolkit is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *    
 */


#include "nmpc_common.h"




/******************************************************************************/
/*                                                                            */
/* ACADO code generation                                                      */
/*                                                                            */
/******************************************************************************/


int nmpc_modelSimulation(  )
{
int ret;

int lRun1;
ret = 0;
for (lRun1 = 0; lRun1 < 80; ++lRun1)
{
nmpcWorkspace.state[0] = nmpcVariables.x[lRun1 * 6];
nmpcWorkspace.state[1] = nmpcVariables.x[lRun1 * 6 + 1];
nmpcWorkspace.state[2] = nmpcVariables.x[lRun1 * 6 + 2];
nmpcWorkspace.state[3] = nmpcVariables.x[lRun1 * 6 + 3];
nmpcWorkspace.state[4] = nmpcVariables.x[lRun1 * 6 + 4];
nmpcWorkspace.state[5] = nmpcVariables.x[lRun1 * 6 + 5];

nmpcWorkspace.state[54] = nmpcVariables.u[lRun1 * 2];
nmpcWorkspace.state[55] = nmpcVariables.u[lRun1 * 2 + 1];

ret = nmpc_integrate(nmpcWorkspace.state, 1);

nmpcWorkspace.d[lRun1 * 6] = nmpcWorkspace.state[0] - nmpcVariables.x[lRun1 * 6 + 6];
nmpcWorkspace.d[lRun1 * 6 + 1] = nmpcWorkspace.state[1] - nmpcVariables.x[lRun1 * 6 + 7];
nmpcWorkspace.d[lRun1 * 6 + 2] = nmpcWorkspace.state[2] - nmpcVariables.x[lRun1 * 6 + 8];
nmpcWorkspace.d[lRun1 * 6 + 3] = nmpcWorkspace.state[3] - nmpcVariables.x[lRun1 * 6 + 9];
nmpcWorkspace.d[lRun1 * 6 + 4] = nmpcWorkspace.state[4] - nmpcVariables.x[lRun1 * 6 + 10];
nmpcWorkspace.d[lRun1 * 6 + 5] = nmpcWorkspace.state[5] - nmpcVariables.x[lRun1 * 6 + 11];

nmpcWorkspace.evGx[lRun1 * 36] = nmpcWorkspace.state[6];
nmpcWorkspace.evGx[lRun1 * 36 + 1] = nmpcWorkspace.state[7];
nmpcWorkspace.evGx[lRun1 * 36 + 2] = nmpcWorkspace.state[8];
nmpcWorkspace.evGx[lRun1 * 36 + 3] = nmpcWorkspace.state[9];
nmpcWorkspace.evGx[lRun1 * 36 + 4] = nmpcWorkspace.state[10];
nmpcWorkspace.evGx[lRun1 * 36 + 5] = nmpcWorkspace.state[11];
nmpcWorkspace.evGx[lRun1 * 36 + 6] = nmpcWorkspace.state[12];
nmpcWorkspace.evGx[lRun1 * 36 + 7] = nmpcWorkspace.state[13];
nmpcWorkspace.evGx[lRun1 * 36 + 8] = nmpcWorkspace.state[14];
nmpcWorkspace.evGx[lRun1 * 36 + 9] = nmpcWorkspace.state[15];
nmpcWorkspace.evGx[lRun1 * 36 + 10] = nmpcWorkspace.state[16];
nmpcWorkspace.evGx[lRun1 * 36 + 11] = nmpcWorkspace.state[17];
nmpcWorkspace.evGx[lRun1 * 36 + 12] = nmpcWorkspace.state[18];
nmpcWorkspace.evGx[lRun1 * 36 + 13] = nmpcWorkspace.state[19];
nmpcWorkspace.evGx[lRun1 * 36 + 14] = nmpcWorkspace.state[20];
nmpcWorkspace.evGx[lRun1 * 36 + 15] = nmpcWorkspace.state[21];
nmpcWorkspace.evGx[lRun1 * 36 + 16] = nmpcWorkspace.state[22];
nmpcWorkspace.evGx[lRun1 * 36 + 17] = nmpcWorkspace.state[23];
nmpcWorkspace.evGx[lRun1 * 36 + 18] = nmpcWorkspace.state[24];
nmpcWorkspace.evGx[lRun1 * 36 + 19] = nmpcWorkspace.state[25];
nmpcWorkspace.evGx[lRun1 * 36 + 20] = nmpcWorkspace.state[26];
nmpcWorkspace.evGx[lRun1 * 36 + 21] = nmpcWorkspace.state[27];
nmpcWorkspace.evGx[lRun1 * 36 + 22] = nmpcWorkspace.state[28];
nmpcWorkspace.evGx[lRun1 * 36 + 23] = nmpcWorkspace.state[29];
nmpcWorkspace.evGx[lRun1 * 36 + 24] = nmpcWorkspace.state[30];
nmpcWorkspace.evGx[lRun1 * 36 + 25] = nmpcWorkspace.state[31];
nmpcWorkspace.evGx[lRun1 * 36 + 26] = nmpcWorkspace.state[32];
nmpcWorkspace.evGx[lRun1 * 36 + 27] = nmpcWorkspace.state[33];
nmpcWorkspace.evGx[lRun1 * 36 + 28] = nmpcWorkspace.state[34];
nmpcWorkspace.evGx[lRun1 * 36 + 29] = nmpcWorkspace.state[35];
nmpcWorkspace.evGx[lRun1 * 36 + 30] = nmpcWorkspace.state[36];
nmpcWorkspace.evGx[lRun1 * 36 + 31] = nmpcWorkspace.state[37];
nmpcWorkspace.evGx[lRun1 * 36 + 32] = nmpcWorkspace.state[38];
nmpcWorkspace.evGx[lRun1 * 36 + 33] = nmpcWorkspace.state[39];
nmpcWorkspace.evGx[lRun1 * 36 + 34] = nmpcWorkspace.state[40];
nmpcWorkspace.evGx[lRun1 * 36 + 35] = nmpcWorkspace.state[41];

nmpcWorkspace.evGu[lRun1 * 12] = nmpcWorkspace.state[42];
nmpcWorkspace.evGu[lRun1 * 12 + 1] = nmpcWorkspace.state[43];
nmpcWorkspace.evGu[lRun1 * 12 + 2] = nmpcWorkspace.state[44];
nmpcWorkspace.evGu[lRun1 * 12 + 3] = nmpcWorkspace.state[45];
nmpcWorkspace.evGu[lRun1 * 12 + 4] = nmpcWorkspace.state[46];
nmpcWorkspace.evGu[lRun1 * 12 + 5] = nmpcWorkspace.state[47];
nmpcWorkspace.evGu[lRun1 * 12 + 6] = nmpcWorkspace.state[48];
nmpcWorkspace.evGu[lRun1 * 12 + 7] = nmpcWorkspace.state[49];
nmpcWorkspace.evGu[lRun1 * 12 + 8] = nmpcWorkspace.state[50];
nmpcWorkspace.evGu[lRun1 * 12 + 9] = nmpcWorkspace.state[51];
nmpcWorkspace.evGu[lRun1 * 12 + 10] = nmpcWorkspace.state[52];
nmpcWorkspace.evGu[lRun1 * 12 + 11] = nmpcWorkspace.state[53];
}
return ret;
}

void nmpc_evaluateLSQ(const real_t* in, real_t* out)
{
const real_t* xd = in;
const real_t* u = in + 6;

/* Compute outputs: */
out[0] = xd[0];
out[1] = xd[1];
out[2] = xd[2];
out[3] = xd[3];
out[4] = xd[4];
out[5] = xd[5];
out[6] = u[0];
out[7] = u[1];
}

void nmpc_evaluateLSQEndTerm(const real_t* in, real_t* out)
{
const real_t* xd = in;

/* Compute outputs: */
out[0] = xd[0];
out[1] = xd[1];
out[2] = xd[2];
out[3] = xd[3];
out[4] = xd[4];
out[5] = xd[5];
}

void nmpc_setObjQ1Q2( real_t* const tmpObjS, real_t* const tmpQ1, real_t* const tmpQ2 )
{
tmpQ2[0] = +tmpObjS[0];
tmpQ2[1] = +tmpObjS[1];
tmpQ2[2] = +tmpObjS[2];
tmpQ2[3] = +tmpObjS[3];
tmpQ2[4] = +tmpObjS[4];
tmpQ2[5] = +tmpObjS[5];
tmpQ2[6] = +tmpObjS[6];
tmpQ2[7] = +tmpObjS[7];
tmpQ2[8] = +tmpObjS[8];
tmpQ2[9] = +tmpObjS[9];
tmpQ2[10] = +tmpObjS[10];
tmpQ2[11] = +tmpObjS[11];
tmpQ2[12] = +tmpObjS[12];
tmpQ2[13] = +tmpObjS[13];
tmpQ2[14] = +tmpObjS[14];
tmpQ2[15] = +tmpObjS[15];
tmpQ2[16] = +tmpObjS[16];
tmpQ2[17] = +tmpObjS[17];
tmpQ2[18] = +tmpObjS[18];
tmpQ2[19] = +tmpObjS[19];
tmpQ2[20] = +tmpObjS[20];
tmpQ2[21] = +tmpObjS[21];
tmpQ2[22] = +tmpObjS[22];
tmpQ2[23] = +tmpObjS[23];
tmpQ2[24] = +tmpObjS[24];
tmpQ2[25] = +tmpObjS[25];
tmpQ2[26] = +tmpObjS[26];
tmpQ2[27] = +tmpObjS[27];
tmpQ2[28] = +tmpObjS[28];
tmpQ2[29] = +tmpObjS[29];
tmpQ2[30] = +tmpObjS[30];
tmpQ2[31] = +tmpObjS[31];
tmpQ2[32] = +tmpObjS[32];
tmpQ2[33] = +tmpObjS[33];
tmpQ2[34] = +tmpObjS[34];
tmpQ2[35] = +tmpObjS[35];
tmpQ2[36] = +tmpObjS[36];
tmpQ2[37] = +tmpObjS[37];
tmpQ2[38] = +tmpObjS[38];
tmpQ2[39] = +tmpObjS[39];
tmpQ2[40] = +tmpObjS[40];
tmpQ2[41] = +tmpObjS[41];
tmpQ2[42] = +tmpObjS[42];
tmpQ2[43] = +tmpObjS[43];
tmpQ2[44] = +tmpObjS[44];
tmpQ2[45] = +tmpObjS[45];
tmpQ2[46] = +tmpObjS[46];
tmpQ2[47] = +tmpObjS[47];
tmpQ1[0] = + tmpQ2[0];
tmpQ1[1] = + tmpQ2[1];
tmpQ1[2] = + tmpQ2[2];
tmpQ1[3] = + tmpQ2[3];
tmpQ1[4] = + tmpQ2[4];
tmpQ1[5] = + tmpQ2[5];
tmpQ1[6] = + tmpQ2[8];
tmpQ1[7] = + tmpQ2[9];
tmpQ1[8] = + tmpQ2[10];
tmpQ1[9] = + tmpQ2[11];
tmpQ1[10] = + tmpQ2[12];
tmpQ1[11] = + tmpQ2[13];
tmpQ1[12] = + tmpQ2[16];
tmpQ1[13] = + tmpQ2[17];
tmpQ1[14] = + tmpQ2[18];
tmpQ1[15] = + tmpQ2[19];
tmpQ1[16] = + tmpQ2[20];
tmpQ1[17] = + tmpQ2[21];
tmpQ1[18] = + tmpQ2[24];
tmpQ1[19] = + tmpQ2[25];
tmpQ1[20] = + tmpQ2[26];
tmpQ1[21] = + tmpQ2[27];
tmpQ1[22] = + tmpQ2[28];
tmpQ1[23] = + tmpQ2[29];
tmpQ1[24] = + tmpQ2[32];
tmpQ1[25] = + tmpQ2[33];
tmpQ1[26] = + tmpQ2[34];
tmpQ1[27] = + tmpQ2[35];
tmpQ1[28] = + tmpQ2[36];
tmpQ1[29] = + tmpQ2[37];
tmpQ1[30] = + tmpQ2[40];
tmpQ1[31] = + tmpQ2[41];
tmpQ1[32] = + tmpQ2[42];
tmpQ1[33] = + tmpQ2[43];
tmpQ1[34] = + tmpQ2[44];
tmpQ1[35] = + tmpQ2[45];
}

void nmpc_setObjR1R2( real_t* const tmpObjS, real_t* const tmpR1, real_t* const tmpR2 )
{
tmpR2[0] = +tmpObjS[48];
tmpR2[1] = +tmpObjS[49];
tmpR2[2] = +tmpObjS[50];
tmpR2[3] = +tmpObjS[51];
tmpR2[4] = +tmpObjS[52];
tmpR2[5] = +tmpObjS[53];
tmpR2[6] = +tmpObjS[54];
tmpR2[7] = +tmpObjS[55];
tmpR2[8] = +tmpObjS[56];
tmpR2[9] = +tmpObjS[57];
tmpR2[10] = +tmpObjS[58];
tmpR2[11] = +tmpObjS[59];
tmpR2[12] = +tmpObjS[60];
tmpR2[13] = +tmpObjS[61];
tmpR2[14] = +tmpObjS[62];
tmpR2[15] = +tmpObjS[63];
tmpR1[0] = + tmpR2[6];
tmpR1[1] = + tmpR2[7];
tmpR1[2] = + tmpR2[14];
tmpR1[3] = + tmpR2[15];
}

void nmpc_setObjQN1QN2( real_t* const tmpObjSEndTerm, real_t* const tmpQN1, real_t* const tmpQN2 )
{
tmpQN2[0] = +tmpObjSEndTerm[0];
tmpQN2[1] = +tmpObjSEndTerm[1];
tmpQN2[2] = +tmpObjSEndTerm[2];
tmpQN2[3] = +tmpObjSEndTerm[3];
tmpQN2[4] = +tmpObjSEndTerm[4];
tmpQN2[5] = +tmpObjSEndTerm[5];
tmpQN2[6] = +tmpObjSEndTerm[6];
tmpQN2[7] = +tmpObjSEndTerm[7];
tmpQN2[8] = +tmpObjSEndTerm[8];
tmpQN2[9] = +tmpObjSEndTerm[9];
tmpQN2[10] = +tmpObjSEndTerm[10];
tmpQN2[11] = +tmpObjSEndTerm[11];
tmpQN2[12] = +tmpObjSEndTerm[12];
tmpQN2[13] = +tmpObjSEndTerm[13];
tmpQN2[14] = +tmpObjSEndTerm[14];
tmpQN2[15] = +tmpObjSEndTerm[15];
tmpQN2[16] = +tmpObjSEndTerm[16];
tmpQN2[17] = +tmpObjSEndTerm[17];
tmpQN2[18] = +tmpObjSEndTerm[18];
tmpQN2[19] = +tmpObjSEndTerm[19];
tmpQN2[20] = +tmpObjSEndTerm[20];
tmpQN2[21] = +tmpObjSEndTerm[21];
tmpQN2[22] = +tmpObjSEndTerm[22];
tmpQN2[23] = +tmpObjSEndTerm[23];
tmpQN2[24] = +tmpObjSEndTerm[24];
tmpQN2[25] = +tmpObjSEndTerm[25];
tmpQN2[26] = +tmpObjSEndTerm[26];
tmpQN2[27] = +tmpObjSEndTerm[27];
tmpQN2[28] = +tmpObjSEndTerm[28];
tmpQN2[29] = +tmpObjSEndTerm[29];
tmpQN2[30] = +tmpObjSEndTerm[30];
tmpQN2[31] = +tmpObjSEndTerm[31];
tmpQN2[32] = +tmpObjSEndTerm[32];
tmpQN2[33] = +tmpObjSEndTerm[33];
tmpQN2[34] = +tmpObjSEndTerm[34];
tmpQN2[35] = +tmpObjSEndTerm[35];
tmpQN1[0] = + tmpQN2[0];
tmpQN1[1] = + tmpQN2[1];
tmpQN1[2] = + tmpQN2[2];
tmpQN1[3] = + tmpQN2[3];
tmpQN1[4] = + tmpQN2[4];
tmpQN1[5] = + tmpQN2[5];
tmpQN1[6] = + tmpQN2[6];
tmpQN1[7] = + tmpQN2[7];
tmpQN1[8] = + tmpQN2[8];
tmpQN1[9] = + tmpQN2[9];
tmpQN1[10] = + tmpQN2[10];
tmpQN1[11] = + tmpQN2[11];
tmpQN1[12] = + tmpQN2[12];
tmpQN1[13] = + tmpQN2[13];
tmpQN1[14] = + tmpQN2[14];
tmpQN1[15] = + tmpQN2[15];
tmpQN1[16] = + tmpQN2[16];
tmpQN1[17] = + tmpQN2[17];
tmpQN1[18] = + tmpQN2[18];
tmpQN1[19] = + tmpQN2[19];
tmpQN1[20] = + tmpQN2[20];
tmpQN1[21] = + tmpQN2[21];
tmpQN1[22] = + tmpQN2[22];
tmpQN1[23] = + tmpQN2[23];
tmpQN1[24] = + tmpQN2[24];
tmpQN1[25] = + tmpQN2[25];
tmpQN1[26] = + tmpQN2[26];
tmpQN1[27] = + tmpQN2[27];
tmpQN1[28] = + tmpQN2[28];
tmpQN1[29] = + tmpQN2[29];
tmpQN1[30] = + tmpQN2[30];
tmpQN1[31] = + tmpQN2[31];
tmpQN1[32] = + tmpQN2[32];
tmpQN1[33] = + tmpQN2[33];
tmpQN1[34] = + tmpQN2[34];
tmpQN1[35] = + tmpQN2[35];
}

void nmpc_evaluateObjective(  )
{
int runObj;
for (runObj = 0; runObj < 80; ++runObj)
{
nmpcWorkspace.objValueIn[0] = nmpcVariables.x[runObj * 6];
nmpcWorkspace.objValueIn[1] = nmpcVariables.x[runObj * 6 + 1];
nmpcWorkspace.objValueIn[2] = nmpcVariables.x[runObj * 6 + 2];
nmpcWorkspace.objValueIn[3] = nmpcVariables.x[runObj * 6 + 3];
nmpcWorkspace.objValueIn[4] = nmpcVariables.x[runObj * 6 + 4];
nmpcWorkspace.objValueIn[5] = nmpcVariables.x[runObj * 6 + 5];
nmpcWorkspace.objValueIn[6] = nmpcVariables.u[runObj * 2];
nmpcWorkspace.objValueIn[7] = nmpcVariables.u[runObj * 2 + 1];

nmpc_evaluateLSQ( nmpcWorkspace.objValueIn, nmpcWorkspace.objValueOut );
nmpcWorkspace.Dy[runObj * 8] = nmpcWorkspace.objValueOut[0];
nmpcWorkspace.Dy[runObj * 8 + 1] = nmpcWorkspace.objValueOut[1];
nmpcWorkspace.Dy[runObj * 8 + 2] = nmpcWorkspace.objValueOut[2];
nmpcWorkspace.Dy[runObj * 8 + 3] = nmpcWorkspace.objValueOut[3];
nmpcWorkspace.Dy[runObj * 8 + 4] = nmpcWorkspace.objValueOut[4];
nmpcWorkspace.Dy[runObj * 8 + 5] = nmpcWorkspace.objValueOut[5];
nmpcWorkspace.Dy[runObj * 8 + 6] = nmpcWorkspace.objValueOut[6];
nmpcWorkspace.Dy[runObj * 8 + 7] = nmpcWorkspace.objValueOut[7];

nmpc_setObjQ1Q2( nmpcVariables.W, &(nmpcWorkspace.Q1[ runObj * 36 ]), &(nmpcWorkspace.Q2[ runObj * 48 ]) );

nmpc_setObjR1R2( nmpcVariables.W, &(nmpcWorkspace.R1[ runObj * 4 ]), &(nmpcWorkspace.R2[ runObj * 16 ]) );

}
nmpcWorkspace.objValueIn[0] = nmpcVariables.x[480];
nmpcWorkspace.objValueIn[1] = nmpcVariables.x[481];
nmpcWorkspace.objValueIn[2] = nmpcVariables.x[482];
nmpcWorkspace.objValueIn[3] = nmpcVariables.x[483];
nmpcWorkspace.objValueIn[4] = nmpcVariables.x[484];
nmpcWorkspace.objValueIn[5] = nmpcVariables.x[485];
nmpc_evaluateLSQEndTerm( nmpcWorkspace.objValueIn, nmpcWorkspace.objValueOut );

nmpcWorkspace.DyN[0] = nmpcWorkspace.objValueOut[0];
nmpcWorkspace.DyN[1] = nmpcWorkspace.objValueOut[1];
nmpcWorkspace.DyN[2] = nmpcWorkspace.objValueOut[2];
nmpcWorkspace.DyN[3] = nmpcWorkspace.objValueOut[3];
nmpcWorkspace.DyN[4] = nmpcWorkspace.objValueOut[4];
nmpcWorkspace.DyN[5] = nmpcWorkspace.objValueOut[5];

nmpc_setObjQN1QN2( nmpcVariables.WN, nmpcWorkspace.QN1, nmpcWorkspace.QN2 );

}

void nmpc_multGxGu( real_t* const Gx1, real_t* const Gu1, real_t* const Gu2 )
{
Gu2[0] = + Gx1[0]*Gu1[0] + Gx1[1]*Gu1[2] + Gx1[2]*Gu1[4] + Gx1[3]*Gu1[6] + Gx1[4]*Gu1[8] + Gx1[5]*Gu1[10];
Gu2[1] = + Gx1[0]*Gu1[1] + Gx1[1]*Gu1[3] + Gx1[2]*Gu1[5] + Gx1[3]*Gu1[7] + Gx1[4]*Gu1[9] + Gx1[5]*Gu1[11];
Gu2[2] = + Gx1[6]*Gu1[0] + Gx1[7]*Gu1[2] + Gx1[8]*Gu1[4] + Gx1[9]*Gu1[6] + Gx1[10]*Gu1[8] + Gx1[11]*Gu1[10];
Gu2[3] = + Gx1[6]*Gu1[1] + Gx1[7]*Gu1[3] + Gx1[8]*Gu1[5] + Gx1[9]*Gu1[7] + Gx1[10]*Gu1[9] + Gx1[11]*Gu1[11];
Gu2[4] = + Gx1[12]*Gu1[0] + Gx1[13]*Gu1[2] + Gx1[14]*Gu1[4] + Gx1[15]*Gu1[6] + Gx1[16]*Gu1[8] + Gx1[17]*Gu1[10];
Gu2[5] = + Gx1[12]*Gu1[1] + Gx1[13]*Gu1[3] + Gx1[14]*Gu1[5] + Gx1[15]*Gu1[7] + Gx1[16]*Gu1[9] + Gx1[17]*Gu1[11];
Gu2[6] = + Gx1[18]*Gu1[0] + Gx1[19]*Gu1[2] + Gx1[20]*Gu1[4] + Gx1[21]*Gu1[6] + Gx1[22]*Gu1[8] + Gx1[23]*Gu1[10];
Gu2[7] = + Gx1[18]*Gu1[1] + Gx1[19]*Gu1[3] + Gx1[20]*Gu1[5] + Gx1[21]*Gu1[7] + Gx1[22]*Gu1[9] + Gx1[23]*Gu1[11];
Gu2[8] = + Gx1[24]*Gu1[0] + Gx1[25]*Gu1[2] + Gx1[26]*Gu1[4] + Gx1[27]*Gu1[6] + Gx1[28]*Gu1[8] + Gx1[29]*Gu1[10];
Gu2[9] = + Gx1[24]*Gu1[1] + Gx1[25]*Gu1[3] + Gx1[26]*Gu1[5] + Gx1[27]*Gu1[7] + Gx1[28]*Gu1[9] + Gx1[29]*Gu1[11];
Gu2[10] = + Gx1[30]*Gu1[0] + Gx1[31]*Gu1[2] + Gx1[32]*Gu1[4] + Gx1[33]*Gu1[6] + Gx1[34]*Gu1[8] + Gx1[35]*Gu1[10];
Gu2[11] = + Gx1[30]*Gu1[1] + Gx1[31]*Gu1[3] + Gx1[32]*Gu1[5] + Gx1[33]*Gu1[7] + Gx1[34]*Gu1[9] + Gx1[35]*Gu1[11];
}

void nmpc_moveGuE( real_t* const Gu1, real_t* const Gu2 )
{
Gu2[0] = Gu1[0];
Gu2[1] = Gu1[1];
Gu2[2] = Gu1[2];
Gu2[3] = Gu1[3];
Gu2[4] = Gu1[4];
Gu2[5] = Gu1[5];
Gu2[6] = Gu1[6];
Gu2[7] = Gu1[7];
Gu2[8] = Gu1[8];
Gu2[9] = Gu1[9];
Gu2[10] = Gu1[10];
Gu2[11] = Gu1[11];
}

void nmpc_multBTW1( real_t* const Gu1, real_t* const Gu2, int iRow, int iCol )
{
nmpcWorkspace.H[(iRow * 320) + (iCol * 2)] = + Gu1[0]*Gu2[0] + Gu1[2]*Gu2[2] + Gu1[4]*Gu2[4] + Gu1[6]*Gu2[6] + Gu1[8]*Gu2[8] + Gu1[10]*Gu2[10];
nmpcWorkspace.H[(iRow * 320) + (iCol * 2 + 1)] = + Gu1[0]*Gu2[1] + Gu1[2]*Gu2[3] + Gu1[4]*Gu2[5] + Gu1[6]*Gu2[7] + Gu1[8]*Gu2[9] + Gu1[10]*Gu2[11];
nmpcWorkspace.H[(iRow * 320 + 160) + (iCol * 2)] = + Gu1[1]*Gu2[0] + Gu1[3]*Gu2[2] + Gu1[5]*Gu2[4] + Gu1[7]*Gu2[6] + Gu1[9]*Gu2[8] + Gu1[11]*Gu2[10];
nmpcWorkspace.H[(iRow * 320 + 160) + (iCol * 2 + 1)] = + Gu1[1]*Gu2[1] + Gu1[3]*Gu2[3] + Gu1[5]*Gu2[5] + Gu1[7]*Gu2[7] + Gu1[9]*Gu2[9] + Gu1[11]*Gu2[11];
}

void nmpc_multBTW1_R1( real_t* const R11, real_t* const Gu1, real_t* const Gu2, int iRow )
{
nmpcWorkspace.H[iRow * 322] = + Gu1[0]*Gu2[0] + Gu1[2]*Gu2[2] + Gu1[4]*Gu2[4] + Gu1[6]*Gu2[6] + Gu1[8]*Gu2[8] + Gu1[10]*Gu2[10] + R11[0];
nmpcWorkspace.H[iRow * 322 + 1] = + Gu1[0]*Gu2[1] + Gu1[2]*Gu2[3] + Gu1[4]*Gu2[5] + Gu1[6]*Gu2[7] + Gu1[8]*Gu2[9] + Gu1[10]*Gu2[11] + R11[1];
nmpcWorkspace.H[iRow * 322 + 160] = + Gu1[1]*Gu2[0] + Gu1[3]*Gu2[2] + Gu1[5]*Gu2[4] + Gu1[7]*Gu2[6] + Gu1[9]*Gu2[8] + Gu1[11]*Gu2[10] + R11[2];
nmpcWorkspace.H[iRow * 322 + 161] = + Gu1[1]*Gu2[1] + Gu1[3]*Gu2[3] + Gu1[5]*Gu2[5] + Gu1[7]*Gu2[7] + Gu1[9]*Gu2[9] + Gu1[11]*Gu2[11] + R11[3];
}

void nmpc_multGxTGu( real_t* const Gx1, real_t* const Gu1, real_t* const Gu2 )
{
Gu2[0] = + Gx1[0]*Gu1[0] + Gx1[6]*Gu1[2] + Gx1[12]*Gu1[4] + Gx1[18]*Gu1[6] + Gx1[24]*Gu1[8] + Gx1[30]*Gu1[10];
Gu2[1] = + Gx1[0]*Gu1[1] + Gx1[6]*Gu1[3] + Gx1[12]*Gu1[5] + Gx1[18]*Gu1[7] + Gx1[24]*Gu1[9] + Gx1[30]*Gu1[11];
Gu2[2] = + Gx1[1]*Gu1[0] + Gx1[7]*Gu1[2] + Gx1[13]*Gu1[4] + Gx1[19]*Gu1[6] + Gx1[25]*Gu1[8] + Gx1[31]*Gu1[10];
Gu2[3] = + Gx1[1]*Gu1[1] + Gx1[7]*Gu1[3] + Gx1[13]*Gu1[5] + Gx1[19]*Gu1[7] + Gx1[25]*Gu1[9] + Gx1[31]*Gu1[11];
Gu2[4] = + Gx1[2]*Gu1[0] + Gx1[8]*Gu1[2] + Gx1[14]*Gu1[4] + Gx1[20]*Gu1[6] + Gx1[26]*Gu1[8] + Gx1[32]*Gu1[10];
Gu2[5] = + Gx1[2]*Gu1[1] + Gx1[8]*Gu1[3] + Gx1[14]*Gu1[5] + Gx1[20]*Gu1[7] + Gx1[26]*Gu1[9] + Gx1[32]*Gu1[11];
Gu2[6] = + Gx1[3]*Gu1[0] + Gx1[9]*Gu1[2] + Gx1[15]*Gu1[4] + Gx1[21]*Gu1[6] + Gx1[27]*Gu1[8] + Gx1[33]*Gu1[10];
Gu2[7] = + Gx1[3]*Gu1[1] + Gx1[9]*Gu1[3] + Gx1[15]*Gu1[5] + Gx1[21]*Gu1[7] + Gx1[27]*Gu1[9] + Gx1[33]*Gu1[11];
Gu2[8] = + Gx1[4]*Gu1[0] + Gx1[10]*Gu1[2] + Gx1[16]*Gu1[4] + Gx1[22]*Gu1[6] + Gx1[28]*Gu1[8] + Gx1[34]*Gu1[10];
Gu2[9] = + Gx1[4]*Gu1[1] + Gx1[10]*Gu1[3] + Gx1[16]*Gu1[5] + Gx1[22]*Gu1[7] + Gx1[28]*Gu1[9] + Gx1[34]*Gu1[11];
Gu2[10] = + Gx1[5]*Gu1[0] + Gx1[11]*Gu1[2] + Gx1[17]*Gu1[4] + Gx1[23]*Gu1[6] + Gx1[29]*Gu1[8] + Gx1[35]*Gu1[10];
Gu2[11] = + Gx1[5]*Gu1[1] + Gx1[11]*Gu1[3] + Gx1[17]*Gu1[5] + Gx1[23]*Gu1[7] + Gx1[29]*Gu1[9] + Gx1[35]*Gu1[11];
}

void nmpc_multQEW2( real_t* const Q11, real_t* const Gu1, real_t* const Gu2, real_t* const Gu3 )
{
Gu3[0] = + Q11[0]*Gu1[0] + Q11[1]*Gu1[2] + Q11[2]*Gu1[4] + Q11[3]*Gu1[6] + Q11[4]*Gu1[8] + Q11[5]*Gu1[10] + Gu2[0];
Gu3[1] = + Q11[0]*Gu1[1] + Q11[1]*Gu1[3] + Q11[2]*Gu1[5] + Q11[3]*Gu1[7] + Q11[4]*Gu1[9] + Q11[5]*Gu1[11] + Gu2[1];
Gu3[2] = + Q11[6]*Gu1[0] + Q11[7]*Gu1[2] + Q11[8]*Gu1[4] + Q11[9]*Gu1[6] + Q11[10]*Gu1[8] + Q11[11]*Gu1[10] + Gu2[2];
Gu3[3] = + Q11[6]*Gu1[1] + Q11[7]*Gu1[3] + Q11[8]*Gu1[5] + Q11[9]*Gu1[7] + Q11[10]*Gu1[9] + Q11[11]*Gu1[11] + Gu2[3];
Gu3[4] = + Q11[12]*Gu1[0] + Q11[13]*Gu1[2] + Q11[14]*Gu1[4] + Q11[15]*Gu1[6] + Q11[16]*Gu1[8] + Q11[17]*Gu1[10] + Gu2[4];
Gu3[5] = + Q11[12]*Gu1[1] + Q11[13]*Gu1[3] + Q11[14]*Gu1[5] + Q11[15]*Gu1[7] + Q11[16]*Gu1[9] + Q11[17]*Gu1[11] + Gu2[5];
Gu3[6] = + Q11[18]*Gu1[0] + Q11[19]*Gu1[2] + Q11[20]*Gu1[4] + Q11[21]*Gu1[6] + Q11[22]*Gu1[8] + Q11[23]*Gu1[10] + Gu2[6];
Gu3[7] = + Q11[18]*Gu1[1] + Q11[19]*Gu1[3] + Q11[20]*Gu1[5] + Q11[21]*Gu1[7] + Q11[22]*Gu1[9] + Q11[23]*Gu1[11] + Gu2[7];
Gu3[8] = + Q11[24]*Gu1[0] + Q11[25]*Gu1[2] + Q11[26]*Gu1[4] + Q11[27]*Gu1[6] + Q11[28]*Gu1[8] + Q11[29]*Gu1[10] + Gu2[8];
Gu3[9] = + Q11[24]*Gu1[1] + Q11[25]*Gu1[3] + Q11[26]*Gu1[5] + Q11[27]*Gu1[7] + Q11[28]*Gu1[9] + Q11[29]*Gu1[11] + Gu2[9];
Gu3[10] = + Q11[30]*Gu1[0] + Q11[31]*Gu1[2] + Q11[32]*Gu1[4] + Q11[33]*Gu1[6] + Q11[34]*Gu1[8] + Q11[35]*Gu1[10] + Gu2[10];
Gu3[11] = + Q11[30]*Gu1[1] + Q11[31]*Gu1[3] + Q11[32]*Gu1[5] + Q11[33]*Gu1[7] + Q11[34]*Gu1[9] + Q11[35]*Gu1[11] + Gu2[11];
}

void nmpc_macATw1QDy( real_t* const Gx1, real_t* const w11, real_t* const w12, real_t* const w13 )
{
w13[0] = + Gx1[0]*w11[0] + Gx1[6]*w11[1] + Gx1[12]*w11[2] + Gx1[18]*w11[3] + Gx1[24]*w11[4] + Gx1[30]*w11[5] + w12[0];
w13[1] = + Gx1[1]*w11[0] + Gx1[7]*w11[1] + Gx1[13]*w11[2] + Gx1[19]*w11[3] + Gx1[25]*w11[4] + Gx1[31]*w11[5] + w12[1];
w13[2] = + Gx1[2]*w11[0] + Gx1[8]*w11[1] + Gx1[14]*w11[2] + Gx1[20]*w11[3] + Gx1[26]*w11[4] + Gx1[32]*w11[5] + w12[2];
w13[3] = + Gx1[3]*w11[0] + Gx1[9]*w11[1] + Gx1[15]*w11[2] + Gx1[21]*w11[3] + Gx1[27]*w11[4] + Gx1[33]*w11[5] + w12[3];
w13[4] = + Gx1[4]*w11[0] + Gx1[10]*w11[1] + Gx1[16]*w11[2] + Gx1[22]*w11[3] + Gx1[28]*w11[4] + Gx1[34]*w11[5] + w12[4];
w13[5] = + Gx1[5]*w11[0] + Gx1[11]*w11[1] + Gx1[17]*w11[2] + Gx1[23]*w11[3] + Gx1[29]*w11[4] + Gx1[35]*w11[5] + w12[5];
}

void nmpc_macBTw1( real_t* const Gu1, real_t* const w11, real_t* const U1 )
{
U1[0] += + Gu1[0]*w11[0] + Gu1[2]*w11[1] + Gu1[4]*w11[2] + Gu1[6]*w11[3] + Gu1[8]*w11[4] + Gu1[10]*w11[5];
U1[1] += + Gu1[1]*w11[0] + Gu1[3]*w11[1] + Gu1[5]*w11[2] + Gu1[7]*w11[3] + Gu1[9]*w11[4] + Gu1[11]*w11[5];
}

void nmpc_macQSbarW2( real_t* const Q11, real_t* const w11, real_t* const w12, real_t* const w13 )
{
w13[0] = + Q11[0]*w11[0] + Q11[1]*w11[1] + Q11[2]*w11[2] + Q11[3]*w11[3] + Q11[4]*w11[4] + Q11[5]*w11[5] + w12[0];
w13[1] = + Q11[6]*w11[0] + Q11[7]*w11[1] + Q11[8]*w11[2] + Q11[9]*w11[3] + Q11[10]*w11[4] + Q11[11]*w11[5] + w12[1];
w13[2] = + Q11[12]*w11[0] + Q11[13]*w11[1] + Q11[14]*w11[2] + Q11[15]*w11[3] + Q11[16]*w11[4] + Q11[17]*w11[5] + w12[2];
w13[3] = + Q11[18]*w11[0] + Q11[19]*w11[1] + Q11[20]*w11[2] + Q11[21]*w11[3] + Q11[22]*w11[4] + Q11[23]*w11[5] + w12[3];
w13[4] = + Q11[24]*w11[0] + Q11[25]*w11[1] + Q11[26]*w11[2] + Q11[27]*w11[3] + Q11[28]*w11[4] + Q11[29]*w11[5] + w12[4];
w13[5] = + Q11[30]*w11[0] + Q11[31]*w11[1] + Q11[32]*w11[2] + Q11[33]*w11[3] + Q11[34]*w11[4] + Q11[35]*w11[5] + w12[5];
}

void nmpc_macASbar( real_t* const Gx1, real_t* const w11, real_t* const w12 )
{
w12[0] += + Gx1[0]*w11[0] + Gx1[1]*w11[1] + Gx1[2]*w11[2] + Gx1[3]*w11[3] + Gx1[4]*w11[4] + Gx1[5]*w11[5];
w12[1] += + Gx1[6]*w11[0] + Gx1[7]*w11[1] + Gx1[8]*w11[2] + Gx1[9]*w11[3] + Gx1[10]*w11[4] + Gx1[11]*w11[5];
w12[2] += + Gx1[12]*w11[0] + Gx1[13]*w11[1] + Gx1[14]*w11[2] + Gx1[15]*w11[3] + Gx1[16]*w11[4] + Gx1[17]*w11[5];
w12[3] += + Gx1[18]*w11[0] + Gx1[19]*w11[1] + Gx1[20]*w11[2] + Gx1[21]*w11[3] + Gx1[22]*w11[4] + Gx1[23]*w11[5];
w12[4] += + Gx1[24]*w11[0] + Gx1[25]*w11[1] + Gx1[26]*w11[2] + Gx1[27]*w11[3] + Gx1[28]*w11[4] + Gx1[29]*w11[5];
w12[5] += + Gx1[30]*w11[0] + Gx1[31]*w11[1] + Gx1[32]*w11[2] + Gx1[33]*w11[3] + Gx1[34]*w11[4] + Gx1[35]*w11[5];
}

void nmpc_expansionStep( real_t* const Gx1, real_t* const Gu1, real_t* const U1, real_t* const w11, real_t* const w12 )
{
w12[0] += + Gx1[0]*w11[0] + Gx1[1]*w11[1] + Gx1[2]*w11[2] + Gx1[3]*w11[3] + Gx1[4]*w11[4] + Gx1[5]*w11[5];
w12[1] += + Gx1[6]*w11[0] + Gx1[7]*w11[1] + Gx1[8]*w11[2] + Gx1[9]*w11[3] + Gx1[10]*w11[4] + Gx1[11]*w11[5];
w12[2] += + Gx1[12]*w11[0] + Gx1[13]*w11[1] + Gx1[14]*w11[2] + Gx1[15]*w11[3] + Gx1[16]*w11[4] + Gx1[17]*w11[5];
w12[3] += + Gx1[18]*w11[0] + Gx1[19]*w11[1] + Gx1[20]*w11[2] + Gx1[21]*w11[3] + Gx1[22]*w11[4] + Gx1[23]*w11[5];
w12[4] += + Gx1[24]*w11[0] + Gx1[25]*w11[1] + Gx1[26]*w11[2] + Gx1[27]*w11[3] + Gx1[28]*w11[4] + Gx1[29]*w11[5];
w12[5] += + Gx1[30]*w11[0] + Gx1[31]*w11[1] + Gx1[32]*w11[2] + Gx1[33]*w11[3] + Gx1[34]*w11[4] + Gx1[35]*w11[5];
w12[0] += + Gu1[0]*U1[0] + Gu1[1]*U1[1];
w12[1] += + Gu1[2]*U1[0] + Gu1[3]*U1[1];
w12[2] += + Gu1[4]*U1[0] + Gu1[5]*U1[1];
w12[3] += + Gu1[6]*U1[0] + Gu1[7]*U1[1];
w12[4] += + Gu1[8]*U1[0] + Gu1[9]*U1[1];
w12[5] += + Gu1[10]*U1[0] + Gu1[11]*U1[1];
}

void nmpc_copyHTH( int iRow, int iCol )
{
nmpcWorkspace.H[(iRow * 320) + (iCol * 2)] = nmpcWorkspace.H[(iCol * 320) + (iRow * 2)];
nmpcWorkspace.H[(iRow * 320) + (iCol * 2 + 1)] = nmpcWorkspace.H[(iCol * 320 + 160) + (iRow * 2)];
nmpcWorkspace.H[(iRow * 320 + 160) + (iCol * 2)] = nmpcWorkspace.H[(iCol * 320) + (iRow * 2 + 1)];
nmpcWorkspace.H[(iRow * 320 + 160) + (iCol * 2 + 1)] = nmpcWorkspace.H[(iCol * 320 + 160) + (iRow * 2 + 1)];
}

void nmpc_multRDy( real_t* const R2, real_t* const Dy1, real_t* const RDy1 )
{
RDy1[0] = + R2[0]*Dy1[0] + R2[1]*Dy1[1] + R2[2]*Dy1[2] + R2[3]*Dy1[3] + R2[4]*Dy1[4] + R2[5]*Dy1[5] + R2[6]*Dy1[6] + R2[7]*Dy1[7];
RDy1[1] = + R2[8]*Dy1[0] + R2[9]*Dy1[1] + R2[10]*Dy1[2] + R2[11]*Dy1[3] + R2[12]*Dy1[4] + R2[13]*Dy1[5] + R2[14]*Dy1[6] + R2[15]*Dy1[7];
}

void nmpc_multQDy( real_t* const Q2, real_t* const Dy1, real_t* const QDy1 )
{
QDy1[0] = + Q2[0]*Dy1[0] + Q2[1]*Dy1[1] + Q2[2]*Dy1[2] + Q2[3]*Dy1[3] + Q2[4]*Dy1[4] + Q2[5]*Dy1[5] + Q2[6]*Dy1[6] + Q2[7]*Dy1[7];
QDy1[1] = + Q2[8]*Dy1[0] + Q2[9]*Dy1[1] + Q2[10]*Dy1[2] + Q2[11]*Dy1[3] + Q2[12]*Dy1[4] + Q2[13]*Dy1[5] + Q2[14]*Dy1[6] + Q2[15]*Dy1[7];
QDy1[2] = + Q2[16]*Dy1[0] + Q2[17]*Dy1[1] + Q2[18]*Dy1[2] + Q2[19]*Dy1[3] + Q2[20]*Dy1[4] + Q2[21]*Dy1[5] + Q2[22]*Dy1[6] + Q2[23]*Dy1[7];
QDy1[3] = + Q2[24]*Dy1[0] + Q2[25]*Dy1[1] + Q2[26]*Dy1[2] + Q2[27]*Dy1[3] + Q2[28]*Dy1[4] + Q2[29]*Dy1[5] + Q2[30]*Dy1[6] + Q2[31]*Dy1[7];
QDy1[4] = + Q2[32]*Dy1[0] + Q2[33]*Dy1[1] + Q2[34]*Dy1[2] + Q2[35]*Dy1[3] + Q2[36]*Dy1[4] + Q2[37]*Dy1[5] + Q2[38]*Dy1[6] + Q2[39]*Dy1[7];
QDy1[5] = + Q2[40]*Dy1[0] + Q2[41]*Dy1[1] + Q2[42]*Dy1[2] + Q2[43]*Dy1[3] + Q2[44]*Dy1[4] + Q2[45]*Dy1[5] + Q2[46]*Dy1[6] + Q2[47]*Dy1[7];
}

void nmpc_condensePrep(  )
{
int lRun1;
int lRun2;
int lRun3;
for (lRun2 = 0; lRun2 < 80; ++lRun2)
{
lRun3 = ((lRun2) * (lRun2 * -1 + 161)) / (2);
nmpc_moveGuE( &(nmpcWorkspace.evGu[ lRun2 * 12 ]), &(nmpcWorkspace.E[ lRun3 * 12 ]) );
for (lRun1 = 1; lRun1 < lRun2 * -1 + 80; ++lRun1)
{
nmpc_multGxGu( &(nmpcWorkspace.evGx[ ((((lRun2) + (lRun1)) * (6)) * (6)) + (0) ]), &(nmpcWorkspace.E[ (((((lRun3) + (lRun1)) - (1)) * (6)) * (2)) + (0) ]), &(nmpcWorkspace.E[ ((((lRun3) + (lRun1)) * (6)) * (2)) + (0) ]) );
}

nmpc_multGxGu( nmpcWorkspace.QN1, &(nmpcWorkspace.E[ ((((((lRun3) - (lRun2)) + (80)) - (1)) * (6)) * (2)) + (0) ]), nmpcWorkspace.W1 );
for (lRun1 = 79; lRun2 < lRun1; --lRun1)
{
nmpc_multBTW1( &(nmpcWorkspace.evGu[ lRun1 * 12 ]), nmpcWorkspace.W1, lRun1, lRun2 );
nmpc_multGxTGu( &(nmpcWorkspace.evGx[ lRun1 * 36 ]), nmpcWorkspace.W1, nmpcWorkspace.W2 );
nmpc_multQEW2( &(nmpcWorkspace.Q1[ lRun1 * 36 ]), &(nmpcWorkspace.E[ ((((((lRun3) + (lRun1)) - (lRun2)) - (1)) * (6)) * (2)) + (0) ]), nmpcWorkspace.W2, nmpcWorkspace.W1 );
}
nmpc_multBTW1_R1( &(nmpcWorkspace.R1[ lRun2 * 4 ]), &(nmpcWorkspace.evGu[ lRun2 * 12 ]), nmpcWorkspace.W1, lRun2 );
}

for (lRun1 = 0; lRun1 < 80; ++lRun1)
{
for (lRun2 = 0; lRun2 < lRun1; ++lRun2)
{
nmpc_copyHTH( lRun2, lRun1 );
}
}

for (lRun1 = 0; lRun1 < 480; ++lRun1)
nmpcWorkspace.sbar[lRun1 + 6] = nmpcWorkspace.d[lRun1];

nmpcWorkspace.lb[0] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[0];
nmpcWorkspace.lb[1] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[1];
nmpcWorkspace.lb[2] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[2];
nmpcWorkspace.lb[3] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[3];
nmpcWorkspace.lb[4] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[4];
nmpcWorkspace.lb[5] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[5];
nmpcWorkspace.lb[6] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[6];
nmpcWorkspace.lb[7] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[7];
nmpcWorkspace.lb[8] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[8];
nmpcWorkspace.lb[9] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[9];
nmpcWorkspace.lb[10] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[10];
nmpcWorkspace.lb[11] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[11];
nmpcWorkspace.lb[12] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[12];
nmpcWorkspace.lb[13] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[13];
nmpcWorkspace.lb[14] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[14];
nmpcWorkspace.lb[15] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[15];
nmpcWorkspace.lb[16] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[16];
nmpcWorkspace.lb[17] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[17];
nmpcWorkspace.lb[18] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[18];
nmpcWorkspace.lb[19] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[19];
nmpcWorkspace.lb[20] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[20];
nmpcWorkspace.lb[21] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[21];
nmpcWorkspace.lb[22] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[22];
nmpcWorkspace.lb[23] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[23];
nmpcWorkspace.lb[24] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[24];
nmpcWorkspace.lb[25] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[25];
nmpcWorkspace.lb[26] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[26];
nmpcWorkspace.lb[27] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[27];
nmpcWorkspace.lb[28] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[28];
nmpcWorkspace.lb[29] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[29];
nmpcWorkspace.lb[30] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[30];
nmpcWorkspace.lb[31] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[31];
nmpcWorkspace.lb[32] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[32];
nmpcWorkspace.lb[33] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[33];
nmpcWorkspace.lb[34] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[34];
nmpcWorkspace.lb[35] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[35];
nmpcWorkspace.lb[36] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[36];
nmpcWorkspace.lb[37] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[37];
nmpcWorkspace.lb[38] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[38];
nmpcWorkspace.lb[39] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[39];
nmpcWorkspace.lb[40] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[40];
nmpcWorkspace.lb[41] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[41];
nmpcWorkspace.lb[42] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[42];
nmpcWorkspace.lb[43] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[43];
nmpcWorkspace.lb[44] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[44];
nmpcWorkspace.lb[45] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[45];
nmpcWorkspace.lb[46] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[46];
nmpcWorkspace.lb[47] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[47];
nmpcWorkspace.lb[48] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[48];
nmpcWorkspace.lb[49] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[49];
nmpcWorkspace.lb[50] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[50];
nmpcWorkspace.lb[51] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[51];
nmpcWorkspace.lb[52] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[52];
nmpcWorkspace.lb[53] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[53];
nmpcWorkspace.lb[54] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[54];
nmpcWorkspace.lb[55] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[55];
nmpcWorkspace.lb[56] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[56];
nmpcWorkspace.lb[57] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[57];
nmpcWorkspace.lb[58] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[58];
nmpcWorkspace.lb[59] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[59];
nmpcWorkspace.lb[60] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[60];
nmpcWorkspace.lb[61] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[61];
nmpcWorkspace.lb[62] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[62];
nmpcWorkspace.lb[63] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[63];
nmpcWorkspace.lb[64] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[64];
nmpcWorkspace.lb[65] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[65];
nmpcWorkspace.lb[66] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[66];
nmpcWorkspace.lb[67] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[67];
nmpcWorkspace.lb[68] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[68];
nmpcWorkspace.lb[69] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[69];
nmpcWorkspace.lb[70] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[70];
nmpcWorkspace.lb[71] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[71];
nmpcWorkspace.lb[72] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[72];
nmpcWorkspace.lb[73] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[73];
nmpcWorkspace.lb[74] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[74];
nmpcWorkspace.lb[75] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[75];
nmpcWorkspace.lb[76] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[76];
nmpcWorkspace.lb[77] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[77];
nmpcWorkspace.lb[78] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[78];
nmpcWorkspace.lb[79] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[79];
nmpcWorkspace.lb[80] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[80];
nmpcWorkspace.lb[81] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[81];
nmpcWorkspace.lb[82] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[82];
nmpcWorkspace.lb[83] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[83];
nmpcWorkspace.lb[84] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[84];
nmpcWorkspace.lb[85] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[85];
nmpcWorkspace.lb[86] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[86];
nmpcWorkspace.lb[87] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[87];
nmpcWorkspace.lb[88] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[88];
nmpcWorkspace.lb[89] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[89];
nmpcWorkspace.lb[90] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[90];
nmpcWorkspace.lb[91] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[91];
nmpcWorkspace.lb[92] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[92];
nmpcWorkspace.lb[93] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[93];
nmpcWorkspace.lb[94] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[94];
nmpcWorkspace.lb[95] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[95];
nmpcWorkspace.lb[96] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[96];
nmpcWorkspace.lb[97] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[97];
nmpcWorkspace.lb[98] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[98];
nmpcWorkspace.lb[99] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[99];
nmpcWorkspace.lb[100] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[100];
nmpcWorkspace.lb[101] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[101];
nmpcWorkspace.lb[102] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[102];
nmpcWorkspace.lb[103] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[103];
nmpcWorkspace.lb[104] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[104];
nmpcWorkspace.lb[105] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[105];
nmpcWorkspace.lb[106] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[106];
nmpcWorkspace.lb[107] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[107];
nmpcWorkspace.lb[108] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[108];
nmpcWorkspace.lb[109] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[109];
nmpcWorkspace.lb[110] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[110];
nmpcWorkspace.lb[111] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[111];
nmpcWorkspace.lb[112] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[112];
nmpcWorkspace.lb[113] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[113];
nmpcWorkspace.lb[114] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[114];
nmpcWorkspace.lb[115] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[115];
nmpcWorkspace.lb[116] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[116];
nmpcWorkspace.lb[117] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[117];
nmpcWorkspace.lb[118] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[118];
nmpcWorkspace.lb[119] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[119];
nmpcWorkspace.lb[120] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[120];
nmpcWorkspace.lb[121] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[121];
nmpcWorkspace.lb[122] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[122];
nmpcWorkspace.lb[123] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[123];
nmpcWorkspace.lb[124] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[124];
nmpcWorkspace.lb[125] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[125];
nmpcWorkspace.lb[126] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[126];
nmpcWorkspace.lb[127] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[127];
nmpcWorkspace.lb[128] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[128];
nmpcWorkspace.lb[129] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[129];
nmpcWorkspace.lb[130] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[130];
nmpcWorkspace.lb[131] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[131];
nmpcWorkspace.lb[132] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[132];
nmpcWorkspace.lb[133] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[133];
nmpcWorkspace.lb[134] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[134];
nmpcWorkspace.lb[135] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[135];
nmpcWorkspace.lb[136] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[136];
nmpcWorkspace.lb[137] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[137];
nmpcWorkspace.lb[138] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[138];
nmpcWorkspace.lb[139] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[139];
nmpcWorkspace.lb[140] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[140];
nmpcWorkspace.lb[141] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[141];
nmpcWorkspace.lb[142] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[142];
nmpcWorkspace.lb[143] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[143];
nmpcWorkspace.lb[144] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[144];
nmpcWorkspace.lb[145] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[145];
nmpcWorkspace.lb[146] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[146];
nmpcWorkspace.lb[147] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[147];
nmpcWorkspace.lb[148] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[148];
nmpcWorkspace.lb[149] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[149];
nmpcWorkspace.lb[150] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[150];
nmpcWorkspace.lb[151] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[151];
nmpcWorkspace.lb[152] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[152];
nmpcWorkspace.lb[153] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[153];
nmpcWorkspace.lb[154] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[154];
nmpcWorkspace.lb[155] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[155];
nmpcWorkspace.lb[156] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[156];
nmpcWorkspace.lb[157] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[157];
nmpcWorkspace.lb[158] = (real_t)-2.9321531433506669e+00 - nmpcVariables.u[158];
nmpcWorkspace.lb[159] = (real_t)-1.0000000000000000e+00 - nmpcVariables.u[159];
nmpcWorkspace.ub[0] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[0];
nmpcWorkspace.ub[1] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[1];
nmpcWorkspace.ub[2] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[2];
nmpcWorkspace.ub[3] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[3];
nmpcWorkspace.ub[4] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[4];
nmpcWorkspace.ub[5] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[5];
nmpcWorkspace.ub[6] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[6];
nmpcWorkspace.ub[7] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[7];
nmpcWorkspace.ub[8] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[8];
nmpcWorkspace.ub[9] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[9];
nmpcWorkspace.ub[10] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[10];
nmpcWorkspace.ub[11] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[11];
nmpcWorkspace.ub[12] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[12];
nmpcWorkspace.ub[13] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[13];
nmpcWorkspace.ub[14] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[14];
nmpcWorkspace.ub[15] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[15];
nmpcWorkspace.ub[16] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[16];
nmpcWorkspace.ub[17] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[17];
nmpcWorkspace.ub[18] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[18];
nmpcWorkspace.ub[19] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[19];
nmpcWorkspace.ub[20] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[20];
nmpcWorkspace.ub[21] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[21];
nmpcWorkspace.ub[22] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[22];
nmpcWorkspace.ub[23] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[23];
nmpcWorkspace.ub[24] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[24];
nmpcWorkspace.ub[25] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[25];
nmpcWorkspace.ub[26] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[26];
nmpcWorkspace.ub[27] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[27];
nmpcWorkspace.ub[28] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[28];
nmpcWorkspace.ub[29] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[29];
nmpcWorkspace.ub[30] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[30];
nmpcWorkspace.ub[31] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[31];
nmpcWorkspace.ub[32] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[32];
nmpcWorkspace.ub[33] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[33];
nmpcWorkspace.ub[34] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[34];
nmpcWorkspace.ub[35] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[35];
nmpcWorkspace.ub[36] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[36];
nmpcWorkspace.ub[37] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[37];
nmpcWorkspace.ub[38] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[38];
nmpcWorkspace.ub[39] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[39];
nmpcWorkspace.ub[40] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[40];
nmpcWorkspace.ub[41] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[41];
nmpcWorkspace.ub[42] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[42];
nmpcWorkspace.ub[43] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[43];
nmpcWorkspace.ub[44] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[44];
nmpcWorkspace.ub[45] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[45];
nmpcWorkspace.ub[46] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[46];
nmpcWorkspace.ub[47] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[47];
nmpcWorkspace.ub[48] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[48];
nmpcWorkspace.ub[49] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[49];
nmpcWorkspace.ub[50] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[50];
nmpcWorkspace.ub[51] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[51];
nmpcWorkspace.ub[52] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[52];
nmpcWorkspace.ub[53] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[53];
nmpcWorkspace.ub[54] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[54];
nmpcWorkspace.ub[55] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[55];
nmpcWorkspace.ub[56] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[56];
nmpcWorkspace.ub[57] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[57];
nmpcWorkspace.ub[58] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[58];
nmpcWorkspace.ub[59] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[59];
nmpcWorkspace.ub[60] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[60];
nmpcWorkspace.ub[61] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[61];
nmpcWorkspace.ub[62] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[62];
nmpcWorkspace.ub[63] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[63];
nmpcWorkspace.ub[64] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[64];
nmpcWorkspace.ub[65] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[65];
nmpcWorkspace.ub[66] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[66];
nmpcWorkspace.ub[67] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[67];
nmpcWorkspace.ub[68] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[68];
nmpcWorkspace.ub[69] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[69];
nmpcWorkspace.ub[70] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[70];
nmpcWorkspace.ub[71] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[71];
nmpcWorkspace.ub[72] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[72];
nmpcWorkspace.ub[73] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[73];
nmpcWorkspace.ub[74] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[74];
nmpcWorkspace.ub[75] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[75];
nmpcWorkspace.ub[76] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[76];
nmpcWorkspace.ub[77] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[77];
nmpcWorkspace.ub[78] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[78];
nmpcWorkspace.ub[79] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[79];
nmpcWorkspace.ub[80] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[80];
nmpcWorkspace.ub[81] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[81];
nmpcWorkspace.ub[82] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[82];
nmpcWorkspace.ub[83] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[83];
nmpcWorkspace.ub[84] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[84];
nmpcWorkspace.ub[85] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[85];
nmpcWorkspace.ub[86] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[86];
nmpcWorkspace.ub[87] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[87];
nmpcWorkspace.ub[88] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[88];
nmpcWorkspace.ub[89] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[89];
nmpcWorkspace.ub[90] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[90];
nmpcWorkspace.ub[91] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[91];
nmpcWorkspace.ub[92] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[92];
nmpcWorkspace.ub[93] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[93];
nmpcWorkspace.ub[94] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[94];
nmpcWorkspace.ub[95] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[95];
nmpcWorkspace.ub[96] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[96];
nmpcWorkspace.ub[97] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[97];
nmpcWorkspace.ub[98] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[98];
nmpcWorkspace.ub[99] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[99];
nmpcWorkspace.ub[100] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[100];
nmpcWorkspace.ub[101] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[101];
nmpcWorkspace.ub[102] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[102];
nmpcWorkspace.ub[103] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[103];
nmpcWorkspace.ub[104] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[104];
nmpcWorkspace.ub[105] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[105];
nmpcWorkspace.ub[106] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[106];
nmpcWorkspace.ub[107] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[107];
nmpcWorkspace.ub[108] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[108];
nmpcWorkspace.ub[109] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[109];
nmpcWorkspace.ub[110] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[110];
nmpcWorkspace.ub[111] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[111];
nmpcWorkspace.ub[112] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[112];
nmpcWorkspace.ub[113] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[113];
nmpcWorkspace.ub[114] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[114];
nmpcWorkspace.ub[115] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[115];
nmpcWorkspace.ub[116] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[116];
nmpcWorkspace.ub[117] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[117];
nmpcWorkspace.ub[118] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[118];
nmpcWorkspace.ub[119] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[119];
nmpcWorkspace.ub[120] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[120];
nmpcWorkspace.ub[121] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[121];
nmpcWorkspace.ub[122] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[122];
nmpcWorkspace.ub[123] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[123];
nmpcWorkspace.ub[124] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[124];
nmpcWorkspace.ub[125] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[125];
nmpcWorkspace.ub[126] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[126];
nmpcWorkspace.ub[127] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[127];
nmpcWorkspace.ub[128] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[128];
nmpcWorkspace.ub[129] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[129];
nmpcWorkspace.ub[130] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[130];
nmpcWorkspace.ub[131] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[131];
nmpcWorkspace.ub[132] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[132];
nmpcWorkspace.ub[133] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[133];
nmpcWorkspace.ub[134] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[134];
nmpcWorkspace.ub[135] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[135];
nmpcWorkspace.ub[136] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[136];
nmpcWorkspace.ub[137] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[137];
nmpcWorkspace.ub[138] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[138];
nmpcWorkspace.ub[139] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[139];
nmpcWorkspace.ub[140] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[140];
nmpcWorkspace.ub[141] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[141];
nmpcWorkspace.ub[142] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[142];
nmpcWorkspace.ub[143] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[143];
nmpcWorkspace.ub[144] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[144];
nmpcWorkspace.ub[145] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[145];
nmpcWorkspace.ub[146] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[146];
nmpcWorkspace.ub[147] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[147];
nmpcWorkspace.ub[148] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[148];
nmpcWorkspace.ub[149] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[149];
nmpcWorkspace.ub[150] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[150];
nmpcWorkspace.ub[151] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[151];
nmpcWorkspace.ub[152] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[152];
nmpcWorkspace.ub[153] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[153];
nmpcWorkspace.ub[154] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[154];
nmpcWorkspace.ub[155] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[155];
nmpcWorkspace.ub[156] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[156];
nmpcWorkspace.ub[157] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[157];
nmpcWorkspace.ub[158] = (real_t)2.9321531433506669e+00 - nmpcVariables.u[158];
nmpcWorkspace.ub[159] = (real_t)1.0000000000000000e+00 - nmpcVariables.u[159];

}

void nmpc_condenseFdb(  )
{
int lRun1;
nmpcWorkspace.Dx0[0] = nmpcVariables.x0[0] - nmpcVariables.x[0];
nmpcWorkspace.Dx0[1] = nmpcVariables.x0[1] - nmpcVariables.x[1];
nmpcWorkspace.Dx0[2] = nmpcVariables.x0[2] - nmpcVariables.x[2];
nmpcWorkspace.Dx0[3] = nmpcVariables.x0[3] - nmpcVariables.x[3];
nmpcWorkspace.Dx0[4] = nmpcVariables.x0[4] - nmpcVariables.x[4];
nmpcWorkspace.Dx0[5] = nmpcVariables.x0[5] - nmpcVariables.x[5];
for (lRun1 = 0; lRun1 < 640; ++lRun1)
nmpcWorkspace.Dy[lRun1] -= nmpcVariables.y[lRun1];

nmpcWorkspace.DyN[0] -= nmpcVariables.yN[0];
nmpcWorkspace.DyN[1] -= nmpcVariables.yN[1];
nmpcWorkspace.DyN[2] -= nmpcVariables.yN[2];
nmpcWorkspace.DyN[3] -= nmpcVariables.yN[3];
nmpcWorkspace.DyN[4] -= nmpcVariables.yN[4];
nmpcWorkspace.DyN[5] -= nmpcVariables.yN[5];

nmpc_multRDy( nmpcWorkspace.R2, nmpcWorkspace.Dy, nmpcWorkspace.g );
nmpc_multRDy( &(nmpcWorkspace.R2[ 16 ]), &(nmpcWorkspace.Dy[ 8 ]), &(nmpcWorkspace.g[ 2 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 32 ]), &(nmpcWorkspace.Dy[ 16 ]), &(nmpcWorkspace.g[ 4 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 48 ]), &(nmpcWorkspace.Dy[ 24 ]), &(nmpcWorkspace.g[ 6 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 64 ]), &(nmpcWorkspace.Dy[ 32 ]), &(nmpcWorkspace.g[ 8 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 80 ]), &(nmpcWorkspace.Dy[ 40 ]), &(nmpcWorkspace.g[ 10 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 96 ]), &(nmpcWorkspace.Dy[ 48 ]), &(nmpcWorkspace.g[ 12 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 112 ]), &(nmpcWorkspace.Dy[ 56 ]), &(nmpcWorkspace.g[ 14 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 128 ]), &(nmpcWorkspace.Dy[ 64 ]), &(nmpcWorkspace.g[ 16 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 144 ]), &(nmpcWorkspace.Dy[ 72 ]), &(nmpcWorkspace.g[ 18 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 160 ]), &(nmpcWorkspace.Dy[ 80 ]), &(nmpcWorkspace.g[ 20 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 176 ]), &(nmpcWorkspace.Dy[ 88 ]), &(nmpcWorkspace.g[ 22 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 192 ]), &(nmpcWorkspace.Dy[ 96 ]), &(nmpcWorkspace.g[ 24 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 208 ]), &(nmpcWorkspace.Dy[ 104 ]), &(nmpcWorkspace.g[ 26 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 224 ]), &(nmpcWorkspace.Dy[ 112 ]), &(nmpcWorkspace.g[ 28 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 240 ]), &(nmpcWorkspace.Dy[ 120 ]), &(nmpcWorkspace.g[ 30 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 256 ]), &(nmpcWorkspace.Dy[ 128 ]), &(nmpcWorkspace.g[ 32 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 272 ]), &(nmpcWorkspace.Dy[ 136 ]), &(nmpcWorkspace.g[ 34 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 288 ]), &(nmpcWorkspace.Dy[ 144 ]), &(nmpcWorkspace.g[ 36 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 304 ]), &(nmpcWorkspace.Dy[ 152 ]), &(nmpcWorkspace.g[ 38 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 320 ]), &(nmpcWorkspace.Dy[ 160 ]), &(nmpcWorkspace.g[ 40 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 336 ]), &(nmpcWorkspace.Dy[ 168 ]), &(nmpcWorkspace.g[ 42 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 352 ]), &(nmpcWorkspace.Dy[ 176 ]), &(nmpcWorkspace.g[ 44 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 368 ]), &(nmpcWorkspace.Dy[ 184 ]), &(nmpcWorkspace.g[ 46 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 384 ]), &(nmpcWorkspace.Dy[ 192 ]), &(nmpcWorkspace.g[ 48 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 400 ]), &(nmpcWorkspace.Dy[ 200 ]), &(nmpcWorkspace.g[ 50 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 416 ]), &(nmpcWorkspace.Dy[ 208 ]), &(nmpcWorkspace.g[ 52 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 432 ]), &(nmpcWorkspace.Dy[ 216 ]), &(nmpcWorkspace.g[ 54 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 448 ]), &(nmpcWorkspace.Dy[ 224 ]), &(nmpcWorkspace.g[ 56 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 464 ]), &(nmpcWorkspace.Dy[ 232 ]), &(nmpcWorkspace.g[ 58 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 480 ]), &(nmpcWorkspace.Dy[ 240 ]), &(nmpcWorkspace.g[ 60 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 496 ]), &(nmpcWorkspace.Dy[ 248 ]), &(nmpcWorkspace.g[ 62 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 512 ]), &(nmpcWorkspace.Dy[ 256 ]), &(nmpcWorkspace.g[ 64 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 528 ]), &(nmpcWorkspace.Dy[ 264 ]), &(nmpcWorkspace.g[ 66 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 544 ]), &(nmpcWorkspace.Dy[ 272 ]), &(nmpcWorkspace.g[ 68 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 560 ]), &(nmpcWorkspace.Dy[ 280 ]), &(nmpcWorkspace.g[ 70 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 576 ]), &(nmpcWorkspace.Dy[ 288 ]), &(nmpcWorkspace.g[ 72 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 592 ]), &(nmpcWorkspace.Dy[ 296 ]), &(nmpcWorkspace.g[ 74 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 608 ]), &(nmpcWorkspace.Dy[ 304 ]), &(nmpcWorkspace.g[ 76 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 624 ]), &(nmpcWorkspace.Dy[ 312 ]), &(nmpcWorkspace.g[ 78 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 640 ]), &(nmpcWorkspace.Dy[ 320 ]), &(nmpcWorkspace.g[ 80 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 656 ]), &(nmpcWorkspace.Dy[ 328 ]), &(nmpcWorkspace.g[ 82 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 672 ]), &(nmpcWorkspace.Dy[ 336 ]), &(nmpcWorkspace.g[ 84 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 688 ]), &(nmpcWorkspace.Dy[ 344 ]), &(nmpcWorkspace.g[ 86 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 704 ]), &(nmpcWorkspace.Dy[ 352 ]), &(nmpcWorkspace.g[ 88 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 720 ]), &(nmpcWorkspace.Dy[ 360 ]), &(nmpcWorkspace.g[ 90 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 736 ]), &(nmpcWorkspace.Dy[ 368 ]), &(nmpcWorkspace.g[ 92 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 752 ]), &(nmpcWorkspace.Dy[ 376 ]), &(nmpcWorkspace.g[ 94 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 768 ]), &(nmpcWorkspace.Dy[ 384 ]), &(nmpcWorkspace.g[ 96 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 784 ]), &(nmpcWorkspace.Dy[ 392 ]), &(nmpcWorkspace.g[ 98 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 800 ]), &(nmpcWorkspace.Dy[ 400 ]), &(nmpcWorkspace.g[ 100 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 816 ]), &(nmpcWorkspace.Dy[ 408 ]), &(nmpcWorkspace.g[ 102 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 832 ]), &(nmpcWorkspace.Dy[ 416 ]), &(nmpcWorkspace.g[ 104 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 848 ]), &(nmpcWorkspace.Dy[ 424 ]), &(nmpcWorkspace.g[ 106 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 864 ]), &(nmpcWorkspace.Dy[ 432 ]), &(nmpcWorkspace.g[ 108 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 880 ]), &(nmpcWorkspace.Dy[ 440 ]), &(nmpcWorkspace.g[ 110 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 896 ]), &(nmpcWorkspace.Dy[ 448 ]), &(nmpcWorkspace.g[ 112 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 912 ]), &(nmpcWorkspace.Dy[ 456 ]), &(nmpcWorkspace.g[ 114 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 928 ]), &(nmpcWorkspace.Dy[ 464 ]), &(nmpcWorkspace.g[ 116 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 944 ]), &(nmpcWorkspace.Dy[ 472 ]), &(nmpcWorkspace.g[ 118 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 960 ]), &(nmpcWorkspace.Dy[ 480 ]), &(nmpcWorkspace.g[ 120 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 976 ]), &(nmpcWorkspace.Dy[ 488 ]), &(nmpcWorkspace.g[ 122 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 992 ]), &(nmpcWorkspace.Dy[ 496 ]), &(nmpcWorkspace.g[ 124 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 1008 ]), &(nmpcWorkspace.Dy[ 504 ]), &(nmpcWorkspace.g[ 126 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 1024 ]), &(nmpcWorkspace.Dy[ 512 ]), &(nmpcWorkspace.g[ 128 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 1040 ]), &(nmpcWorkspace.Dy[ 520 ]), &(nmpcWorkspace.g[ 130 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 1056 ]), &(nmpcWorkspace.Dy[ 528 ]), &(nmpcWorkspace.g[ 132 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 1072 ]), &(nmpcWorkspace.Dy[ 536 ]), &(nmpcWorkspace.g[ 134 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 1088 ]), &(nmpcWorkspace.Dy[ 544 ]), &(nmpcWorkspace.g[ 136 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 1104 ]), &(nmpcWorkspace.Dy[ 552 ]), &(nmpcWorkspace.g[ 138 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 1120 ]), &(nmpcWorkspace.Dy[ 560 ]), &(nmpcWorkspace.g[ 140 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 1136 ]), &(nmpcWorkspace.Dy[ 568 ]), &(nmpcWorkspace.g[ 142 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 1152 ]), &(nmpcWorkspace.Dy[ 576 ]), &(nmpcWorkspace.g[ 144 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 1168 ]), &(nmpcWorkspace.Dy[ 584 ]), &(nmpcWorkspace.g[ 146 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 1184 ]), &(nmpcWorkspace.Dy[ 592 ]), &(nmpcWorkspace.g[ 148 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 1200 ]), &(nmpcWorkspace.Dy[ 600 ]), &(nmpcWorkspace.g[ 150 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 1216 ]), &(nmpcWorkspace.Dy[ 608 ]), &(nmpcWorkspace.g[ 152 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 1232 ]), &(nmpcWorkspace.Dy[ 616 ]), &(nmpcWorkspace.g[ 154 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 1248 ]), &(nmpcWorkspace.Dy[ 624 ]), &(nmpcWorkspace.g[ 156 ]) );
nmpc_multRDy( &(nmpcWorkspace.R2[ 1264 ]), &(nmpcWorkspace.Dy[ 632 ]), &(nmpcWorkspace.g[ 158 ]) );

nmpc_multQDy( nmpcWorkspace.Q2, nmpcWorkspace.Dy, nmpcWorkspace.QDy );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 48 ]), &(nmpcWorkspace.Dy[ 8 ]), &(nmpcWorkspace.QDy[ 6 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 96 ]), &(nmpcWorkspace.Dy[ 16 ]), &(nmpcWorkspace.QDy[ 12 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 144 ]), &(nmpcWorkspace.Dy[ 24 ]), &(nmpcWorkspace.QDy[ 18 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 192 ]), &(nmpcWorkspace.Dy[ 32 ]), &(nmpcWorkspace.QDy[ 24 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 240 ]), &(nmpcWorkspace.Dy[ 40 ]), &(nmpcWorkspace.QDy[ 30 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 288 ]), &(nmpcWorkspace.Dy[ 48 ]), &(nmpcWorkspace.QDy[ 36 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 336 ]), &(nmpcWorkspace.Dy[ 56 ]), &(nmpcWorkspace.QDy[ 42 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 384 ]), &(nmpcWorkspace.Dy[ 64 ]), &(nmpcWorkspace.QDy[ 48 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 432 ]), &(nmpcWorkspace.Dy[ 72 ]), &(nmpcWorkspace.QDy[ 54 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 480 ]), &(nmpcWorkspace.Dy[ 80 ]), &(nmpcWorkspace.QDy[ 60 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 528 ]), &(nmpcWorkspace.Dy[ 88 ]), &(nmpcWorkspace.QDy[ 66 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 576 ]), &(nmpcWorkspace.Dy[ 96 ]), &(nmpcWorkspace.QDy[ 72 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 624 ]), &(nmpcWorkspace.Dy[ 104 ]), &(nmpcWorkspace.QDy[ 78 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 672 ]), &(nmpcWorkspace.Dy[ 112 ]), &(nmpcWorkspace.QDy[ 84 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 720 ]), &(nmpcWorkspace.Dy[ 120 ]), &(nmpcWorkspace.QDy[ 90 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 768 ]), &(nmpcWorkspace.Dy[ 128 ]), &(nmpcWorkspace.QDy[ 96 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 816 ]), &(nmpcWorkspace.Dy[ 136 ]), &(nmpcWorkspace.QDy[ 102 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 864 ]), &(nmpcWorkspace.Dy[ 144 ]), &(nmpcWorkspace.QDy[ 108 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 912 ]), &(nmpcWorkspace.Dy[ 152 ]), &(nmpcWorkspace.QDy[ 114 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 960 ]), &(nmpcWorkspace.Dy[ 160 ]), &(nmpcWorkspace.QDy[ 120 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 1008 ]), &(nmpcWorkspace.Dy[ 168 ]), &(nmpcWorkspace.QDy[ 126 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 1056 ]), &(nmpcWorkspace.Dy[ 176 ]), &(nmpcWorkspace.QDy[ 132 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 1104 ]), &(nmpcWorkspace.Dy[ 184 ]), &(nmpcWorkspace.QDy[ 138 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 1152 ]), &(nmpcWorkspace.Dy[ 192 ]), &(nmpcWorkspace.QDy[ 144 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 1200 ]), &(nmpcWorkspace.Dy[ 200 ]), &(nmpcWorkspace.QDy[ 150 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 1248 ]), &(nmpcWorkspace.Dy[ 208 ]), &(nmpcWorkspace.QDy[ 156 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 1296 ]), &(nmpcWorkspace.Dy[ 216 ]), &(nmpcWorkspace.QDy[ 162 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 1344 ]), &(nmpcWorkspace.Dy[ 224 ]), &(nmpcWorkspace.QDy[ 168 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 1392 ]), &(nmpcWorkspace.Dy[ 232 ]), &(nmpcWorkspace.QDy[ 174 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 1440 ]), &(nmpcWorkspace.Dy[ 240 ]), &(nmpcWorkspace.QDy[ 180 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 1488 ]), &(nmpcWorkspace.Dy[ 248 ]), &(nmpcWorkspace.QDy[ 186 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 1536 ]), &(nmpcWorkspace.Dy[ 256 ]), &(nmpcWorkspace.QDy[ 192 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 1584 ]), &(nmpcWorkspace.Dy[ 264 ]), &(nmpcWorkspace.QDy[ 198 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 1632 ]), &(nmpcWorkspace.Dy[ 272 ]), &(nmpcWorkspace.QDy[ 204 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 1680 ]), &(nmpcWorkspace.Dy[ 280 ]), &(nmpcWorkspace.QDy[ 210 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 1728 ]), &(nmpcWorkspace.Dy[ 288 ]), &(nmpcWorkspace.QDy[ 216 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 1776 ]), &(nmpcWorkspace.Dy[ 296 ]), &(nmpcWorkspace.QDy[ 222 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 1824 ]), &(nmpcWorkspace.Dy[ 304 ]), &(nmpcWorkspace.QDy[ 228 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 1872 ]), &(nmpcWorkspace.Dy[ 312 ]), &(nmpcWorkspace.QDy[ 234 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 1920 ]), &(nmpcWorkspace.Dy[ 320 ]), &(nmpcWorkspace.QDy[ 240 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 1968 ]), &(nmpcWorkspace.Dy[ 328 ]), &(nmpcWorkspace.QDy[ 246 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 2016 ]), &(nmpcWorkspace.Dy[ 336 ]), &(nmpcWorkspace.QDy[ 252 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 2064 ]), &(nmpcWorkspace.Dy[ 344 ]), &(nmpcWorkspace.QDy[ 258 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 2112 ]), &(nmpcWorkspace.Dy[ 352 ]), &(nmpcWorkspace.QDy[ 264 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 2160 ]), &(nmpcWorkspace.Dy[ 360 ]), &(nmpcWorkspace.QDy[ 270 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 2208 ]), &(nmpcWorkspace.Dy[ 368 ]), &(nmpcWorkspace.QDy[ 276 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 2256 ]), &(nmpcWorkspace.Dy[ 376 ]), &(nmpcWorkspace.QDy[ 282 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 2304 ]), &(nmpcWorkspace.Dy[ 384 ]), &(nmpcWorkspace.QDy[ 288 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 2352 ]), &(nmpcWorkspace.Dy[ 392 ]), &(nmpcWorkspace.QDy[ 294 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 2400 ]), &(nmpcWorkspace.Dy[ 400 ]), &(nmpcWorkspace.QDy[ 300 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 2448 ]), &(nmpcWorkspace.Dy[ 408 ]), &(nmpcWorkspace.QDy[ 306 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 2496 ]), &(nmpcWorkspace.Dy[ 416 ]), &(nmpcWorkspace.QDy[ 312 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 2544 ]), &(nmpcWorkspace.Dy[ 424 ]), &(nmpcWorkspace.QDy[ 318 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 2592 ]), &(nmpcWorkspace.Dy[ 432 ]), &(nmpcWorkspace.QDy[ 324 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 2640 ]), &(nmpcWorkspace.Dy[ 440 ]), &(nmpcWorkspace.QDy[ 330 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 2688 ]), &(nmpcWorkspace.Dy[ 448 ]), &(nmpcWorkspace.QDy[ 336 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 2736 ]), &(nmpcWorkspace.Dy[ 456 ]), &(nmpcWorkspace.QDy[ 342 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 2784 ]), &(nmpcWorkspace.Dy[ 464 ]), &(nmpcWorkspace.QDy[ 348 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 2832 ]), &(nmpcWorkspace.Dy[ 472 ]), &(nmpcWorkspace.QDy[ 354 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 2880 ]), &(nmpcWorkspace.Dy[ 480 ]), &(nmpcWorkspace.QDy[ 360 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 2928 ]), &(nmpcWorkspace.Dy[ 488 ]), &(nmpcWorkspace.QDy[ 366 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 2976 ]), &(nmpcWorkspace.Dy[ 496 ]), &(nmpcWorkspace.QDy[ 372 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 3024 ]), &(nmpcWorkspace.Dy[ 504 ]), &(nmpcWorkspace.QDy[ 378 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 3072 ]), &(nmpcWorkspace.Dy[ 512 ]), &(nmpcWorkspace.QDy[ 384 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 3120 ]), &(nmpcWorkspace.Dy[ 520 ]), &(nmpcWorkspace.QDy[ 390 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 3168 ]), &(nmpcWorkspace.Dy[ 528 ]), &(nmpcWorkspace.QDy[ 396 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 3216 ]), &(nmpcWorkspace.Dy[ 536 ]), &(nmpcWorkspace.QDy[ 402 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 3264 ]), &(nmpcWorkspace.Dy[ 544 ]), &(nmpcWorkspace.QDy[ 408 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 3312 ]), &(nmpcWorkspace.Dy[ 552 ]), &(nmpcWorkspace.QDy[ 414 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 3360 ]), &(nmpcWorkspace.Dy[ 560 ]), &(nmpcWorkspace.QDy[ 420 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 3408 ]), &(nmpcWorkspace.Dy[ 568 ]), &(nmpcWorkspace.QDy[ 426 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 3456 ]), &(nmpcWorkspace.Dy[ 576 ]), &(nmpcWorkspace.QDy[ 432 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 3504 ]), &(nmpcWorkspace.Dy[ 584 ]), &(nmpcWorkspace.QDy[ 438 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 3552 ]), &(nmpcWorkspace.Dy[ 592 ]), &(nmpcWorkspace.QDy[ 444 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 3600 ]), &(nmpcWorkspace.Dy[ 600 ]), &(nmpcWorkspace.QDy[ 450 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 3648 ]), &(nmpcWorkspace.Dy[ 608 ]), &(nmpcWorkspace.QDy[ 456 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 3696 ]), &(nmpcWorkspace.Dy[ 616 ]), &(nmpcWorkspace.QDy[ 462 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 3744 ]), &(nmpcWorkspace.Dy[ 624 ]), &(nmpcWorkspace.QDy[ 468 ]) );
nmpc_multQDy( &(nmpcWorkspace.Q2[ 3792 ]), &(nmpcWorkspace.Dy[ 632 ]), &(nmpcWorkspace.QDy[ 474 ]) );

nmpcWorkspace.QDy[480] = + nmpcWorkspace.QN2[0]*nmpcWorkspace.DyN[0] + nmpcWorkspace.QN2[1]*nmpcWorkspace.DyN[1] + nmpcWorkspace.QN2[2]*nmpcWorkspace.DyN[2] + nmpcWorkspace.QN2[3]*nmpcWorkspace.DyN[3] + nmpcWorkspace.QN2[4]*nmpcWorkspace.DyN[4] + nmpcWorkspace.QN2[5]*nmpcWorkspace.DyN[5];
nmpcWorkspace.QDy[481] = + nmpcWorkspace.QN2[6]*nmpcWorkspace.DyN[0] + nmpcWorkspace.QN2[7]*nmpcWorkspace.DyN[1] + nmpcWorkspace.QN2[8]*nmpcWorkspace.DyN[2] + nmpcWorkspace.QN2[9]*nmpcWorkspace.DyN[3] + nmpcWorkspace.QN2[10]*nmpcWorkspace.DyN[4] + nmpcWorkspace.QN2[11]*nmpcWorkspace.DyN[5];
nmpcWorkspace.QDy[482] = + nmpcWorkspace.QN2[12]*nmpcWorkspace.DyN[0] + nmpcWorkspace.QN2[13]*nmpcWorkspace.DyN[1] + nmpcWorkspace.QN2[14]*nmpcWorkspace.DyN[2] + nmpcWorkspace.QN2[15]*nmpcWorkspace.DyN[3] + nmpcWorkspace.QN2[16]*nmpcWorkspace.DyN[4] + nmpcWorkspace.QN2[17]*nmpcWorkspace.DyN[5];
nmpcWorkspace.QDy[483] = + nmpcWorkspace.QN2[18]*nmpcWorkspace.DyN[0] + nmpcWorkspace.QN2[19]*nmpcWorkspace.DyN[1] + nmpcWorkspace.QN2[20]*nmpcWorkspace.DyN[2] + nmpcWorkspace.QN2[21]*nmpcWorkspace.DyN[3] + nmpcWorkspace.QN2[22]*nmpcWorkspace.DyN[4] + nmpcWorkspace.QN2[23]*nmpcWorkspace.DyN[5];
nmpcWorkspace.QDy[484] = + nmpcWorkspace.QN2[24]*nmpcWorkspace.DyN[0] + nmpcWorkspace.QN2[25]*nmpcWorkspace.DyN[1] + nmpcWorkspace.QN2[26]*nmpcWorkspace.DyN[2] + nmpcWorkspace.QN2[27]*nmpcWorkspace.DyN[3] + nmpcWorkspace.QN2[28]*nmpcWorkspace.DyN[4] + nmpcWorkspace.QN2[29]*nmpcWorkspace.DyN[5];
nmpcWorkspace.QDy[485] = + nmpcWorkspace.QN2[30]*nmpcWorkspace.DyN[0] + nmpcWorkspace.QN2[31]*nmpcWorkspace.DyN[1] + nmpcWorkspace.QN2[32]*nmpcWorkspace.DyN[2] + nmpcWorkspace.QN2[33]*nmpcWorkspace.DyN[3] + nmpcWorkspace.QN2[34]*nmpcWorkspace.DyN[4] + nmpcWorkspace.QN2[35]*nmpcWorkspace.DyN[5];

nmpcWorkspace.sbar[0] = nmpcWorkspace.Dx0[0];
nmpcWorkspace.sbar[1] = nmpcWorkspace.Dx0[1];
nmpcWorkspace.sbar[2] = nmpcWorkspace.Dx0[2];
nmpcWorkspace.sbar[3] = nmpcWorkspace.Dx0[3];
nmpcWorkspace.sbar[4] = nmpcWorkspace.Dx0[4];
nmpcWorkspace.sbar[5] = nmpcWorkspace.Dx0[5];
nmpc_macASbar( nmpcWorkspace.evGx, nmpcWorkspace.sbar, &(nmpcWorkspace.sbar[ 6 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 36 ]), &(nmpcWorkspace.sbar[ 6 ]), &(nmpcWorkspace.sbar[ 12 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 72 ]), &(nmpcWorkspace.sbar[ 12 ]), &(nmpcWorkspace.sbar[ 18 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 108 ]), &(nmpcWorkspace.sbar[ 18 ]), &(nmpcWorkspace.sbar[ 24 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 144 ]), &(nmpcWorkspace.sbar[ 24 ]), &(nmpcWorkspace.sbar[ 30 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 180 ]), &(nmpcWorkspace.sbar[ 30 ]), &(nmpcWorkspace.sbar[ 36 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 216 ]), &(nmpcWorkspace.sbar[ 36 ]), &(nmpcWorkspace.sbar[ 42 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 252 ]), &(nmpcWorkspace.sbar[ 42 ]), &(nmpcWorkspace.sbar[ 48 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 288 ]), &(nmpcWorkspace.sbar[ 48 ]), &(nmpcWorkspace.sbar[ 54 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 324 ]), &(nmpcWorkspace.sbar[ 54 ]), &(nmpcWorkspace.sbar[ 60 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 360 ]), &(nmpcWorkspace.sbar[ 60 ]), &(nmpcWorkspace.sbar[ 66 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 396 ]), &(nmpcWorkspace.sbar[ 66 ]), &(nmpcWorkspace.sbar[ 72 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 432 ]), &(nmpcWorkspace.sbar[ 72 ]), &(nmpcWorkspace.sbar[ 78 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 468 ]), &(nmpcWorkspace.sbar[ 78 ]), &(nmpcWorkspace.sbar[ 84 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 504 ]), &(nmpcWorkspace.sbar[ 84 ]), &(nmpcWorkspace.sbar[ 90 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 540 ]), &(nmpcWorkspace.sbar[ 90 ]), &(nmpcWorkspace.sbar[ 96 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 576 ]), &(nmpcWorkspace.sbar[ 96 ]), &(nmpcWorkspace.sbar[ 102 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 612 ]), &(nmpcWorkspace.sbar[ 102 ]), &(nmpcWorkspace.sbar[ 108 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 648 ]), &(nmpcWorkspace.sbar[ 108 ]), &(nmpcWorkspace.sbar[ 114 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 684 ]), &(nmpcWorkspace.sbar[ 114 ]), &(nmpcWorkspace.sbar[ 120 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 720 ]), &(nmpcWorkspace.sbar[ 120 ]), &(nmpcWorkspace.sbar[ 126 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 756 ]), &(nmpcWorkspace.sbar[ 126 ]), &(nmpcWorkspace.sbar[ 132 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 792 ]), &(nmpcWorkspace.sbar[ 132 ]), &(nmpcWorkspace.sbar[ 138 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 828 ]), &(nmpcWorkspace.sbar[ 138 ]), &(nmpcWorkspace.sbar[ 144 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 864 ]), &(nmpcWorkspace.sbar[ 144 ]), &(nmpcWorkspace.sbar[ 150 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 900 ]), &(nmpcWorkspace.sbar[ 150 ]), &(nmpcWorkspace.sbar[ 156 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 936 ]), &(nmpcWorkspace.sbar[ 156 ]), &(nmpcWorkspace.sbar[ 162 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 972 ]), &(nmpcWorkspace.sbar[ 162 ]), &(nmpcWorkspace.sbar[ 168 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1008 ]), &(nmpcWorkspace.sbar[ 168 ]), &(nmpcWorkspace.sbar[ 174 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1044 ]), &(nmpcWorkspace.sbar[ 174 ]), &(nmpcWorkspace.sbar[ 180 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1080 ]), &(nmpcWorkspace.sbar[ 180 ]), &(nmpcWorkspace.sbar[ 186 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1116 ]), &(nmpcWorkspace.sbar[ 186 ]), &(nmpcWorkspace.sbar[ 192 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1152 ]), &(nmpcWorkspace.sbar[ 192 ]), &(nmpcWorkspace.sbar[ 198 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1188 ]), &(nmpcWorkspace.sbar[ 198 ]), &(nmpcWorkspace.sbar[ 204 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1224 ]), &(nmpcWorkspace.sbar[ 204 ]), &(nmpcWorkspace.sbar[ 210 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1260 ]), &(nmpcWorkspace.sbar[ 210 ]), &(nmpcWorkspace.sbar[ 216 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1296 ]), &(nmpcWorkspace.sbar[ 216 ]), &(nmpcWorkspace.sbar[ 222 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1332 ]), &(nmpcWorkspace.sbar[ 222 ]), &(nmpcWorkspace.sbar[ 228 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1368 ]), &(nmpcWorkspace.sbar[ 228 ]), &(nmpcWorkspace.sbar[ 234 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1404 ]), &(nmpcWorkspace.sbar[ 234 ]), &(nmpcWorkspace.sbar[ 240 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1440 ]), &(nmpcWorkspace.sbar[ 240 ]), &(nmpcWorkspace.sbar[ 246 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1476 ]), &(nmpcWorkspace.sbar[ 246 ]), &(nmpcWorkspace.sbar[ 252 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1512 ]), &(nmpcWorkspace.sbar[ 252 ]), &(nmpcWorkspace.sbar[ 258 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1548 ]), &(nmpcWorkspace.sbar[ 258 ]), &(nmpcWorkspace.sbar[ 264 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1584 ]), &(nmpcWorkspace.sbar[ 264 ]), &(nmpcWorkspace.sbar[ 270 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1620 ]), &(nmpcWorkspace.sbar[ 270 ]), &(nmpcWorkspace.sbar[ 276 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1656 ]), &(nmpcWorkspace.sbar[ 276 ]), &(nmpcWorkspace.sbar[ 282 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1692 ]), &(nmpcWorkspace.sbar[ 282 ]), &(nmpcWorkspace.sbar[ 288 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1728 ]), &(nmpcWorkspace.sbar[ 288 ]), &(nmpcWorkspace.sbar[ 294 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1764 ]), &(nmpcWorkspace.sbar[ 294 ]), &(nmpcWorkspace.sbar[ 300 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1800 ]), &(nmpcWorkspace.sbar[ 300 ]), &(nmpcWorkspace.sbar[ 306 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1836 ]), &(nmpcWorkspace.sbar[ 306 ]), &(nmpcWorkspace.sbar[ 312 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1872 ]), &(nmpcWorkspace.sbar[ 312 ]), &(nmpcWorkspace.sbar[ 318 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1908 ]), &(nmpcWorkspace.sbar[ 318 ]), &(nmpcWorkspace.sbar[ 324 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1944 ]), &(nmpcWorkspace.sbar[ 324 ]), &(nmpcWorkspace.sbar[ 330 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 1980 ]), &(nmpcWorkspace.sbar[ 330 ]), &(nmpcWorkspace.sbar[ 336 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2016 ]), &(nmpcWorkspace.sbar[ 336 ]), &(nmpcWorkspace.sbar[ 342 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2052 ]), &(nmpcWorkspace.sbar[ 342 ]), &(nmpcWorkspace.sbar[ 348 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2088 ]), &(nmpcWorkspace.sbar[ 348 ]), &(nmpcWorkspace.sbar[ 354 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2124 ]), &(nmpcWorkspace.sbar[ 354 ]), &(nmpcWorkspace.sbar[ 360 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2160 ]), &(nmpcWorkspace.sbar[ 360 ]), &(nmpcWorkspace.sbar[ 366 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2196 ]), &(nmpcWorkspace.sbar[ 366 ]), &(nmpcWorkspace.sbar[ 372 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2232 ]), &(nmpcWorkspace.sbar[ 372 ]), &(nmpcWorkspace.sbar[ 378 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2268 ]), &(nmpcWorkspace.sbar[ 378 ]), &(nmpcWorkspace.sbar[ 384 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2304 ]), &(nmpcWorkspace.sbar[ 384 ]), &(nmpcWorkspace.sbar[ 390 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2340 ]), &(nmpcWorkspace.sbar[ 390 ]), &(nmpcWorkspace.sbar[ 396 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2376 ]), &(nmpcWorkspace.sbar[ 396 ]), &(nmpcWorkspace.sbar[ 402 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2412 ]), &(nmpcWorkspace.sbar[ 402 ]), &(nmpcWorkspace.sbar[ 408 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2448 ]), &(nmpcWorkspace.sbar[ 408 ]), &(nmpcWorkspace.sbar[ 414 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2484 ]), &(nmpcWorkspace.sbar[ 414 ]), &(nmpcWorkspace.sbar[ 420 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2520 ]), &(nmpcWorkspace.sbar[ 420 ]), &(nmpcWorkspace.sbar[ 426 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2556 ]), &(nmpcWorkspace.sbar[ 426 ]), &(nmpcWorkspace.sbar[ 432 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2592 ]), &(nmpcWorkspace.sbar[ 432 ]), &(nmpcWorkspace.sbar[ 438 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2628 ]), &(nmpcWorkspace.sbar[ 438 ]), &(nmpcWorkspace.sbar[ 444 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2664 ]), &(nmpcWorkspace.sbar[ 444 ]), &(nmpcWorkspace.sbar[ 450 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2700 ]), &(nmpcWorkspace.sbar[ 450 ]), &(nmpcWorkspace.sbar[ 456 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2736 ]), &(nmpcWorkspace.sbar[ 456 ]), &(nmpcWorkspace.sbar[ 462 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2772 ]), &(nmpcWorkspace.sbar[ 462 ]), &(nmpcWorkspace.sbar[ 468 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2808 ]), &(nmpcWorkspace.sbar[ 468 ]), &(nmpcWorkspace.sbar[ 474 ]) );
nmpc_macASbar( &(nmpcWorkspace.evGx[ 2844 ]), &(nmpcWorkspace.sbar[ 474 ]), &(nmpcWorkspace.sbar[ 480 ]) );

nmpcWorkspace.w1[0] = + nmpcWorkspace.QN1[0]*nmpcWorkspace.sbar[480] + nmpcWorkspace.QN1[1]*nmpcWorkspace.sbar[481] + nmpcWorkspace.QN1[2]*nmpcWorkspace.sbar[482] + nmpcWorkspace.QN1[3]*nmpcWorkspace.sbar[483] + nmpcWorkspace.QN1[4]*nmpcWorkspace.sbar[484] + nmpcWorkspace.QN1[5]*nmpcWorkspace.sbar[485] + nmpcWorkspace.QDy[480];
nmpcWorkspace.w1[1] = + nmpcWorkspace.QN1[6]*nmpcWorkspace.sbar[480] + nmpcWorkspace.QN1[7]*nmpcWorkspace.sbar[481] + nmpcWorkspace.QN1[8]*nmpcWorkspace.sbar[482] + nmpcWorkspace.QN1[9]*nmpcWorkspace.sbar[483] + nmpcWorkspace.QN1[10]*nmpcWorkspace.sbar[484] + nmpcWorkspace.QN1[11]*nmpcWorkspace.sbar[485] + nmpcWorkspace.QDy[481];
nmpcWorkspace.w1[2] = + nmpcWorkspace.QN1[12]*nmpcWorkspace.sbar[480] + nmpcWorkspace.QN1[13]*nmpcWorkspace.sbar[481] + nmpcWorkspace.QN1[14]*nmpcWorkspace.sbar[482] + nmpcWorkspace.QN1[15]*nmpcWorkspace.sbar[483] + nmpcWorkspace.QN1[16]*nmpcWorkspace.sbar[484] + nmpcWorkspace.QN1[17]*nmpcWorkspace.sbar[485] + nmpcWorkspace.QDy[482];
nmpcWorkspace.w1[3] = + nmpcWorkspace.QN1[18]*nmpcWorkspace.sbar[480] + nmpcWorkspace.QN1[19]*nmpcWorkspace.sbar[481] + nmpcWorkspace.QN1[20]*nmpcWorkspace.sbar[482] + nmpcWorkspace.QN1[21]*nmpcWorkspace.sbar[483] + nmpcWorkspace.QN1[22]*nmpcWorkspace.sbar[484] + nmpcWorkspace.QN1[23]*nmpcWorkspace.sbar[485] + nmpcWorkspace.QDy[483];
nmpcWorkspace.w1[4] = + nmpcWorkspace.QN1[24]*nmpcWorkspace.sbar[480] + nmpcWorkspace.QN1[25]*nmpcWorkspace.sbar[481] + nmpcWorkspace.QN1[26]*nmpcWorkspace.sbar[482] + nmpcWorkspace.QN1[27]*nmpcWorkspace.sbar[483] + nmpcWorkspace.QN1[28]*nmpcWorkspace.sbar[484] + nmpcWorkspace.QN1[29]*nmpcWorkspace.sbar[485] + nmpcWorkspace.QDy[484];
nmpcWorkspace.w1[5] = + nmpcWorkspace.QN1[30]*nmpcWorkspace.sbar[480] + nmpcWorkspace.QN1[31]*nmpcWorkspace.sbar[481] + nmpcWorkspace.QN1[32]*nmpcWorkspace.sbar[482] + nmpcWorkspace.QN1[33]*nmpcWorkspace.sbar[483] + nmpcWorkspace.QN1[34]*nmpcWorkspace.sbar[484] + nmpcWorkspace.QN1[35]*nmpcWorkspace.sbar[485] + nmpcWorkspace.QDy[485];
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 948 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 158 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2844 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 474 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2844 ]), &(nmpcWorkspace.sbar[ 474 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 936 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 156 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2808 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 468 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2808 ]), &(nmpcWorkspace.sbar[ 468 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 924 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 154 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2772 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 462 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2772 ]), &(nmpcWorkspace.sbar[ 462 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 912 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 152 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2736 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 456 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2736 ]), &(nmpcWorkspace.sbar[ 456 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 900 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 150 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2700 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 450 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2700 ]), &(nmpcWorkspace.sbar[ 450 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 888 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 148 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2664 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 444 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2664 ]), &(nmpcWorkspace.sbar[ 444 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 876 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 146 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2628 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 438 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2628 ]), &(nmpcWorkspace.sbar[ 438 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 864 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 144 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2592 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 432 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2592 ]), &(nmpcWorkspace.sbar[ 432 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 852 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 142 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2556 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 426 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2556 ]), &(nmpcWorkspace.sbar[ 426 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 840 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 140 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2520 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 420 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2520 ]), &(nmpcWorkspace.sbar[ 420 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 828 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 138 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2484 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 414 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2484 ]), &(nmpcWorkspace.sbar[ 414 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 816 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 136 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2448 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 408 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2448 ]), &(nmpcWorkspace.sbar[ 408 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 804 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 134 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2412 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 402 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2412 ]), &(nmpcWorkspace.sbar[ 402 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 792 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 132 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2376 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 396 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2376 ]), &(nmpcWorkspace.sbar[ 396 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 780 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 130 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2340 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 390 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2340 ]), &(nmpcWorkspace.sbar[ 390 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 768 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 128 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2304 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 384 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2304 ]), &(nmpcWorkspace.sbar[ 384 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 756 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 126 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2268 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 378 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2268 ]), &(nmpcWorkspace.sbar[ 378 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 744 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 124 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2232 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 372 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2232 ]), &(nmpcWorkspace.sbar[ 372 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 732 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 122 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2196 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 366 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2196 ]), &(nmpcWorkspace.sbar[ 366 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 720 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 120 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2160 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 360 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2160 ]), &(nmpcWorkspace.sbar[ 360 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 708 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 118 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2124 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 354 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2124 ]), &(nmpcWorkspace.sbar[ 354 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 696 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 116 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2088 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 348 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2088 ]), &(nmpcWorkspace.sbar[ 348 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 684 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 114 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2052 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 342 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2052 ]), &(nmpcWorkspace.sbar[ 342 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 672 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 112 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 2016 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 336 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 2016 ]), &(nmpcWorkspace.sbar[ 336 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 660 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 110 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1980 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 330 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1980 ]), &(nmpcWorkspace.sbar[ 330 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 648 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 108 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1944 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 324 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1944 ]), &(nmpcWorkspace.sbar[ 324 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 636 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 106 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1908 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 318 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1908 ]), &(nmpcWorkspace.sbar[ 318 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 624 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 104 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1872 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 312 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1872 ]), &(nmpcWorkspace.sbar[ 312 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 612 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 102 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1836 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 306 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1836 ]), &(nmpcWorkspace.sbar[ 306 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 600 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 100 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1800 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 300 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1800 ]), &(nmpcWorkspace.sbar[ 300 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 588 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 98 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1764 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 294 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1764 ]), &(nmpcWorkspace.sbar[ 294 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 576 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 96 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1728 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 288 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1728 ]), &(nmpcWorkspace.sbar[ 288 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 564 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 94 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1692 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 282 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1692 ]), &(nmpcWorkspace.sbar[ 282 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 552 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 92 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1656 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 276 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1656 ]), &(nmpcWorkspace.sbar[ 276 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 540 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 90 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1620 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 270 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1620 ]), &(nmpcWorkspace.sbar[ 270 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 528 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 88 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1584 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 264 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1584 ]), &(nmpcWorkspace.sbar[ 264 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 516 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 86 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1548 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 258 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1548 ]), &(nmpcWorkspace.sbar[ 258 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 504 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 84 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1512 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 252 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1512 ]), &(nmpcWorkspace.sbar[ 252 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 492 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 82 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1476 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 246 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1476 ]), &(nmpcWorkspace.sbar[ 246 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 480 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 80 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1440 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 240 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1440 ]), &(nmpcWorkspace.sbar[ 240 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 468 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 78 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1404 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 234 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1404 ]), &(nmpcWorkspace.sbar[ 234 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 456 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 76 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1368 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 228 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1368 ]), &(nmpcWorkspace.sbar[ 228 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 444 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 74 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1332 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 222 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1332 ]), &(nmpcWorkspace.sbar[ 222 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 432 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 72 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1296 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 216 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1296 ]), &(nmpcWorkspace.sbar[ 216 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 420 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 70 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1260 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 210 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1260 ]), &(nmpcWorkspace.sbar[ 210 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 408 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 68 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1224 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 204 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1224 ]), &(nmpcWorkspace.sbar[ 204 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 396 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 66 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1188 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 198 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1188 ]), &(nmpcWorkspace.sbar[ 198 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 384 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 64 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1152 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 192 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1152 ]), &(nmpcWorkspace.sbar[ 192 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 372 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 62 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1116 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 186 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1116 ]), &(nmpcWorkspace.sbar[ 186 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 360 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 60 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1080 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 180 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1080 ]), &(nmpcWorkspace.sbar[ 180 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 348 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 58 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1044 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 174 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1044 ]), &(nmpcWorkspace.sbar[ 174 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 336 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 56 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 1008 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 168 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 1008 ]), &(nmpcWorkspace.sbar[ 168 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 324 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 54 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 972 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 162 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 972 ]), &(nmpcWorkspace.sbar[ 162 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 312 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 52 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 936 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 156 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 936 ]), &(nmpcWorkspace.sbar[ 156 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 300 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 50 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 900 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 150 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 900 ]), &(nmpcWorkspace.sbar[ 150 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 288 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 48 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 864 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 144 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 864 ]), &(nmpcWorkspace.sbar[ 144 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 276 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 46 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 828 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 138 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 828 ]), &(nmpcWorkspace.sbar[ 138 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 264 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 44 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 792 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 132 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 792 ]), &(nmpcWorkspace.sbar[ 132 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 252 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 42 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 756 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 126 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 756 ]), &(nmpcWorkspace.sbar[ 126 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 240 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 40 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 720 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 120 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 720 ]), &(nmpcWorkspace.sbar[ 120 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 228 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 38 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 684 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 114 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 684 ]), &(nmpcWorkspace.sbar[ 114 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 216 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 36 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 648 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 108 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 648 ]), &(nmpcWorkspace.sbar[ 108 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 204 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 34 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 612 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 102 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 612 ]), &(nmpcWorkspace.sbar[ 102 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 192 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 32 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 576 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 96 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 576 ]), &(nmpcWorkspace.sbar[ 96 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 180 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 30 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 540 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 90 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 540 ]), &(nmpcWorkspace.sbar[ 90 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 168 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 28 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 504 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 84 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 504 ]), &(nmpcWorkspace.sbar[ 84 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 156 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 26 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 468 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 78 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 468 ]), &(nmpcWorkspace.sbar[ 78 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 144 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 24 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 432 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 72 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 432 ]), &(nmpcWorkspace.sbar[ 72 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 132 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 22 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 396 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 66 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 396 ]), &(nmpcWorkspace.sbar[ 66 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 120 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 20 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 360 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 60 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 360 ]), &(nmpcWorkspace.sbar[ 60 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 108 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 18 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 324 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 54 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 324 ]), &(nmpcWorkspace.sbar[ 54 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 96 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 16 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 288 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 48 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 288 ]), &(nmpcWorkspace.sbar[ 48 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 84 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 14 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 252 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 42 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 252 ]), &(nmpcWorkspace.sbar[ 42 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 72 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 12 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 216 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 36 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 216 ]), &(nmpcWorkspace.sbar[ 36 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 60 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 10 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 180 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 30 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 180 ]), &(nmpcWorkspace.sbar[ 30 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 48 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 8 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 144 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 24 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 144 ]), &(nmpcWorkspace.sbar[ 24 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 36 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 6 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 108 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 18 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 108 ]), &(nmpcWorkspace.sbar[ 18 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 24 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 4 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 72 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 12 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 72 ]), &(nmpcWorkspace.sbar[ 12 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( &(nmpcWorkspace.evGu[ 12 ]), nmpcWorkspace.w1, &(nmpcWorkspace.g[ 2 ]) );
nmpc_macATw1QDy( &(nmpcWorkspace.evGx[ 36 ]), nmpcWorkspace.w1, &(nmpcWorkspace.QDy[ 6 ]), nmpcWorkspace.w2 );
nmpc_macQSbarW2( &(nmpcWorkspace.Q1[ 36 ]), &(nmpcWorkspace.sbar[ 6 ]), nmpcWorkspace.w2, nmpcWorkspace.w1 );
nmpc_macBTw1( nmpcWorkspace.evGu, nmpcWorkspace.w1, nmpcWorkspace.g );


}

void nmpc_expand(  )
{
int lRun1;
for (lRun1 = 0; lRun1 < 160; ++lRun1)
nmpcVariables.u[lRun1] += nmpcWorkspace.x[lRun1];

nmpcWorkspace.sbar[0] = nmpcWorkspace.Dx0[0];
nmpcWorkspace.sbar[1] = nmpcWorkspace.Dx0[1];
nmpcWorkspace.sbar[2] = nmpcWorkspace.Dx0[2];
nmpcWorkspace.sbar[3] = nmpcWorkspace.Dx0[3];
nmpcWorkspace.sbar[4] = nmpcWorkspace.Dx0[4];
nmpcWorkspace.sbar[5] = nmpcWorkspace.Dx0[5];
for (lRun1 = 0; lRun1 < 480; ++lRun1)
nmpcWorkspace.sbar[lRun1 + 6] = nmpcWorkspace.d[lRun1];

nmpc_expansionStep( nmpcWorkspace.evGx, nmpcWorkspace.evGu, nmpcWorkspace.x, nmpcWorkspace.sbar, &(nmpcWorkspace.sbar[ 6 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 36 ]), &(nmpcWorkspace.evGu[ 12 ]), &(nmpcWorkspace.x[ 2 ]), &(nmpcWorkspace.sbar[ 6 ]), &(nmpcWorkspace.sbar[ 12 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 72 ]), &(nmpcWorkspace.evGu[ 24 ]), &(nmpcWorkspace.x[ 4 ]), &(nmpcWorkspace.sbar[ 12 ]), &(nmpcWorkspace.sbar[ 18 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 108 ]), &(nmpcWorkspace.evGu[ 36 ]), &(nmpcWorkspace.x[ 6 ]), &(nmpcWorkspace.sbar[ 18 ]), &(nmpcWorkspace.sbar[ 24 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 144 ]), &(nmpcWorkspace.evGu[ 48 ]), &(nmpcWorkspace.x[ 8 ]), &(nmpcWorkspace.sbar[ 24 ]), &(nmpcWorkspace.sbar[ 30 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 180 ]), &(nmpcWorkspace.evGu[ 60 ]), &(nmpcWorkspace.x[ 10 ]), &(nmpcWorkspace.sbar[ 30 ]), &(nmpcWorkspace.sbar[ 36 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 216 ]), &(nmpcWorkspace.evGu[ 72 ]), &(nmpcWorkspace.x[ 12 ]), &(nmpcWorkspace.sbar[ 36 ]), &(nmpcWorkspace.sbar[ 42 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 252 ]), &(nmpcWorkspace.evGu[ 84 ]), &(nmpcWorkspace.x[ 14 ]), &(nmpcWorkspace.sbar[ 42 ]), &(nmpcWorkspace.sbar[ 48 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 288 ]), &(nmpcWorkspace.evGu[ 96 ]), &(nmpcWorkspace.x[ 16 ]), &(nmpcWorkspace.sbar[ 48 ]), &(nmpcWorkspace.sbar[ 54 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 324 ]), &(nmpcWorkspace.evGu[ 108 ]), &(nmpcWorkspace.x[ 18 ]), &(nmpcWorkspace.sbar[ 54 ]), &(nmpcWorkspace.sbar[ 60 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 360 ]), &(nmpcWorkspace.evGu[ 120 ]), &(nmpcWorkspace.x[ 20 ]), &(nmpcWorkspace.sbar[ 60 ]), &(nmpcWorkspace.sbar[ 66 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 396 ]), &(nmpcWorkspace.evGu[ 132 ]), &(nmpcWorkspace.x[ 22 ]), &(nmpcWorkspace.sbar[ 66 ]), &(nmpcWorkspace.sbar[ 72 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 432 ]), &(nmpcWorkspace.evGu[ 144 ]), &(nmpcWorkspace.x[ 24 ]), &(nmpcWorkspace.sbar[ 72 ]), &(nmpcWorkspace.sbar[ 78 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 468 ]), &(nmpcWorkspace.evGu[ 156 ]), &(nmpcWorkspace.x[ 26 ]), &(nmpcWorkspace.sbar[ 78 ]), &(nmpcWorkspace.sbar[ 84 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 504 ]), &(nmpcWorkspace.evGu[ 168 ]), &(nmpcWorkspace.x[ 28 ]), &(nmpcWorkspace.sbar[ 84 ]), &(nmpcWorkspace.sbar[ 90 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 540 ]), &(nmpcWorkspace.evGu[ 180 ]), &(nmpcWorkspace.x[ 30 ]), &(nmpcWorkspace.sbar[ 90 ]), &(nmpcWorkspace.sbar[ 96 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 576 ]), &(nmpcWorkspace.evGu[ 192 ]), &(nmpcWorkspace.x[ 32 ]), &(nmpcWorkspace.sbar[ 96 ]), &(nmpcWorkspace.sbar[ 102 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 612 ]), &(nmpcWorkspace.evGu[ 204 ]), &(nmpcWorkspace.x[ 34 ]), &(nmpcWorkspace.sbar[ 102 ]), &(nmpcWorkspace.sbar[ 108 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 648 ]), &(nmpcWorkspace.evGu[ 216 ]), &(nmpcWorkspace.x[ 36 ]), &(nmpcWorkspace.sbar[ 108 ]), &(nmpcWorkspace.sbar[ 114 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 684 ]), &(nmpcWorkspace.evGu[ 228 ]), &(nmpcWorkspace.x[ 38 ]), &(nmpcWorkspace.sbar[ 114 ]), &(nmpcWorkspace.sbar[ 120 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 720 ]), &(nmpcWorkspace.evGu[ 240 ]), &(nmpcWorkspace.x[ 40 ]), &(nmpcWorkspace.sbar[ 120 ]), &(nmpcWorkspace.sbar[ 126 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 756 ]), &(nmpcWorkspace.evGu[ 252 ]), &(nmpcWorkspace.x[ 42 ]), &(nmpcWorkspace.sbar[ 126 ]), &(nmpcWorkspace.sbar[ 132 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 792 ]), &(nmpcWorkspace.evGu[ 264 ]), &(nmpcWorkspace.x[ 44 ]), &(nmpcWorkspace.sbar[ 132 ]), &(nmpcWorkspace.sbar[ 138 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 828 ]), &(nmpcWorkspace.evGu[ 276 ]), &(nmpcWorkspace.x[ 46 ]), &(nmpcWorkspace.sbar[ 138 ]), &(nmpcWorkspace.sbar[ 144 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 864 ]), &(nmpcWorkspace.evGu[ 288 ]), &(nmpcWorkspace.x[ 48 ]), &(nmpcWorkspace.sbar[ 144 ]), &(nmpcWorkspace.sbar[ 150 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 900 ]), &(nmpcWorkspace.evGu[ 300 ]), &(nmpcWorkspace.x[ 50 ]), &(nmpcWorkspace.sbar[ 150 ]), &(nmpcWorkspace.sbar[ 156 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 936 ]), &(nmpcWorkspace.evGu[ 312 ]), &(nmpcWorkspace.x[ 52 ]), &(nmpcWorkspace.sbar[ 156 ]), &(nmpcWorkspace.sbar[ 162 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 972 ]), &(nmpcWorkspace.evGu[ 324 ]), &(nmpcWorkspace.x[ 54 ]), &(nmpcWorkspace.sbar[ 162 ]), &(nmpcWorkspace.sbar[ 168 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1008 ]), &(nmpcWorkspace.evGu[ 336 ]), &(nmpcWorkspace.x[ 56 ]), &(nmpcWorkspace.sbar[ 168 ]), &(nmpcWorkspace.sbar[ 174 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1044 ]), &(nmpcWorkspace.evGu[ 348 ]), &(nmpcWorkspace.x[ 58 ]), &(nmpcWorkspace.sbar[ 174 ]), &(nmpcWorkspace.sbar[ 180 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1080 ]), &(nmpcWorkspace.evGu[ 360 ]), &(nmpcWorkspace.x[ 60 ]), &(nmpcWorkspace.sbar[ 180 ]), &(nmpcWorkspace.sbar[ 186 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1116 ]), &(nmpcWorkspace.evGu[ 372 ]), &(nmpcWorkspace.x[ 62 ]), &(nmpcWorkspace.sbar[ 186 ]), &(nmpcWorkspace.sbar[ 192 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1152 ]), &(nmpcWorkspace.evGu[ 384 ]), &(nmpcWorkspace.x[ 64 ]), &(nmpcWorkspace.sbar[ 192 ]), &(nmpcWorkspace.sbar[ 198 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1188 ]), &(nmpcWorkspace.evGu[ 396 ]), &(nmpcWorkspace.x[ 66 ]), &(nmpcWorkspace.sbar[ 198 ]), &(nmpcWorkspace.sbar[ 204 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1224 ]), &(nmpcWorkspace.evGu[ 408 ]), &(nmpcWorkspace.x[ 68 ]), &(nmpcWorkspace.sbar[ 204 ]), &(nmpcWorkspace.sbar[ 210 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1260 ]), &(nmpcWorkspace.evGu[ 420 ]), &(nmpcWorkspace.x[ 70 ]), &(nmpcWorkspace.sbar[ 210 ]), &(nmpcWorkspace.sbar[ 216 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1296 ]), &(nmpcWorkspace.evGu[ 432 ]), &(nmpcWorkspace.x[ 72 ]), &(nmpcWorkspace.sbar[ 216 ]), &(nmpcWorkspace.sbar[ 222 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1332 ]), &(nmpcWorkspace.evGu[ 444 ]), &(nmpcWorkspace.x[ 74 ]), &(nmpcWorkspace.sbar[ 222 ]), &(nmpcWorkspace.sbar[ 228 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1368 ]), &(nmpcWorkspace.evGu[ 456 ]), &(nmpcWorkspace.x[ 76 ]), &(nmpcWorkspace.sbar[ 228 ]), &(nmpcWorkspace.sbar[ 234 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1404 ]), &(nmpcWorkspace.evGu[ 468 ]), &(nmpcWorkspace.x[ 78 ]), &(nmpcWorkspace.sbar[ 234 ]), &(nmpcWorkspace.sbar[ 240 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1440 ]), &(nmpcWorkspace.evGu[ 480 ]), &(nmpcWorkspace.x[ 80 ]), &(nmpcWorkspace.sbar[ 240 ]), &(nmpcWorkspace.sbar[ 246 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1476 ]), &(nmpcWorkspace.evGu[ 492 ]), &(nmpcWorkspace.x[ 82 ]), &(nmpcWorkspace.sbar[ 246 ]), &(nmpcWorkspace.sbar[ 252 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1512 ]), &(nmpcWorkspace.evGu[ 504 ]), &(nmpcWorkspace.x[ 84 ]), &(nmpcWorkspace.sbar[ 252 ]), &(nmpcWorkspace.sbar[ 258 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1548 ]), &(nmpcWorkspace.evGu[ 516 ]), &(nmpcWorkspace.x[ 86 ]), &(nmpcWorkspace.sbar[ 258 ]), &(nmpcWorkspace.sbar[ 264 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1584 ]), &(nmpcWorkspace.evGu[ 528 ]), &(nmpcWorkspace.x[ 88 ]), &(nmpcWorkspace.sbar[ 264 ]), &(nmpcWorkspace.sbar[ 270 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1620 ]), &(nmpcWorkspace.evGu[ 540 ]), &(nmpcWorkspace.x[ 90 ]), &(nmpcWorkspace.sbar[ 270 ]), &(nmpcWorkspace.sbar[ 276 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1656 ]), &(nmpcWorkspace.evGu[ 552 ]), &(nmpcWorkspace.x[ 92 ]), &(nmpcWorkspace.sbar[ 276 ]), &(nmpcWorkspace.sbar[ 282 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1692 ]), &(nmpcWorkspace.evGu[ 564 ]), &(nmpcWorkspace.x[ 94 ]), &(nmpcWorkspace.sbar[ 282 ]), &(nmpcWorkspace.sbar[ 288 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1728 ]), &(nmpcWorkspace.evGu[ 576 ]), &(nmpcWorkspace.x[ 96 ]), &(nmpcWorkspace.sbar[ 288 ]), &(nmpcWorkspace.sbar[ 294 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1764 ]), &(nmpcWorkspace.evGu[ 588 ]), &(nmpcWorkspace.x[ 98 ]), &(nmpcWorkspace.sbar[ 294 ]), &(nmpcWorkspace.sbar[ 300 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1800 ]), &(nmpcWorkspace.evGu[ 600 ]), &(nmpcWorkspace.x[ 100 ]), &(nmpcWorkspace.sbar[ 300 ]), &(nmpcWorkspace.sbar[ 306 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1836 ]), &(nmpcWorkspace.evGu[ 612 ]), &(nmpcWorkspace.x[ 102 ]), &(nmpcWorkspace.sbar[ 306 ]), &(nmpcWorkspace.sbar[ 312 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1872 ]), &(nmpcWorkspace.evGu[ 624 ]), &(nmpcWorkspace.x[ 104 ]), &(nmpcWorkspace.sbar[ 312 ]), &(nmpcWorkspace.sbar[ 318 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1908 ]), &(nmpcWorkspace.evGu[ 636 ]), &(nmpcWorkspace.x[ 106 ]), &(nmpcWorkspace.sbar[ 318 ]), &(nmpcWorkspace.sbar[ 324 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1944 ]), &(nmpcWorkspace.evGu[ 648 ]), &(nmpcWorkspace.x[ 108 ]), &(nmpcWorkspace.sbar[ 324 ]), &(nmpcWorkspace.sbar[ 330 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 1980 ]), &(nmpcWorkspace.evGu[ 660 ]), &(nmpcWorkspace.x[ 110 ]), &(nmpcWorkspace.sbar[ 330 ]), &(nmpcWorkspace.sbar[ 336 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2016 ]), &(nmpcWorkspace.evGu[ 672 ]), &(nmpcWorkspace.x[ 112 ]), &(nmpcWorkspace.sbar[ 336 ]), &(nmpcWorkspace.sbar[ 342 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2052 ]), &(nmpcWorkspace.evGu[ 684 ]), &(nmpcWorkspace.x[ 114 ]), &(nmpcWorkspace.sbar[ 342 ]), &(nmpcWorkspace.sbar[ 348 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2088 ]), &(nmpcWorkspace.evGu[ 696 ]), &(nmpcWorkspace.x[ 116 ]), &(nmpcWorkspace.sbar[ 348 ]), &(nmpcWorkspace.sbar[ 354 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2124 ]), &(nmpcWorkspace.evGu[ 708 ]), &(nmpcWorkspace.x[ 118 ]), &(nmpcWorkspace.sbar[ 354 ]), &(nmpcWorkspace.sbar[ 360 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2160 ]), &(nmpcWorkspace.evGu[ 720 ]), &(nmpcWorkspace.x[ 120 ]), &(nmpcWorkspace.sbar[ 360 ]), &(nmpcWorkspace.sbar[ 366 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2196 ]), &(nmpcWorkspace.evGu[ 732 ]), &(nmpcWorkspace.x[ 122 ]), &(nmpcWorkspace.sbar[ 366 ]), &(nmpcWorkspace.sbar[ 372 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2232 ]), &(nmpcWorkspace.evGu[ 744 ]), &(nmpcWorkspace.x[ 124 ]), &(nmpcWorkspace.sbar[ 372 ]), &(nmpcWorkspace.sbar[ 378 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2268 ]), &(nmpcWorkspace.evGu[ 756 ]), &(nmpcWorkspace.x[ 126 ]), &(nmpcWorkspace.sbar[ 378 ]), &(nmpcWorkspace.sbar[ 384 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2304 ]), &(nmpcWorkspace.evGu[ 768 ]), &(nmpcWorkspace.x[ 128 ]), &(nmpcWorkspace.sbar[ 384 ]), &(nmpcWorkspace.sbar[ 390 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2340 ]), &(nmpcWorkspace.evGu[ 780 ]), &(nmpcWorkspace.x[ 130 ]), &(nmpcWorkspace.sbar[ 390 ]), &(nmpcWorkspace.sbar[ 396 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2376 ]), &(nmpcWorkspace.evGu[ 792 ]), &(nmpcWorkspace.x[ 132 ]), &(nmpcWorkspace.sbar[ 396 ]), &(nmpcWorkspace.sbar[ 402 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2412 ]), &(nmpcWorkspace.evGu[ 804 ]), &(nmpcWorkspace.x[ 134 ]), &(nmpcWorkspace.sbar[ 402 ]), &(nmpcWorkspace.sbar[ 408 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2448 ]), &(nmpcWorkspace.evGu[ 816 ]), &(nmpcWorkspace.x[ 136 ]), &(nmpcWorkspace.sbar[ 408 ]), &(nmpcWorkspace.sbar[ 414 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2484 ]), &(nmpcWorkspace.evGu[ 828 ]), &(nmpcWorkspace.x[ 138 ]), &(nmpcWorkspace.sbar[ 414 ]), &(nmpcWorkspace.sbar[ 420 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2520 ]), &(nmpcWorkspace.evGu[ 840 ]), &(nmpcWorkspace.x[ 140 ]), &(nmpcWorkspace.sbar[ 420 ]), &(nmpcWorkspace.sbar[ 426 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2556 ]), &(nmpcWorkspace.evGu[ 852 ]), &(nmpcWorkspace.x[ 142 ]), &(nmpcWorkspace.sbar[ 426 ]), &(nmpcWorkspace.sbar[ 432 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2592 ]), &(nmpcWorkspace.evGu[ 864 ]), &(nmpcWorkspace.x[ 144 ]), &(nmpcWorkspace.sbar[ 432 ]), &(nmpcWorkspace.sbar[ 438 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2628 ]), &(nmpcWorkspace.evGu[ 876 ]), &(nmpcWorkspace.x[ 146 ]), &(nmpcWorkspace.sbar[ 438 ]), &(nmpcWorkspace.sbar[ 444 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2664 ]), &(nmpcWorkspace.evGu[ 888 ]), &(nmpcWorkspace.x[ 148 ]), &(nmpcWorkspace.sbar[ 444 ]), &(nmpcWorkspace.sbar[ 450 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2700 ]), &(nmpcWorkspace.evGu[ 900 ]), &(nmpcWorkspace.x[ 150 ]), &(nmpcWorkspace.sbar[ 450 ]), &(nmpcWorkspace.sbar[ 456 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2736 ]), &(nmpcWorkspace.evGu[ 912 ]), &(nmpcWorkspace.x[ 152 ]), &(nmpcWorkspace.sbar[ 456 ]), &(nmpcWorkspace.sbar[ 462 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2772 ]), &(nmpcWorkspace.evGu[ 924 ]), &(nmpcWorkspace.x[ 154 ]), &(nmpcWorkspace.sbar[ 462 ]), &(nmpcWorkspace.sbar[ 468 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2808 ]), &(nmpcWorkspace.evGu[ 936 ]), &(nmpcWorkspace.x[ 156 ]), &(nmpcWorkspace.sbar[ 468 ]), &(nmpcWorkspace.sbar[ 474 ]) );
nmpc_expansionStep( &(nmpcWorkspace.evGx[ 2844 ]), &(nmpcWorkspace.evGu[ 948 ]), &(nmpcWorkspace.x[ 158 ]), &(nmpcWorkspace.sbar[ 474 ]), &(nmpcWorkspace.sbar[ 480 ]) );
for (lRun1 = 0; lRun1 < 486; ++lRun1)
nmpcVariables.x[lRun1] += nmpcWorkspace.sbar[lRun1];

}

int nmpc_preparationStep(  )
{
int ret;

ret = nmpc_modelSimulation();
nmpc_evaluateObjective(  );
nmpc_condensePrep(  );
return ret;
}

int nmpc_feedbackStep(  )
{
int tmp;

nmpc_condenseFdb(  );

tmp = nmpc_solve( );

nmpc_expand(  );
return tmp;
}

int nmpc_initializeSolver(  )
{
int ret;

/* This is a function which must be called once before any other function call! */


ret = 0;

memset(&nmpcWorkspace, 0, sizeof( nmpcWorkspace ));
return ret;
}

void nmpc_initializeNodesByForwardSimulation(  )
{
int index;
for (index = 0; index < 80; ++index)
{
nmpcWorkspace.state[0] = nmpcVariables.x[index * 6];
nmpcWorkspace.state[1] = nmpcVariables.x[index * 6 + 1];
nmpcWorkspace.state[2] = nmpcVariables.x[index * 6 + 2];
nmpcWorkspace.state[3] = nmpcVariables.x[index * 6 + 3];
nmpcWorkspace.state[4] = nmpcVariables.x[index * 6 + 4];
nmpcWorkspace.state[5] = nmpcVariables.x[index * 6 + 5];
nmpcWorkspace.state[54] = nmpcVariables.u[index * 2];
nmpcWorkspace.state[55] = nmpcVariables.u[index * 2 + 1];

nmpc_integrate(nmpcWorkspace.state, index == 0);

nmpcVariables.x[index * 6 + 6] = nmpcWorkspace.state[0];
nmpcVariables.x[index * 6 + 7] = nmpcWorkspace.state[1];
nmpcVariables.x[index * 6 + 8] = nmpcWorkspace.state[2];
nmpcVariables.x[index * 6 + 9] = nmpcWorkspace.state[3];
nmpcVariables.x[index * 6 + 10] = nmpcWorkspace.state[4];
nmpcVariables.x[index * 6 + 11] = nmpcWorkspace.state[5];
}
}

void nmpc_shiftStates( int strategy, real_t* const xEnd, real_t* const uEnd )
{
int index;
for (index = 0; index < 80; ++index)
{
nmpcVariables.x[index * 6] = nmpcVariables.x[index * 6 + 6];
nmpcVariables.x[index * 6 + 1] = nmpcVariables.x[index * 6 + 7];
nmpcVariables.x[index * 6 + 2] = nmpcVariables.x[index * 6 + 8];
nmpcVariables.x[index * 6 + 3] = nmpcVariables.x[index * 6 + 9];
nmpcVariables.x[index * 6 + 4] = nmpcVariables.x[index * 6 + 10];
nmpcVariables.x[index * 6 + 5] = nmpcVariables.x[index * 6 + 11];
}

if (strategy == 1 && xEnd != 0)
{
nmpcVariables.x[480] = xEnd[0];
nmpcVariables.x[481] = xEnd[1];
nmpcVariables.x[482] = xEnd[2];
nmpcVariables.x[483] = xEnd[3];
nmpcVariables.x[484] = xEnd[4];
nmpcVariables.x[485] = xEnd[5];
}
else if (strategy == 2) 
{
nmpcWorkspace.state[0] = nmpcVariables.x[480];
nmpcWorkspace.state[1] = nmpcVariables.x[481];
nmpcWorkspace.state[2] = nmpcVariables.x[482];
nmpcWorkspace.state[3] = nmpcVariables.x[483];
nmpcWorkspace.state[4] = nmpcVariables.x[484];
nmpcWorkspace.state[5] = nmpcVariables.x[485];
if (uEnd != 0)
{
nmpcWorkspace.state[54] = uEnd[0];
nmpcWorkspace.state[55] = uEnd[1];
}
else
{
nmpcWorkspace.state[54] = nmpcVariables.u[158];
nmpcWorkspace.state[55] = nmpcVariables.u[159];
}

nmpc_integrate(nmpcWorkspace.state, 1);

nmpcVariables.x[480] = nmpcWorkspace.state[0];
nmpcVariables.x[481] = nmpcWorkspace.state[1];
nmpcVariables.x[482] = nmpcWorkspace.state[2];
nmpcVariables.x[483] = nmpcWorkspace.state[3];
nmpcVariables.x[484] = nmpcWorkspace.state[4];
nmpcVariables.x[485] = nmpcWorkspace.state[5];
}
}

void nmpc_shiftControls( real_t* const uEnd )
{
int index;
for (index = 0; index < 79; ++index)
{
nmpcVariables.u[index * 2] = nmpcVariables.u[index * 2 + 2];
nmpcVariables.u[index * 2 + 1] = nmpcVariables.u[index * 2 + 3];
}

if (uEnd != 0)
{
nmpcVariables.u[158] = uEnd[0];
nmpcVariables.u[159] = uEnd[1];
}
}

real_t nmpc_getKKT(  )
{
real_t kkt;

int index;
real_t prd;

kkt = + nmpcWorkspace.g[0]*nmpcWorkspace.x[0] + nmpcWorkspace.g[1]*nmpcWorkspace.x[1] + nmpcWorkspace.g[2]*nmpcWorkspace.x[2] + nmpcWorkspace.g[3]*nmpcWorkspace.x[3] + nmpcWorkspace.g[4]*nmpcWorkspace.x[4] + nmpcWorkspace.g[5]*nmpcWorkspace.x[5] + nmpcWorkspace.g[6]*nmpcWorkspace.x[6] + nmpcWorkspace.g[7]*nmpcWorkspace.x[7] + nmpcWorkspace.g[8]*nmpcWorkspace.x[8] + nmpcWorkspace.g[9]*nmpcWorkspace.x[9] + nmpcWorkspace.g[10]*nmpcWorkspace.x[10] + nmpcWorkspace.g[11]*nmpcWorkspace.x[11] + nmpcWorkspace.g[12]*nmpcWorkspace.x[12] + nmpcWorkspace.g[13]*nmpcWorkspace.x[13] + nmpcWorkspace.g[14]*nmpcWorkspace.x[14] + nmpcWorkspace.g[15]*nmpcWorkspace.x[15] + nmpcWorkspace.g[16]*nmpcWorkspace.x[16] + nmpcWorkspace.g[17]*nmpcWorkspace.x[17] + nmpcWorkspace.g[18]*nmpcWorkspace.x[18] + nmpcWorkspace.g[19]*nmpcWorkspace.x[19] + nmpcWorkspace.g[20]*nmpcWorkspace.x[20] + nmpcWorkspace.g[21]*nmpcWorkspace.x[21] + nmpcWorkspace.g[22]*nmpcWorkspace.x[22] + nmpcWorkspace.g[23]*nmpcWorkspace.x[23] + nmpcWorkspace.g[24]*nmpcWorkspace.x[24] + nmpcWorkspace.g[25]*nmpcWorkspace.x[25] + nmpcWorkspace.g[26]*nmpcWorkspace.x[26] + nmpcWorkspace.g[27]*nmpcWorkspace.x[27] + nmpcWorkspace.g[28]*nmpcWorkspace.x[28] + nmpcWorkspace.g[29]*nmpcWorkspace.x[29] + nmpcWorkspace.g[30]*nmpcWorkspace.x[30] + nmpcWorkspace.g[31]*nmpcWorkspace.x[31] + nmpcWorkspace.g[32]*nmpcWorkspace.x[32] + nmpcWorkspace.g[33]*nmpcWorkspace.x[33] + nmpcWorkspace.g[34]*nmpcWorkspace.x[34] + nmpcWorkspace.g[35]*nmpcWorkspace.x[35] + nmpcWorkspace.g[36]*nmpcWorkspace.x[36] + nmpcWorkspace.g[37]*nmpcWorkspace.x[37] + nmpcWorkspace.g[38]*nmpcWorkspace.x[38] + nmpcWorkspace.g[39]*nmpcWorkspace.x[39] + nmpcWorkspace.g[40]*nmpcWorkspace.x[40] + nmpcWorkspace.g[41]*nmpcWorkspace.x[41] + nmpcWorkspace.g[42]*nmpcWorkspace.x[42] + nmpcWorkspace.g[43]*nmpcWorkspace.x[43] + nmpcWorkspace.g[44]*nmpcWorkspace.x[44] + nmpcWorkspace.g[45]*nmpcWorkspace.x[45] + nmpcWorkspace.g[46]*nmpcWorkspace.x[46] + nmpcWorkspace.g[47]*nmpcWorkspace.x[47] + nmpcWorkspace.g[48]*nmpcWorkspace.x[48] + nmpcWorkspace.g[49]*nmpcWorkspace.x[49] + nmpcWorkspace.g[50]*nmpcWorkspace.x[50] + nmpcWorkspace.g[51]*nmpcWorkspace.x[51] + nmpcWorkspace.g[52]*nmpcWorkspace.x[52] + nmpcWorkspace.g[53]*nmpcWorkspace.x[53] + nmpcWorkspace.g[54]*nmpcWorkspace.x[54] + nmpcWorkspace.g[55]*nmpcWorkspace.x[55] + nmpcWorkspace.g[56]*nmpcWorkspace.x[56] + nmpcWorkspace.g[57]*nmpcWorkspace.x[57] + nmpcWorkspace.g[58]*nmpcWorkspace.x[58] + nmpcWorkspace.g[59]*nmpcWorkspace.x[59] + nmpcWorkspace.g[60]*nmpcWorkspace.x[60] + nmpcWorkspace.g[61]*nmpcWorkspace.x[61] + nmpcWorkspace.g[62]*nmpcWorkspace.x[62] + nmpcWorkspace.g[63]*nmpcWorkspace.x[63] + nmpcWorkspace.g[64]*nmpcWorkspace.x[64] + nmpcWorkspace.g[65]*nmpcWorkspace.x[65] + nmpcWorkspace.g[66]*nmpcWorkspace.x[66] + nmpcWorkspace.g[67]*nmpcWorkspace.x[67] + nmpcWorkspace.g[68]*nmpcWorkspace.x[68] + nmpcWorkspace.g[69]*nmpcWorkspace.x[69] + nmpcWorkspace.g[70]*nmpcWorkspace.x[70] + nmpcWorkspace.g[71]*nmpcWorkspace.x[71] + nmpcWorkspace.g[72]*nmpcWorkspace.x[72] + nmpcWorkspace.g[73]*nmpcWorkspace.x[73] + nmpcWorkspace.g[74]*nmpcWorkspace.x[74] + nmpcWorkspace.g[75]*nmpcWorkspace.x[75] + nmpcWorkspace.g[76]*nmpcWorkspace.x[76] + nmpcWorkspace.g[77]*nmpcWorkspace.x[77] + nmpcWorkspace.g[78]*nmpcWorkspace.x[78] + nmpcWorkspace.g[79]*nmpcWorkspace.x[79] + nmpcWorkspace.g[80]*nmpcWorkspace.x[80] + nmpcWorkspace.g[81]*nmpcWorkspace.x[81] + nmpcWorkspace.g[82]*nmpcWorkspace.x[82] + nmpcWorkspace.g[83]*nmpcWorkspace.x[83] + nmpcWorkspace.g[84]*nmpcWorkspace.x[84] + nmpcWorkspace.g[85]*nmpcWorkspace.x[85] + nmpcWorkspace.g[86]*nmpcWorkspace.x[86] + nmpcWorkspace.g[87]*nmpcWorkspace.x[87] + nmpcWorkspace.g[88]*nmpcWorkspace.x[88] + nmpcWorkspace.g[89]*nmpcWorkspace.x[89] + nmpcWorkspace.g[90]*nmpcWorkspace.x[90] + nmpcWorkspace.g[91]*nmpcWorkspace.x[91] + nmpcWorkspace.g[92]*nmpcWorkspace.x[92] + nmpcWorkspace.g[93]*nmpcWorkspace.x[93] + nmpcWorkspace.g[94]*nmpcWorkspace.x[94] + nmpcWorkspace.g[95]*nmpcWorkspace.x[95] + nmpcWorkspace.g[96]*nmpcWorkspace.x[96] + nmpcWorkspace.g[97]*nmpcWorkspace.x[97] + nmpcWorkspace.g[98]*nmpcWorkspace.x[98] + nmpcWorkspace.g[99]*nmpcWorkspace.x[99] + nmpcWorkspace.g[100]*nmpcWorkspace.x[100] + nmpcWorkspace.g[101]*nmpcWorkspace.x[101] + nmpcWorkspace.g[102]*nmpcWorkspace.x[102] + nmpcWorkspace.g[103]*nmpcWorkspace.x[103] + nmpcWorkspace.g[104]*nmpcWorkspace.x[104] + nmpcWorkspace.g[105]*nmpcWorkspace.x[105] + nmpcWorkspace.g[106]*nmpcWorkspace.x[106] + nmpcWorkspace.g[107]*nmpcWorkspace.x[107] + nmpcWorkspace.g[108]*nmpcWorkspace.x[108] + nmpcWorkspace.g[109]*nmpcWorkspace.x[109] + nmpcWorkspace.g[110]*nmpcWorkspace.x[110] + nmpcWorkspace.g[111]*nmpcWorkspace.x[111] + nmpcWorkspace.g[112]*nmpcWorkspace.x[112] + nmpcWorkspace.g[113]*nmpcWorkspace.x[113] + nmpcWorkspace.g[114]*nmpcWorkspace.x[114] + nmpcWorkspace.g[115]*nmpcWorkspace.x[115] + nmpcWorkspace.g[116]*nmpcWorkspace.x[116] + nmpcWorkspace.g[117]*nmpcWorkspace.x[117] + nmpcWorkspace.g[118]*nmpcWorkspace.x[118] + nmpcWorkspace.g[119]*nmpcWorkspace.x[119] + nmpcWorkspace.g[120]*nmpcWorkspace.x[120] + nmpcWorkspace.g[121]*nmpcWorkspace.x[121] + nmpcWorkspace.g[122]*nmpcWorkspace.x[122] + nmpcWorkspace.g[123]*nmpcWorkspace.x[123] + nmpcWorkspace.g[124]*nmpcWorkspace.x[124] + nmpcWorkspace.g[125]*nmpcWorkspace.x[125] + nmpcWorkspace.g[126]*nmpcWorkspace.x[126] + nmpcWorkspace.g[127]*nmpcWorkspace.x[127] + nmpcWorkspace.g[128]*nmpcWorkspace.x[128] + nmpcWorkspace.g[129]*nmpcWorkspace.x[129] + nmpcWorkspace.g[130]*nmpcWorkspace.x[130] + nmpcWorkspace.g[131]*nmpcWorkspace.x[131] + nmpcWorkspace.g[132]*nmpcWorkspace.x[132] + nmpcWorkspace.g[133]*nmpcWorkspace.x[133] + nmpcWorkspace.g[134]*nmpcWorkspace.x[134] + nmpcWorkspace.g[135]*nmpcWorkspace.x[135] + nmpcWorkspace.g[136]*nmpcWorkspace.x[136] + nmpcWorkspace.g[137]*nmpcWorkspace.x[137] + nmpcWorkspace.g[138]*nmpcWorkspace.x[138] + nmpcWorkspace.g[139]*nmpcWorkspace.x[139] + nmpcWorkspace.g[140]*nmpcWorkspace.x[140] + nmpcWorkspace.g[141]*nmpcWorkspace.x[141] + nmpcWorkspace.g[142]*nmpcWorkspace.x[142] + nmpcWorkspace.g[143]*nmpcWorkspace.x[143] + nmpcWorkspace.g[144]*nmpcWorkspace.x[144] + nmpcWorkspace.g[145]*nmpcWorkspace.x[145] + nmpcWorkspace.g[146]*nmpcWorkspace.x[146] + nmpcWorkspace.g[147]*nmpcWorkspace.x[147] + nmpcWorkspace.g[148]*nmpcWorkspace.x[148] + nmpcWorkspace.g[149]*nmpcWorkspace.x[149] + nmpcWorkspace.g[150]*nmpcWorkspace.x[150] + nmpcWorkspace.g[151]*nmpcWorkspace.x[151] + nmpcWorkspace.g[152]*nmpcWorkspace.x[152] + nmpcWorkspace.g[153]*nmpcWorkspace.x[153] + nmpcWorkspace.g[154]*nmpcWorkspace.x[154] + nmpcWorkspace.g[155]*nmpcWorkspace.x[155] + nmpcWorkspace.g[156]*nmpcWorkspace.x[156] + nmpcWorkspace.g[157]*nmpcWorkspace.x[157] + nmpcWorkspace.g[158]*nmpcWorkspace.x[158] + nmpcWorkspace.g[159]*nmpcWorkspace.x[159];
kkt = fabs( kkt );
for (index = 0; index < 160; ++index)
{
prd = nmpcWorkspace.y[index];
if (prd > 1e-12)
kkt += fabs(nmpcWorkspace.lb[index] * prd);
else if (prd < -1e-12)
kkt += fabs(nmpcWorkspace.ub[index] * prd);
}
return kkt;
}

real_t nmpc_getObjective(  )
{
real_t objVal;

int lRun1;
/** Row vector of size: 8 */
real_t tmpDy[ 8 ];

/** Row vector of size: 6 */
real_t tmpDyN[ 6 ];

for (lRun1 = 0; lRun1 < 80; ++lRun1)
{
nmpcWorkspace.objValueIn[0] = nmpcVariables.x[lRun1 * 6];
nmpcWorkspace.objValueIn[1] = nmpcVariables.x[lRun1 * 6 + 1];
nmpcWorkspace.objValueIn[2] = nmpcVariables.x[lRun1 * 6 + 2];
nmpcWorkspace.objValueIn[3] = nmpcVariables.x[lRun1 * 6 + 3];
nmpcWorkspace.objValueIn[4] = nmpcVariables.x[lRun1 * 6 + 4];
nmpcWorkspace.objValueIn[5] = nmpcVariables.x[lRun1 * 6 + 5];
nmpcWorkspace.objValueIn[6] = nmpcVariables.u[lRun1 * 2];
nmpcWorkspace.objValueIn[7] = nmpcVariables.u[lRun1 * 2 + 1];

nmpc_evaluateLSQ( nmpcWorkspace.objValueIn, nmpcWorkspace.objValueOut );
nmpcWorkspace.Dy[lRun1 * 8] = nmpcWorkspace.objValueOut[0] - nmpcVariables.y[lRun1 * 8];
nmpcWorkspace.Dy[lRun1 * 8 + 1] = nmpcWorkspace.objValueOut[1] - nmpcVariables.y[lRun1 * 8 + 1];
nmpcWorkspace.Dy[lRun1 * 8 + 2] = nmpcWorkspace.objValueOut[2] - nmpcVariables.y[lRun1 * 8 + 2];
nmpcWorkspace.Dy[lRun1 * 8 + 3] = nmpcWorkspace.objValueOut[3] - nmpcVariables.y[lRun1 * 8 + 3];
nmpcWorkspace.Dy[lRun1 * 8 + 4] = nmpcWorkspace.objValueOut[4] - nmpcVariables.y[lRun1 * 8 + 4];
nmpcWorkspace.Dy[lRun1 * 8 + 5] = nmpcWorkspace.objValueOut[5] - nmpcVariables.y[lRun1 * 8 + 5];
nmpcWorkspace.Dy[lRun1 * 8 + 6] = nmpcWorkspace.objValueOut[6] - nmpcVariables.y[lRun1 * 8 + 6];
nmpcWorkspace.Dy[lRun1 * 8 + 7] = nmpcWorkspace.objValueOut[7] - nmpcVariables.y[lRun1 * 8 + 7];
}
nmpcWorkspace.objValueIn[0] = nmpcVariables.x[480];
nmpcWorkspace.objValueIn[1] = nmpcVariables.x[481];
nmpcWorkspace.objValueIn[2] = nmpcVariables.x[482];
nmpcWorkspace.objValueIn[3] = nmpcVariables.x[483];
nmpcWorkspace.objValueIn[4] = nmpcVariables.x[484];
nmpcWorkspace.objValueIn[5] = nmpcVariables.x[485];
nmpc_evaluateLSQEndTerm( nmpcWorkspace.objValueIn, nmpcWorkspace.objValueOut );
nmpcWorkspace.DyN[0] = nmpcWorkspace.objValueOut[0] - nmpcVariables.yN[0];
nmpcWorkspace.DyN[1] = nmpcWorkspace.objValueOut[1] - nmpcVariables.yN[1];
nmpcWorkspace.DyN[2] = nmpcWorkspace.objValueOut[2] - nmpcVariables.yN[2];
nmpcWorkspace.DyN[3] = nmpcWorkspace.objValueOut[3] - nmpcVariables.yN[3];
nmpcWorkspace.DyN[4] = nmpcWorkspace.objValueOut[4] - nmpcVariables.yN[4];
nmpcWorkspace.DyN[5] = nmpcWorkspace.objValueOut[5] - nmpcVariables.yN[5];
objVal = 0.0000000000000000e+00;
for (lRun1 = 0; lRun1 < 80; ++lRun1)
{
tmpDy[0] = + nmpcWorkspace.Dy[lRun1 * 8]*nmpcVariables.W[0];
tmpDy[1] = + nmpcWorkspace.Dy[lRun1 * 8 + 1]*nmpcVariables.W[9];
tmpDy[2] = + nmpcWorkspace.Dy[lRun1 * 8 + 2]*nmpcVariables.W[18];
tmpDy[3] = + nmpcWorkspace.Dy[lRun1 * 8 + 3]*nmpcVariables.W[27];
tmpDy[4] = + nmpcWorkspace.Dy[lRun1 * 8 + 4]*nmpcVariables.W[36];
tmpDy[5] = + nmpcWorkspace.Dy[lRun1 * 8 + 5]*nmpcVariables.W[45];
tmpDy[6] = + nmpcWorkspace.Dy[lRun1 * 8 + 6]*nmpcVariables.W[54];
tmpDy[7] = + nmpcWorkspace.Dy[lRun1 * 8 + 7]*nmpcVariables.W[63];
objVal += + nmpcWorkspace.Dy[lRun1 * 8]*tmpDy[0] + nmpcWorkspace.Dy[lRun1 * 8 + 1]*tmpDy[1] + nmpcWorkspace.Dy[lRun1 * 8 + 2]*tmpDy[2] + nmpcWorkspace.Dy[lRun1 * 8 + 3]*tmpDy[3] + nmpcWorkspace.Dy[lRun1 * 8 + 4]*tmpDy[4] + nmpcWorkspace.Dy[lRun1 * 8 + 5]*tmpDy[5] + nmpcWorkspace.Dy[lRun1 * 8 + 6]*tmpDy[6] + nmpcWorkspace.Dy[lRun1 * 8 + 7]*tmpDy[7];
}

tmpDyN[0] = + nmpcWorkspace.DyN[0]*nmpcVariables.WN[0];
tmpDyN[1] = + nmpcWorkspace.DyN[1]*nmpcVariables.WN[7];
tmpDyN[2] = + nmpcWorkspace.DyN[2]*nmpcVariables.WN[14];
tmpDyN[3] = + nmpcWorkspace.DyN[3]*nmpcVariables.WN[21];
tmpDyN[4] = + nmpcWorkspace.DyN[4]*nmpcVariables.WN[28];
tmpDyN[5] = + nmpcWorkspace.DyN[5]*nmpcVariables.WN[35];
objVal += + nmpcWorkspace.DyN[0]*tmpDyN[0] + nmpcWorkspace.DyN[1]*tmpDyN[1] + nmpcWorkspace.DyN[2]*tmpDyN[2] + nmpcWorkspace.DyN[3]*tmpDyN[3] + nmpcWorkspace.DyN[4]*tmpDyN[4] + nmpcWorkspace.DyN[5]*tmpDyN[5];

objVal *= 0.5;
return objVal;
}

