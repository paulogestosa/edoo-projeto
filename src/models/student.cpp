#include "Student.h"

// Construtor
Student::Student(const std::string &id, const std::string &name, const std::string &email, const std::string &addressName)
    : Person(name, id, email), addressName(addressName) {}

// // Getter para faltas
// int Student::getAbsences() const {
//     return absences;
// }

// Getter para o endereço
std::string Student::getAddressName() const {
    return addressName;
}

// // Incrementa faltas
// void Student::addAbsence() {
//     absences++;
// }

// Atualiza o endereço
void Student::setAddressName(const std::string &newAddress) {
    addressName = newAddress;
}
