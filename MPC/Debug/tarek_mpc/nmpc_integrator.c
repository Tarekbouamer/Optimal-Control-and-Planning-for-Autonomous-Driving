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


void nmpc_rhs(const real_t* in, real_t* out)
{
const real_t* xd = in;
const real_t* u = in + 6;
/* Vector of auxiliary variables; number of elements: 17. */
real_t* a = nmpcWorkspace.rhs_aux;

/* Compute intermediate quantities: */
a[0] = ((((real_t)(5.0000000000000000e-01)*u[1])*(real_t)(5.8400000000000000e+02))/(real_t)(2.9199999999999998e-01));
a[1] = (cos((u[0]/(real_t)(1.6960000000000001e+01))));
a[2] = (atan((((xd[2]*(real_t)(1.0560000000000000e+00))+xd[1])/xd[0])));
a[3] = (((real_t)(0.0000000000000000e+00)-a[2])+(u[0]/(real_t)(1.6960000000000001e+01)));
a[4] = ((real_t)(8.3701705517399998e+04)*a[3]);
a[5] = (sin((u[0]/(real_t)(1.6960000000000001e+01))));
a[6] = ((real_t)(1.0000000000000001e-01)+(((real_t)(5.9999999999999998e-01)*xd[0])*xd[0]));
a[7] = (sin((u[0]/(real_t)(1.6960000000000001e+01))));
a[8] = (cos((u[0]/(real_t)(1.6960000000000001e+01))));
a[9] = (atan((((xd[2]*(real_t)(1.3439999999999999e+00))-xd[1])/xd[0])));
a[10] = ((real_t)(1.0235155003400000e+05)*a[9]);
a[11] = (cos((u[0]/(real_t)(1.6960000000000001e+01))));
a[12] = (sin((u[0]/(real_t)(1.6960000000000001e+01))));
a[13] = (cos(xd[3]));
a[14] = (sin(xd[3]));
a[15] = (sin(xd[3]));
a[16] = (cos(xd[3]));

/* Compute outputs: */
out[0] = ((real_t)(6.9930069930069930e-04)*(((((a[0]*a[1])+a[0])-(a[4]*a[5]))-a[6])+(((real_t)(1.4300000000000000e+03)*xd[2])*xd[1])));
out[1] = ((real_t)(6.9930069930069930e-04)*((((a[0]*a[7])+(a[4]*a[8]))+a[10])-(((real_t)(1.4300000000000000e+03)*xd[2])*xd[0])));
out[2] = ((real_t)(7.6923076923076923e-04)*(((real_t)(1.0560000000000000e+00)*((a[4]*a[11])+(a[0]*a[12])))-((real_t)(1.3439999999999999e+00)*a[10])));
out[3] = xd[2];
out[4] = ((xd[0]*a[13])-(xd[1]*a[14]));
out[5] = ((xd[0]*a[15])+(xd[1]*a[16]));
}



