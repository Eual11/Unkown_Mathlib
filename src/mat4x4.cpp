#include "../include/mat4x4.h"

mat4x4::mat4x4(float n00, float n01, float n02, float n03, float n10, float n11,
               float n12, float n13, float n20, float n21, float n22, float n23,
               float n30, float n31, float n32, float n33) {
  m[0][0] = n00;
  m[0][1] = n01;
  m[0][2] = n02;
  m[0][3] = n03;
  m[1][0] = n10;
  m[1][1] = n11;
  m[1][2] = n12;
  m[1][3] = n13;
  m[2][0] = n20;
  m[2][1] = n21;
  m[2][2] = n22;
  m[2][3] = n23;
  m[3][0] = n30;
  m[3][1] = n31;
  m[3][2] = n32;
  m[3][3] = n33;
}
mat4x4::mat4x4(float a) {
  m[0][0] = a;
  m[0][1] = a;
  m[0][2] = a;
  m[0][3] = a;

  m[1][0] = a;
  m[1][1] = a;
  m[1][2] = a;
  m[1][3] = a;

  m[2][0] = a;
  m[2][1] = a;
  m[2][2] = a;
  m[2][3] = a;

  m[3][0] = a;
  m[3][1] = a;
  m[3][2] = a;
  m[3][3] = a;
}
mat4x4::mat4x4(const mat4x4 &n) {
  m[0][0] = n[0][0];
  m[0][1] = n[0][1];
  m[0][2] = n[0][2];
  m[0][3] = n[0][3];

  m[1][0] = n[1][0];
  m[1][1] = n[1][1];
  m[1][2] = n[1][2];
  m[1][3] = n[1][3];

  m[2][0] = n[2][0];
  m[2][1] = n[2][1];
  m[2][2] = n[2][2];
  m[2][3] = n[2][3];

  m[3][0] = n[3][0];
  m[3][1] = n[3][1];
  m[3][2] = n[3][2];
  m[3][3] = n[3][3];
}

mat4x4 &mat4x4::operator=(const mat4x4 &n) {

  if (this != &n) {
    m[0][0] = n[0][0];
    m[0][1] = n[0][1];
    m[0][2] = n[0][2];
    m[0][3] = n[0][3];

    m[1][0] = n[1][0];
    m[1][1] = n[1][1];
    m[1][2] = n[1][2];
    m[1][3] = n[1][3];

    m[2][0] = n[2][0];
    m[2][1] = n[2][1];
    m[2][2] = n[2][2];
    m[2][3] = n[2][3];

    m[3][0] = n[3][0];
    m[3][1] = n[3][1];
    m[3][2] = n[3][2];
    m[3][3] = n[3][3];
  }
  return *this;
}

mat4x4::mat4x4(const vec4 &v1, const vec4 &v2, const vec4 &v3, const vec4 &v4) {

  m[0][0] = v1.x;
  m[0][1] = v1.y;
  m[0][2] = v1.z;
  m[0][3] = v1.w;

  m[1][0] = v2.x;
  m[1][1] = v2.y;
  m[1][2] = v2.z;
  m[1][3] = v2.w;

  m[2][0] = v3.x;
  m[2][1] = v3.y;
  m[2][2] = v3.z;
  m[2][3] = v3.w;

  m[3][0] = v4.x;
  m[3][1] = v4.y;
  m[3][2] = v4.z;
  m[3][3] = v4.w;
}

vec4 &mat4x4::operator[](int i) {
  assert(i < 4 && i >= 0);
  return *(reinterpret_cast<vec4 *>(m[i]));
}

const vec4 &mat4x4::operator[](int i) const {
  assert(i < 4 && i >= 0);
  return *(reinterpret_cast<const vec4 *>(m[i]));
}

