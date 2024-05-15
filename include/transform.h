#ifndef _UML_TRANSFORM
#define _UML_TRANSFORM

#include "mat2x2.h"
#include "mat3x3.h"
#include "mat4x4.h"
#include "vec3.h"

// identity
//

inline mat2x2 IdentityMat2x2();
inline mat3x3 IdentityMat3x3();
inline mat4x4 IdentityMat4x4();

// builds various scaling matrices
inline mat4x4 ScaleUniform(float s);
inline mat4x4 ScaleX(float xs);
inline mat4x4 ScaleY(float ys);
inline mat4x4 ScaleZ(float zs);
inline mat4x4 ScaleXYZ(float xs, float xy, float xz);
mat4x4 ScaleAxis(vec3 v, float k);

// rotation matrices
inline mat4x4 RotateX(float theta);
inline mat4x4 RotateY(float theta);
inline mat4x4 RotateZ(float theta);
mat4x4 RotateAxis(vec3 axis, float theta);
inline mat4x4 RotateEuler(float fYaw, float fPitch, float fBank);

// translating
//

inline mat4x4 TranslateX(float x);
inline mat4x4 TranslateY(float y);
inline mat4x4 TranslateZ(float z);
inline mat4x4 TranslateXYZ(float x, float y, float z);

// projections
//

mat4x4 ProjectX(vec3 n);
mat4x4 ProjectY(vec3 n);
mat4x4 ProjectZ(vec3 n);
mat4x4 ProjectAxis(vec3 n);

mat4x4 ClipOrthogonal(float aspectRatio, float fov, float zNear, float zFar);
mat4x4 ClipPrespective(float aspectRatio, float fov, float zNear, float zFar);
#endif
