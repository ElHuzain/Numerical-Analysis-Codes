#include <iostream>
#include <cmath>
using namespace std;
const double eps = 0.5;
double xiPlus1 = 0, xi = 0, error = 0;
int iter = 0;
double f(double x){
    return  -0.6 * pow(x, 2) + 2.4 * x + 5.5;
}
double fDash(double x){
    return -1.2 * x + 2.4;
}
double newton(double xo){
    xi = xo;
    cout << "i=" << iter << " | Xi= " << xi << " | F(Xi)= "
         << f(xi) << " | F'(Xi)= " << fDash(xi) << " | E= %" << error << endl;
    xiPlus1 = xi - (f(xi) / fDash(xi));
    if (error > eps || iter == 0){
        error = abs((xiPlus1 - xi) / xiPlus1) * 100;
        iter++;
        newton(xiPlus1);
    }
    return xi;
}
int main(){
    double Xo = 5;
    double root = newton(Xo);
    cout << "root= " << root << endl;
    return 0;
}
