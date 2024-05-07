#include "../include/vec3.h"
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

int main() {

  testAll();
  return 0;
}
