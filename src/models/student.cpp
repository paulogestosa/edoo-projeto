#include "Student.h"

Student::Student(int id, const std::string &name, const std::string &adressName) : id(id), name(name), absences(0) adressName(adressName) {}

int Student::getId() const
{
    return id;
}

std::string Student::getName() const
{
    return name;
}

int Student::getAbsences() const
{
    return absences;
}

void Student::addAbsence()
{
    absences++;
}

// void Student::addAdress()
// {
//     return adressName;
// }
std::string Student::getAdress() const
{
    return adressName;
}

void Student::setAdress(const std::string &newAdress)
{
    adressName = newAdress;
}