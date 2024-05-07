#include "../include/mat3x3.h"

mat3x3::mat3x3(float n00, float n01, float n02, float n10, float n11, float n12,
               float n20, float n21, float n22

) {
  m[0][0] = n00;
  m[0][1] = n01;
  m[0][2] = n02;
  m[1][0] = n10;
  m[1][1] = n11;
  m[1][2] = n12;
  m[2][0] = n20;
  m[2][1] = n21;
  m[2][2] = n22;
}

mat3x3::mat3x3(const vec3 &v1, const vec3 &v2, const vec3 &v3) {
  m[0][0] = v1.x;
  m[0][1] = v1.y;
  m[0][2] = v1.z;

  m[1][0] = v2.x;
  m[1][1] = v2.y;
  m[1][2] = v2.z;

  m[2][0] = v3.x;
  m[2][1] = v3.y;
  m[2][2] = v3.z;
}
vec3 &mat3x3::operator[](int i) { return *(reinterpret_cast<vec3 *>(m[i])); }
const vec3 &mat3x3::operator[](int i) const {
  return *(reinterpret_cast<const vec3 *>(m[i]));
}

void mat3x3::print_mat() {
  std::cout << "[";

  for (size_t i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << (*this)[i][j] << ", ";
    }
    std::cout << "\n";
  }
  std::cout << "]\n";
}

mat3x3 mat3x3::operator+(const mat3x3 &n) {
  return mat3x3{

      m[0][0] + n[0][0], m[0][1] + n[0][1], m[0][2] + n[0][2],
      m[1][0] + n[1][0], m[1][1] + n[1][1], m[1][2] + n[1][2],
      m[2][0] + n[2][0], m[2][1] + n[2][1], m[2][2] + n[2][2]};
}
mat3x3 mat3x3::operator-(const mat3x3 &n) {
  return mat3x3{

      m[0][0] - n[0][0], m[0][1] - n[0][1], m[0][2] - n[0][2],
      m[1][0] - n[1][0], m[1][1] - n[1][1], m[1][2] - n[1][2],
      m[2][0] - n[2][0], m[2][1] - n[2][1], m[2][2] - n[2][2]};
}

mat3x3 mat3x3::operator*(float s) {
  return mat3x3{
      m[0][0] * s, m[0][1] * s, m[0][2] * s, m[1][0] * s, m[1][1] * s,
      m[1][2] * s, m[2][0] * s, m[2][1] * s, m[2][2] * s,
  };
}

mat3x3 mat3x3::operator/(float s) {
  float S = 1 / s;
  return mat3x3{
      m[0][0] * S, m[0][1] * S, m[0][2] * S, m[1][0] * S, m[1][1] * S,
      m[1][2] * S, m[2][0] * S, m[2][1] * S, m[2][2] * S,
  };
}
void mat3x3::transpose() {

  vec3 v1{m[0][0], m[0][1], m[0][2]};
  vec3 v2{m[1][0], m[1][1], m[1][2]};
  vec3 v3{m[2][0], m[2][1], m[2][2]};

  m[0][0] = v1[0];
  m[1][0] = v1[1];
  m[2][0] = v1[2];

  m[0][1] = v2[0];
  m[1][1] = v2[1];
  m[2][1] = v2[2];

  m[0][2] = v3[0];
  m[1][2] = v3[1];
  m[2][2] = v3[2];
}

float mat3x3::det() {
  return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
         m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
         m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
}
float Determinant(const mat3x3 &m) {
  return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
         m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
         m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
}
mat3x3 Transpose(mat3x3 m) {
  vec3 v1{m[0][0], m[0][1], m[0][2]};
  vec3 v2{m[1][0], m[1][1], m[1][2]};
  vec3 v3{m[2][0], m[2][1], m[2][2]};

  m[0][0] = v1[0];
  m[1][0] = v1[1];
  m[2][0] = v1[2];

  m[0][1] = v2[0];
  m[1][1] = v2[1];
  m[2][1] = v2[2];

  m[0][2] = v3[0];
  m[1][2] = v3[1];
  m[2][2] = v3[2];

  return m;
}
