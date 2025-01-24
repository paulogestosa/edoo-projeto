#ifndef STUDENT_CONTROLLER_H
#define STUDENT_CONTROLLER_H

#include <map>
#include <string>
#include "src/models/student.h"

class StudentControllerCPP
{
private:
    std::map<int, Student> students; // Precisa ser mapeado para o objeto da classe

public:
    // void addStudent(int studentId);
    void listStudents();
    void deleteStudent(int studentId);
    bool verifyStudentId(int studentId); //deve ser bool e não void
    void updateAdress( int studentId);
};

#endif
