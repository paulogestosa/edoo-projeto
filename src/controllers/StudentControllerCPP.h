#ifndef STUDENT_CONTROLLERCPP_H
#define STUDENT_CONTROLLERCPP_H

#include <map>
#include <string>
#include "c:\Users\PICHAU\OneDrive\Documentos\edoo-projeto\src/models/student.h"

// Classe com padrão Singleton
class StudentControllerCPP 
{
    
    private:

        // Construtor privado para evitar criação direta de instâncias
        StudentControllerCPP() {};

        // Evita cópia ou atribuição
        StudentControllerCPP(const StudentControllerCPP&) = delete;
        StudentControllerCPP& operator=(const StudentControllerCPP&) = delete;

        // map<id,Student>
        std::map<int, Student> students;

    public:

        // Método estático para acessar uma única instância
        static StudentControllerCPP& getInstance() {
            static StudentControllerCPP instance; // Instância única criada
            return instance;
        }

        void addStudent(int studentId, const std::string &name, const std::string &email, const std::string &address);
        void listStudents();
        void deleteStudent(int studentId);
        bool verifyStudentId(int studentId);
        Student* returnStudent(int studentId);
};

#endif