void nmpc_diffs(const real_t* in, real_t* out)
{
const real_t* xd = in;
const real_t* u = in + 6;
/* Vector of auxiliary variables; number of elements: 90. */
real_t* a = nmpcWorkspace.rhs_aux;

/* Compute intermediate quantities: */
a[0] = ((real_t)(1.0000000000000000e+00)/xd[0]);
a[1] = (a[0]*a[0]);
a[2] = ((real_t)(1.0000000000000000e+00)/((real_t)(1.0000000000000000e+00)+(pow((((xd[2]*(real_t)(1.0560000000000000e+00))+xd[1])/xd[0]),2))));
a[3] = (((real_t)(0.0000000000000000e+00)-(((xd[2]*(real_t)(1.0560000000000000e+00))+xd[1])*a[1]))*a[2]);
a[4] = ((real_t)(0.0000000000000000e+00)-a[3]);
a[5] = ((real_t)(8.3701705517399998e+04)*a[4]);
a[6] = (sin((u[0]/(real_t)(1.6960000000000001e+01))));
a[7] = (((real_t)(5.9999999999999998e-01)*xd[0])+((real_t)(5.9999999999999998e-01)*xd[0]));
a[8] = (a[0]*a[2]);
a[9] = ((real_t)(0.0000000000000000e+00)-a[8]);
a[10] = ((real_t)(8.3701705517399998e+04)*a[9]);
a[11] = (((real_t)(1.0560000000000000e+00)*a[0])*a[2]);
a[12] = ((real_t)(0.0000000000000000e+00)-a[11]);
a[13] = ((real_t)(8.3701705517399998e+04)*a[12]);
a[14] = ((((real_t)(5.0000000000000000e-01)*u[1])*(real_t)(5.8400000000000000e+02))/(real_t)(2.9199999999999998e-01));
a[15] = ((real_t)(1.0000000000000000e+00)/(real_t)(1.6960000000000001e+01));
a[16] = ((real_t)(-1.0000000000000000e+00)*(sin((u[0]/(real_t)(1.6960000000000001e+01)))));
a[17] = (a[15]*a[16]);
a[18] = ((real_t)(1.0000000000000000e+00)/(real_t)(1.6960000000000001e+01));
a[19] = ((real_t)(8.3701705517399998e+04)*a[18]);
a[20] = (atan((((xd[2]*(real_t)(1.0560000000000000e+00))+xd[1])/xd[0])));
a[21] = (((real_t)(0.0000000000000000e+00)-a[20])+(u[0]/(real_t)(1.6960000000000001e+01)));
a[22] = ((real_t)(8.3701705517399998e+04)*a[21]);
a[23] = ((real_t)(1.0000000000000000e+00)/(real_t)(1.6960000000000001e+01));
a[24] = (cos((u[0]/(real_t)(1.6960000000000001e+01))));
a[25] = (a[23]*a[24]);
a[26] = ((real_t)(1.0000000000000000e+00)/(real_t)(2.9199999999999998e-01));
a[27] = (((real_t)(2.9200000000000000e+02))*a[26]);
a[28] = (cos((u[0]/(real_t)(1.6960000000000001e+01))));
a[29] = (((real_t)(0.0000000000000000e+00)-(((xd[2]*(real_t)(1.0560000000000000e+00))+xd[1])*a[1]))*a[2]);
a[30] = ((real_t)(0.0000000000000000e+00)-a[29]);
a[31] = ((real_t)(8.3701705517399998e+04)*a[30]);
a[32] = (cos((u[0]/(real_t)(1.6960000000000001e+01))));
a[33] = ((real_t)(1.0000000000000000e+00)/xd[0]);
a[34] = (a[33]*a[33]);
a[35] = ((real_t)(1.0000000000000000e+00)/((real_t)(1.0000000000000000e+00)+(pow((((xd[2]*(real_t)(1.3439999999999999e+00))-xd[1])/xd[0]),2))));
a[36] = (((real_t)(0.0000000000000000e+00)-(((xd[2]*(real_t)(1.3439999999999999e+00))-xd[1])*a[34]))*a[35]);
a[37] = ((real_t)(1.0235155003400000e+05)*a[36]);
a[38] = (a[0]*a[2]);
a[39] = ((real_t)(0.0000000000000000e+00)-a[38]);
a[40] = ((real_t)(8.3701705517399998e+04)*a[39]);
a[41] = ((((real_t)(0.0000000000000000e+00)-(real_t)(1.0000000000000000e+00))*a[33])*a[35]);
a[42] = ((real_t)(1.0235155003400000e+05)*a[41]);
a[43] = (((real_t)(1.0560000000000000e+00)*a[0])*a[2]);
a[44] = ((real_t)(0.0000000000000000e+00)-a[43]);
a[45] = ((real_t)(8.3701705517399998e+04)*a[44]);
a[46] = (((real_t)(1.3439999999999999e+00)*a[33])*a[35]);
a[47] = ((real_t)(1.0235155003400000e+05)*a[46]);
a[48] = ((real_t)(1.0000000000000000e+00)/(real_t)(1.6960000000000001e+01));
a[49] = (cos((u[0]/(real_t)(1.6960000000000001e+01))));
a[50] = (a[48]*a[49]);
a[51] = ((real_t)(8.3701705517399998e+04)*a[18]);
a[52] = ((real_t)(1.0000000000000000e+00)/(real_t)(1.6960000000000001e+01));
a[53] = ((real_t)(-1.0000000000000000e+00)*(sin((u[0]/(real_t)(1.6960000000000001e+01)))));
a[54] = (a[52]*a[53]);
a[55] = (((real_t)(2.9200000000000000e+02))*a[26]);
a[56] = (sin((u[0]/(real_t)(1.6960000000000001e+01))));
a[57] = (((real_t)(0.0000000000000000e+00)-(((xd[2]*(real_t)(1.0560000000000000e+00))+xd[1])*a[1]))*a[2]);
a[58] = ((real_t)(0.0000000000000000e+00)-a[57]);
a[59] = ((real_t)(8.3701705517399998e+04)*a[58]);
a[60] = (cos((u[0]/(real_t)(1.6960000000000001e+01))));
a[61] = (((real_t)(0.0000000000000000e+00)-(((xd[2]*(real_t)(1.3439999999999999e+00))-xd[1])*a[34]))*a[35]);
a[62] = ((real_t)(1.0235155003400000e+05)*a[61]);
a[63] = (a[0]*a[2]);
a[64] = ((real_t)(0.0000000000000000e+00)-a[63]);
a[65] = ((real_t)(8.3701705517399998e+04)*a[64]);
a[66] = ((((real_t)(0.0000000000000000e+00)-(real_t)(1.0000000000000000e+00))*a[33])*a[35]);
a[67] = ((real_t)(1.0235155003400000e+05)*a[66]);
a[68] = (((real_t)(1.0560000000000000e+00)*a[0])*a[2]);
a[69] = ((real_t)(0.0000000000000000e+00)-a[68]);
a[70] = ((real_t)(8.3701705517399998e+04)*a[69]);
a[71] = (((real_t)(1.3439999999999999e+00)*a[33])*a[35]);
a[72] = ((real_t)(1.0235155003400000e+05)*a[71]);
a[73] = ((real_t)(8.3701705517399998e+04)*a[18]);
a[74] = ((real_t)(1.0000000000000000e+00)/(real_t)(1.6960000000000001e+01));
a[75] = ((real_t)(-1.0000000000000000e+00)*(sin((u[0]/(real_t)(1.6960000000000001e+01)))));
a[76] = (a[74]*a[75]);
a[77] = ((real_t)(1.0000000000000000e+00)/(real_t)(1.6960000000000001e+01));
a[78] = (cos((u[0]/(real_t)(1.6960000000000001e+01))));
a[79] = (a[77]*a[78]);
a[80] = (((real_t)(2.9200000000000000e+02))*a[26]);
a[81] = (sin((u[0]/(real_t)(1.6960000000000001e+01))));
a[82] = (cos(xd[3]));
a[83] = (sin(xd[3]));
a[84] = ((real_t)(-1.0000000000000000e+00)*(sin(xd[3])));
a[85] = (cos(xd[3]));
a[86] = (sin(xd[3]));
a[87] = (cos(xd[3]));
a[88] = (cos(xd[3]));
a[89] = ((real_t)(-1.0000000000000000e+00)*(sin(xd[3])));

/* Compute outputs: */
out[0] = ((real_t)(6.9930069930069930e-04)*(((real_t)(0.0000000000000000e+00)-(a[5]*a[6]))-a[7]));
out[1] = ((real_t)(6.9930069930069930e-04)*(((real_t)(0.0000000000000000e+00)-(a[10]*a[6]))+((real_t)(1.4300000000000000e+03)*xd[2])));
out[2] = ((real_t)(6.9930069930069930e-04)*(((real_t)(0.0000000000000000e+00)-(a[13]*a[6]))+((real_t)(1.4300000000000000e+03)*xd[1])));
out[3] = (real_t)(0.0000000000000000e+00);
out[4] = (real_t)(0.0000000000000000e+00);
out[5] = (real_t)(0.0000000000000000e+00);
out[6] = ((real_t)(6.9930069930069930e-04)*((a[14]*a[17])-((a[19]*a[6])+(a[22]*a[25]))));
out[7] = ((real_t)(6.9930069930069930e-04)*((a[27]*a[28])+a[27]));
out[8] = ((real_t)(6.9930069930069930e-04)*(((a[31]*a[32])+a[37])-((real_t)(1.4300000000000000e+03)*xd[2])));
out[9] = ((real_t)(6.9930069930069930e-04)*((a[40]*a[32])+a[42]));
out[10] = ((real_t)(6.9930069930069930e-04)*(((a[45]*a[32])+a[47])-((real_t)(1.4300000000000000e+03)*xd[0])));
out[11] = (real_t)(0.0000000000000000e+00);
out[12] = (real_t)(0.0000000000000000e+00);
out[13] = (real_t)(0.0000000000000000e+00);
out[14] = ((real_t)(6.9930069930069930e-04)*((a[14]*a[50])+((a[51]*a[32])+(a[22]*a[54]))));
out[15] = ((real_t)(6.9930069930069930e-04)*(a[55]*a[56]));
out[16] = ((real_t)(7.6923076923076923e-04)*(((real_t)(1.0560000000000000e+00)*(a[59]*a[60]))-((real_t)(1.3439999999999999e+00)*a[62])));
out[17] = ((real_t)(7.6923076923076923e-04)*(((real_t)(1.0560000000000000e+00)*(a[65]*a[60]))-((real_t)(1.3439999999999999e+00)*a[67])));
out[18] = ((real_t)(7.6923076923076923e-04)*(((real_t)(1.0560000000000000e+00)*(a[70]*a[60]))-((real_t)(1.3439999999999999e+00)*a[72])));
out[19] = (real_t)(0.0000000000000000e+00);
out[20] = (real_t)(0.0000000000000000e+00);
out[21] = (real_t)(0.0000000000000000e+00);
out[22] = ((real_t)(7.6923076923076923e-04)*((real_t)(1.0560000000000000e+00)*(((a[73]*a[60])+(a[22]*a[76]))+(a[14]*a[79]))));
out[23] = ((real_t)(7.6923076923076923e-04)*((real_t)(1.0560000000000000e+00)*(a[80]*a[81])));
out[24] = (real_t)(0.0000000000000000e+00);
out[25] = (real_t)(0.0000000000000000e+00);
out[26] = (real_t)(1.0000000000000000e+00);
out[27] = (real_t)(0.0000000000000000e+00);
out[28] = (real_t)(0.0000000000000000e+00);
out[29] = (real_t)(0.0000000000000000e+00);
out[30] = (real_t)(0.0000000000000000e+00);
out[31] = (real_t)(0.0000000000000000e+00);
out[32] = a[82];
out[33] = ((real_t)(0.0000000000000000e+00)-a[83]);
out[34] = (real_t)(0.0000000000000000e+00);
out[35] = ((xd[0]*a[84])-(xd[1]*a[85]));
out[36] = (real_t)(0.0000000000000000e+00);
out[37] = (real_t)(0.0000000000000000e+00);
out[38] = (real_t)(0.0000000000000000e+00);
out[39] = (real_t)(0.0000000000000000e+00);
out[40] = a[86];
out[41] = a[87];
out[42] = (real_t)(0.0000000000000000e+00);
out[43] = ((xd[0]*a[88])+(xd[1]*a[89]));
out[44] = (real_t)(0.0000000000000000e+00);
out[45] = (real_t)(0.0000000000000000e+00);
out[46] = (real_t)(0.0000000000000000e+00);
out[47] = (real_t)(0.0000000000000000e+00);
}



