#include "Teacher.h"

Teacher::Teacher(int id, const std::string& name) : id(id), name(name) {}

int Teacher::getId() const { return id; }
const std::string& Teacher::getName() const { return name; }
const std::vector<int>& Teacher::getClasses() const { return classes; }

void Teacher::addClass(int classId) {
    classes.push_back(classId);
}
