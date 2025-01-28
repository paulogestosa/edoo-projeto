#include "TeacherController.h"
#include "database.h"
#include <iostream>

void TeacherController::showClasses(const std::vector<int> classes) const
{
    for (int id : classes)
    {
        const Class *foundClass = nullptr;

        for (const auto &c : classes)
        {
            if (c.getId() == id)
            {
                foundClass = &c;
                break;
            }
        }

        if (foundClass)
        {
            std::cout << " - ID: " << foundClass->getId()
                      << ", Nome: " << foundClass->getName() << std::endl;
        }
        else
        {
            std::cout << "Classe com ID " << id << " não encontrada." << std::endl;
        }
    }
}

void TeacherController::addTeacher(int teacherId, Teacher teacherToAdd)
{
    // Inserindo professor no banco de dados
    std::string query = "INSERT INTO teachers (id, name, email) VALUES (" +
                        std::to_string(teacherId) + ", '" + teacherToAdd.getName() + "', '" + teacherToAdd.getEmail() + "');";

    char *errMsg = nullptr;
    if (sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Teacher '" << teacherToAdd.getName() << "' added to database successfully.\n";
    }
    else
    {
        std::cerr << "Error adding teacher to database: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
}

void TeacherController::removeTeacher(int teacherId)
{
    std::string query = "DELETE FROM teachers WHERE id = " + std::to_string(teacherId) + ";";

    char *errMsg = nullptr;
    if (sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Teacher with ID " << teacherId << " removed from database successfully.\n";
    }
    else
    {
        std::cerr << "Error removing teacher from database: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
}

void TeacherController::changeTeacherInfo(int teacherId)
{
    std::string name, email;
    std::cout << "Update teacherName: ";
    std::cin >> name;

    std::cout << "Update teacherEmail: ";
    std::cin >> email;

    std::string query = "UPDATE teachers SET name = '" + name + "', email = '" + email + "' WHERE id = " + std::to_string(teacherId) + ";";

    char *errMsg = nullptr;
    if (sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Teacher with ID " << teacherId << " updated successfully.\n";
    }
    else
    {
        std::cerr << "Error updating teacher in database: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
}

bool TeacherController::verifyTeacherId(int teacherId)
{
    std::string query = "SELECT 1 FROM teachers WHERE id = " + std::to_string(teacherId) + ";";

    char *errMsg = nullptr;
    bool exists = false;

    auto callback = [](void *data, int argc, char **argv, char **colNames) -> int
    {
        *static_cast<bool *>(data) = true;
        return 0;
    };

    if (sqlite3_exec(db, query.c_str(), callback, &exists, &errMsg) != SQLITE_OK)
    {
        std::cerr << "Error verifying teacher ID in database: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }

    return exists;
}