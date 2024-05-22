#include "../include/utils.h"
#include <uml/vec3.h>

void testIntresection() {
  vec3 plane_n = {1, 0, 0};
  vec3 plane_p = {0, 0, 0};

  vec3 a = {0, 0, 0};
  vec3 b = {1, 1, 1};

  vec3 intresection = LineIntersectPlane(plane_n, plane_p, a, b);

  if (!(intresection == vec3{0, 0, 0})) {
    printf("Test Failed \n");
    printf("(%f, %f, %f\n)", intresection.x, intresection.y, intresection.z);
  } else {
    printf("test 1 passed\n");
  }

  /* Plane: Normal vector (1, 0, 0), Point on plane (0, 0, 0) */
  /* Line: Start point (0, 0, 0), End point (1, 1, 1) */
  /* Expected Result: Intersection point (0, 0, 0) */
  /* Plane: Normal vector (0, 1, 0), Point on plane (0, 0, 0) */
  /* Line: Start point (1, 2, 3), End point (3, 4, 5) */
  /* Expected Result: Intersection point (2, 2, 2) */
  /* Plane: Normal vector (0, 0, 1), Point on plane (0, 0, 0) */
  /* Line: Start point (-1, -1, -1), End point (1, 1, 1) */
  /* Expected Result: Intersection point (0, 0, 0) */
  /**/
  plane_n = {0, 1, 0};
  plane_p = {0, 0, 0};
  a = {1, 2, 3};
  b = {3, 4, 5};

  intresection = LineIntersectPlane(plane_n, plane_p, a, b);

  if (!(intresection == vec3{-1, 0, 1})) {
    printf("Test Failed \n");
    printf("(%f, %f, %f)\n", intresection.x, intresection.y, intresection.z);
  } else {
    printf("test 2 passed\n");
  }
  plane_n = {0, 0, 1};
  plane_p = {0, 0, 0};
  a = {-1, -1, -1};
  b = {1, 1, 1};

  intresection = LineIntersectPlane(plane_n, plane_p, a, b);

  if (!(intresection == vec3{0, 0, 0})) {
    printf("Test Failed \n");
    printf("(%f, %f, %f)\n", intresection.x, intresection.y, intresection.z);
  } else {
    printf("test 3 passed\n");
  }
}

#include <assert.h>
#include <uml/vec3.h>

void test_LineIntersectPlane() {
  // Test case 1: Line intersects the plane
  vec3 plane_n = vec3(0, 1, 0);
  vec3 plane_p = vec3(0, 0, 0);
  vec3 linestart = vec3(1, 2, 3);
  vec3 linend = vec3(3, 4, 5);
  vec3 intersection = LineIntersectPlane(plane_n, plane_p, linestart, linend);
  assert(intersection == vec3(-1, 0, 1));

  // Test case 2: Line is parallel to the plane
  plane_n = vec3(0, 1, 0);
  plane_p = vec3(0, 1, 0);
  linestart = vec3(1, 1, 1);
  linend = vec3(3, 1, 3);
  intersection = LineIntersectPlane(plane_n, plane_p, linestart, linend);

  printf("(%f, %f, %f\n)", intersection.x, intersection.y, intersection.z);

  // Test case 3: Line is perpendicular to the plane
  plane_n = vec3(1, 0, 0);
  plane_p = vec3(0, 0, 0);
  linestart = vec3(0, 2, 3);
  linend = vec3(0, -2, 3);
  intersection = LineIntersectPlane(plane_n, plane_p, linestart, linend);
  printf("(%f, %f, %f\n)", intersection.x, intersection.y, intersection.z);
}

void test_PointPlaneDistance() {
  // Test case 1: Point is on the plane
  vec3 plane_n = vec3(0, 1, 0);
  vec3 plane_p = vec3(0, 0, 0);
  vec3 p = vec3(1, 0, 2);
  float distance = PointPlaneDistance(plane_n, plane_p, p);
  assert(distance == 0);

  // Test case 2: Point is above the plane
  plane_n = vec3(0, 1, 0);
  plane_p = vec3(0, 0, 0);
  p = vec3(1, 1, 2);
  distance = PointPlaneDistance(plane_n, plane_p, p);
  assert(distance == 1);

  // Test case 3: Point is below the plane
  plane_n = vec3(0, 1, 0);
  plane_p = vec3(0, 0, 0);
  p = vec3(1, -1, 2);
  distance = PointPlaneDistance(plane_n, plane_p, p);
  assert(distance == -1);
}

int main(int argc, char **agrv) {
  /* testIntresection(); */
  /* test_LineIntersectPlane(); */
  /* test_PointPlaneDistance(); */
  /* Invertex: (-0.321787, -0.119180, 1.001124) */
  /* outvertex: (-0.500557, 0.119180, 1.001124) */
  /* Plane_n: (1.000000, 0.000000, 0.000000) */
  /* Plane_p: (-0.500000, 0.000000, 0.000000) */
  vec3 inpnt = {-0.321787, -0.119180, 1.001124};
  vec3 opnt = {-0.500557, 0.119180, 1.001124};
  vec3 pnt = LineIntersectPlane({1.0, 0.0, 0.0}, {-0.5, 0.0, 0.0}, inpnt, opnt);
  vec3 c = opnt - inpnt;
  printf("Change: (%f, %f, %f)\n", pnt.x, pnt.y, pnt.z);
  printf("intresection: (%f, %f, %f)\n", pnt.x, pnt.y, pnt.z);
  return 0;
}
