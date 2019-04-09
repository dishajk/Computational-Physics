//
//  1dtb_02.cpp
//  
//
//  Created by Disha Kuzhively on 24/03/19.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_eigen.h>
#include <gsl/gsl_sort_vector.h>

static const double t = 1;
static const double pi = acos(-1);
static const int N = 1000; //N has to be larger than 2, kDelta is defined that way

using namespace std;

int kDelta(int, int);
double Lorentzian(double, double, double);

int main(void){
    
    gsl_matrix * H = gsl_matrix_alloc (N, N);
    
//    Hamiltonian matrix
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            gsl_matrix_set (H, i-1, j-1, - 1 * (kDelta(i,j-1) + kDelta(i,j+1))*t);
        }
    }
    
    
//    Display Hamiltonian matrix
    
//    for (int i = 0; i < N; i ++) {
//        for (int j = 0; j < N; j++) {
//            cout << gsl_matrix_get (H, i, j) << " \t " ;
//        }
//        cout << endl ;
//    }
    gsl_vector * eig_val = gsl_vector_alloc (N);
    gsl_eigen_symm_workspace * w = gsl_eigen_symm_alloc (N);
    gsl_eigen_symm(H, eig_val,  w);
    gsl_eigen_symm_free (w);
    gsl_sort_vector(eig_val);
    
//    for (int i = 0; i < N; i++) {
//        cout << gsl_vector_get(eig_val,i) << endl;
//    }
    
    double en_min = gsl_vector_get(eig_val,0);
    double en_max = gsl_vector_get(eig_val, N-1);
    double gamma = ( en_max - en_min )/N;
    ofstream outfile;
    outfile.open( "1dtb02.dat" );
    double E = en_min;
    for (int i = 0; i <= 50; i ++) {
        double dos = 0;
        for (int j = 0; j < N; j ++) {
            dos += Lorentzian(E, gsl_vector_get(eig_val,j), gamma);
        }
        E += (en_max - en_min)/50;
        outfile << E << " \t " << dos << " \t " <<endl;
    }
    outfile.close();
    gsl_vector_free (eig_val);
    gsl_matrix_free (H);
    return 0;
}

int kDelta(int a, int b)
{
    if (a%N == b%N) {
        return 1;
    } else {
        return 0;
    }
}

double Lorentzian(double E, double E0 , double gamma)
{
    return gamma / ( 2*pi*( pow((E-E0),2) + pow((gamma/2),2) ) );
}
