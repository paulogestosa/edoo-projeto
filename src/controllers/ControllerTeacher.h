#ifndef TEACHER_CONTROLLER_H
#define TEACHER_CONTROLLER_H

#include <vector>
#include "src/models/Teacher.h"
#include "src/models/Class.h"

class TeacherController {
private:
    std::vector<int> classes;
public:
    void addExam(const Classes& class);
    void chooseClass(int classId);
    void listClasses() const;
    void addClass(int classId);
    void addGrade ( int classId, int studentId);
    // questão das faltas a ser vista
};

#endif
