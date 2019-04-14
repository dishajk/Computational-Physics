//
//  Rec_Green.cpp
//  
//
//  Created by Disha Kuzhively on 13/04/19.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>

using namespace std;

int main(void){
double eps1 = 1;
double eps2 = 2;
double omega;
double eta = 0.1;
double pi = acos(-1);
gsl_complex z, g11inv, g22inv, G11, G22, t;
GSL_SET_COMPLEX(&t, 1, 0);
ofstream outfile;
outfile.open ("G11.dat");
int count = 1000;
omega = -5.0;
for (int i = 0; i < count; ++i)
{	
	omega += 10.0/(double)count;

	GSL_SET_COMPLEX(&z, omega, eta);

	g11inv = gsl_complex_sub_real(z,eps1);

	g22inv = gsl_complex_sub_real(z,eps2);

	G11 = gsl_complex_inverse(gsl_complex_sub(g11inv, gsl_complex_mul(gsl_complex_mul(gsl_complex_conjugate(t), gsl_complex_inverse(g22inv)), t)));
	G22 = gsl_complex_inverse(gsl_complex_sub(g22inv, gsl_complex_mul(gsl_complex_mul(gsl_complex_conjugate(t), gsl_complex_inverse(g11inv)), t)));

gsl_complex_inverse(gsl_complex_sub(g11inv, gsl_complex_mul(gsl_complex_mul(gsl_complex_conjugate(t), gsl_complex_inverse(g22inv)), t)));
	outfile << omega << "\t" << -GSL_IMAG(G11)/pi << " \t " << -GSL_IMAG(G22)/pi << endl;
}
outfile.close();

return 0;
}
