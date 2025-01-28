#ifndef STUDENT_CONTROLLERCPP_H
#define STUDENT_CONTROLLERCPP_H

#include <map>
#include <string>
#include "src/models/student.h"
#include "database.h"
class StudentControllerCPP
{
private:
    std::map<int, Student> students; // Precisa ser mapeado para o objeto da classe
    sqlite3 *db;                     // Conexão com o db

public:
    StudentControllerCPP(sqlite3 *database) : db(database) {}
    ~StudentControllerCPP() {}
    void addStudent(int studentId, const std::string &name, const std::string &email, const std::string &address);
    void listStudents();
    void deleteStudent(int studentId);
    bool verifyStudentId(int studentId);
};

#endif
