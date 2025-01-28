#ifndef TEACHER_CONTROLLER_H
#define TEACHER_CONTROLLER_H

#include <vector>
#include "src/models/Teacher.h"
#include "src/models/Class.h"

class TeacherControllerCPP
{
private:

    // Construtor privado para evitar criação direta de instâncias
    TeacherControllerCPP() {};

    // Evita cópia ou atribuição
    TeacherControllerCPP(const TeacherControllerCPP&) = delete;
    TeacherControllerCPP& operator=(const TeacherControllerCPP&) = delete;

    // map<id,Student>
    std::vector<int> classes;

public:

    // Método estático para acessar uma única instância
    static TeacherControllerCPP& getInstance() {
        static TeacherControllerCPP instance; // Instância única criada
        return instance;
    }
    void showClasses(const std::vector<int> classes) const; 
    void addTeacher(int teacherId, Teacher teacherToAdd);
    void removeTeacher(int teacherId);
    void changeTeacherInfo(int teacherId);
    bool verifyTeacherId(int teacherId); // bool e não void
};

#endif
