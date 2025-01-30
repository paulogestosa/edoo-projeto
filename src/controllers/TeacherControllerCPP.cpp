#include "/home/beatrizanjos/edoo-projeto-1/src/controllers/TeacherControllerCPP.h"
#include "/home/beatrizanjos/edoo-projeto-1/src/database/database.h"
// const char *dbName = "teacher_database.db";
void TeacherControllerCPP::listTeachers() {
    if (teachers.empty()) {
        std::cout << "Nenhum professor registrado.\n";
        return;
    }

    // Iterando com um iterador em vez de 'auto' e 'structured binding'
    for (std::map<int, Teacher>::iterator it = teachers.begin(); it != teachers.end(); ++it) {
        std::cout << "ID: " << it->first << "\n"; // 'it->first' é o ID
        std::cout << "Nome: " << it->second.getName() << "\n";
        std::cout << "Email: " << it->second.getEmail() << "\n";
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
    // insertTeacher(dbName,teacherId,name,email);

}

void TeacherControllerCPP::removeTeacher(int teacherId) {

    if (teachers.find(teacherId) != teachers.end()) {

        teachers.erase(teacherId);
        std::cout << "Teacher with ID " << teacherId << " deleted.\n";
        // removeTeacher(dbName, int teacherId);
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
        readTeacher(dbName, teacherId);
        return &teachers[teacherId];
    }

    return nullptr; // Indica que o professor não foi encontrado
}
