#include "../include/vec3.h"
#include <atomic>
#include <cassert>
#include <cstdlib>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <vector>

int testVecAddition() {
  int testCount = 100;
  int failedTests = 0;
  srand(time(NULL));
  for (int i = 0; i < testCount; i++) {

    float v1x = rand();
    float v1y = rand();
    float v1z = rand();

    float v2x = rand();
    float v2y = rand();
    float v2z = rand();

    vec3 a(v1x, v1y, v1z);
    vec3 b(v2x, v2y, v2z);

    vec3 c = a + b;
    vec3 d = vec3(v1x + v2x, v1y + v2y, v1z + v2z);
    if (!(c == d)) {
      failedTests++;
      printf("Test %d failled\n", i);
      std::cout << "at ->" << a << "\n" << b << "\n" << c << "\n" << d << "\n";
    }
  }

  return failedTests;
}
int testVecSubtraction() {
  int testCount = 100;
  int failedTests = 0;
  srand(time(NULL));
  for (int i = 0; i < testCount; i++) {

    float v1x = rand();
    float v1y = rand();
    float v1z = rand();

    float v2x = rand();
    float v2y = rand();
    float v2z = rand();

    vec3 a(v1x, v1y, v1z);
    vec3 b(v2x, v2y, v2z);

    vec3 c = a - b;
    vec3 d = vec3(v1x - v2x, v1y - v2y, v1z - v2z);
    if (!(c == d)) {
      failedTests++;
      printf("Test %d failled\n", i);
      std::cout << "at ->" << a << "\n" << b << "\n" << c << "\n" << d << "\n";
    }
  }

  return failedTests;
}

int testSubscript() {

  float vx = rand();
  float vz = rand();
  float vy = rand();
  int testFailed = 0;

  vec3 v = vec3(vx, vy, vz);

  if (v[0] != vx)
    testFailed++;
  if (v[1] != vy)
    testFailed++;
  if (v[2] != vz)
    testFailed++;

  return testFailed;
}

int testCompundSubtraction() {
  int testsFailed = 0;

  float vx = rand();
  float vy = rand();
  float vz = rand();

  vec3 a = vec3(vx, vy, vz);
  a -= a;
  if (!(a == vec3(0, 0, 0)))
    testsFailed++;
  return testsFailed;
}

int testCompundAddition() {
  int testsFailed = 0;

  float vx = rand();
  float vy = rand();
  float vz = rand();

  vec3 a = vec3(vx, vy, vz);
  a += a;
  if (!(a == vec3(vx + vx, vy + vy, vz + vz)))
    testsFailed++;
  return testsFailed;
}

int testScalarMult() {
  int testsFailed = 0;

  vec3 a(1, 2, 3);

  if (!(a * 0 == vec3(0, 0, 0)))
    testsFailed++;
  return testsFailed;
}
int testScalarDiv() {
  int testFailed = 0;

  vec3 a(3, 3, 3);
  if (!(a / 3 == vec3(1, 1, 1)))
    testFailed++;

  // test zero division
  a / 0;
  return testFailed;
}

int testNormalize() {
  int testsFailed = 0;
  vec3 a(1, 2, 3);
  a.normalize();
  float diff = a.magnitude();
  if (fabs(diff - 1) > 0.001)
    testsFailed++;
  return testsFailed;
}

void testAll() {

  int tf = 0;

  tf = testVecAddition();
  assert(tf == 0);
  tf = testVecSubtraction();
  assert(tf == 0);
  tf = testSubscript();
  assert(tf == 0);
  tf = testCompundSubtraction();
  assert(tf == 0);
  tf = testCompundSubtraction();
  assert(tf == 0);
  tf = testScalarDiv();
  assert(tf == 0);
  tf = testNormalize();

  assert(tf == 0);

  std::cout << "vec3: All Tests Passed \n";
}
struct triangle {
  vec3 p[3];
  triangle(std::initializer_list<vec3> vals) {
    if (vals.size() != 3)
      throw new std::invalid_argument("invalid arg");
    auto it = vals.begin();
    p[0] = *it++;
    p[1] = *it++;
    p[2] = *it;
  }
};
struct mesh {
  std::vector<triangle> tris;
};
;

int main() {

  triangle tr({{1, 2, 3}, {1, 2, 3}, {1, 2, 3}});
  mesh cube;

  cube.tris = {{{0, 0, 0}, {0, 1, 0}, {0, 0, 1}},
               {{1, 0, 0}, {1, 1, 0}, {0, 1, 1}}};
  for (auto tri : cube.tris) {
    printf("(%f, %f, %f)\n", tri.p[0].x, tri.p[0].y, tri.p[0].z);
    printf("(%f, %f, %f)\n", tri.p[1].x, tri.p[1].y, tri.p[1].z);
    printf("(%f, %f, %f)\n", tri.p[2].x, tri.p[2].y, tri.p[2].z);
    printf("/////////////// \n");
  }
  /* cube.tris = {{{0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 0.0f}}};
   */
  return 0;
}
