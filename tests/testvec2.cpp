#include "../include/vec2.h"
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

    float v2x = rand();
    float v2y = rand();

    vec2 a(v1x, v1y);
    vec2 b(v2x, v2y);

    vec2 c = a + b;
    vec2 d = vec2(v1x + v2x, v1y + v2y);
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

    float v2x = rand();
    float v2y = rand();

    vec2 a(v1x, v1y);
    vec2 b(v2x, v2y);

    vec2 c = a - b;
    vec2 d = vec2(v1x - v2x, v1y - v2y);
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
  int testFailed = 0;

  vec2 v = vec2(vx, vy);

  if (v[0] != vx)
    testFailed++;
  if (v[1] != vy)
    testFailed++;
  return testFailed;
}

int testCompundSubtraction() {
  int testsFailed = 0;

  float vx = rand();
  float vy = rand();

  vec2 a = vec2(vx, vy);
  a -= a;
  if (!(a == vec2(0, 0)))
    testsFailed++;
  return testsFailed;
}

int testCompundAddition() {
  int testsFailed = 0;

  float vx = rand();
  float vy = rand();

  vec2 a = vec2(vx, vy);
  a += a;
  if (!(a == vec2(vx + vx, vy + vy)))
    testsFailed++;
  return testsFailed;
}

int testScalarMult() {
  int testsFailed = 0;

  vec2 a(1, 2);

  if (!(a * 0 == vec2(0, 0)))
    testsFailed++;
  return testsFailed;
}
int testScalarDiv() {
  int testFailed = 0;

  vec2 a(3, 3);
  if (!(a / 3 == vec2(1, 1)))
    testFailed++;

  // test zero division
  a / 0;
  return testFailed;
}

int testNormalize() {
  int testsFailed = 0;
  vec2 a(1, 2);
  a.normalize();
  float diff = a.magnitude();
  if (fabs(diff - 1) > 0.01)
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

  std::cout << "vec2: All Tests Passed \n";
}

int main() {

  vec2({1, 2, 3});
  return 0;
}
