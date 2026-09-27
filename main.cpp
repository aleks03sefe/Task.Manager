#include <iostream>
#include <vector>

#include "employee.h"

void menu(std::vector<employee *> &eVec) {
  int input;

  std::cout << "[1] add an Employee\n";
  std::cout << "[2] show Employees\n";
  std::cout << "[3] add a Task\n";
  std::cout << "[4] show Tasks\n";

  std::cin >> input;

  switch (input) {
  case 1:
    std::cin >> eVec;
    break;
  case 2:
    std::cout << eVec;
    break;
  case 3:
    addTask(eVec);
    break;
    case 4:
showTask(eVec);
    break;
  default:
    std::cout << "Invaid input\n";
    return;
  }

  menu(eVec);
}

int main() {
  std::vector<employee *> eVec;

  menu(eVec);

  return 0;
}