#include "../include/uml/mat4x4.h"
#include <cmath>
#include <iostream>

mat4x4 test(mat4x4 mat) {
  mat4x4 matrix;
  matrix[0][0] = mat[0][0];
  matrix[0][1] = mat[1][0];
  matrix[0][2] = mat[2][0];
  matrix[0][3] = 0;
  matrix[1][0] = mat[0][1];
  matrix[1][1] = mat[1][1];
  matrix[1][2] = mat[2][1];
  matrix[1][3] = 0;
  matrix[2][0] = mat[0][2];
  matrix[2][1] = mat[1][2];
  matrix[2][2] = mat[2][2];
  matrix[2][0] = 0;
  matrix[3][0] = -(mat[3][0] * matrix[0][0] + mat[3][1] * matrix[1][0] +
                   mat[3][2] * matrix[2][0]);
  matrix[3][1] = -(mat[3][0] * matrix[0][1] + mat[3][1] * matrix[1][1] +
                   mat[3][2] * matrix[2][1]);
  matrix[3][2] = -(mat[3][0] * matrix[0][2] + mat[3][1] * matrix[1][2] +
                   mat[3][2] * matrix[2][2]);
  matrix[3][3] = 1.0f;
  return matrix;
}
int main(void) {
  mat4x4 a = {

      1, 0, 0, 0, 0, 0.5, -0.866, 0, 0, 0.866, 0.5, 0, 0, 0, 0, 1};

  mat4x4 b = test(a);

  a.inverse();
  printf("a: \n");
  a.print_mat();
  printf("b: \n");
  b.print_mat();
}
