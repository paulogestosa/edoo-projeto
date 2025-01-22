#include "Teacher.h"

Teacher::Teacher(const std::string &name, const std::string &id, const std::string &email)
    : Person(name, id, email) {}

const std::vector<int> &Teacher::getClasses() const
{
    return classes;
}

void Teacher::addClass(int classId)
{
    classes.push_back(classId);
}
