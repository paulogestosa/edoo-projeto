#ifndef CONTROLLERCLASS_H
#define CONTROLLERCLASS_H

#include <iostream>
#include "src/models/Class.h"
#include "ControllerStudent.h"
#include "ControllerTeacher.h"
#include "database.h"
class ControllerClass
{

private:
    sqlite3 *db;                  // conexão com o banco
    std::map<int, Class> classes; // Armazena as aulas pelo ID

public:
    ControllerClass(sqlite3 *database) : db(database) {}
    ~ControllerClass() {}
    void addClass(const std::string &name);
    void addStudentToClass(int classId, int studentId);
    void removeStudentOfClass(int classId, int studentId);
    void assignTeacher(int classId, int teacherId);
    void addTest(int classId, const std::string &testName);
    void setStudentGrade(int classId, int studentId, int grade);
    void updateStudentGrade(int classId, int studentId, int newGrade);
    void removeStudentGrade(int classId, int studentId);
    void atributeStudentAbssences(int classId, int studentId, int numAbssences);
    void removeStudentAbssences(int classId, int studentId, int numAbssencesToRemove);

    void getClassbyId(int id); // boll e não void

    // Falta todos os getters
    // Show Classes notes
    // Show Classes absences
    // Show Classes students
};

#endif
