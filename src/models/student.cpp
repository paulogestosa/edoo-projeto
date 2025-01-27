#include "Student.h"

// Construtor
Student::Student(int id, const std::string &name, const std::string &email, const std::string &addressName)
    : Person(name, id, email), addressName(addressName) {}


std::string Student::getAddressName() const {
    return addressName;
}


void Student::updateAddressName(const std::string &newAddress) {
    addressName = newAddress;
}
