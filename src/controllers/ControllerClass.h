#ifndef CONTROLLERCLASS_H
#define CONTROLLERCLASS_H

#include <iostream>
#include "src/models/Class.h"
#include "src/controllers/StudentControllerCPP.h"
#include "src/controllers/TeacherControllerCPP.h"

class ControllerClass {

    private:

        std::map<int, Class> classes;  // Armazena as aulas pelo ID

        // úteis para checkagem de existência de objetos com Id's específicos
        bool checkClass(int classId);
        bool checkStudent(int studentId);
        bool checkTeacher(int teacherId);

    public:

        //instâncias das classes de controles para manejar dados
        StudentControllerCPP studentController;
        TeacherControllerCPP teacherController;

        // Lógica do sistema
        void addClass(const std::string &name);
        void addStudentToClass(int classId, int studentId);
        void removeStudentOfClass(int classId, int studentId);
        void assignTeacher(int classId, int teacherId);
        void addTest(int classId, const std::string &testName);
        void setStudentGrade(int classId, int studentId, int grade);
        void updateStudentGrade(int classId, int studentId, int newGrade);
        void removeStudentGrade(int classId, int studentId);
        void atributeStudentAbssences(int classId, int studentId, int numAbssences);
        void removeStudentAbssences(int classId, int studentId, int numAbssencesToRemove);
        
        // Getters para UI
        void showClassAbsences(int classId);
        void showStudentAbsences(int classId, int studentId);
        void showClassGrades(int classId);
        void showStudentGrade(int classId, int studentId);
        const std::vector<int> showStudentClasses(int studentId);

};

#endif
