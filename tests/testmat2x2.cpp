#include "../include/mat2x2.h"

void testMisc() {
  vec2 v1(1, 0);
  vec2 v2(0, 1);

  mat2x2 mat3(v1, v2);
  mat2x2 default_mat;
  default_mat.print_mat();
  mat2x2 another_mat{1, 2, 3, 4};
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

  if (another_mat.det() == Determinant(another_mat))
    std::cout << "tests passed 4\n";
  (another_mat + mat3).print_mat();

  (another_mat / 2).print_mat();
  another_mat.transpose();
  another_mat.print_mat();
  Transpose(another_mat).print_mat();
}

void testMat2Mult() {

  int testfailed = 0;
  mat2x2 a{1, 2, 3, 4};
  a.print_mat();
  mat2x2 zm(0);
  mat2x2 id{1, 0, 0, 1};
  mat2x2 az = a * zm;
  if (!((az[0] == vec2(0, 0)) && az[1] == vec2(0, 0))) {
    testfailed++;
    printf("test failed\n");
  }
  mat2x2 aid = a * id;

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

  vec2 a{1, 2};
  mat2x2 b{1, 3, 4, 5};

  vec2 c = a * b;

  printf("(%f, %f)\n", c.x, c.y);
  return 0;
}
