#include "../include/mat3x3.h"

int main(void) {
  std::cout << "Hello World\n";

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

  return 0;
}