void nmpc_solve_dim12_triangular( real_t* const A, real_t* const b )
{

b[11] = b[11]/A[143];
b[10] -= + A[131]*b[11];
b[10] = b[10]/A[130];
b[9] -= + A[119]*b[11];
b[9] -= + A[118]*b[10];
b[9] = b[9]/A[117];
b[8] -= + A[107]*b[11];
b[8] -= + A[106]*b[10];
b[8] -= + A[105]*b[9];
b[8] = b[8]/A[104];
b[7] -= + A[95]*b[11];
b[7] -= + A[94]*b[10];
b[7] -= + A[93]*b[9];
b[7] -= + A[92]*b[8];
b[7] = b[7]/A[91];
b[6] -= + A[83]*b[11];
b[6] -= + A[82]*b[10];
b[6] -= + A[81]*b[9];
b[6] -= + A[80]*b[8];
b[6] -= + A[79]*b[7];
b[6] = b[6]/A[78];
b[5] -= + A[71]*b[11];
b[5] -= + A[70]*b[10];
b[5] -= + A[69]*b[9];
b[5] -= + A[68]*b[8];
b[5] -= + A[67]*b[7];
b[5] -= + A[66]*b[6];
b[5] = b[5]/A[65];
b[4] -= + A[59]*b[11];
b[4] -= + A[58]*b[10];
b[4] -= + A[57]*b[9];
b[4] -= + A[56]*b[8];
b[4] -= + A[55]*b[7];
b[4] -= + A[54]*b[6];
b[4] -= + A[53]*b[5];
b[4] = b[4]/A[52];
b[3] -= + A[47]*b[11];
b[3] -= + A[46]*b[10];
b[3] -= + A[45]*b[9];
b[3] -= + A[44]*b[8];
b[3] -= + A[43]*b[7];
b[3] -= + A[42]*b[6];
b[3] -= + A[41]*b[5];
b[3] -= + A[40]*b[4];
b[3] = b[3]/A[39];
b[2] -= + A[35]*b[11];
b[2] -= + A[34]*b[10];
b[2] -= + A[33]*b[9];
b[2] -= + A[32]*b[8];
b[2] -= + A[31]*b[7];
b[2] -= + A[30]*b[6];
b[2] -= + A[29]*b[5];
b[2] -= + A[28]*b[4];
b[2] -= + A[27]*b[3];
b[2] = b[2]/A[26];
b[1] -= + A[23]*b[11];
b[1] -= + A[22]*b[10];
b[1] -= + A[21]*b[9];
b[1] -= + A[20]*b[8];
b[1] -= + A[19]*b[7];
b[1] -= + A[18]*b[6];
b[1] -= + A[17]*b[5];
b[1] -= + A[16]*b[4];
b[1] -= + A[15]*b[3];
b[1] -= + A[14]*b[2];
b[1] = b[1]/A[13];
b[0] -= + A[11]*b[11];
b[0] -= + A[10]*b[10];
b[0] -= + A[9]*b[9];
b[0] -= + A[8]*b[8];
b[0] -= + A[7]*b[7];
b[0] -= + A[6]*b[6];
b[0] -= + A[5]*b[5];
b[0] -= + A[4]*b[4];
b[0] -= + A[3]*b[3];
b[0] -= + A[2]*b[2];
b[0] -= + A[1]*b[1];
b[0] = b[0]/A[0];
}

