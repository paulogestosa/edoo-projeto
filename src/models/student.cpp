#include "Student.h"

Student::Student(int id, const std::string& name) : id(id), name(name), absences(0) {}

int Student::getId() const {
    return id;
}

std::string Student::getName() const {
    return name;
}

int Student::getAbsences() const {
    return absences;
}

void Student::addAbsence() {
    absences++;
}

