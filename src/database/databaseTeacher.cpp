#include <iostream>
#include <database.h>
#include <sqlite3.h>

int createTeacherTable(const char *s)
{

    sqlite3 *DB;
    std::string query = R"(
        CREATE TABLE IF NOT EXISTS Teacher (
             id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            email TEXT NOT NULL,
        );
    )";

    int exit = 0;
    exit = sqlite3_open(s, &DB);

    char *messageError;
    exit = sqlite3_exec(DB, query.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error creating Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
    {
        std::cout << " Table created" << std::endl;
        sqlite3_close(DB);
    }
    return 0;
}

int insertTeacher(const char *s)
{
    sqlite3 *DB;
    char *errMsg;

    int exit = sqlite3_open(s, &DB);

    std::string query = "INSERT INTO teachers (id, name, email) VALUES (" +
                        std::to_string(teacherId) + ", '" + name + "', '" + email + "');";
    if (sqlite3_exec(DB, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Teacher '" << name << "' added to database successfully.\n";
    }
    else
    {
        std::cerr << "Error adding Teacher to database: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
    return 0;
}

int removeTeacher(const char *s, teacherId)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);

    std::string query = "DELETE FROM Teacher WHERE teacher_id = " + std::to_string(teacherId) +
                        ";";
    char *errMsg = nullptr;
    if (sqlite3_exec(DB, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Teacher removed successfully.\n";
    }
    else
    {
        std::cerr << "Error deleting  " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
    return 0;
}

int updateTeacherInfo(const char *s, teacherId)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);
    std::string query = "UPDATE teachers SET name = '" + name + "', email = '" + email + "' WHERE id = " + std::to_string(teacherId) + ";";

    char *errMsg = nullptr;
    if (sqlite3_exec(DB, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Teacher Info Updated.\n";
    }
    else
    {
        std::cerr << "Error updating info " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
    return 0;
}

int getTeacher(const char *s, teacherId)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);

    std::string query = "SELECT 1 FROM teachers WHERE id = " + std::to_string(teacherId) + ";";
    auto callback = [](void *data, int argc, char **argv, char **colNames) -> int
    {
        *static_cast<bool *>(data) = true;
        return 0;
    };
    if (sqlite3_exec(DB, query.c_str(), callback, NULL, NULL) != SQLITE_OK)
    {
        std::cerr << "Error verifying student ID in database: \n";
    }
    return 0;
}