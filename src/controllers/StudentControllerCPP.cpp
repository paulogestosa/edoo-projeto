#include "StudentControllerCPP.h"
#include <iostream>

void StudentControllerCPP::listStudents()
{
    if (students.empty())
    {
        std::cout << "No Students Created Yet.\n";
        return;
    }

    for (const auto& [id, studentObj] : students) { 
        std::cout << "ID: " << id << ", Nome: " << studentObj.getName() << std::endl;
    }
}

void StudentControllerCPP::addStudent(int studentId, std::string &name, std::string &email, std::string &address) {

    if (students.find(studentId) != students.end()) {
        std::cout << "Student with ID " << studentId << " already exists\n";
        return;
    }

    students[studentId] = Student(studentId, name, email, address);

    // Inserindo no banco de dados usando uma abordagem simples
    std::string query = "INSERT INTO students (id, name, email, address) VALUES (" + 
                        std::to_string(studentId) + ", '" + name + "', '" + email + "', '" + address + "');";

    char* errMsg = nullptr;
    if (sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK) {
        std::cout << "Student '" << name << "' added to database successfully.\n";
    } else {
        std::cerr << "Error adding student to database: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
}

void StudentControllerCPP::deleteStudent(int studentId)
{
    if (students.find(studentId) != students.end()) {
        students.erase(studentId);
        std::cout << "Student with ID " << studentId << " deleted.\n";

        // Removendo do banco de dados
        std::string query = "DELETE FROM students WHERE id = " + std::to_string(studentId) + ";";

        char* errMsg = nullptr;
        if (sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK) {
            std::cout << "Student removed from database successfully.\n";
        } else {
            std::cerr << "Error deleting student from database: " << errMsg << '\n';
            sqlite3_free(errMsg);
        }
    }
    else {
        std::cout << "Student with ID " << studentId << " not found.\n";
    }
}

bool StudentControllerCPP::verifyStudentId(int studentId)
{
    if (students.find(studentId) != students.end()) {
        return true;
    }

    // Verificando no banco de dados 
    std::string query = "SELECT 1 FROM students WHERE id = " + std::to_string(studentId) + ";";

    char* errMsg = nullptr;
    bool exists = false;

    auto callback = [](void* data, int argc, char** argv, char** colNames) -> int {
        *static_cast<bool*>(data) = true;
        return 0;
    };

    if (sqlite3_exec(db, query.c_str(), callback, &exists, &errMsg) != SQLITE_OK) {
        std::cerr << "Error verifying student ID in database: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }

    return exists;
}
