#ifndef STUDENT_CONTROLLER_H
#define STUDENT_CONTROLLER_H

#include <vector>
#include <string>

class StudentControllerCPP
{
private:
    std::vector<int> students; 

public:
    // void addStudent(int studentId);
    void listStudents();
    void deleteStudent(int studentId);
    void verifyStudentId(int studentId);
    void updateAdress(const std::string &adressName, int studentId);
};

#endif
