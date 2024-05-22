#ifndef _UML_MAT4X4
#define _UML_MAT4X4

#include "mat3x3.h"
#include "vec4.h"
#include <iostream>
struct mat4x4 {
  float m[4][4] = {0};

public:
  // constructors
  mat4x4() = default;
  mat4x4(const mat4x4 &);

  mat4x4(float);
  mat4x4 &operator=(const mat4x4 &);

  mat4x4(float, float, float, float, float, float, float, float, float, float,
         float, float, float, float, float, float);

  mat4x4(const vec4 &, const vec4 &, const vec4 &, const vec4 &);

  vec4 &operator[](int i);
  const vec4 &operator[](int i) const;

  mat4x4 operator+(const mat4x4 &);
  mat4x4 operator-(const mat4x4 &);
  mat4x4 operator*(const mat4x4 &);
  mat4x4 operator*(float);
  mat4x4 operator/(float);
  float det();
  void inverse();
  void transpose();
  void print_mat();
  mat3x3 minor(int _i, int _j) const;
};

float Determinant(const mat4x4 &);
mat4x4 Transpose(const mat4x4 &);
mat4x4 Inverse(mat4x4 &m);
mat3x3 Minor(const mat4x4 &m, int _i, int _j);

#endif
