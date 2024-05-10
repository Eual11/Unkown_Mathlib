#ifndef _UML_MAT3X3
#define _UML_MAT3X3
#include "mat2x2.h"
#include "vec3.h"
#include <iostream>
// struct representing 3x3 matrices
//
//

struct mat3x3 {

  // trivial constructor

private:
  float m[3][3];

public:
  mat3x3() = default;
  mat3x3(const mat3x3 &);
  mat3x3 &operator=(const mat3x3 &);
  mat3x3(float, float, float, float, float, float, float, float, float);
  mat3x3(float); // populate with a single element

  mat3x3(const vec3 &, const vec3 &, const vec3 &);

  vec3 &operator[](int i);
  const vec3 &operator[](int i) const;

  mat3x3 operator+(const mat3x3 &);
  mat3x3 operator-(const mat3x3 &);
  mat3x3 operator*(const mat3x3 &);
  mat3x3 operator*(float);
  mat3x3 operator/(float);
  float det();
  void inverse();
  void transpose();
  void print_mat();
  mat2x2 minor(int _i, int _j);
};

float Determinant(const mat3x3 &);
mat3x3 Transpose(const mat3x3 &);
mat3x3 Inverse(mat3x3 &m);
mat2x2 Minor(const mat3x3 &m, int _i, int _j);
#endif
