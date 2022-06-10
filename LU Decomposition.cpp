#include <iostream>
#include <cmath>
using namespace std;

void GJE(float _a[][4], float& m21, float& m31, float& m32)
{
    m21 = _a[1][0] / _a[0][0];
    m31 = _a[2][0] / _a[0][0];
    //rule E2-(m21)E1 = E2
    for (int j = 0; j < 4; j++)
    {
        float e2 = _a[1][j];
        float e1 = ((m21)*_a[0][j]);
        _a[1][j] = e2 - e1;
    }
    //rule E3-(m31)E1 = E3
    for (int j = 0; j < 4; j++)
    {
        float e3 = _a[2][j];
        float e1 = ((m31)*_a[0][j]);
        _a[2][j] = e3 - e1;
    }
    m32 = _a[2][1] / _a[1][1];
    //rule E3-(m32)E2 = E3
    for (int j = 0; j < 4; j++)
    {
        float e3 = _a[2][j];
        float e1 = ((m32)*_a[1][j]);
        _a[2][j] = e3 - e1;
    }
    float x3 = _a[2][3] / _a[2][2];
    float x2 = (_a[1][3] - (_a[1][2] * x3)) / _a[1][1];
    float x1 = (_a[0][3] - ((_a[0][1] * x2) + (_a[0][2] * x3))) / _a[0][0];
    cout << "Gauss Jordan Result" << endl << "X1 = " << x1 << endl << "X2 = ";
    cout << x2 << endl << "X3 = " << x3 << endl;
}

void LUDecomposition(float _a[3][4])
{
    float _u[3][3], _l[3][3], _b[3];
    float _m21 = 0, _m31 = 0, _m32 = 0;
    for (int i = 0; i < 3; i++) _b[i] = _a[i][3];
    GJE(_a, _m21, _m31, _m32);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) _u[i][j] = _a[i][j];
    }
    cout << endl;
    _l[0][1] = 0;
    _l[0][2] = 0;
    _l[1][2] = 0;
    _l[0][0] = 1;
    _l[1][1] = 1;
    _l[2][2] = 1;
    _l[1][0] = _m21;
    _l[2][0] = _m31;
    _l[2][1] = _m32;
    //lc=b
    float c1 = _b[0] / _l[0][0];
    float c2 = (_b[1] - (_l[1][0] * c1)) / _l[1][1];
    float c3 = (_b[2] - ((_l[2][0] * c1) + (_l[2][1] * c2))) / _l[2][2];
    //ux=c
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++) _a[i][j] = _u[i][j];
    }
    _a[0][3] = c1;
    _a[1][3] = c2;
    _a[2][3] = c3;
    float x3 = _a[2][3] / _a[2][2];
    float x2 = (_a[1][3] - (_a[1][2] * x3)) / _a[1][1];
    float x1 = (_a[0][3] - ((_a[0][1] * x2) + (_a[0][2] * x3))) / _a[0][0];
    cout << "LU decomposition" << endl << "X1 = " << x1 << endl << "X2 = "
         << x2 << endl << "X3 = " << x3 << endl;
}


int main(){
    float _a[3][4];
    float _m21 = 0, _m31 = 0, _m32 = 0;
    cout << "Enter matrix" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "row" << i << j << ": ";
            cin >> _a[i][j];
        }
    }
    LUDecomposition(_a);

}

