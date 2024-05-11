#include "../include/vec4.h"

float &vec4::operator[](int i) { return ((&x)[i]); }
const float &vec4::operator[](int i) const { return ((&x)[i]); }
vec4 &vec4::operator+=(const vec4 &v) {

  x += v.x;
  y += v.y;
  z += v.z;
  w += v.z;

  return *(this);
}
vec4::vec4(std::initializer_list<float> vals) {
  auto it = vals.begin();
  x = *it++;
  y = *it++;
  z = *it++;
  w = *it;
}

vec4 &vec4::operator-=(const vec4 &v) {
  x -= v.x;
  y -= v.y;
  z -= v.z;
  w -= v.w;

  return *(this);
}

vec4 &vec4::operator/=(float s) {

  x /= s;
  y /= s;
  z /= s;
  w /= s;

  return *(this);
}

vec4 &vec4::operator*=(float s) {
  x *= s;
  y *= s;
  z *= s;
  w *= s;

  return *(this);
}

vec4 vec4::operator+(const vec4 &v) {
  return vec4(x + v.x, y + v.y, z + v.z, w + v.w);
}
vec4 vec4::operator*(float f) { return vec4(x * f, y * f, z * f, w * f); }
vec4 vec4::operator-(const vec4 &v) {
  return vec4(x - v.x, y - v.y, z - v.z, w - v.w);
}

float vec4::operator*(const vec4 &v) {
  return (x * v.x + y * v.y + z * v.z + w * v.w);
}

float vec4::magnitude() { return sqrtf(x * x + y * y + z * z + w * w); }

void vec4::normalize() {

  float absv = magnitude();
  x /= absv;
  y /= absv;
  z /= absv;
  w /= absv;
}

bool vec4::operator==(const vec4 &v) {
  return (x == v.x && y == v.y && z == v.z && w == v.w);
}
