#include <iostream>
#include <database.h>
#include <sqlite3.h>

int createStudentsTable(const char *s)
{

    sqlite3 *DB;
    std::string query = R"(
        CREATE TABLE IF NOT EXISTS Students (
            id INTEGER PRIMARY KEY,
            name TEXT NOT NULL,
            email TEXT NOT NULL UNIQUE,
            address TEXT NOT NULL
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

int insertStudent(const char *s, int studentId, const std::string &name, const std::string email, const std::string address)
{
    sqlite3 *DB;
    char *errMsg;

    int exit = sqlite3_open(s, &DB);

    std::string query = "INSERT INTO students (id, name, email, address) VALUES (" + std::to_string(studentId) + ", ' " + name + "', '" + email + "','" + address + "');";

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

int deleteStudentDB(const char *s, int studentId)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);

    std::string query = "DELETE FROM students WHERE id = " + std::to_string(studentId) + ";";
    char *errMsg = nullptr;
    if (sqlite3_exec(DB, query.c_str(), NULL, NULL, &errMsg) == SQLITE_OK)
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


int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; i++)
    {
        std::cout << azColName[i] << ":" << argv[i] << std::endl;
    }

    std::cout << endl;

    return 0;
}

int readStudentsDB(const char *s)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error: " << sqlite3_errmsg(DB) << std::endl;
        return exit;
    }

    std::string query = "SELECT * FROM Students;";
    char *errMsg = nullptr;

    exit = sqlite3_exec(DB, query.c_str(), callback, NULL, &errMsg);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }

    sqlite3_close(DB);
    return exit;
}
