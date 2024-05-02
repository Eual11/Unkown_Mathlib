#include "../include/vec3.h"

float &vec3::operator[](int i) { return ((&x)[i]); }

vec3 &vec3::operator+=(const vec3 &v) {

  x += v.x;
  y += v.y;
  z += v.z;

  return *(this);
}

vec3 &vec3::operator-=(const vec3 &v) {
  x -= v.x;
  y -= v.y;
  z -= v.z;

  return *(this);
}

vec3 &vec3::operator/=(float s) {

  x /= s;
  y /= s;
  z /= s;

  return *(this);
}

vec3 &vec3::operator*=(float s) {
  x *= s;
  y *= s;
  z *= s;

  return *(this);
}

vec3 vec3::operator+(const vec3 &v) { return vec3(x + v.x, y + v.y, z + v.z); }
vec3 vec3::operator*(float f) { return vec3(x * f, y * f, z * f); }
vec3 vec3::operator-(const vec3 &v) { return vec3(x - v.x, y - v.y, z - v.z); }

float vec3::operator*(const vec3 &v) { return (x * v.x + y * v.y + z * v.z); }

float vec3::magnitude() { return sqrtf(x * x + y * y + z * z); }

void vec3::normalize() {

  float absv = magnitude();
  x /= absv;
  y /= absv;
  z /= absv;
}

bool vec3::operator==(const vec3 &v) {
  return (x == v.x && y == v.y && z == v.z);
}
