#ifndef CONTROLLERCLASS_H
#define CONTROLLERCLASS_H

#include <iostream>
#include "src/models/Class.h"
#include "ControllerStudent.h"

class ControllerClass {

    private:

        std::map<int, Class> classes;  // Armazena as aulas pelo ID

    public:

        void addClass(const std::string &name);
        void addStudentToClass(int classId, int studentId);
        // removeStudentOfClass
        void assignTeacher(int classId, int teacherId);
        void addTest(int classId, std::string &testName);
        void setStudentGrade(int classId, int studentId, int grade);
        void updateStudentGrade(int classId, int studentId, int newGrade);
        void removeStudentGrade(int classId, int studentId);
        void atributeStudentAbssences(int classId, int studentId, int numAbssences);
        void removeStudentAbssences(int classId, int studentId, int numAbssencesToRemove);

        void getClassbyId(int id);
        
        // Falta todos os getters
        // Show Classes notes 
        // Show Classes absences
        // Show Classes students

};

#endif