real_t nmpc_solve_dim12_system( real_t* const A, real_t* const b, int* const rk_perm )
{
real_t det;

int i;
int j;
int k;

int indexMax;

int intSwap;

real_t valueMax;

real_t temp;

for (i = 0; i < 12; ++i)
{
rk_perm[i] = i;
}
det = 1.0000000000000000e+00;
for( i=0; i < (11); i++ ) {
	indexMax = i;
	valueMax = fabs(A[i*12+i]);
	for( j=(i+1); j < 12; j++ ) {
		temp = fabs(A[j*12+i]);
		if( temp > valueMax ) {
			indexMax = j;
			valueMax = temp;
		}
	}
	if( indexMax > i ) {
for (k = 0; k < 12; ++k)
{
	nmpcWorkspace.rk_dim12_swap = A[i*12+k];
	A[i*12+k] = A[indexMax*12+k];
	A[indexMax*12+k] = nmpcWorkspace.rk_dim12_swap;
}
	nmpcWorkspace.rk_dim12_swap = b[i];
	b[i] = b[indexMax];
	b[indexMax] = nmpcWorkspace.rk_dim12_swap;
	intSwap = rk_perm[i];
	rk_perm[i] = rk_perm[indexMax];
	rk_perm[indexMax] = intSwap;
	}
	det *= A[i*12+i];
	for( j=i+1; j < 12; j++ ) {
		A[j*12+i] = -A[j*12+i]/A[i*12+i];
		for( k=i+1; k < 12; k++ ) {
			A[j*12+k] += A[j*12+i] * A[i*12+k];
		}
		b[j] += A[j*12+i] * b[i];
	}
}
det *= A[143];
det = fabs(det);
nmpc_solve_dim12_triangular( A, b );
return det;
}

