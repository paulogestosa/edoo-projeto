#include "Student.h"

// Construtor
Student::Student(int id, const std::string &name, const std::string &email, const std::string &addressName)
    : Person(name, id, email), addressName(addressName) {}


std::string Student::getAddressName() const {
    return addressName;
}

std::vector<int> Student::getClassesJoined() const {
    return classesJoined;
}

void Student::updateAddressName(const std::string &newAddress) {
    addressName = newAddress;
}

void Student::updateClassesJoined(int classId) {
    classesJoined.push_back(classId);
}

void Student::removeClassJoined(int classId) {
    auto it = std::remove(classesJoined.begin(), classesJoined.end(), classId);
    
    if (it != classesJoined.end()) {
        classesJoined.erase(it, classesJoined.end());
        std::cout << "Classe " << classId << " removida do estudante com sucesso!\n";
    } else {
        std::cout << "Classe " << classId << " não encontrada para o estudante.\n";
    }
}
