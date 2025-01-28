#include <iostream>
#include <database.h>
#include <sqlite3.h>

int createStudentsTable(const char *s)
{

    sqlite3 *DB;
    std::string query = R"(
        CREATE TABLE IF NOT EXISTS students (
            id INTEGER PRIMARY KEY,
            name TEXT NOT NULL,
            email TEXT NOT NULL UNIQUE,
            adress TEXT NOT NULL
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

int insertStudent(const char *s, studentId, name, email, adress)
{
    sqlite3 *DB;
    char *errMsg;

    int exit = sqlite3_open(s, &DB);

    std::string query = "INSERT INTO students (id, name, email, adress) VALUES (" + std::to_string(studentId) + ", ' " + name + "', '" + email + "','" + adress + "');";

    if (sqlite3_exec(DB, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Student '" << name << "' added to database successfully.\n";
    }
    else
    {
        std::cerr << "Error adding student to database: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
    return 0;
}

int deleteStudentDB(const char *s, studentId)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);

    std::string query = "DELETE FROM students WHERE id = " + std::to_string(studentId) + ";";
    char *errMsg = nullptr;
    if (sqlite3_exec(DB, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Student removed from database successfully.\n";
    }
    else
    {
        std::cerr << "Error deleting student from database: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
    return 0;
}

int getStudent(const char *s, studentId)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);

    std::string query = "SELECT 1 FROM students WHERE id = " + std::to_string(studentId) + ";";
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