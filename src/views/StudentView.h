#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include "src/controllers/ControllerClass.h"

class StudentView {

    private:
        
        int currentId = 1; // Gerador incremental de IDs

        // Valida entradas numéricas
        int validateIntInput();

    public:

        void mainStudentView();
        void singleStudentView();
        void addStudent();
        void deleteStudent();
        void seeStudents();
};

#endif
