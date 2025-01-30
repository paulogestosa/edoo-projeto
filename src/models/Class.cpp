#include "/home/beatrizanjos/edoo-projeto-1/src/models/Class.h"
#include <algorithm>

// Construtor
Class::Class(int id, const std::string &name) : id(id), name(name) {}

// Getters
int Class::getId() const
{
    return id;
}

std::string Class::getName() const
{
    return name;
}

const std::vector<int> &Class::getEnrolledStudents() const
{
    return enrolledStudents;
}

int Class::getEnrolledTeacher() const
{
    return enrolledTeacher;
}

int Class::getGradeByStudent(int studentId) const
{
    auto it = gradeByStudents.find(studentId);
    if (it != gradeByStudents.end())
    {
        return it->second; // Retorna a nota do aluno
    }
    return -1; // Ou outro valor que indique "não encontrado"
}

int Class::getAbsencesByStudent(int studentId) const
{
    if (absencesByStudents.find(studentId) != absencesByStudents.end())
    {
        return absencesByStudents.at(studentId);
    }
    return 0;
}

// Setters
void Class::setName(const std::string &newName)
{
    name = newName;
}

void Class::enrollStudent(int studentId)
{
    enrolledStudents.push_back(studentId);
}

void Class::removeStudent(int studentId)
{
    enrolledStudents.erase(
        std::remove(enrolledStudents.begin(), enrolledStudents.end(), studentId),
        enrolledStudents.end());
}

void Class::setEnrolledTeacher(int teacherId)
{
    enrolledTeacher = teacherId;
}

void Class::setGradeByStudent(int studentId, int grade)
{
    gradeByStudents[studentId] = grade;
}

void Class::setAbsencesByStudent(int studentId, int absences)
{
    absencesByStudents[studentId] = absences;
}
