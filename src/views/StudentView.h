#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include "src/controllers/ControllerClass.h"

class StudentView {

    private:
        
        ControllerClass& controller = ControllerClass::getInstance();
        
        int currentId = 1; // Gerador incremental de IDs

    public:

        void mainStudentView();
        void singleStudentView();
        void addStudent();
        void deleteStudent();
        void seeStudents();
};

#endif
