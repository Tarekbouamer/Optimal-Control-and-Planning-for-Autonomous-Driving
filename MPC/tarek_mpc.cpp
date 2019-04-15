
/*
*    This file is part of ACADO Toolkit.
*
*    ACADO Toolkit -- A Toolkit for Automatic Control and Dynamic Optimization.
*    Copyright (C) 2008-2014 by Boris Houska, Hans Joachim Ferreau,
*    Milan Vukov, Rien Quirynen, KU Leuven.
*    Developed within the Optimization in Engineering Center (OPTEC)
*    under supervision of Moritz Diehl. All rights reserved.
*
*    ACADO Toolkit is free software; you can redistribute it and/or
*    modify it under the terms of the GNU Lesser General Public
*    License as published by the Free Software Foundation; either
*    version 3 of the License, or (at your option) any later version.
*
*    ACADO Toolkit is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*    Lesser General Public License for more details.
*
*    You should have received a copy of the GNU Lesser General Public
*    License along with ACADO Toolkit; if not, write to the Free Software
*    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*
*/

/**
*    \author Hans Joachim Ferreau, Boris Houska, Milan Vukov
*    \date   2011-2013
*/

#include <acado_optimal_control.hpp>
#include <acado_code_generation.hpp>



int main()
{
	USING_NAMESPACE_ACADO

		// System Variables:
	
	DifferentialState   Ux, Uy;
	DifferentialState	r, phi;
	DifferentialState   x, y;
//	DifferentialState   delta;

	Control             delta, throttle;

	IntermediateState slip_f, slip_r;

	IntermediateState Fxf, Fxr;
	IntermediateState Fyf, Fyr;

	IntermediateState Fres;

	// parameters
	const double	 m = 1430;
	const double	 Iz = 1300;

	const double	 Lf = 1.056;
	const double	 Lr = 2.4-1.056;

	const double	 Kf = 41850.8527587;
	const double	 Kr = 51175.775017;

	const double	 Cr0 = 0.1;
	const double	 Cr2 = 0.6;

	const double	 R = 0.292;

	const double	 Tmax = 584;
	const double	 G = 16.96;

	const double	 pi = 3.14159265359;
	const double     Ts = 0.01;
	const double     N = 40;



	DifferentialEquation f;

	slip_f = -atan((r*Lf + Uy) / Ux) + delta/G;
	slip_r =  atan((r*Lr - Uy) / Ux);

	Fxf = 0.5*throttle*Tmax/R;
	Fxr = Fxf;

	Fyf = 2*Kf*slip_f;
	Fyr = 2*Kr*slip_r;

	Fres = Cr0 + Cr2*Ux*Ux;

	f << dot(Ux) == ( 1/ m )*( Fxf*cos(delta/G) + Fxr - Fyf*sin(delta/G) - Fres + m*r*Uy );
	f << dot(Uy) == ( 1/ m )*( Fxf*sin(delta/G) + Fyf*cos(delta/G) + Fyr -m*r*Ux );

	f << dot(r) ==  ( 1/Iz )*( Lf*( Fyf*cos(delta/G) + Fxf*sin(delta/G)) - Lr*Fyr );
	f << dot(phi) == ( r );

	f << dot(x) == Ux*cos(phi) - Uy*sin(phi);
	f << dot(y) == Ux*sin(phi) + Uy*cos(phi);


	// Reference functions and weighting matrices:
	Function h, hN;

	h << Ux << Uy << r << phi << x << y << delta << throttle;
	hN << Ux << Uy << r << phi << x << y;

	BMatrix W = eye<bool>(h.getDim());
	BMatrix WN = eye<bool>(hN.getDim());

	//
	// Optimal Control Problem
	//
	OCP ocp(0.0, Ts*N, N);

	ocp.subjectTo(f);

	ocp.minimizeLSQ(W, h);
	ocp.minimizeLSQEndTerm(WN, hN);


	ocp.subjectTo( -168*pi/180 <= delta <= 168*pi/180);

	//ocp.subjectTo( -5* pi / 180 <= d_delta <= 5* pi / 180);
	ocp.subjectTo( -1 <= throttle <= 1 );


	// Export the code:
	OCPexport mpc(ocp);

	mpc.set(HESSIAN_APPROXIMATION, GAUSS_NEWTON);
	mpc.set(DISCRETIZATION_TYPE, MULTIPLE_SHOOTING);
	mpc.set(INTEGRATOR_TYPE, INT_IRK_GL4);
	mpc.set(NUM_INTEGRATOR_STEPS, 4*N);

	mpc.set(SPARSE_QP_SOLUTION, FULL_CONDENSING_N2);
	mpc.set(QP_SOLVER, QP_QPOASES);
	mpc.set(FIX_INITIAL_STATE, YES);

	// 	mpc.set( SPARSE_QP_SOLUTION, SPARSE_SOLVER );
	// 	mpc.set( QP_SOLVER, QP_QPDUNES );

	mpc.set(HOTSTART_QP, YES);
	mpc.set(GENERATE_TEST_FILE, YES);
	mpc.set(GENERATE_MAKE_FILE, NO);
	mpc.set(GENERATE_MATLAB_INTERFACE, YES);
	mpc.set(GENERATE_SIMULINK_INTERFACE, YES);

	// Optionally set custom module name:
	mpc.set(CG_MODULE_NAME, "nmpc");

	if (mpc.exportCode("tarek_mpc") != SUCCESSFUL_RETURN)
		exit(EXIT_FAILURE);

	mpc.printDimensionsQP();

	return EXIT_SUCCESS;
}