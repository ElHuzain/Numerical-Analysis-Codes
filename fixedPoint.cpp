#include <iostream>
#include <cmath>
using namespace std;

double eps = 1.0;
int iter = 0;
double xiPlus1 = 0, xi = 0, error = 0;

double f(double x){
    return sqrt(4*x+9.166);
}

double fixedpoint(double x){
    xi = x;
    xiPlus1 = f(xi);
    cout << "i=" << iter << " | Xi= " << x << " | Xi+1= "
         << xiPlus1 << " | E= %" << error << endl;
    error = abs((xiPlus1 - xi) / xiPlus1) * 100;
    iter++;
    if (error > eps) fixedpoint(xiPlus1);
    return xi;
}

int main(){
    double xo = 5;
    double root;
    root = fixedpoint(xo);
    cout << "root= " << root << endl;
    return 0;
}