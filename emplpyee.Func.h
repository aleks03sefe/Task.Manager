#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "sstream"
#include "unordered_map"

class employee {
private:
  std::string firstName;
  std::string secondName;
  std::string title;
  std::unordered_map<std::string, int> tasks;

public:
  employee(std::string firstName, std::string secondName, std::string title)
      : firstName(firstName), secondName(secondName), title(title) {}

  std::stringstream testEmployees() {
    std::stringstream ss;
    ss << "Marcus" << " Delaney" << " ceo\n";
    ss << "Priya" << " Chandrasekaran" << " marketing team lead\n";
    ss << "Owen" << " Fitzgerald" << " intern\n";
    ss << "Naomi" << " Vasquez" << " customer support\n";
    ss << "Tobias" << " Renner" << " assistent\n";
    return ss;
  }

  void addTask(std::string nameOfTask, int priority) {
    tasks[nameOfTask] = priority;
  }

  void changePriority() {
    // list all the current tasks and select one and change the priority of it
  }

  void getFirstName() const { this->firstName; }
  void getSecondName() const { this->secondName; }
  void getTitle() const { this->title; }
  void getTasks() const { this->tasks; }
};

#endif