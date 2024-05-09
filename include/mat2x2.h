// 2x2 matrix structure
//
#ifndef _UML_MAT2x2
#define _UML_MAT2x2
#include "vec2.h"
#include <cassert>
#include <iostream>

struct mat2x2 {

private:
  float m[2][2];

public:
  mat2x2() = default;
  mat2x2(const mat2x2 &) = default;
  mat2x2(float, float, float, float);
  mat2x2(float);
  mat2x2(const vec2 &, const vec2 &);

  vec2 &operator[](int i);
  const vec2 &operator[](int i) const;

  mat2x2 operator+(const mat2x2 &);
  mat2x2 operator-(const mat2x2 &);
  mat2x2 operator*(const mat2x2 &);
  mat2x2 operator*(float);
  mat2x2 operator/(float);
  float det();
  void inverse();
  void transpose();
  void print_mat();
};

float Determinant(const mat2x2 &);
mat2x2 Transpose(const mat2x2 &);
mat2x2 Inverse(const mat2x2 &);
#endif
