//
//  hubbard01.cpp
//  
//
//  Created by Disha Kuzhively on 31/03/19.
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
static const int d = 3; //N has to be larger than 2, kDelta is defined that way
int sites = d*d;

using namespace std;
int kDelta(int, int);

int main(void){
    
    gsl_matrix * H = gsl_matrix_alloc (sites, sites);
    
//    Hamiltonian matrix
    int x, y;
    for (int i = 1; i <= sites; i ++) {
        for (int j = 1; j <= sites; j ++) {
            if ((j%d == 0)/*||(i%d == 0)*/) {
                x = d - 1;
            } else {
                x = -1;
            }
//            if (i <= d) {
//                y = d - sites;
//            } else {
//                y = d;
//            }
            gsl_matrix_set (H, i-1, j-1, -1*( kDelta(i+x,j) /*+ kDelta(i,j+y) + kDelta(i,j+x) */)*t);
        }
    }
//    Display
    
    for (int i = 0; i < sites; i ++) {
        for (int j = 0; j < sites; j ++) {
            cout << gsl_matrix_get (H, i, j) << " \t " ;
        }
        cout << endl ;
    }
    
    gsl_matrix_free (H);
    return 0;
}

int kDelta(int a, int b)
{
    if (a == b) {
        return 1;
    } else {
        return 0;
    }
}
