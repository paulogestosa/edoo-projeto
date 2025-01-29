#ifndef MAINVIEW_H
#define MAINVIEW_H 

#include "StudentView.h"
#include "TeacherView.h"
#include "ClassView.h"

class MainView {

    private:

        StudentView studentView;
        ClassView classView;
        TeacherView teacherView;

    public:

        void mainScreen();
        void studentScreen();
        void classeScreen();
        void teacherScreen();
}

#endif