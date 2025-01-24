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

const std::vector<int>& Class::getEnrolledStudents() const {
    return enrolledStudents;
}

int Class::getEnrolledTeacher() const {
    return enrolledTeacher;
}

int Class::getGradeByStudent(int studentId) const {
    if (gradeByStudents.find(studentId) != gradeByStudents.end()) {
        return gradeByStudents[studentId];
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

void Class::enrollStudent(int studentId) {
    enrolledStudents.push_back(studentId);
}

void Class::setEnrolledTeacher(int teacherId) {
    enrolledTeacher = teacherId;
}

void Class::setGradeByStudent(int studentId, int grade) {
    gradeByStudents[studentId] = grade;
}

void Class::setAbsencesByStudent(int studentId, int absences) {
    absencesByStudents[studentId] = absences;
}
