#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>
#include <iostream>

// Funções do banco de dados de classes
int createClassTable(const char *s);
int insertClass(const char *s, const std::string &name);
int insertStudentToClass(const char *s, int studentId, int classId);
int deleteStudentFromClass(const char *s, int studentId, int classId);
int insertTeacherFromClass(const char *s, int teacherId, int classId, std::string name);
int insertGrades(const char *s, int classId, int studentId, int grade);
int deleteGradeStudent(const char *s, int studentId, int classId);
int insertAbsencesStudent(const char *s, int studentId, int classId, int numAbsences);
int callback(void *NotUsed, int argc, char **argv, char **azColName);
int deleteStudentAbsences(const char *s, int studentId, int classId, int numAbsencesToRemove);
int readClassAbsences(const char *s, int classId); 
int readClassGrades(const char *s, int classId);
int readStudentGrade(const char *s, int classId, int studentId);
int readStudentClasses(const char *s, int studentId);
int readTeacherClasses(const char *s, int teacherId);
int readAllClasses(const char *s);
int checkClassInDatabase(const char *s, int classId);
int checkStudentInDatabase(const char *s, int studentId);


//funções do banco de dados de estudantes
int createStudentsTable(const char *s);
int insertStudent(const char *s, int studentId, const std::string &name, const std::string email, const std::string address);
int deleteStudentDB(const char *s, int studentId);
int readStudentsDB(const char *s);

//funções do banco de dados de professor
int createTeacherTable(const char *s);
int insertTeacher(const char *s, int teacherId, const std::string &name, const std::string &email);
int removeTeacher(const char *s, int teacherId);
int readTeacher(const char *s, int teacherId);



#endif // DATABASE_H
