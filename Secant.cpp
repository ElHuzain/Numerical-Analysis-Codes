#include <iostream>
#include <cmath>
using namespace std;

const double eps = 1.0;
int iter = 0;
double error = 0;

double f(double x){
    return -0.6 * pow(x, 2) + 2.4 * x + 5.5;
}

double secant(double xiMinus1, double xi, double error, int iter){
    double xiOld = xi;
    error = abs((xi - xiMinus1)/xi) * 100;
    cout << "i=" << iter << " | Xi-1= " << xiMinus1 << "| f(Xi-1)= "
         << f(xiMinus1) << " | Xi= " << xi << " | f(Xi)= "
         << f(xi) << "| E= %" << error << endl;
    xi = xi - ((f(xi) * (xiMinus1 - xi)) / (f(xiMinus1) - f(xi)));
    xiMinus1 = xiOld;
    iter++;
    if(error > eps) secant(xiMinus1, xi, error, iter);
    else return xi;
}

int main(){
    double xiMinus1 = 5, xi = 10;
    double root = secant(xiMinus1, xi, error, iter);
    cout << "Root: " << root << endl;
}
