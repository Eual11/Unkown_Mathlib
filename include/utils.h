#ifndef _UML_UTILS
#define _UML_UTILS
#include <uml/vec3.h>
vec3 LineIntersectPlane(vec3 plane_n, vec3 plane_p, vec3 linestart,
                        vec3 linend);
float PointPlaneDistance(vec3 plane_n, vec3 plane_p, vec3 p);

#endif
