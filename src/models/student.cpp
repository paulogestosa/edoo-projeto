#include "Student.h"

// Construtor
Student::Student(int id, const std::string &name, const std::string &email, const std::string &addressName)
    : Person(name, id, email), addressName(addressName) {}


const std::string Student::getAddressName() const {
    return addressName;
}

const std::vector<int> Student::getClassesJoined() const {
    return classesJoined;
}

void Student::updateAddressName(const std::string &newAddress) {
    addressName = newAddress;
}

void Student::updateClassesJoined(int classId) {
    classesJoined.push_back(classId);
}
