#include "../include/mat3x3.h"

void testMisc() {
  vec3 v1(1, 0, 0);
  vec3 v2(0, 1, 0);
  vec3 v3(0, 0, 1);

  mat3x3 mat3(v1, v2, v3);
  mat3x3 default_mat;
  default_mat.print_mat();
  mat3x3 another_mat{1, 2, 3, 4, 5, 6, 7, 8, 9};
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
  mat3x3 a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  a.print_mat();
  mat3x3 zm(0);
  mat3x3 id{1, 0, 0, 0, 1, 0, 0, 0, 1};
  mat3x3 az = a * zm;
  if (!((az[0] == vec3(0, 0, 0)) && az[1] == vec3(0, 0, 0) &&
        az[2] == vec3(0, 0, 0))) {
    testfailed++;
    printf("test failed\n");
  }
  mat3x3 aid = a * id;

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

  mat3x3 a{2, 2, 4, 5, 6, 7, 8, 9, 10};

  mat3x3 f = a * Inverse(a);
  Inverse(a).print_mat();
  f.print_mat();

  return 0;
}
