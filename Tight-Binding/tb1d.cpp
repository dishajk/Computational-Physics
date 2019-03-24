#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

static const double t = 1;
static const int N = 4; //N has to be larger than 2, kDelta is defined such a way

using namespace std;

int kDelta(int, int);
double** Hamiltonian(int);
void display_matrix(double**, int);

int main(void) {
    
// 1D TB Hamiltonian
    double** H = Hamiltonian(N); //use type appropriately
    display_matrix(H,N);
// to clear memory   
//    for ( int h = 0; h < N; h++)
//    {
//        delete [] H[N];
//    }
//    delete [] H;
//    H = 0;
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

double** Hamiltonian(int n)
{
    double** H = 0;
    H = new double*[n];
    for (int i = 1; i <= n; i++)
    {
        H[i-1] = new double[n];
        
        for (int j = 1; j <= n; j++)
        {
            H[i-1][j-1] = - 1 * (kDelta(i,j-1) + kDelta(i,j+1))*t;
        }
    }
    
    return H;
}
void display_matrix(double** matrix, int n)
{
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cout << matrix[i-1][j-1] << " \t ";
        }
        cout << " \n ";
    }
}
