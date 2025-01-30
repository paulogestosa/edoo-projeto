#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <vector>
#include "Person.h"

class Teacher : public Person
{
private:
    std::vector<int> classes;

public:

    Teacher() = default;
    Teacher(const std::string &name, int id, const std::string &email);

    const std::vector<int> getClasses() const;

    void addClass(int classId);
};

#endif
