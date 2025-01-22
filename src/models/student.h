#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "person.h"
class Student : public Person
{
private:
    std::string addressName;

public:
    Student(int id, const std::string &name, const std::string &email, const std::string &addressName);
   
    //getters
    std::string getAddressName() const;

    // setters
    void setAddressName(const std::string &address);
    void updateAdressName(const std::string &newAddres);
};

#endif
