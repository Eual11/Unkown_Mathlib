#include "../include/mat2x2.h"

// constructors and assignment operators
mat2x2::mat2x2(float a) {
  m[0][0] = a;
  m[0][1] = a;
  m[1][0] = a;
  m[1][1] = a;
}
mat2x2::mat2x2(float n00, float n01, float n10, float n11) {
  m[0][0] = n00;
  m[0][1] = n01;
  m[1][0] = n10;
  m[1][1] = n11;
}
mat2x2::mat2x2(const vec2 &v1, const vec2 &v2) {
  m[0][0] = v1.x;
  m[0][1] = v1.y;
  m[1][0] = v2.x;
  m[1][1] = v2.y;
}
mat2x2::mat2x2(const mat2x2 &n) {

  m[0][0] = n[0][0];
  m[0][1] = n[0][1];
  m[1][0] = n[1][0];
  m[1][1] = n[1][1];
}
mat2x2 &mat2x2::operator=(const mat2x2 &n) {

  if (this != &n) {
    m[0][0] = n[0][0];
    m[0][1] = n[0][1];
    m[1][0] = n[1][0];
    m[1][1] = n[1][1];
  }
  return *this;
}
// access
//
vec2 &mat2x2::operator[](int i) {
  assert((i < 2) && (i >= 0));
  return *(reinterpret_cast<vec2 *>(m[i]));
}
const vec2 &mat2x2::operator[](int i) const {
  assert((i < 2) && (i >= 0));
  return *(reinterpret_cast<const vec2 *>(m[i]));
}
// basic operatons
mat2x2 mat2x2::operator+(const mat2x2 &n) {
  return mat2x2{m[0][0] + n[0][0], m[0][1] + n[0][1], m[1][0] + n[1][0],
                m[1][1] + n[1][1]};
}
mat2x2 mat2x2::operator-(const mat2x2 &n) {
  return mat2x2{m[0][0] - n[0][0], m[0][1] - n[0][1], m[1][0] - n[1][0],
                m[1][1] - n[1][1]};
}
mat2x2 mat2x2::operator*(float s) {
  return mat2x2{s * m[0][0], s * m[0][1], s * m[1][0], s * m[1][1]};
}
mat2x2 mat2x2::operator*(const mat2x2 &n) {

  mat2x2 r;
  r[0][0] = m[0][0] * n[0][0] + m[0][1] * n[1][0];
  r[0][1] = m[0][0] * n[0][1] + m[0][1] * n[1][1];

  r[1][0] = m[1][0] * n[0][0] + m[1][1] * n[1][0];
  r[1][1] = m[1][0] * n[0][1] + m[1][1] * n[1][1];

  return r;
}
mat2x2 mat2x2::operator/(float S) {
  float s = 1 / S;
  return mat2x2{s * m[0][0], s * m[0][1], s * m[1][0], s * m[1][1]};
}
float mat2x2::det() { return m[0][0] * m[1][1] - m[0][1] * m[1][0]; }

void mat2x2::transpose() {
  float n01 = m[0][1];
  float n10 = m[1][0];

  m[0][1] = n10;
  m[1][0] = n01;
}

void mat2x2::print_mat() {
  std::cout << "[";

  for (size_t i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      std::cout << (*this)[i][j] << ", ";
    }
    std::cout << "\n";
  }
  std::cout << "]\n";
}
void mat2x2::inverse() {
  mat2x2 adj{m[1][1], -m[0][1], -m[1][0], m[0][0]};
  mat2x2 mat = adj / adj.det();
  m[0][0] = mat[0][0];
  m[0][1] = mat[0][1];
  m[1][0] = mat[1][0];
  m[1][1] = mat[1][1];
}

float Determinant(const mat2x2 &m) {
  return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}
mat2x2 Transpose(const mat2x2 &m) {
  mat2x2 tmp(m);
  tmp[0][1] = m[1][0];
  tmp[1][0] = m[0][1];
  return tmp;
}
mat2x2 Inverse(const mat2x2 &m) {

  mat2x2 adj{m[1][1], -m[0][1], -m[1][0], m[0][0]};

  return adj / adj.det();
}
