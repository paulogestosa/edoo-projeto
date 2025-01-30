#include "StudentControllerCPP.h"
#include <iostream>
//#include "database.h"

// const char *dbName = "student_database.db";

void StudentControllerCPP::listStudents() {
    if (students.empty()) {
        std::cout << "Nenhum estudante registrado.\n";
        return;
    }

    // Iterando com um iterador em vez de 'auto'
    for (std::map<int, Student>::iterator it = students.begin(); it != students.end(); ++it) {
        std::cout << "ID: " << it->first << "\n"; // 'it->first' é o ID
        std::cout << "Nome: " << it->second.getName() << "\n";
        std::cout << "Email: " << it->second.getEmail() << "\n";
        std::cout << "Endereço: " << it->second.getAddressName() << "\n";
        std::cout << "-------------------------\n";
    }
    // readStudentsDB(dbName);

}


void StudentControllerCPP::addStudent(int studentId, const std::string &name, const  std::string &email, const std::string &address) {

    if (students.find(studentId) != students.end()) {

        std::cout << "Student with ID " << studentId << " already exists\n";
        return;
    }

    students[studentId] = Student(studentId, name, email, address);
    std::cout << "Student with ID " << studentId << " created\n";
    // insertStudent(dbName, name, email, address);

}

void StudentControllerCPP::deleteStudent(int studentId)
{
    if (students.find(studentId) != students.end()) {

        students.erase(studentId);
        std::cout << "Student with ID " << studentId << " deleted.\n";
        // deleteStudentDB(dbName, studentId);

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
