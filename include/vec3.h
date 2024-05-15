#pragma once
#include <initializer_list>
#ifndef _UML_VEC3
#define _UML_VEC3
#include <cmath>
#include <cstdio>
#include <ostream>
struct mat3x3;
struct mat4x4;
struct vec3 {

  // default constructor
  vec3() = default;
  vec3(const vec3 &) = default;
  vec3 &operator=(const vec3 &) = default;
  float x, y, z;
  vec3(float a, float b, float c) {

    x = a;
    y = b;
    z = c;
  }
  vec3(std::initializer_list<float>);

  float &operator[](int i);

  const float &operator[](int i) const;
  vec3 &operator+=(const vec3 &); // icrementing by another vecror
  vec3 &operator-=(const vec3 &); // decrementing by another vecror
  vec3 &operator/=(float);
  vec3 &operator*=(float);
  vec3 operator*(float);

  bool operator==(const vec3 &a);
  vec3 operator+(const vec3 &);
  vec3 operator-(const vec3 &);

  vec3 operator*(const mat3x3 &);
  vec3 operator*(const mat4x4 &m);
  float operator*(const vec3 &); // dot product
  float magnitude();
  void normalize();
};

inline vec3 operator-(const vec3 &v) { return vec3(-v.x, -v.y, -v.z); }

inline vec3 operator/(const vec3 &v, float s) {

  float S = 1 / s;

  return vec3(v.x * S, v.y * S, v.z * S);
}
inline float Magnitude(const vec3 &v) {
  return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

inline vec3 Normalize(const vec3 &v) { return v / Magnitude(v); }
inline std::ostream &operator<<(std::ostream &ost, vec3 vec) {
  ost << "( " << vec.x << ", " << vec.y << ", " << vec.z << " )";

  return ost;
}
inline vec3 Cross(const vec3 &v1, const vec3 &v2) {
  return vec3(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z,
              v1.x * v2.y - v1.y * v2.x);
}

#endif
