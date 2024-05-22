#include "../include/utils.h"
#include <uml/vec3.h>
// intersection of plane and a line
vec3 LineIntersectPlane(vec3 plane_n, vec3 plane_p, vec3 linestart,
                        vec3 linend) {
  // normalizing plane_n for some house keeping
  plane_n.normalize();
  float plane_d = plane_n * plane_p;
  float ad = plane_n * linestart;
  float bd = plane_n * linend;

  float t = (plane_d - ad) / (bd - ad);

  vec3 w = linend - linestart;
  return linestart + w * t;
}
// shortest distance between a plane and point

float PointPlaneDistance(vec3 plane_n, vec3 plane_p, vec3 p) {
  plane_n.normalize();
  return (p - plane_p) * plane_n;
}
