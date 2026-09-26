#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <limits>
#include <sstream>
#include <unordered_map>
#include <vector>

class employee {
private:
  std::string firstName;
  std::string secondName;
  std::string title;
  std::unordered_map<std::string, int> tasks;

public:
  employee(std::string firstName, std::string secondName, std::string title)
      : firstName(firstName), secondName(secondName), title(title) {}

  employee() = default;

  void addTask(std::string nameOfTask, int priority) {
    tasks[nameOfTask] = priority;
  }

  void changePriority() {
    // list all the current tasks and select one and change the priority of it
  }

  friend std::istream &operator>>(std::istream &in, employee &e);

  std::string getFirstName() const { return firstName; }
  std::string getSecondName() const { return secondName; }
  std::string getTitle() const { return title; }
  void getTasks() const {
    this->tasks;
  } // dosent work for now as i dont need it
};

std::istream &operator>>(std::istream &in, employee &e) {
  std::cout << "Whats the first name of the employee?" << std::endl;
  in >> e.firstName;
  e.firstName[0] = toupper(e.firstName[0]);
  std::cout << "Whats the secnd name of the employee?" << std::endl;
  in >> e.secondName;
  e.secondName[0] = toupper(e.secondName[0]);

  std::cout << "Whats the title of this employee?" << std::endl;

  // we need to ignore the remaining whitespaces between the last cin and the \n
  in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::getline(in, e.title);
  return in;
}

std::istream &operator>>(std::istream &in, std::vector<employee *> &eVec) {
  // i use e to take from the stream each value one at a time and store them in
  // a vector
  employee *e = new employee();
  while (in >> *e) {
    eVec.push_back(e);
    e = new employee();
    break;
  }
  delete e;
  return in;
}

std::ostream &operator<<(std::ostream &out, const employee &e) {
  out << e.getFirstName() << " " << e.getSecondName() << " " << e.getTitle();
  return out;
}

std::ostream &operator<<(std::ostream &out, std::vector<employee *> &eVec) {
  for (const employee *e : eVec)
    out << *e << "\n";
  return out;
}

std::stringstream testEmployees() {
  std::stringstream ss;
  ss << "Marcus" << " Delaney " << "ceo\n";
  ss << "Priya" << " Chandrasekaran " << "marketing team lead\n";
  ss << "Owen" << " Fitzgerald " << "intern\n";
  ss << "Naomi" << " Vasquez " << "customer support\n";
  ss << "Tobias" << " Renner " << "assistent\n";
  return ss;
}

#endif