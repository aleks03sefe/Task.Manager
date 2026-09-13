#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <sstream>
#include <unordered_map>
<<<<<<< HEAD
#include <vector>
=======
>>>>>>> e3d53c57124c9d9b142eda00fef16491e6cdbca5

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
  void getTasks() const { this->tasks; }
};

std::istream &operator>>(std::istream &in, employee &e) {
  in >> e.firstName >> e.secondName;
  std::getline(in, e.title);
  return in;
}

std::istream &operator>>(std::istream &in, std::vector<employee *> &eVec) {
  employee *e = new employee();
  while (in >> *e) {
    eVec.push_back(e);
    e = new employee();
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