#include <iostream>
#include <cmath>
using namespace std;

void CopyMatrix(float _x[][4], float _y[][4])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            _y[i][j] = _x[i][j];
        }
    }
}

void CramersRule(float _a[][4])
{
    float _ca[3][4];
    float detA, _detA[3];
    float r0, r1, r2;
    CopyMatrix(_a, _ca);
    r0 = _a[0][0] * ((_a[1][1] * _a[2][2]) - (_a[1][2] * _a[2][1]));
    r1 = _a[0][1] * ((_a[1][0] * _a[2][2]) - (_a[1][2] * _a[2][0]));
    r2 = _a[0][2] * ((_a[1][0] * _a[2][1]) - (_a[1][1] * _a[2][0]));
    detA = r0 + (-r1) + r2;
    cout << "Determinte of A = " << detA << endl;
    for (int i = 0; i < 3; i++)
    {
        _a[0][i] = _a[0][3];
        _a[1][i] = _a[1][3];
        _a[2][i] = _a[2][3];
        r0 = _a[0][0] * ((_a[1][1] * _a[2][2]) - (_a[1][2] * _a[2][1]));
        r1 = _a[0][1] * ((_a[1][0] * _a[2][2]) - (_a[1][2] * _a[2][0]));
        r2 = _a[0][2] * ((_a[1][0] * _a[2][1]) - (_a[1][1] * _a[2][0]));
        _detA[i] = r0 + (-r1) + r2;
        CopyMatrix(_ca, _a);
        cout << "A[" << (i + 1) << "] = " << _detA[i] << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "x" << (i + 1) << " = " << _detA[i] / detA << endl;
    }
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
    CramersRule(_a);
}
