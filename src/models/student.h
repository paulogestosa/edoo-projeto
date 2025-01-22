#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "person.h"
class Student : public Person
{
private:
    std::string addressName;

public:
    Student(int id, const std::string &name, const std::string adressName);
   
    
    // setters
    std::string setAdress();
    void updateAdress();
};

#endif
