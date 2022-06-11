#include <iostream>
#include <cmath>
using namespace std;

void gaussJordanDivide(float matrix[][4], int row, float divider){
  for(int i = 0; i < 4; i++){
    matrix[row][i] = matrix[row][i]/divider;
  }
}

void gaussJordanMultiply(float matrix[][4], int row1, int row2){
  int multiplier = -matrix[row1][row2];
  for(int i = 0; i < 4; i++) matrix[row1][i] = matrix[row1][i] + (multiplier * matrix[row2][i]);
}

void swap(float matrix[][4], int r1, int r2){
    for(int i = 0; i < 4; i++){
        float temp = matrix[r1][i];
        matrix[r1][i] = matrix[r2][i];
        matrix[r2][i] = temp;
    }
}

void GaussJordan(float matrix[][4]){
  int cols = 4;
  int rows = 3;
  // Augmented Matrix

  // Make m00 = 1 (divide or swap)
  if(matrix[0][0] != 1){
    if(matrix[1][0] == 1) {
      swap(matrix, 0, 1);
    }
    else if(matrix[2][0] == 1){
      swap(matrix, 0, 2);
    }
    else {
      gaussJordanDivide(matrix, 0, matrix[0][0]);
    }
  }
  // R2 = R2 + Mutiplier * R1
  if(matrix[1][0] != 0){
    gaussJordanMultiply(matrix, 1, 0);
  }

  // R3 = R3 + Multiplier * R1
  if(matrix[2][0] != 0){
    gaussJordanMultiply(matrix, 2, 0);
  }

  // Make m11 = 1 (divide or swap)
  if(matrix[1][1] != 1){
    if(matrix[2][1] == 1){
      swap(matrix, 1, 2);
    }
    else{
        gaussJordanDivide(matrix, 1, matrix[1][1]);
    }
  }

  // R3 = R3 + Multiplier R2
  if(matrix[0][1] != 0){
    gaussJordanMultiply(matrix, 0, 1);
  }
  
  // R1 = R1 + Multiplier R2
  if(matrix[2][1] != 0){
    gaussJordanMultiply(matrix, 2, 1);
  }

  // Make m22 = 1 (By dividing)
  if(matrix[2][2] != 1){
    gaussJordanDivide(matrix, 2, matrix[2][2]);
  }

  // R1 = R1 + Multiplier R2
  if(matrix[0][2] != 0){
    gaussJordanMultiply(matrix, 0, 2);
  }

  // R2 = R2 + Multiplier R3
  if(matrix[1][2] != 0){
    gaussJordanMultiply(matrix, 1, 2);
  }
  
  float x3 = matrix[2][3] / matrix[2][2];
  float x2 = (matrix[1][3] - ((matrix[1][2] * x3)))/matrix[1][1];
  float x1 = (matrix[0][3] - ( (matrix[0][1] * x2)  + (matrix[0][2] * x3) ))/matrix[0][0];
  cout << "Gauss Jordan Result" << endl << "X1 = " << x1 << endl << "X2 = ";
  cout << x2 << endl << "X3 = " << x3 << endl;
}

int main(){
    float matrix[3][4];
    float _m21 = 0, _m31 = 0, _m32 = 0;
    cout << "Enter matrix" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "row" << i << j << ": ";
            cin >> matrix[i][j];
        }
    }
    GaussJordan(matrix);
}
