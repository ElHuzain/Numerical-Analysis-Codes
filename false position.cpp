#include <iostream>
#include <cmath>
using namespace std;

const double eps = 1.0;
int iter = 0;
double xr = 0, xrOld = 0, error = 0;

double f(double x){
    return -0.6 * pow(x, 2) + 2.4 * x + 5.5;
}

double falsePosition(double xl, double xu){
    xrOld = xr;
    xr = (xl + xu) / 2;
    xr = xu - (f(xu) * (xl - xu))/(f(xl) - f(xu));
    error = abs((xr - xrOld) / xr) * 100;
    cout << "iteration=" << iter << " | xl=" << xl 
         << " | f(xl)=" << f(xl) << " | xu=" << xu << " | f(xu)"
         << f(xu) << " | xr=" << xr << " | f(xr)="
         << f(xr) << " Error%=" << error << endl << endl;
    if (f(xl) * f(xr) > 0) xl = xr;
    else if (f(xl) * f(xr) < 0) xu = xr;
    else return xr;
    iter++;
    if(error > eps) falsePosition(xl, xu);
    else return xr;
}

int main(){
    float xl = 5, xu = 10;
    cout << "Root =" << falsePosition(xl, xu) << endl;
    return 0;
}
