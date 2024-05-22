#include "../include/vec2.h"

float &vec2::operator[](int i) { return ((&x)[i]); }

const float &vec2::operator[](int i) const { return ((&x)[i]); }

vec2 &vec2::operator+=(const vec2 &v) {

  x += v.x;
  y += v.y;

  return *(this);
}
vec2::vec2(std::initializer_list<float> vals) {
  auto it = vals.begin();
  x = *it++;
  y = *it;
}

vec2 &vec2::operator-=(const vec2 &v) {
  x -= v.x;
  y -= v.y;

  return *(this);
}

vec2 &vec2::operator/=(float s) {
  float S = 1 / s;
  x *= S;
  y *= S;

  return *(this);
}

vec2 &vec2::operator*=(float s) {
  x *= s;
  y *= s;

  return *(this);
}

vec2 vec2::operator+(const vec2 &v) { return vec2(x + v.x, y + v.y); }
vec2 vec2::operator*(float f) { return vec2(x * f, y * f); }
vec2 vec2::operator-(const vec2 &v) { return vec2(x - v.x, y - v.y); }

float vec2::operator*(const vec2 &v) { return (x * v.x + y * v.y); }

float vec2::magnitude() { return sqrtf(x * x + y * y); }

void vec2::normalize() {

  float absv = sqrtf(x * x + y * y);
  if (absv != 0.0) {

    x /= absv;
    y /= absv;
  }
}

bool vec2::operator==(const vec2 &v) { return (x == v.x && y == v.y); }
