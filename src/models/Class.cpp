#include "Class.h"

// Construtor
Class::Class(int id, const std::string &name) : id(id), name(name) {}

// Getters
int Class::getId() const {
    return id;
}

std::string Class::getName() const {
    return name;
}

const std::vector<Student>& Class::getEnrolledStudents() const {
    return enrolledStudents;
}

const Teacher& Class::getEnrolledTeacher() const {
    return enrolledTeacher;
}

int Class::getGradeByStudent(int studentId) const {
    if (gradeByStudents.find(studentId) != gradeByStudents.end()) {
        return gradeByStudents.at(studentId);
    }
    return -1; 
}

int Class::getAbsencesByStudent(int studentId) const {
    if (absencesByStudents.find(studentId) != absencesByStudents.end()) {
        return absencesByStudents.at(studentId);
    }
    return 0; 
}

// Setters
void Class::setName(const std::string &newName) {
    name = newName;
}

void Class::enrollStudent(const Student &student) {
    enrolledStudents.push_back(student);
}

void Class::setEnrolledTeacher(const Teacher &teacher) {
    enrolledTeacher = teacher;
}

void Class::setGradeByStudent(int studentId, int grade) {
    gradeByStudents[studentId] = grade;
}

void Class::setAbsencesByStudent(int studentId, int absences) {
    absencesByStudents[studentId] = absences;
}
