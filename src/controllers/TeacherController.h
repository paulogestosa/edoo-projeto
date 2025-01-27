#ifndef TEACHER_CONTROLLER_H
#define TEACHER_CONTROLLER_H

#include <vector>
#include "src/models/Teacher.h"
#include "src/models/Class.h"

class TeacherController
{
private:
    std::vector<int> classes;

public:
    void showClasses(const std::vector<int> classes) const; 
    void addTeacher(int teacherId, Teacher teacherToAdd);
    void removeTeacher(int teacherId);
    void changeTeacherInfo(int teacherId);
    bool verifyTeacherId(int teacherId); // bool e não void
};

#endif
