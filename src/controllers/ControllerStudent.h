#ifndef STUDENT_CONTROLLER_H
#define STUDENT_CONTROLLER_H

#include <vector>
#include "src/models/Student.h"

// Toda a lógica que envolve o aluno
// Acredito que o Professor tenha mais, muito provavelmente o aluno só vai poder visualizar as coisas, então aqui vai ter basicamente vários métodos para o aluno visualizar as faltas notas etc sla
// Seria legal algo como contestar falta, seria bem engraçado
class StudentController {
private:
    std::vector<Student> students;

public:
    void addStudent(const Student& student);
    void addAbsence(int studentId, int classId);
    void listStudents() const;
    // A ideia é usar os modelos das classes como objetos que vamos trabalhar sobre eles aqui
};

#endif
