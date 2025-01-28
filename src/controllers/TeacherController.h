#ifndef TEACHER_CONTROLLER_H
#define TEACHER_CONTROLLER_H

#include <vector>
#include "src/models/Teacher.h"
#include "src/models/Class.h"
#include "database.h"
class TeacherController
{
private:
    std::vector<int> classes;
    sqlite3 *db; // Conexão com db

public:
    TeacherController(sqlite3 *database) : db(database) {}
    ~TeacherController() {}
    void showClasses(const std::vector<int> classes) const;
    void addTeacher(int teacherId, Teacher teacherToAdd);
    void removeTeacher(int teacherId);
    void changeTeacherInfo(int teacherId);
    bool verifyTeacherId(int teacherId); // bool e não void

    int insertTeacher(const char *s);
    int removeTeacher(const char *s, teacherId);
    int updateTeacherInfo(const char *s, teacherId);
    int getTeacher(const char *s, teacherId);
};

#endif
