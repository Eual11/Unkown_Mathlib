#pragma once
#ifndef _UML_VEC2
#define _UML_VEC2
#include <cmath>
#include <cstdio>
#include <ostream>
struct vec2 {

  // default constructor
  vec2() = default;

  float x, y, z;
  vec2(float a, float b) {

    x = a;
    y = b;
  }

  float &operator[](int i);

  vec2 &operator+=(const vec2 &); // icrementing by another vecror
  vec2 &operator-=(const vec2 &); // decrementing by another vecror
  vec2 &operator/=(float);
  vec2 &operator*=(float);
  vec2 operator*(float);

  bool operator==(const vec2 &a);
  vec2 operator+(const vec2 &);
  vec2 operator-(const vec2 &);

  float operator*(const vec2 &); // dot product
  float magnitude();
  void normalize();
};

inline vec2 operator-(const vec2 &v) { return vec2(-v.x, -v.y); }

inline vec2 operator/(const vec2 &v, float s) {

  float S = 1 / s;

  return vec2(v.x * S, v.y * S);
}
inline float Magnitude(const vec2 &v) { return sqrtf(v.x * v.x + v.y * v.y); }
inline vec2 Normalize(const vec2 &v) { return v / Magnitude(v); }
inline std::ostream &operator<<(std::ostream &ost, vec2 vec) {
  ost << "( " << vec.x << ", " << vec.y << " )";

  return ost;
}

// eual
//  interactive
//   game
//: s
#endif
