#ifndef CLASSVIEW_H
#define CLASSVIEW_H

#include "/home/beatrizanjos/edoo-projeto-1/src/controllers/ControllerClass.h"

class ClassView {

    private:

        ControllerClass& controller = ControllerClass::getInstance();

    public:

        void mainClassView();
        void addClass();
        void addTeacherToClass();
        void addStudentToClass();
        void removeStudentOfClass();
        void seeStudentsAbsences();
        void seeStudentsGrades();
        void seeClasses();

        void setStudentGradeView();
        void setStudentAbsence();
};

#endif