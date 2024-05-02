#pragma once
#ifndef _UML_VEC4
#define _UML_VEC4
#include <cmath>
#include <cstdio>
#include <ostream>
struct vec4 {

  // default constructor
  vec4() = default;

  float x, y, z, w;
  vec4(float a, float b, float c, float d) {

    x = a;
    y = b;
    z = c;
    w = d;
  }

  float &operator[](int i);

  vec4 &operator+=(const vec4 &); // icrementing by another vecror
  vec4 &operator-=(const vec4 &); // decrementing by another vecror
  vec4 &operator/=(float);
  vec4 &operator*=(float);
  vec4 operator*(float);

  bool operator==(const vec4 &a);
  vec4 operator+(const vec4 &);
  vec4 operator-(const vec4 &);

  float operator*(const vec4 &); // dot product
  float magnitude();
  void normalize();
};

inline vec4 operator-(const vec4 &v) { return vec4(-v.x, -v.y, -v.z, -v.w); }

inline vec4 operator/(const vec4 &v, float s) {

  float S = 1 / s;

  return vec4(v.x * S, v.y * S, v.z * S, v.w * S);
}
inline float Magnitude(const vec4 &v) {
  return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}
inline vec4 Normalize(const vec4 &v) { return v / Magnitude(v); }
inline std::ostream &operator<<(std::ostream &ost, vec4 vec) {
  ost << "( " << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w
      << " )";

  return ost;
}

// eual
//  interactive
//   game
//: s
#endif
