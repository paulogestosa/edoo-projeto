#ifndef STUDENT_CONTROLLER_H
#define STUDENT_CONTROLLER_H

#include <vector>
#include "src/models/Student.h"
#include <string>
// Toda a lógica que envolve o aluno
// Acredito que o Professor tenha mais, muito provavelmente o aluno só vai poder visualizar as coisas, então aqui vai ter basicamente vários métodos para o aluno visualizar as faltas notas etc sla
// Seria legal algo como contestar falta, seria bem engraçado
class StudentController
{
private:
    std::vector<int> students;

public:
    void addStudent(const Student &student);
    void addAbsence(int studentId, int classId); // APAGAR
    void listStudents() const;
    void setAdress(int studentId, const std::string &adressName) void updateAdress(std::string adressName, studentId); // APAGAR 
    void deleteStudent(const Student &student); // sair do terminal?
    // A ideia é usar os modelos das classes como objetos que vamos trabalhar sobre eles aqui

    // funções a implementar
    // verifyStudentId 
    // UpdateStudentInfo
    
};

#endif
