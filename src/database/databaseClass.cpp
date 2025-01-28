#include <iostream>
#include <database.h>
#include <sqlite3.h>

int createClassTable(const char *s)
{

    sqlite3 *DB;
    std::string query = R"(
        CREATE TABLE IF NOT EXISTS Classes (
             id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            teacher_id INTEGER,
            FOREIGN KEY (teacher_id) REFERENCES Teachers(id)
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
}

int insertClass(const char *s, id, name)
{
    sqlite3 *DB;
    char *errMsg;

    int exit = sqlite3_open(s, &DB);

    std::string query = "INSERT INTO Classes (id, name) VALUES (" +
                        std::to_string(Id) + ", '" + name + "');";
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

int insertStudentToClass(const char *s, studentId, classId)
{
    sqlite3 *DB;
    char *errMsg;

    int exit = sqlite3_open(s, &DB);
    std::string query = "INSERT INTO Classes (classId, studentId,absences) VALUES (" +
                        std::to_string(classId) + ", " + std::to_string(studentId) + ", 0);";

    char *errMsg = nullptr;
    if (sqlite3_exec(DB, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Student with Id " << studentId << " added to class" << classId << " in db!\n";
    }
    else
    {
        std::cerr << "Errr" << errMsg << '\n';
        sqlite3_free(errMsg);
    }
}

int deleteStudentFromClass(const char *s, studentId, classId)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);

    std::string query = "DELETE FROM Classes WHERE class_id = " + std::to_string(classId) +
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

int updateTeacherFromClass(const char *s, teacherId, classId)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);
    std::string query = "INSERT INTO Classes (id, teacher_id) VALUES (" +
                        std::to_string(Id) + ", '" + name + "');";

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

int insertGrades(const char *s, classId, studentId, grade)
{
    sqlite3 *DB;
    char *errMsg;

    int exit = sqlite3_open(s, &DB);

    std::string query = "INSERT INTO Grades (class_id, student_id, grade) VALUES (" +
                        std::to_string(classId) + ", " + std::to_string(studentId) + ", " + std::to_string(grade) +
                        ") ON CONFLICT(class_id, student_id) DO UPDATE SET grade = " + std::to_string(grade) + ";";

    if (sqlite3_exec(DB, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Nota " << grade << " atribuída ao estudante " << studentId << " na classe " << classId << " no banco de dados.\n";
    }
    else
    {
        std::cerr << "Error attributing grade  to database: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
    return 0;
}

int updateGradeFromStudent(const char *s, studentId, classId, newGrade)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);

    std::string query = "UPDATE Grades SET grade = " + std::to_string(newGrade) +
                        " WHERE class_id = " + std::to_string(classId) +
                        " AND student_id = " + std::to_string(studentId) + ";";
    char *errMsg = nullptr;
    exit=sqlite3_exec(DB, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    if (exit!=SQLITE_OK)
    {
        std::cerr << "Error" << std::endl;
    }
    else
    {
        std::cout << "Grades updated" << endl;
    }
}

int deleteGradeStudent(const char *s, studentId, classId)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);

    std::string query = "DELETE FROM Grades WHERE class_id = " + std::to_string(classId) +
                        " AND student_id = " + std::to_string(studentId) + ";";

    char *errMsg = nullptr;
    exit=sqlite3_exec(DB, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    if (exit!=SQLITE_OK)
    {
        std::cerr << "Error" << std::endl;
    }
    else
    {
        std::cout << "Grades updated" << endl;
    }
}

int updateAbsencesStudent(const char *s, studentId, classId, numAbssences)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);

    std::string query = "UPDATE Grades SET grade = " + std::to_string(newGrade) +
                        " WHERE class_id = " + std::to_string(classId) +
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

int selectClass(const char *s, classId)
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
