#include "../include/vec4.h"
#include <atomic>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>

int testVecAddition() {
  int testCount = 100;
  int failedTests = 0;
  srand(time(NULL));
  for (int i = 0; i < testCount; i++) {

    float v1x = rand();
    float v1y = rand();
    float v1z = rand();
    float v1w = rand();

    float v2x = rand();
    float v2y = rand();
    float v2z = rand();
    float v2w = rand();

    vec4 a(v1x, v1y, v1z, v1w);
    vec4 b(v2x, v2y, v2z, v2w);

    vec4 c = a + b;
    vec4 d = vec4(v1x + v2x, v1y + v2y, v1z + v2z, v1w + v2w);
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
    float v1w = rand();

    float v2x = rand();
    float v2y = rand();
    float v2z = rand();
    float v2w = rand();

    vec4 a(v1x, v1y, v1z, v1w);
    vec4 b(v2x, v2y, v2z, v2w);
    vec4 c = a - b;
    vec4 d = vec4(v1x - v2x, v1y - v2y, v1z - v2z, v1w - v2w);
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
  float vy = rand();
  float vz = rand();
  float vw = rand();
  int testFailed = 0;

  vec4 v = vec4(vx, vy, vz, vw);

  if (v[0] != vx)
    testFailed++;
  if (v[1] != vy)
    testFailed++;
  if (v[2] != vz)
    testFailed++;
  if (v[3] != vw)
    testFailed++;

  return testFailed;
}

int testCompundSubtraction() {
  int testsFailed = 0;

  float vx = rand();
  float vy = rand();
  float vz = rand();
  float vw = rand();

  vec4 a = vec4(vx, vy, vz, vw);
  a -= a;
  if (!(a == vec4(0, 0, 0, 0)))
    testsFailed++;
  return testsFailed;
}

int testCompundAddition() {
  int testsFailed = 0;

  float vx = rand();
  float vy = rand();
  float vz = rand();
  float vw = rand();

  vec4 a = vec4(vx, vy, vz, vw);
  a += a;
  if (!(a == vec4(vx + vx, vy + vy, vz + vz, vw + vw)))
    testsFailed++;
  return testsFailed;
}

int testScalarMult() {
  int testsFailed = 0;

  vec4 a(1, 2, 3, 4);

  if (!(a * 0 == vec4(0, 0, 0, 0)))
    testsFailed++;
  return testsFailed;
}
int testScalarDiv() {
  int testFailed = 0;

  vec4 a(3, 3, 3, 3);
  if (!(a / 3 == vec4(1, 1, 1, 1)))
    testFailed++;

  // test zero division
  a / 0;
  return testFailed;
}

int testNormalize() {
  int testsFailed = 0;
  vec4 a(1, 2, 3, 4);
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

  std::cout << "vec4: All Tests Passed \n";
}

int main() {

  testAll();
  return 0;
}
