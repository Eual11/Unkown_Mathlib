#include "../include/transform.h"
#include <cmath>

mat2x2 IdentityMat2x2() {
  mat2x2 m;

  m.m[0][0] = 1.0f;
  m.m[1][1] = 1.0f;

  return m;
}
mat3x3 IdentityMat3xe() {
  mat3x3 m;
  m.m[0][0] = 1.0f;
  m.m[1][1] = 1.0f;
  m.m[2][2] = 1.0f;

  return m;
}
mat4x4 IdentityMat4x4() {
  mat4x4 m;
  m.m[0][0] = 1.0f;
  m.m[1][1] = 1.0f;
  m.m[2][2] = 1.0f;
  m.m[3][3] = 1.0f;

  return m;
}

mat4x4 ScaleUniform(float s) {

  mat4x4 m;
  m.m[0][0] = s;
  m.m[1][1] = s;
  m.m[2][2] = s;
  m.m[3][3] = 1.0f;
  return m;
}
mat4x4 ScaleX(float xs) {
  mat4x4 m;
  m.m[0][0] = xs;
  m.m[1][1] = 1.0f;
  m.m[2][2] = 1.0f;
  m.m[3][3] = 1.0f;
  return m;
}
mat4x4 ScaleY(float ys) {
  mat4x4 m;
  m.m[0][0] = 1.0f;
  m.m[1][1] = ys;
  m.m[2][2] = 1.0f;
  m.m[3][3] = 1.0f;
  return m;
}

mat4x4 ScaleZ(float zs) {
  mat4x4 m;
  m.m[0][0] = 1.0f;
  m.m[1][1] = 1.0f;
  m.m[2][2] = zs;
  m.m[3][3] = 1.0f;
  return m;
}
mat4x4 ScaleXYZ(float xs, float ys, float zs) {
  mat4x4 m;
  m.m[0][0] = xs;
  m.m[1][1] = ys;
  m.m[2][2] = zs;
  m.m[3][3] = 1.0f;
  return m;
}
mat4x4 ScaleAxis(vec3 n, float k) {
  n.normalize();
  mat4x4 m;
  m.m[0][0] = 1 + (k - 1) * n.x * n.x;
  m.m[0][1] = (k - 1) * n.x * n.y;
  m.m[0][2] = (k - 1) * n.x * n.z;

  m.m[1][0] = (k - 1) * n.x * n.y;
  m.m[1][1] = 1 + (k - 1) * n.y * n.y;
  m.m[1][2] = (k - 1) * n.z * n.y;

  m.m[2][0] = (k - 1) * n.x * n.z;
  m.m[2][1] = (k - 1) * n.y * n.z;
  m.m[2][2] = 1 + (k - 1) * n.z * n.z;
  m.m[3][3] = 1.0f;
  return m;
}
mat4x4 TranslateX(float xt) {
  mat4x4 m;
  m.m[0][0] = 1.0f;
  m.m[1][1] = 1.0f;
  m.m[2][2] = 1.0f;
  m.m[3][3] = 1.0f;
  m.m[3][0] = xt;
  return m;
}
mat4x4 TranslateY(float yt) {
  mat4x4 m;
  m.m[0][0] = 1.0f;
  m.m[1][1] = 1.0f;
  m.m[2][2] = 1.0f;
  m.m[3][3] = 1.0f;
  m.m[3][1] = yt;
  return m;
}
mat4x4 TranslateZ(float zt) {
  mat4x4 m;
  m.m[0][0] = 1.0f;
  m.m[1][1] = 1.0f;
  m.m[2][2] = 1.0f;
  m.m[3][3] = 1.0f;
  m.m[3][2] = zt;
  return m;
}
mat4x4 TranslateXYZ(float xt, float yt, float zt) {
  mat4x4 m;
  m.m[0][0] = 1.0f;
  m.m[1][1] = 1.0f;
  m.m[2][2] = 1.0f;
  m.m[3][3] = 1.0f;
  m.m[3][0] = xt;
  m.m[3][1] = yt;
  m.m[3][2] = zt;
  return m;
}

