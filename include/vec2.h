#pragma once
#include <initializer_list>
#ifndef _UML_VEC2
#define _UML_VEC2
#include <cmath>
#include <cstdio>
#include <ostream>
struct mat2x2;
struct vec2 {

  // default constructor
  vec2() = default;
  vec2(const vec2 &) = default;
  vec2 &operator=(const vec2 &) = default;

  vec2(std::initializer_list<float>);

  float x, y;
  vec2(float a, float b) {

    x = a;
    y = b;
  }

  float &operator[](int i);

  const float &operator[](int i) const;
  vec2 &operator+=(const vec2 &); // icrementing by another vecror
  vec2 &operator-=(const vec2 &); // decrementing by another vecror
  vec2 &operator/=(float);
  vec2 &operator*=(float);
  vec2 operator*(float);

  bool operator==(const vec2 &a);
  vec2 operator+(const vec2 &);
  vec2 operator-(const vec2 &);
  // component wise product
  vec2 operator&(const vec2 &);

  float operator*(const vec2 &); // dot product
  vec2 operator*(const mat2x2 &);
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
inline vec2 Schur_Product(const vec2 &v1, const vec2 &v2) {
  return vec2{v1.x * v2.x, v1.y * v2.y};
}
inline std::ostream &operator<<(std::ostream &ost, vec2 vec) {
  ost << "( " << vec.x << ", " << vec.y << " )";

  return ost;
}

// eual
//  interactive
//   game
//: s
#endif
