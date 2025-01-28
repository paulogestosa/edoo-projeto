#ifndef TEACHER_CONTROLLER_H
#define TEACHER_CONTROLLER_H

#include <map>
#include <string>
#include <iostream>
#include "src/models/Teacher.h"

// Classe com padrão Singleton
class TeacherControllerCPP
{

    private:

        // Construtor privado para evitar criação direta de instâncias
        TeacherControllerCPP() {};

        // Evita cópia ou atribuição
        TeacherControllerCPP(const TeacherControllerCPP&) = delete;
        TeacherControllerCPP& operator=(const TeacherControllerCPP&) = delete;

        // map<id,Student>
        std::map<int, Teacher> teachers;

    public:

        // Método estático para acessar uma única instância
        static TeacherControllerCPP& getInstance() {
            static TeacherControllerCPP instance; // Instância única criada
            return instance;
        }
        
        void addTeacher(int teacherId, const std::string &name, const std::string &email);
        void listTeachers();
        void removeTeacher(int teacherId);
        bool verifyTeacherId(int teacherId);
        Teacher* returnTeacher(int teacherId);
};

#endif
