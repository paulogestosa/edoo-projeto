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
    // void chooseClass(int classId);
    void showClasses(const std::vector<int> classes) const; // como isso será feito?
    void addTeacher();
    void removeTeacher(int teacherId);
    void changeTeacherInfo(int teacherId);
    void verifyTeacherId(int teacherId); // bool e não void
};

#endif
