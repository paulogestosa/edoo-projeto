#ifndef CLASSVIEW_H
#define CLASSVIEW_H

#include "c:\Users\PICHAU\OneDrive\Documentos\edoo-projeto\src/controllers/ControllerClass.h"

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