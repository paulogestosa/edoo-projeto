#ifndef MAINVIEW_H
#define MAINVIEW_H 

#include "/home/beatrizanjos/edoo-projeto-1/src/views/StudentView.h"
#include "/home/beatrizanjos/edoo-projeto-1/src/views/TeacherView.h"
#include "/home/beatrizanjos/edoo-projeto-1/src/views/ClassView.h"

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
};

#endif