void nmpc_solve_dim12_system_reuse( real_t* const A, real_t* const b, int* const rk_perm )
{

nmpcWorkspace.rk_dim12_bPerm[0] = b[rk_perm[0]];
nmpcWorkspace.rk_dim12_bPerm[1] = b[rk_perm[1]];
nmpcWorkspace.rk_dim12_bPerm[2] = b[rk_perm[2]];
nmpcWorkspace.rk_dim12_bPerm[3] = b[rk_perm[3]];
nmpcWorkspace.rk_dim12_bPerm[4] = b[rk_perm[4]];
nmpcWorkspace.rk_dim12_bPerm[5] = b[rk_perm[5]];
nmpcWorkspace.rk_dim12_bPerm[6] = b[rk_perm[6]];
nmpcWorkspace.rk_dim12_bPerm[7] = b[rk_perm[7]];
nmpcWorkspace.rk_dim12_bPerm[8] = b[rk_perm[8]];
nmpcWorkspace.rk_dim12_bPerm[9] = b[rk_perm[9]];
nmpcWorkspace.rk_dim12_bPerm[10] = b[rk_perm[10]];
nmpcWorkspace.rk_dim12_bPerm[11] = b[rk_perm[11]];
nmpcWorkspace.rk_dim12_bPerm[1] += A[12]*nmpcWorkspace.rk_dim12_bPerm[0];

nmpcWorkspace.rk_dim12_bPerm[2] += A[24]*nmpcWorkspace.rk_dim12_bPerm[0];
nmpcWorkspace.rk_dim12_bPerm[2] += A[25]*nmpcWorkspace.rk_dim12_bPerm[1];

nmpcWorkspace.rk_dim12_bPerm[3] += A[36]*nmpcWorkspace.rk_dim12_bPerm[0];
nmpcWorkspace.rk_dim12_bPerm[3] += A[37]*nmpcWorkspace.rk_dim12_bPerm[1];
nmpcWorkspace.rk_dim12_bPerm[3] += A[38]*nmpcWorkspace.rk_dim12_bPerm[2];

nmpcWorkspace.rk_dim12_bPerm[4] += A[48]*nmpcWorkspace.rk_dim12_bPerm[0];
nmpcWorkspace.rk_dim12_bPerm[4] += A[49]*nmpcWorkspace.rk_dim12_bPerm[1];
nmpcWorkspace.rk_dim12_bPerm[4] += A[50]*nmpcWorkspace.rk_dim12_bPerm[2];
nmpcWorkspace.rk_dim12_bPerm[4] += A[51]*nmpcWorkspace.rk_dim12_bPerm[3];

nmpcWorkspace.rk_dim12_bPerm[5] += A[60]*nmpcWorkspace.rk_dim12_bPerm[0];
nmpcWorkspace.rk_dim12_bPerm[5] += A[61]*nmpcWorkspace.rk_dim12_bPerm[1];
nmpcWorkspace.rk_dim12_bPerm[5] += A[62]*nmpcWorkspace.rk_dim12_bPerm[2];
nmpcWorkspace.rk_dim12_bPerm[5] += A[63]*nmpcWorkspace.rk_dim12_bPerm[3];
nmpcWorkspace.rk_dim12_bPerm[5] += A[64]*nmpcWorkspace.rk_dim12_bPerm[4];

nmpcWorkspace.rk_dim12_bPerm[6] += A[72]*nmpcWorkspace.rk_dim12_bPerm[0];
nmpcWorkspace.rk_dim12_bPerm[6] += A[73]*nmpcWorkspace.rk_dim12_bPerm[1];
nmpcWorkspace.rk_dim12_bPerm[6] += A[74]*nmpcWorkspace.rk_dim12_bPerm[2];
nmpcWorkspace.rk_dim12_bPerm[6] += A[75]*nmpcWorkspace.rk_dim12_bPerm[3];
nmpcWorkspace.rk_dim12_bPerm[6] += A[76]*nmpcWorkspace.rk_dim12_bPerm[4];
nmpcWorkspace.rk_dim12_bPerm[6] += A[77]*nmpcWorkspace.rk_dim12_bPerm[5];

nmpcWorkspace.rk_dim12_bPerm[7] += A[84]*nmpcWorkspace.rk_dim12_bPerm[0];
nmpcWorkspace.rk_dim12_bPerm[7] += A[85]*nmpcWorkspace.rk_dim12_bPerm[1];
nmpcWorkspace.rk_dim12_bPerm[7] += A[86]*nmpcWorkspace.rk_dim12_bPerm[2];
nmpcWorkspace.rk_dim12_bPerm[7] += A[87]*nmpcWorkspace.rk_dim12_bPerm[3];
nmpcWorkspace.rk_dim12_bPerm[7] += A[88]*nmpcWorkspace.rk_dim12_bPerm[4];
nmpcWorkspace.rk_dim12_bPerm[7] += A[89]*nmpcWorkspace.rk_dim12_bPerm[5];
nmpcWorkspace.rk_dim12_bPerm[7] += A[90]*nmpcWorkspace.rk_dim12_bPerm[6];

nmpcWorkspace.rk_dim12_bPerm[8] += A[96]*nmpcWorkspace.rk_dim12_bPerm[0];
nmpcWorkspace.rk_dim12_bPerm[8] += A[97]*nmpcWorkspace.rk_dim12_bPerm[1];
nmpcWorkspace.rk_dim12_bPerm[8] += A[98]*nmpcWorkspace.rk_dim12_bPerm[2];
nmpcWorkspace.rk_dim12_bPerm[8] += A[99]*nmpcWorkspace.rk_dim12_bPerm[3];
nmpcWorkspace.rk_dim12_bPerm[8] += A[100]*nmpcWorkspace.rk_dim12_bPerm[4];
nmpcWorkspace.rk_dim12_bPerm[8] += A[101]*nmpcWorkspace.rk_dim12_bPerm[5];
nmpcWorkspace.rk_dim12_bPerm[8] += A[102]*nmpcWorkspace.rk_dim12_bPerm[6];
nmpcWorkspace.rk_dim12_bPerm[8] += A[103]*nmpcWorkspace.rk_dim12_bPerm[7];

nmpcWorkspace.rk_dim12_bPerm[9] += A[108]*nmpcWorkspace.rk_dim12_bPerm[0];
nmpcWorkspace.rk_dim12_bPerm[9] += A[109]*nmpcWorkspace.rk_dim12_bPerm[1];
nmpcWorkspace.rk_dim12_bPerm[9] += A[110]*nmpcWorkspace.rk_dim12_bPerm[2];
nmpcWorkspace.rk_dim12_bPerm[9] += A[111]*nmpcWorkspace.rk_dim12_bPerm[3];
nmpcWorkspace.rk_dim12_bPerm[9] += A[112]*nmpcWorkspace.rk_dim12_bPerm[4];
nmpcWorkspace.rk_dim12_bPerm[9] += A[113]*nmpcWorkspace.rk_dim12_bPerm[5];
nmpcWorkspace.rk_dim12_bPerm[9] += A[114]*nmpcWorkspace.rk_dim12_bPerm[6];
nmpcWorkspace.rk_dim12_bPerm[9] += A[115]*nmpcWorkspace.rk_dim12_bPerm[7];
nmpcWorkspace.rk_dim12_bPerm[9] += A[116]*nmpcWorkspace.rk_dim12_bPerm[8];

nmpcWorkspace.rk_dim12_bPerm[10] += A[120]*nmpcWorkspace.rk_dim12_bPerm[0];
nmpcWorkspace.rk_dim12_bPerm[10] += A[121]*nmpcWorkspace.rk_dim12_bPerm[1];
nmpcWorkspace.rk_dim12_bPerm[10] += A[122]*nmpcWorkspace.rk_dim12_bPerm[2];
nmpcWorkspace.rk_dim12_bPerm[10] += A[123]*nmpcWorkspace.rk_dim12_bPerm[3];
nmpcWorkspace.rk_dim12_bPerm[10] += A[124]*nmpcWorkspace.rk_dim12_bPerm[4];
nmpcWorkspace.rk_dim12_bPerm[10] += A[125]*nmpcWorkspace.rk_dim12_bPerm[5];
nmpcWorkspace.rk_dim12_bPerm[10] += A[126]*nmpcWorkspace.rk_dim12_bPerm[6];
nmpcWorkspace.rk_dim12_bPerm[10] += A[127]*nmpcWorkspace.rk_dim12_bPerm[7];
nmpcWorkspace.rk_dim12_bPerm[10] += A[128]*nmpcWorkspace.rk_dim12_bPerm[8];
nmpcWorkspace.rk_dim12_bPerm[10] += A[129]*nmpcWorkspace.rk_dim12_bPerm[9];

nmpcWorkspace.rk_dim12_bPerm[11] += A[132]*nmpcWorkspace.rk_dim12_bPerm[0];
nmpcWorkspace.rk_dim12_bPerm[11] += A[133]*nmpcWorkspace.rk_dim12_bPerm[1];
nmpcWorkspace.rk_dim12_bPerm[11] += A[134]*nmpcWorkspace.rk_dim12_bPerm[2];
nmpcWorkspace.rk_dim12_bPerm[11] += A[135]*nmpcWorkspace.rk_dim12_bPerm[3];
nmpcWorkspace.rk_dim12_bPerm[11] += A[136]*nmpcWorkspace.rk_dim12_bPerm[4];
nmpcWorkspace.rk_dim12_bPerm[11] += A[137]*nmpcWorkspace.rk_dim12_bPerm[5];
nmpcWorkspace.rk_dim12_bPerm[11] += A[138]*nmpcWorkspace.rk_dim12_bPerm[6];
nmpcWorkspace.rk_dim12_bPerm[11] += A[139]*nmpcWorkspace.rk_dim12_bPerm[7];
nmpcWorkspace.rk_dim12_bPerm[11] += A[140]*nmpcWorkspace.rk_dim12_bPerm[8];
nmpcWorkspace.rk_dim12_bPerm[11] += A[141]*nmpcWorkspace.rk_dim12_bPerm[9];
nmpcWorkspace.rk_dim12_bPerm[11] += A[142]*nmpcWorkspace.rk_dim12_bPerm[10];


nmpc_solve_dim12_triangular( A, nmpcWorkspace.rk_dim12_bPerm );
b[0] = nmpcWorkspace.rk_dim12_bPerm[0];
b[1] = nmpcWorkspace.rk_dim12_bPerm[1];
b[2] = nmpcWorkspace.rk_dim12_bPerm[2];
b[3] = nmpcWorkspace.rk_dim12_bPerm[3];
b[4] = nmpcWorkspace.rk_dim12_bPerm[4];
b[5] = nmpcWorkspace.rk_dim12_bPerm[5];
b[6] = nmpcWorkspace.rk_dim12_bPerm[6];
b[7] = nmpcWorkspace.rk_dim12_bPerm[7];
b[8] = nmpcWorkspace.rk_dim12_bPerm[8];
b[9] = nmpcWorkspace.rk_dim12_bPerm[9];
b[10] = nmpcWorkspace.rk_dim12_bPerm[10];
b[11] = nmpcWorkspace.rk_dim12_bPerm[11];
}



