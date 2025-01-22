#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "person.h"

class Student : public Person
{
private:
    std::string addressName;        
    std::vector<float> grades;     
    int absences;                  
    std::vector<int> classmates;  

public:
    // Construtor
    Student(int id, const std::string &name, const std::string &email, const std::string &addressName);

    // Getters (visualização apenas)
    std::string getAddressName() const;
    std::vector<float> getGrades() const;
    int getAbsences() const;
    std::vector<int> getClassmates() const;

    // Setter (apenas para endereço)
    void updateAddressName(const std::string &newAddress);
};

#endif
