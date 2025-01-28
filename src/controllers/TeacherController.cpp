#include "TeacherController.h"
#include "database.h"
#include <iostream>

void TeacherController::showClasses(const std::vector<int> classes) const
{
    for (int id : classes)
    {
        const Class *foundClass = nullptr;

        for (const auto &c : classes)
        {
            if (c.getId() == id)
            {
                foundClass = &c;
                break;
            }
        }

        if (foundClass)
        {
            std::cout << " - ID: " << foundClass->getId()
                      << ", Nome: " << foundClass->getName() << std::endl;
        }
        else
        {
            std::cout << "Classe com ID " << id << " não encontrada." << std::endl;
        }
    }
}

void TeacherControllerCPP::addTeacher()
{
    std::string name, email;
    int id;

    std::cout << "ProfessorName: ";
    std::cin >> name;

    std::cout << "ProfessorId: ";
    std::cin >> id;

    std::cout << "ProfessorMail: ";
    std::cin >> email;

    Teacher newTeacher(name, id, email);
    teacher.push_back(newTeacher.getId());
    insertTeacher(const char *s, name, id, email);

    std::cout << "Teacher " << name << " added to the list!" << std::endl;
}
void TeacherControllerCPP::removeTeacher(int teacherId)
{
    bool found = false;

    for (size_t i = 0; i < teacher.size(); ++i)
    {
        if (teacher[i] == teacherId)
        {
            teacher.erase(teacher.begin() + i);
            removeTeacher(const char *s, teacherId)
                    std::cout
                << "Teacher  " << teacherId << " has been removed!" << std::endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "Teacher " << teacherId << " does not exist" << std::endl;
    }
}
void TeacherControllerCPP::changeTeacherInfo(int teacherId)
{
    bool found = false;

    for (size_t i = 0; i < teacher.size(); ++i)
    {
        if (teacher[i] == teacherId)
        {
            std::string name, email;

            std::cout << "Update teacherName: ";
            std::cin >> name;

            std::cout << "Update teacherEmail: ";
            std::cin >> email;

            Teacher updatedTeacher(name, teacherId, email);
            teacher[i] = updatedTeacher.getId();
            updateTeacherInfo(const char *s, teacherId); // db
            std::cout << "All information updated." << std::endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "Teacher with ID " << teacherId << " not found!" << std::endl;
    }
}
bool TeacherControllerCPP::verifyTeacherId(int teacherId)
{
    for (int id : teacher)
    {
        if (id == teacherId)
        {
            std::cout << "Teacher with ID " << teacherId << " exists.\n";
            getTeacher(const char *s, teacherId) return true;
        }
    }

    std::cout << "Teacher with ID " << teacherId << " does not exist.\n";
    return false;
}