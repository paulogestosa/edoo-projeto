#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "person.h"

class Student : public Person
{
private:

    std::string addressName;        
    std::vector<int> classesJoined;     

public:

    // Construtor
    Student() = default;
    Student(int id, const std::string &name, const std::string &email, const std::string &addressName);

    // Getters (visualização apenas)
    std::string getAddressName() const;
    std::vector<int> getClassesJoined() const;

    // Setter (apenas para endereço)
    void updateAddressName(const std::string &newAddress);
    void updateClassesJoined(int classeId);
};

#endif
