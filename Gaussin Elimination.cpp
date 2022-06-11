#include <iostream>
#include <cmath>
using namespace std;


//---!! ONLY WHEN SOLVING WITH PARTIAL PIVOT !!---
void swap(float _a[][4], int r1, int r2){
    cout << "Swap R" << r1 << " <-> R" << r2 << endl;
    for(int i = 0; i < 4; i++){
        float temp = _a[r1][i];
        _a[r1][i] = _a[r2][i];
        _a[r2][i] = temp;
    }
}
//---!! ONLY WHEN SOLVING WITH PARTIAL PIVOT !!---

void GJE(float _a[][4], float& m21, float& m31, float& m32)
{
    //---!! ONLY WHEN SOLVING WITH PARTIAL PIVOT !!---
    // Check if pivot is larger than the elements below it
    if(abs(_a[0][0]) < abs(_a[1][0]) || abs(_a[0][0]) < abs(_a[2][0]))
        if(abs(_a[1][0]) > abs(_a[2][0]))
            swap(_a, 0, 1);
        else swap(_a, 0, 2);
    //---!! ONLY WHEN SOLVING WITH PARTIAL PIVOT !!---


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

    //---!! ONLY WHEN SOLVING WITH PARTIAL PIVOT !!---
    // Check if m22 is larger than the element below it
    if(abs(_a[1][1]) < abs(_a[2][1]))
        swap(_a, 1, 2);
    //---!! ONLY WHEN SOLVING WITH PARTIAL PIVOT !!---

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
    GJE(_a, _m21, _m31, _m32);

}
