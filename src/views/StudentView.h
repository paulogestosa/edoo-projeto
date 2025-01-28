#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include <iostream>
#include <string>
#include <vector>
#include <map> // para usar como estrutura temporária de "banco de dados"
#include "src/controllers/ControllerClass.h"
#include "src/controllers/StudentControllerCPP.h"

class StudentView {

    private:
        
        ControllerClass controller;
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
