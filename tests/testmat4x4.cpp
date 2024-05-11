#include "../include/mat4x4.h"

void testMisc() {
  vec4 v1(1, 0, 0, 0);
  vec4 v2(0, 1, 0, 0);
  vec4 v3(0, 0, 1, 0);
  vec4 v4(0, 0, 0, 1);

  mat4x4 mat3(v1, v2, v3, v4);
  mat4x4 default_mat;
  default_mat.print_mat();
  mat4x4 another_mat{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  another_mat.transpose();
  mat3.print_mat();
  another_mat.print_mat();

  if (mat3[0] == v1) {
    std::cout << "tests passed 1\n";
  }
  if (mat3[0] == v1) {
    std::cout << "tests passed 3\n";
  }
  if (mat3[0] == v1) {
    std::cout << "tests passed 3\n";
  } else
    std::cout << "something is wrong\n";

  (another_mat + mat3).print_mat();

  (another_mat / 2).print_mat();
}

void testMat3Mult() {

  int testfailed = 0;
  mat4x4 a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  printf("matrix a:\n");
  a.print_mat();
  printf(" zero matrix :\n");
  mat4x4 zm(0);
  mat4x4 id{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  mat4x4 az = a * zm;
  if (!((az[0] == vec4(0, 0, 0, 0)) && az[1] == vec4(0, 0, 0, 0) &&
        az[2] == vec4(0, 0, 0, 0) && az[3] == vec4(0, 0, 0, 0))) {
    testfailed++;
    printf("test failed\n");
  }
  mat4x4 aid = a * id;
  printf(" a*id matrix :\n");
  aid.print_mat();

  (a * a).print_mat();
  if ((a * a).det() != a.det() * a.det()) {
    testfailed++;
    printf("test failed\n");
  }
  if (testfailed == 0)
    printf("all tests passed\n");
}
int main(void) {

  /* mat4x4 a{1, 5, 3, 5, 5, 6, 7, 8, 9, 0, 11, 2, 13, 14, 15, 16}; */
  /**/
  /* printf("inv a: \n"); */
  /* mat4x4 b(a); */
  /* b.inverse(); */
  /* printf("b: \n"); */
  /* b.print_mat(); */
  /* printf("a: \n"); */
  /* a.print_mat(); */
  /* printf("id: \n"); */
  /* mat4x4 f = a * b; */
  /* f.print_mat(); */
  /**/

  vec4 a{1, 2, 3, 4};

  mat4x4 m{{1, 2, 3, 7}, {3, 2, 1, 12}, {1, 2, 3, 9}, {8, 2, 1, 9}};
  vec4 f = a * m;

  printf("(%f, %f, %f, %f\n)", f.x, f.y, f.z, f.w);
  return 0;
}
