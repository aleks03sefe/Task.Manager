#include <iostream>
#include <sstream>
#include <vector>

#include "emplpyee.Func.h"

int main() {

  std::stringstream ss = testEmployees();

  std::vector<employee *> eVec;

 ss >> eVec;

 std::cout << eVec;

  return 0;
}