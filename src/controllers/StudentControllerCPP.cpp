#include "StudentControllerCPP.h"
#include <iostream>

void StudentControllerCPP::listStudents() {
    if (students.empty()) {
        std::cout << "Nenhum estudante registrado.\n";
        return;
    }

    for (const auto& [id, studentObj] : students) {
        std::cout << "ID: " << id << "\n";
        std::cout << "Nome: " << studentObj.getName() << "\n";
        std::cout << "Email: " << studentObj.getEmail() << "\n";
        std::cout << "Endereço: " << studentObj.getAddress() << "\n";
        std::cout << "-------------------------\n";
    }
}


void StudentControllerCPP::addStudent(int studentId, const std::string &name, const  std::string &email, const std::string &address) {

    if (students.find(studentId) != students.end()) {

        std::cout << "Student with ID " << studentId << " already exists\n";
        return;
    }

    students[studentId] = Student(studentId, name, email, address);
    std::cout << "Student with ID " << studentId << " created\n";
}

void StudentControllerCPP::deleteStudent(int studentId)
{
    if (students.find(studentId) != students.end()) {

        students.erase(studentId);
        std::cout << "Student with ID " << studentId << " deleted.\n";
        return;
    }

    std::cout << "Student with ID " << studentId << " not found.\n";

}

bool StudentControllerCPP::verifyStudentId(int studentId)
{
    if (students.find(studentId) != students.end()) {

        return true;
    }

    return false;
}

Student* StudentControllerCPP::returnStudent(int studentId) {
    if (verifyStudentId(studentId)) {
        return &students[studentId];
    }

    return nullptr; // Indica que o estudante não foi encontrado
}
