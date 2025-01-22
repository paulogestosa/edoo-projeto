#include "ControllerStudent.h"
#include "database.h"
#include "iostream"
#include "student.h"
void StudentControllerCPP::addStudent(const Student &student)
{
    students.push_back(student);
    cout << "Student" << student.getName() << "created!\n";
}

void StudentController::setAdress(int studentId, const std::string &adressName)
{
    for (auto &student : students)
    {
        if (student.getId() == studentId)
        {
            student.setAdress(adressName);
            std::cout << "Address created successfully for student " << student.getName() << ".\n";
            return;
        }
    }
}

void StudentControllerCPP::addAbsense(int studentId, int classId)
{
    for (auto &student : students)
    {
        if (student.getId() == studentId)
        {
            student.addAbsense();
            cout << "Student" << student.getName() << "has" << Student.getAbsences() << "absences!\n";
        }
    }
}

void StudentControllerCPP::listStudents()
{
    if (students.size() > 0)
    {
        for (const auto &student : students)
        {
            std::cout << "\nStudent Name: " << student.getName();
        }
    }
    else
    {
        std::cout << "No Students Created Yet.\n";
        return;
    }
}

void StudentControllerCPP::updateAdress(std::string adressName, studentId)
{
    for (const auto &student : students)
    {
        if (student.getId() == studentId)
        {
            student.setAdress(adressName);
            cout << "Adress updated successfully for student" << Student.getName() << "\n";
            return;
        }
    }
}

void StudentControllerCPP::deleteStudent(const Student &student)
{
    for (auto i = students.begin(); i != students.end(); ++i)
    {
        if (i->getId() == student.getId())
        {
            students.erase(i);
            std::cout << "Student" << student.getId() << " not in project anymore.\n";
            return;
        }
    }
}