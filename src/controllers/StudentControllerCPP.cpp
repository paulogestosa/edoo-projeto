#include "StudentControllerCPP.h"
#include <iostream>

void StudentControllerCPP::listStudents()
{
    if (students.empty())
    {
        std::cout << "No Students Created Yet.\n";
        return;
    }

    for (const auto& [id, studentObj] : students) { 
    
        std::cout << "ID: " << id << ", Nome: " << studentObj.getName() << std::endl;
    }
}

void StudentControllerCPP::addStudent(int studentId, std::string &name, std::string &email, std::string &address) {

    if (students.find(studentId) != students.end()) {

        std::cout << "Student with ID " << studentId << " already exists\n";
        return;
    }

    students[studentId] = Student(id, name, email, address);
}

void StudentControllerCPP::deleteStudent(int studentId)
{
    if (students.find(studentId) != students.end()) {

        students.erase(studentId);
        std::cout << "Student with ID " << studentId << " deleted.\n";
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
