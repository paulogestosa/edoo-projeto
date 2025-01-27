#ifndef CONTROLLERCLASS_H
#define CONTROLLERCLASS_H

#include <iostream>
#include "src/models/Class.h"
#include "ControllerStudent.h"
#include "ControllerTeacher.h"
#include "sqlite3.h"
class ControllerClass
{

private:
    std::map<int, Class> classes; // Armazena as aulas pelo ID

public:
    void addClass(sqlite3 *db, const std::string &name);
    void addStudentToClass(sqlite3 *db, int classId, int studentId);
    void removeStudentOfClass(sqlite3 *db, int classId, int studentId);
    void assignTeacher(sqlite3 *db, int classId, int teacherId);
    void addTest(sqlite3 *db, int classId, const std::string &testName);
    void setStudentGrade(sqlite3 *db, int classId, int studentId, int grade);
    void updateStudentGrade(sqlite3 *db, int classId, int studentId, int newGrade);
    void removeStudentGrade(sqlite3 *db, int classId, int studentId);
    void atributeStudentAbssences(sqlite3 *db, int classId, int studentId, int numAbssences);
    void removeStudentAbssences(sqlite3 *db, int classId, int studentId, int numAbssencesToRemove);

    void getClassbyId(sqlite3 *db, int id); // boll e não void

    // Falta todos os getters
    // Show Classes notes
    // Show Classes absences
    // Show Classes students
};

#endif