mat4x4 RotateX(float theta) {
  float ct = cos(theta);
  float st = sin(theta);
  mat4x4 m;
  m.m[0][0] = 1.0f;
  m.m[1][1] = ct;
  m.m[1][2] = st;
  m.m[2][1] = -st;
  m.m[2][2] = ct;
  m.m[3][3] = 1;

  return m;
}
mat4x4 RotateY(float theta) {
  float ct = cos(theta);
  float st = sin(theta);
  mat4x4 m;
  m.m[0][0] = ct;
  m.m[0][2] = -st;
  m.m[1][1] = 1.0f;
  m.m[2][0] = st;
  m.m[2][2] = ct;
  m.m[3][3] = 1.0f;

  return m;
}
mat4x4 RotateZ(float theta) {
  float ct = cos(theta);
  float st = sin(theta);
  mat4x4 m;
  m.m[0][0] = ct;
  m.m[0][1] = st;
  m.m[1][0] = -st;
  m.m[1][1] = ct;
  m.m[2][2] = 1.0f;
  m.m[3][3] = 1.0f;

  return m;
}
mat4x4 RotateAxis(vec3 n, float t) {
  n.normalize();

  float c = 1 - cos(t);
  float ct = cos(t);
  float st = sin(t);
  mat4x4 m;
  m.m[0][0] = n.x * n.x * c + ct;
  m.m[0][1] = n.x * n.y * c + n.z * st;
  m.m[0][2] = n.x * n.z * c - n.y * st;

  m.m[1][0] = n.x * n.y * c - n.z * st;
  m.m[1][1] = n.y * n.y * c + ct;
  m.m[1][2] = n.z * n.y * c + n.x * st;

  m.m[2][0] = n.x * n.z * c + n.y * st;
  m.m[2][1] = n.y * n.z * c - n.x * st;
  m.m[2][2] = n.z * n.z * c + ct;
  m.m[3][3] = 1.0f;
  return m;
}

mat4x4 RotateEuler(float fYaw, float fPitch, float fRoll) {
  return RotateY(fYaw) * RotateX(fPitch) * RotateZ(fRoll);
}
mat4x4 ClipOrthogonal(float aspectRatio, float fov, float zNear, float zFar) {
  mat4x4 m;
  float zoom = 1.0 / tan(fov / 2);
  float lamba = zFar / (zFar - zNear);
  m.m[0][0] = aspectRatio * zoom;
  m.m[1][1] = zoom;
  m.m[2][2] = lamba;
  m.m[3][2] = -zNear * lamba;
  m.m[3][3] = 1;

  return m;
}
mat4x4 ClipPrespective(float aspectRatio, float fov, float zNear, float zFar) {
  mat4x4 m;
  float zoom = 1.0 / tan(fov / 2);
  float lamba = zFar / (zFar - zNear);
  m.m[0][0] = aspectRatio * zoom;
  m.m[1][1] = zoom;
  m.m[2][2] = lamba;
  m.m[2][3] = 1;
  m.m[3][2] = -zNear * lamba;
  return m;
}

mat4x4 PointAt(vec3 position, vec3 target, vec3 up) {

  vec3 forward = target - position;
  forward.normalize();

  vec3 newup = up - forward * (forward * up);
  newup.normalize();

  vec3 right = Cross(newup, forward);
  //clang-format off
  return {right.x,    right.y,    right.z,    0,         newup.x,   newup.y,
          newup.z,    0,          forward.x,  forward.y, forward.z, 0,
          position.x, position.y, position.z, 1};
}

mat4x4 LookAt(vec3 position, vec3 target, vec3 up) {

  vec3 forward = target - position;
  forward.normalize();

  vec3 newup = up - forward * (forward * up);
  newup.normalize();

  vec3 right = Cross(newup, forward);
  //clang-format off
  mat4x4 mat;
  mat.m[0][0] = right.x;
  mat.m[1][0] = right.y;
  mat.m[2][0] = right.z;

  mat.m[0][1] = newup.x;
  mat.m[1][1] = newup.y;
  mat.m[2][1] = newup.z;

  mat.m[0][2] = forward.x;
  mat.m[1][2] = forward.y;
  mat.m[2][2] = forward.z;
  float tx = -position * right;
  float ty = -position * newup;
  float tz = -position * forward;

  mat.m[3][0] = tx;
  mat.m[3][1] = ty;
  mat.m[3][2] = tz;
  mat.m[3][3] = 1.0f;
  return mat;
}