mat4x4 mat4x4::operator+(const mat4x4 &n) {

  return mat4x4{
      m[0][0] + n[0][0], m[0][1] + n[0][1], m[0][2] + n[0][2],
      m[0][3] + n[0][3], m[1][0] + n[1][0], m[1][1] + n[1][1],
      m[1][2] + n[1][2], m[1][3] + n[1][3], m[2][0] + n[2][0],
      m[2][1] + n[2][1], m[2][2] + n[2][2], m[2][3] + n[2][3],
      m[3][0] + n[3][0], m[3][1] + n[3][1], m[3][2] + n[3][2],
      m[3][3] + n[3][3],
  };
}
mat4x4 mat4x4::operator-(const mat4x4 &n) {
  return mat4x4{
      m[0][0] - n[0][0], m[0][1] - n[0][1], m[0][2] - n[0][2],
      m[0][3] - n[0][3], m[1][0] - n[1][0], m[1][1] - n[1][1],
      m[1][2] - n[1][2], m[1][3] - n[1][3], m[2][0] - n[2][0],
      m[2][1] - n[2][1], m[2][2] - n[2][2], m[2][3] - n[2][3],
      m[3][0] - n[3][0], m[3][1] - n[3][1], m[3][2] - n[3][2],
      m[3][3] - n[3][3],
  };
}
mat4x4 mat4x4::operator*(float s) {
  return mat4x4{
      m[0][0] * s, m[0][1] * s, m[0][2] * s, m[0][3] * s,
      m[1][0] * s, m[1][1] * s, m[1][2] * s, m[1][3] * s,
      m[2][0] * s, m[2][1] * s, m[2][2] * s, m[2][3] * s,
      m[3][0] * s, m[3][1] * s, m[3][2] * s, m[3][3] * s,
  };
}
mat4x4 mat4x4::operator/(float S) {
  float s = 1 / S;
  return mat4x4{
      m[0][0] * s, m[0][1] * s, m[0][2] * s, m[0][3] * s,
      m[1][0] * s, m[1][1] * s, m[1][2] * s, m[1][3] * s,
      m[2][0] * s, m[2][1] * s, m[2][2] * s, m[2][3] * s,
      m[3][0] * s, m[3][1] * s, m[3][2] * s, m[3][3] * s,
  };
}
void mat4x4::transpose() {
  std::swap(m[0][1], m[1][0]);
  std::swap(m[0][2], m[2][0]);
  std::swap(m[0][3], m[3][0]);
  std::swap(m[1][2], m[2][1]);
  std::swap(m[1][3], m[3][1]);
  std::swap(m[2][3], m[3][2]);
}
void mat4x4::inverse() {
  assert(det() != 0);
  auto cofactor = [this](int i, int j) {
    if ((i + j) % 2)
      return -minor(i, j).det();
    return minor(i, j).det();
  };

  mat4x4 adj = {

      cofactor(0, 0), cofactor(0, 1), cofactor(0, 2), cofactor(0, 3),
      cofactor(1, 0), cofactor(1, 1), cofactor(1, 2), cofactor(1, 3),
      cofactor(2, 0), cofactor(2, 1), cofactor(2, 2), cofactor(2, 3),
      cofactor(3, 0), cofactor(3, 1), cofactor(3, 2), cofactor(3, 3),
  };
  adj.transpose();

  *this = adj / det();
}
float mat4x4::det() {
  return m[0][0] * minor(0, 0).det() - m[0][1] * minor(0, 1).det() +
         m[0][2] * minor(0, 2).det() - m[0][3] * minor(0, 3).det();
}

mat4x4 mat4x4::operator*(const mat4x4 &n) {
  mat4x4 r{0.0};

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        r[i][j] += m[i][k] * n[k][j];
      }
    }
  }
  return r;
}

void mat4x4::print_mat() {

  for (size_t i = 0; i < 4; i++) {
    std::cout << " [ ";
    for (int j = 0; j < 4; j++) {
      std::cout << (*this)[i][j] << ", ";
    }

    std::cout << "]\n";
  }
}

vec4 vec4::operator*(const mat4x4 &m) {
  vec4 r;

  r.x = m[0][0] * x + m[1][0] * y + m[2][0] * z + m[3][0] * w;
  r.y = m[0][1] * x + m[1][1] * y + m[2][1] * z + m[3][1] * w;
  r.z = m[0][2] * x + m[1][2] * y + m[2][2] * z + m[3][2] * w;
  r.w = m[0][3] * x + m[1][3] * y + m[2][3] * z + m[3][3] * w;
  return r;
}

mat3x3 mat4x4::minor(int _i, int _j) const {
  mat3x3 mnr;

  int k = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i != _i && j != _j)

      {
        mnr[k / 3][k % 3] = m[i][j];
        k++;
      }
    }
  }
  return mnr;
}
mat3x3 Minor(const mat4x4 &m, int _i, int _j) {
  mat3x3 mnr;

  int k = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i != _i && j != _j)

      {
        mnr[k / 3][k % 3] = m[i][j];
        k++;
      }
    }
  }
  return mnr;
}
mat4x4 Transpose(const mat4x4 &m) {
  return mat4x4{
      m[0][0], m[1][0], m[2][0], m[3][0], m[0][1], m[1][2], m[2][2], m[3][1],
      m[0][2], m[1][2], m[2][2], m[3][2], m[0][3], m[1][3], m[2][3], m[3][3],
  };
}
float Determinant(const mat4x4 &m) {
  return m[0][0] * m.minor(0, 0).det() - m[0][1] * m.minor(0, 1).det() +
         m[0][2] * m.minor(0, 2).det() - m[0][3] * m.minor(0, 3).det();
}
