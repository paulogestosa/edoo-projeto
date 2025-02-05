#ifndef CONTROLLERCLASS_H
#define CONTROLLERCLASS_H

#include <iostream>
#include "c:\Users\PICHAU\OneDrive\Documentos\edoo-projeto\src/models/Class.h"
#include "c:\Users\PICHAU\OneDrive\Documentos\edoo-projeto\src/controllers/StudentControllerCPP.h"
#include "c:\Users\PICHAU\OneDrive\Documentos\edoo-projeto\src/controllers/TeacherControllerCPP.h"

// Classe com padrão Singleton
class ControllerClass {

    private:

        // Construtor privado para evitar criação direta de instâncias
        ControllerClass() {};

        // Evita cópia ou atribuição
        ControllerClass(const ControllerClass&) = delete;
        ControllerClass& operator=(const ControllerClass&) = delete;

        // map<id,Classe>
        std::map<int, Class> classes;

        // úteis para checkagem de existência de objetos com Id's específicos
        bool checkClass(int classId);
        bool checkStudent(int studentId);
        bool checkTeacher(int teacherId);

    public:

        // Método estático para acessar uma única instância
        static ControllerClass& getInstance() {
            static ControllerClass instance; // Instância única criada
            return instance;
        }

        //instâncias das classes de controles para manejar dados
        StudentControllerCPP& studentController = StudentControllerCPP::getInstance();
        TeacherControllerCPP& teacherController = TeacherControllerCPP::getInstance();


        // Lógica do sistema
        void addClass(const std::string &name);
        void addStudentToClass(int classId, int studentId);
        void removeStudentOfClass(int classId, int studentId);
        void assignTeacher(int classId, int teacherId);
        void setStudentGrade(int classId, int studentId, int grade);
        void removeStudentGrade(int classId, int studentId);
        void atributeStudentAbssences(int classId, int studentId, int numAbssences);
        void removeStudentAbssences(int classId, int studentId, int numAbssencesToRemove);
        
        // Getters para UI
        void showClassAbsences(int classId);
        void showStudentAbsences(int classId, int studentId);
        void showClassGrades(int classId);
        void showStudentGrade(int classId, int studentId);
        const std::vector<int> showStudentClasses(int studentId);
        const std::vector<int> showTeacherClasses(int teacherId);
        void showAllClasses();
};

#endif
