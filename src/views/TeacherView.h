#ifndef TEACHERVIEW_H
#define TEACHERVIEW_H

#include <iostream>
#include <string>
#include <vector>
#include <map> // para usar como estrutura temporária de "banco de dados"
#include "/home/beatrizanjos/edoo-projeto-1/src/controllers/ControllerClass.h"

class TeacherView {

    private:

        ControllerClass& controller = ControllerClass::getInstance();
        
        int currentId = 1;

    public:

        void mainTeacherView();
        void singleTeacherView();
        void addTeacher();
        void deleteTeacher();
        void seeTeachers();
};


#endif