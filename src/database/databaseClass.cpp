#include <iostream>
#include <database.h>
#include <sqlite3.h>

int createClassTable(const char *s)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);
    if (exit != SQLITE_OK)
    {
        std::cerr << "Error opening database: " << sqlite3_errmsg(DB) << std::endl;
        return exit;
    }

    std::string query = R"(
        CREATE TABLE IF NOT EXISTS Classes (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            teacher_id INTEGER,
            FOREIGN KEY (teacher_id) REFERENCES Teachers(id) ON DELETE SET NULL
        );

        CREATE TABLE IF NOT EXISTS Class_Students (
            class_id INTEGER,
            student_id INTEGER,
            absences INTEGER DEFAULT 0,
            grade INTEGER DEFAULT NULL,
            PRIMARY KEY (class_id, student_id),
            FOREIGN KEY (class_id) REFERENCES Classes(id) ON DELETE CASCADE,
            FOREIGN KEY (student_id) REFERENCES Students(id) ON DELETE CASCADE
        );
    )";

    char *messageError;
    exit = sqlite3_exec(DB, query.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error creating Tables: " << messageError << std::endl;
        sqlite3_free(messageError);
    }
    else
    {
        std::cout << "Tables created successfully!" << std::endl;
    }

    sqlite3_close(DB);
    return exit;
}

int insertClass(const char *s, int id, const std::string &name)
{
    sqlite3 *DB;
    char *errMsg;

    int exit = sqlite3_open(s, &DB);

    std::string query = "INSERT INTO Classes (id, name) VALUES (" +
                        std::to_string(id) + ", '" + name + "');";
    if (sqlite3_exec(DB, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Class '" << name << "' added to database successfully.\n";
    }
    else
    {
        std::cerr << "Error adding class to database: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
    return 0;
}

int insertStudentToClass(const char *s, int studentId, int id)
{
    sqlite3 *DB;
    char *errMsg;

    int exit = sqlite3_open(s, &DB);
    std::string query = "INSERT INTO Class_Students (class_id, student_id, absences) VALUES (" +
                        std::to_string(id) + ", " + std::to_string(studentId) + ", 0);";

    if (sqlite3_exec(DB, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Student with Id " << studentId << " added to class" << id << " in db!\n";
    }
    else
    {
        std::cerr << "Errr" << errMsg << '\n';
        sqlite3_free(errMsg);
    }
    return 0;
}

int deleteStudentFromClass(const char *s, int studentId, int id)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);

    std::string query = "DELETE FROM Class_Students WHERE class_id = " + std::to_string(id) +
                        " AND student_id = " + std::to_string(studentId) + ";";
    char *errMsg = nullptr;
    if (sqlite3_exec(DB, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Student removed from class successfully.\n";
    }
    else
    {
        std::cerr << "Error deleting student from class: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
}

int updateTeacherFromClass(const char *s, int teacherId, int id, const std::string name)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);
    std::string query = "INSERT INTO Classes (id, teacher_id) VALUES (" +
                        std::to_string(id) + ", '" + name + "');";

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
}

int insertGrades(const char *s, int id, int studentId, int grade)
{
    sqlite3 *DB;
    char *errMsg;

    int exit = sqlite3_open(s, &DB);

    std::string query = "UPDATE Class_Students SET grade = " + std::to_string(grade) +
                        " WHERE class_id = " + std::to_string(id) +
                        " AND student_id = " + std::to_string(studentId) + ";";

    if (sqlite3_exec(DB, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Nota " << grade << " atribuída ao estudante " << studentId << " na classe " << id << " no banco de dados.\n";
    }
    else
    {
        std::cerr << "Error attributing grade  to database: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
    return 0;
}

int updateGradeFromStudent(const char *s, int studentId, int id, int newGrade)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);
    std::string query = "UPDATE Class_Students SET grade = " + std::to_string(newGrade) +
                        " WHERE class_id = " + std::to_string(id) +
                        " AND student_id = " + std::to_string(studentId) + ";";

    char *errMsg = nullptr;
    exit = sqlite3_exec(DB, query.c_str(), nullptr, nullptr, &errMsg);
    if (exit != SQLITE_OK)
    {
        std::cerr << "Error" << std::endl;
    }
    else
    {
        std::cout << "Grades updated" << std::endl;
    }
}

int deleteGradeStudent(const char *s, int studentId, int id)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);

    std::string query = "UPDATE Class_Students SET grade = NULL WHERE class_id = " +
                        std::to_string(id) + " AND student_id = " + std::to_string(studentId) + ";";

    char *errMsg = nullptr;
    exit = sqlite3_exec(DB, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK;
    if (exit != SQLITE_OK)
    {
        std::cerr << "Error" << std::endl;
    }
    else
    {
        std::cout << "Grades updated" << std::endl;
    }
}

int updateAbsencesStudent(const char *s, int studentId, int id, int numAbsences)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);
    if (exit != SQLITE_OK)
    {
        std::cerr << "Error opening database: " << sqlite3_errmsg(DB) << std::endl;
        return exit;
    }

    std::string query = "INSERT INTO Class_Students (class_id, student_id, absences) VALUES (" +
                        std::to_string(id) + ", " + std::to_string(studentId) + ", " + std::to_string(numAbsences) +
                        ") ON CONFLICT(class_id, student_id) DO UPDATE SET absences = absences + " + std::to_string(numAbsences) + ";";

    char *errMsg = nullptr;
    exit = sqlite3_exec(DB, query.c_str(), nullptr, nullptr, &errMsg);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error inserting absences in database: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
    else
    {
        std::cout << numAbsences << " absence(s) inserted for student " << studentId
                  << " in class " << id << ".\n";
    }

    sqlite3_close(DB);
    return exit;
}

int selectClass(const char *s, int id)
{

    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);

    std::string query = "SELECT * FROM Classes WHERE id = " + std::to_string(id) + ";";
    char *errMsg = nullptr;

    exit = sqlite3_exec(DB, query.c_str(), nullptr, nullptr, &errMsg);
    if (exit != SQLITE_OK)
    {
        std::cerr << "Error" << std::endl;
    }
    else
    {
        std::cout << "Found Class" << std::endl;
    }
}
