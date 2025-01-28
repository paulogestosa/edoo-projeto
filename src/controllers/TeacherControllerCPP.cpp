#include "TeacherControllerCPP.h"

void TeacherControllerCPP::listTeachers() {
    if (teachers.empty()) {
        std::cout << "Nenhum professor registrado.\n";
        return;
    }

    for (const auto& [id, teacherObj] : teachers) {
        std::cout << "ID: " << id << "\n";
        std::cout << "Nome: " << teacherObj.getName() << "\n";
        std::cout << "Email: " << teacherObj.getEmail() << "\n";
        std::cout << "Endereço: " << teacherObj.getAddress() << "\n";
        std::cout << "-------------------------\n";
    }
}

void TeacherControllerCPP::addTeacher(int teacherId, const std::string &name, const std::string &email)
{
    if (teachers.find(teacherId) != teachers.end()) {

        std::cout << "Teacher with ID " << teacherId << " already exists\n";
        return;
    }

    teachers[teacherId] = Teacher(name, teacherId, email);
    std::cout << "Teacher with ID " << teacherId << " created\n";

}

void TeacherControllerCPP::removeTeacher(int teacherId) {

    if (teachers.find(teacherId) != teachers.end()) {

        teachers.erase(teacherId);
        std::cout << "Teacher with ID " << teacherId << " deleted.\n";
        return;
    }

    std::cout << "Teacher with ID " << teacherId << " not found.\n";
}
bool TeacherControllerCPP::verifyTeacherId(int teacherId)
{
    if (teachers.find(teacherId) != teachers.end()) {
        
        return true;
    }

    return false;
}

Teacher* TeacherControllerCPP::returnTeacher(int teacherId) {
    if (verifyTeacherId(teacherId)) {
        return &teachers[teacherId];
    }

    return nullptr; // Indica que o professor não foi encontrado
}
