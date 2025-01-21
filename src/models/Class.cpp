#include "Class.h"

Class::Class(int id, const std::string& name) : id(id), name(name) {}

int Class::getId() const { return id; }
const std::string& Class::getName() const { return name; }
const std::vector<int>& Class::getEnrolledStudents() const { return enrolledStudents; }

void Class::enrollStudent(int studentId) {
    enrolledStudents.push_back(studentId);
}
