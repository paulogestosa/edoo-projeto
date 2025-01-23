#include "ControllerStudent.h"
#include <iostream>

void StudentControllerCPP::listStudents()
{
    if (students.empty())
    {
        std::cout << "No Students Created Yet.\n";
        return;
    }
}

void StudentControllerCPP::deleteStudent(int studentId)
{
    for (auto i = students.begin(); i != students.end(); ++i)
    {
        if (*i == studentId)
        {
            students.erase(i);
            std::cout << "Student with ID " << studentId << " removed successfully.\n";
            return;
        }
    }
    std::cout << "Student with ID " << studentId << " not found.\n";
}

void StudentControllerCPP::verifyStudentId(int studentId)
{
    for (int id : students)
    {
        if (id == studentId)
        {
            std::cout << "Student with ID " << studentId << " exists.\n";
            return;
        }
    }
    std::cout << "Student with ID " << studentId << " does not exist.\n";
}

void StudentControllerCPP::updateAdress( int studentId)
{
    for (int id : students)
    {
        if (id == studentId)
        {
            std::cout << "Address  should be updated to: " << adressName << "\n";
            return;
        }
    }
    std::cout << "Student with ID " << studentId << " not found.\n";
}