/** Matrix of size: 2 x 2 (row major format) */
static const real_t nmpc_Ah_mat[ 4 ] = 
{ 2.5000000000000001e-03, 5.3867513459481290e-03, 
-3.8675134594812866e-04, 2.5000000000000001e-03 };


/* Fixed step size:0.01 */
int nmpc_integrate( real_t* const rk_eta, int resetIntegrator )
{
int error;

int i;
int j;
int k;
int run;
int run1;
int tmp_index1;
int tmp_index2;

real_t det;

nmpcWorkspace.rk_ttt = 0.0000000000000000e+00;
nmpcWorkspace.rk_xxx[6] = rk_eta[54];
nmpcWorkspace.rk_xxx[7] = rk_eta[55];

for (run = 0; run < 1; ++run)
{
if( resetIntegrator ) {
for (i = 0; i < 1; ++i)
{
for (run1 = 0; run1 < 2; ++run1)
{
for (j = 0; j < 6; ++j)
{
nmpcWorkspace.rk_xxx[j] = rk_eta[j];
tmp_index1 = j;
nmpcWorkspace.rk_xxx[j] += + nmpc_Ah_mat[run1 * 2]*nmpcWorkspace.rk_kkk[tmp_index1 * 2];
nmpcWorkspace.rk_xxx[j] += + nmpc_Ah_mat[run1 * 2 + 1]*nmpcWorkspace.rk_kkk[tmp_index1 * 2 + 1];
}
nmpc_diffs( nmpcWorkspace.rk_xxx, &(nmpcWorkspace.rk_diffsTemp2[ run1 * 48 ]) );
for (j = 0; j < 6; ++j)
{
tmp_index1 = (run1 * 6) + (j);
nmpcWorkspace.rk_A[tmp_index1 * 12] = + nmpc_Ah_mat[run1 * 2]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8)];
nmpcWorkspace.rk_A[tmp_index1 * 12 + 1] = + nmpc_Ah_mat[run1 * 2]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 1)];
nmpcWorkspace.rk_A[tmp_index1 * 12 + 2] = + nmpc_Ah_mat[run1 * 2]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 2)];
nmpcWorkspace.rk_A[tmp_index1 * 12 + 3] = + nmpc_Ah_mat[run1 * 2]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 3)];
nmpcWorkspace.rk_A[tmp_index1 * 12 + 4] = + nmpc_Ah_mat[run1 * 2]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 4)];
nmpcWorkspace.rk_A[tmp_index1 * 12 + 5] = + nmpc_Ah_mat[run1 * 2]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 5)];
if( 0 == run1 ) nmpcWorkspace.rk_A[(tmp_index1 * 12) + (j)] -= 1.0000000000000000e+00;
nmpcWorkspace.rk_A[tmp_index1 * 12 + 6] = + nmpc_Ah_mat[run1 * 2 + 1]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8)];
nmpcWorkspace.rk_A[tmp_index1 * 12 + 7] = + nmpc_Ah_mat[run1 * 2 + 1]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 1)];
nmpcWorkspace.rk_A[tmp_index1 * 12 + 8] = + nmpc_Ah_mat[run1 * 2 + 1]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 2)];
nmpcWorkspace.rk_A[tmp_index1 * 12 + 9] = + nmpc_Ah_mat[run1 * 2 + 1]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 3)];
nmpcWorkspace.rk_A[tmp_index1 * 12 + 10] = + nmpc_Ah_mat[run1 * 2 + 1]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 4)];
nmpcWorkspace.rk_A[tmp_index1 * 12 + 11] = + nmpc_Ah_mat[run1 * 2 + 1]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 5)];
if( 1 == run1 ) nmpcWorkspace.rk_A[(tmp_index1 * 12) + (j + 6)] -= 1.0000000000000000e+00;
}
nmpc_rhs( nmpcWorkspace.rk_xxx, nmpcWorkspace.rk_rhsTemp );
nmpcWorkspace.rk_b[run1 * 6] = nmpcWorkspace.rk_kkk[run1] - nmpcWorkspace.rk_rhsTemp[0];
nmpcWorkspace.rk_b[run1 * 6 + 1] = nmpcWorkspace.rk_kkk[run1 + 2] - nmpcWorkspace.rk_rhsTemp[1];
nmpcWorkspace.rk_b[run1 * 6 + 2] = nmpcWorkspace.rk_kkk[run1 + 4] - nmpcWorkspace.rk_rhsTemp[2];
nmpcWorkspace.rk_b[run1 * 6 + 3] = nmpcWorkspace.rk_kkk[run1 + 6] - nmpcWorkspace.rk_rhsTemp[3];
nmpcWorkspace.rk_b[run1 * 6 + 4] = nmpcWorkspace.rk_kkk[run1 + 8] - nmpcWorkspace.rk_rhsTemp[4];
nmpcWorkspace.rk_b[run1 * 6 + 5] = nmpcWorkspace.rk_kkk[run1 + 10] - nmpcWorkspace.rk_rhsTemp[5];
}
det = nmpc_solve_dim12_system( nmpcWorkspace.rk_A, nmpcWorkspace.rk_b, nmpcWorkspace.rk_dim12_perm );
for (j = 0; j < 2; ++j)
{
nmpcWorkspace.rk_kkk[j] += nmpcWorkspace.rk_b[j * 6];
nmpcWorkspace.rk_kkk[j + 2] += nmpcWorkspace.rk_b[j * 6 + 1];
nmpcWorkspace.rk_kkk[j + 4] += nmpcWorkspace.rk_b[j * 6 + 2];
nmpcWorkspace.rk_kkk[j + 6] += nmpcWorkspace.rk_b[j * 6 + 3];
nmpcWorkspace.rk_kkk[j + 8] += nmpcWorkspace.rk_b[j * 6 + 4];
nmpcWorkspace.rk_kkk[j + 10] += nmpcWorkspace.rk_b[j * 6 + 5];
}
}
}
for (i = 0; i < 5; ++i)
{
for (run1 = 0; run1 < 2; ++run1)
{
for (j = 0; j < 6; ++j)
{
nmpcWorkspace.rk_xxx[j] = rk_eta[j];
tmp_index1 = j;
nmpcWorkspace.rk_xxx[j] += + nmpc_Ah_mat[run1 * 2]*nmpcWorkspace.rk_kkk[tmp_index1 * 2];
nmpcWorkspace.rk_xxx[j] += + nmpc_Ah_mat[run1 * 2 + 1]*nmpcWorkspace.rk_kkk[tmp_index1 * 2 + 1];
}
nmpc_rhs( nmpcWorkspace.rk_xxx, nmpcWorkspace.rk_rhsTemp );
nmpcWorkspace.rk_b[run1 * 6] = nmpcWorkspace.rk_kkk[run1] - nmpcWorkspace.rk_rhsTemp[0];
nmpcWorkspace.rk_b[run1 * 6 + 1] = nmpcWorkspace.rk_kkk[run1 + 2] - nmpcWorkspace.rk_rhsTemp[1];
nmpcWorkspace.rk_b[run1 * 6 + 2] = nmpcWorkspace.rk_kkk[run1 + 4] - nmpcWorkspace.rk_rhsTemp[2];
nmpcWorkspace.rk_b[run1 * 6 + 3] = nmpcWorkspace.rk_kkk[run1 + 6] - nmpcWorkspace.rk_rhsTemp[3];
nmpcWorkspace.rk_b[run1 * 6 + 4] = nmpcWorkspace.rk_kkk[run1 + 8] - nmpcWorkspace.rk_rhsTemp[4];
nmpcWorkspace.rk_b[run1 * 6 + 5] = nmpcWorkspace.rk_kkk[run1 + 10] - nmpcWorkspace.rk_rhsTemp[5];
}
nmpc_solve_dim12_system_reuse( nmpcWorkspace.rk_A, nmpcWorkspace.rk_b, nmpcWorkspace.rk_dim12_perm );
for (j = 0; j < 2; ++j)
{
nmpcWorkspace.rk_kkk[j] += nmpcWorkspace.rk_b[j * 6];
nmpcWorkspace.rk_kkk[j + 2] += nmpcWorkspace.rk_b[j * 6 + 1];
nmpcWorkspace.rk_kkk[j + 4] += nmpcWorkspace.rk_b[j * 6 + 2];
nmpcWorkspace.rk_kkk[j + 6] += nmpcWorkspace.rk_b[j * 6 + 3];
nmpcWorkspace.rk_kkk[j + 8] += nmpcWorkspace.rk_b[j * 6 + 4];
nmpcWorkspace.rk_kkk[j + 10] += nmpcWorkspace.rk_b[j * 6 + 5];
}
}
for (run1 = 0; run1 < 2; ++run1)
{
for (j = 0; j < 6; ++j)
{
nmpcWorkspace.rk_xxx[j] = rk_eta[j];
tmp_index1 = j;
nmpcWorkspace.rk_xxx[j] += + nmpc_Ah_mat[run1 * 2]*nmpcWorkspace.rk_kkk[tmp_index1 * 2];
nmpcWorkspace.rk_xxx[j] += + nmpc_Ah_mat[run1 * 2 + 1]*nmpcWorkspace.rk_kkk[tmp_index1 * 2 + 1];
}
nmpc_diffs( nmpcWorkspace.rk_xxx, &(nmpcWorkspace.rk_diffsTemp2[ run1 * 48 ]) );
for (j = 0; j < 6; ++j)
{
tmp_index1 = (run1 * 6) + (j);
nmpcWorkspace.rk_A[tmp_index1 * 12] = + nmpc_Ah_mat[run1 * 2]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8)];
nmpcWorkspace.rk_A[tmp_index1 * 12 + 1] = + nmpc_Ah_mat[run1 * 2]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 1)];
nmpcWorkspace.rk_A[tmp_index1 * 12 + 2] = + nmpc_Ah_mat[run1 * 2]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 2)];
nmpcWorkspace.rk_A[tmp_index1 * 12 + 3] = + nmpc_Ah_mat[run1 * 2]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 3)];
nmpcWorkspace.rk_A[tmp_index1 * 12 + 4] = + nmpc_Ah_mat[run1 * 2]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 4)];
nmpcWorkspace.rk_A[tmp_index1 * 12 + 5] = + nmpc_Ah_mat[run1 * 2]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 5)];
if( 0 == run1 ) nmpcWorkspace.rk_A[(tmp_index1 * 12) + (j)] -= 1.0000000000000000e+00;
nmpcWorkspace.rk_A[tmp_index1 * 12 + 6] = + nmpc_Ah_mat[run1 * 2 + 1]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8)];
nmpcWorkspace.rk_A[tmp_index1 * 12 + 7] = + nmpc_Ah_mat[run1 * 2 + 1]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 1)];
nmpcWorkspace.rk_A[tmp_index1 * 12 + 8] = + nmpc_Ah_mat[run1 * 2 + 1]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 2)];
nmpcWorkspace.rk_A[tmp_index1 * 12 + 9] = + nmpc_Ah_mat[run1 * 2 + 1]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 3)];
nmpcWorkspace.rk_A[tmp_index1 * 12 + 10] = + nmpc_Ah_mat[run1 * 2 + 1]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 4)];
nmpcWorkspace.rk_A[tmp_index1 * 12 + 11] = + nmpc_Ah_mat[run1 * 2 + 1]*nmpcWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 5)];
if( 1 == run1 ) nmpcWorkspace.rk_A[(tmp_index1 * 12) + (j + 6)] -= 1.0000000000000000e+00;
}
}
for (run1 = 0; run1 < 6; ++run1)
{
for (i = 0; i < 2; ++i)
{
nmpcWorkspace.rk_b[i * 6] = - nmpcWorkspace.rk_diffsTemp2[(i * 48) + (run1)];
nmpcWorkspace.rk_b[i * 6 + 1] = - nmpcWorkspace.rk_diffsTemp2[(i * 48) + (run1 + 8)];
nmpcWorkspace.rk_b[i * 6 + 2] = - nmpcWorkspace.rk_diffsTemp2[(i * 48) + (run1 + 16)];
nmpcWorkspace.rk_b[i * 6 + 3] = - nmpcWorkspace.rk_diffsTemp2[(i * 48) + (run1 + 24)];
nmpcWorkspace.rk_b[i * 6 + 4] = - nmpcWorkspace.rk_diffsTemp2[(i * 48) + (run1 + 32)];
nmpcWorkspace.rk_b[i * 6 + 5] = - nmpcWorkspace.rk_diffsTemp2[(i * 48) + (run1 + 40)];
}
if( 0 == run1 ) {
det = nmpc_solve_dim12_system( nmpcWorkspace.rk_A, nmpcWorkspace.rk_b, nmpcWorkspace.rk_dim12_perm );
}
 else {
nmpc_solve_dim12_system_reuse( nmpcWorkspace.rk_A, nmpcWorkspace.rk_b, nmpcWorkspace.rk_dim12_perm );
}
for (i = 0; i < 2; ++i)
{
nmpcWorkspace.rk_diffK[i] = nmpcWorkspace.rk_b[i * 6];
nmpcWorkspace.rk_diffK[i + 2] = nmpcWorkspace.rk_b[i * 6 + 1];
nmpcWorkspace.rk_diffK[i + 4] = nmpcWorkspace.rk_b[i * 6 + 2];
nmpcWorkspace.rk_diffK[i + 6] = nmpcWorkspace.rk_b[i * 6 + 3];
nmpcWorkspace.rk_diffK[i + 8] = nmpcWorkspace.rk_b[i * 6 + 4];
nmpcWorkspace.rk_diffK[i + 10] = nmpcWorkspace.rk_b[i * 6 + 5];
}
for (i = 0; i < 6; ++i)
{
nmpcWorkspace.rk_diffsNew2[(i * 8) + (run1)] = (i == run1-0);
nmpcWorkspace.rk_diffsNew2[(i * 8) + (run1)] += + nmpcWorkspace.rk_diffK[i * 2]*(real_t)5.0000000000000001e-03 + nmpcWorkspace.rk_diffK[i * 2 + 1]*(real_t)5.0000000000000001e-03;
}
}
for (run1 = 0; run1 < 2; ++run1)
{
for (i = 0; i < 2; ++i)
{
for (j = 0; j < 6; ++j)
{
tmp_index1 = (i * 6) + (j);
tmp_index2 = (run1) + (j * 8);
nmpcWorkspace.rk_b[tmp_index1] = - nmpcWorkspace.rk_diffsTemp2[(i * 48) + (tmp_index2 + 6)];
}
}
nmpc_solve_dim12_system_reuse( nmpcWorkspace.rk_A, nmpcWorkspace.rk_b, nmpcWorkspace.rk_dim12_perm );
for (i = 0; i < 2; ++i)
{
nmpcWorkspace.rk_diffK[i] = nmpcWorkspace.rk_b[i * 6];
nmpcWorkspace.rk_diffK[i + 2] = nmpcWorkspace.rk_b[i * 6 + 1];
nmpcWorkspace.rk_diffK[i + 4] = nmpcWorkspace.rk_b[i * 6 + 2];
nmpcWorkspace.rk_diffK[i + 6] = nmpcWorkspace.rk_b[i * 6 + 3];
nmpcWorkspace.rk_diffK[i + 8] = nmpcWorkspace.rk_b[i * 6 + 4];
nmpcWorkspace.rk_diffK[i + 10] = nmpcWorkspace.rk_b[i * 6 + 5];
}
for (i = 0; i < 6; ++i)
{
nmpcWorkspace.rk_diffsNew2[(i * 8) + (run1 + 6)] = + nmpcWorkspace.rk_diffK[i * 2]*(real_t)5.0000000000000001e-03 + nmpcWorkspace.rk_diffK[i * 2 + 1]*(real_t)5.0000000000000001e-03;
}
}
rk_eta[0] += + nmpcWorkspace.rk_kkk[0]*(real_t)5.0000000000000001e-03 + nmpcWorkspace.rk_kkk[1]*(real_t)5.0000000000000001e-03;
rk_eta[1] += + nmpcWorkspace.rk_kkk[2]*(real_t)5.0000000000000001e-03 + nmpcWorkspace.rk_kkk[3]*(real_t)5.0000000000000001e-03;
rk_eta[2] += + nmpcWorkspace.rk_kkk[4]*(real_t)5.0000000000000001e-03 + nmpcWorkspace.rk_kkk[5]*(real_t)5.0000000000000001e-03;
rk_eta[3] += + nmpcWorkspace.rk_kkk[6]*(real_t)5.0000000000000001e-03 + nmpcWorkspace.rk_kkk[7]*(real_t)5.0000000000000001e-03;
rk_eta[4] += + nmpcWorkspace.rk_kkk[8]*(real_t)5.0000000000000001e-03 + nmpcWorkspace.rk_kkk[9]*(real_t)5.0000000000000001e-03;
rk_eta[5] += + nmpcWorkspace.rk_kkk[10]*(real_t)5.0000000000000001e-03 + nmpcWorkspace.rk_kkk[11]*(real_t)5.0000000000000001e-03;
for (i = 0; i < 6; ++i)
{
for (j = 0; j < 6; ++j)
{
tmp_index2 = (j) + (i * 6);
rk_eta[tmp_index2 + 6] = nmpcWorkspace.rk_diffsNew2[(i * 8) + (j)];
}
for (j = 0; j < 2; ++j)
{
tmp_index2 = (j) + (i * 2);
rk_eta[tmp_index2 + 42] = nmpcWorkspace.rk_diffsNew2[(i * 8) + (j + 6)];
}
}
resetIntegrator = 0;
nmpcWorkspace.rk_ttt += 1.0000000000000000e+00;
}
for (i = 0; i < 6; ++i)
{
}
if( det < 1e-12 ) {
error = 2;
} else if( det < 1e-6 ) {
error = 1;
} else {
error = 0;
}
return error;
}



