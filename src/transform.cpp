#include "../include/transform.h"
#include <cmath>

mat2x2 IdentityMat2x2() { return {1, 0, 0, 1}; }
mat3x3 IdentityMat3xe() { return {1, 0, 0, 0, 1, 0, 0, 0, 1}; }
mat4x4 IdentityMat4x4() {

  return {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
}

mat4x4 ScaleUniform(float s) {

  return {s, 0, 0, 0, 0, s, 0, 0, 0, 0, s, 0, 0, 0, 0, 1};
}
mat4x4 ScaleX(float xs) {
  return {xs, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
}
mat4x4 ScaleY(float ys) {
  return {1, 0, 0, 0, 0, ys, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
}

mat4x4 ScaleZ(float zs) {
  return {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, zs, 0, 0, 0, 0, 1};
}
mat4x4 ScaleXYZ(float xs, float ys, float zs) {
  return {xs, 0, 0, 0, 0, ys, 0, 0, 0, 0, zs, 0, 0, 0, 0, 1};
}
mat4x4 ScaleAxis(vec3 n, float k) {
  n.normalize();
  return mat4x4{1 + (k - 1) * n.x * n.x,
                (k - 1) * n.x * n.y,
                (k - 1) * n.x * n.z,
                0,
                (k - 1) * n.x * n.y,
                1 + (k - 1) * n.y * n.y,
                (k - 1) * n.z * n.y,
                0,
                (k - 1) * n.x * n.z,
                (k - 1) * n.y * n.z,
                1 + (k - 1) * n.z * n.z,
                0,
                0,
                0,
                0,
                1};
}
mat4x4 TranslateX(float xt) {
  return {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, xt, 0, 0, 1};
}
mat4x4 TranslateY(float yt) {
  return {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, yt, 0, 1};
}
mat4x4 TranslateZ(float zt) {
  return {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, zt, 1};
}
mat4x4 TranslateXYZ(float xt, float yt, float zt) {
  return {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, xt, yt, zt, 1};
}

mat4x4 RotateX(float theta) {
  float ct = cos(theta);
  float st = sin(theta);

  return {1, 0, 0, 0, 0, ct, st, 0, 0, -st, ct, 0, 0, 0, 0, 1};
}
mat4x4 RotateY(float theta) {
  float ct = cos(theta);
  float st = sin(theta);

  return {ct, 0, -st, 0, 0, 1, 0, 0, st, 0, ct, 0, 0, 0, 0, 1};
}
mat4x4 RotateZ(float theta) {
  float ct = cos(theta);
  float st = sin(theta);

  return {ct, st, 0, 0, -st, ct, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
}
mat4x4 RotateAxis(vec3 n, float t) {
  n.normalize();

  float c = 1 - cos(t);
  float ct = cos(t);
  float st = sin(t);

  return {n.x * n.x * c + ct,
          n.x * n.y * c + n.z * st,
          n.x * n.z * c - n.y * st,
          0,

          n.x * n.y * c - n.z * st,
          n.y * n.y * c + ct,
          n.z * n.y * c + n.x * st,
          0,

          n.x * n.z * c + n.y * st,
          n.y * n.z * c - n.x * st,
          n.z * n.z * c + ct,
          0,

          0,
          0,
          0,
          1

  };
}

mat4x4 RotateEuler(float fYaw, float fPitch, float fRoll) {
  return RotateY(fYaw) * RotateX(fPitch) * RotateZ(fRoll);
}
mat4x4 ClipOrthogonal(float aspectRatio, float fov, float zNear, float zFar) {
  mat4x4 m{0};
  float zoom = 1.0 / tan(fov / 2);
  float lamba = zFar / (zFar - zNear);
  m[0][0] = aspectRatio * zoom;
  m[1][1] = zoom;
  m[2][2] = lamba;
  m[3][2] = -zNear * lamba;
  m[3][3] = 1;

  return m;
}
mat4x4 ClipPrespective(float aspectRatio, float fov, float zNear, float zFar) {
  mat4x4 m{0};
  float zoom = 1.0 / tan(fov / 2);
  float lamba = zFar / (zFar - zNear);
  m[0][0] = aspectRatio * zoom;
  m[1][1] = zoom;
  m[2][2] = lamba;
  m[2][3] = 1;
  m[3][2] = -zNear * lamba;
  return m;
}
