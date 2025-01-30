#include <iostream>
#include <sqlite3.h>
#include "/home/beatrizanjos/edoo-projeto-1/src/database/database.h"
//Função de criação da tabela
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
    //execução
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


//criação de classes
int insertClass(const char *s, const std::string &name)
{
    sqlite3 *DB;
    char *errMsg;

    int exit = sqlite3_open(s, &DB);

    std::string query = "INSERT INTO Classes (name) VALUES ('" + name + "');";

    if (sqlite3_exec(DB, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Class '" << name << "' added to database successfully.\n";
    }
    else
    {
        std::cerr << "Error adding class to database: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
    return exit;
}

//atrelar um estudante a uma classe
int insertStudentToClass(const char *s, int studentId, int classId)
{
    sqlite3 *DB;
    char *errMsg;

    int exit = sqlite3_open(s, &DB);
    std::string query = "INSERT OR IGNORE INTO Class_Students (class_id, student_id, absences) VALUES (" +
                        std::to_string(classId) + ", " + std::to_string(studentId) + ", 0);";

    if (sqlite3_exec(DB, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Student with Id " << studentId << " added to class" << classId << " in db!\n";
    }
    else
    {
        std::cerr << "Errr" << errMsg << '\n';
        sqlite3_free(errMsg);
    }
    return exit;
}

// deletar um estudante de uma classe 
int deleteStudentFromClass(const char *s, int studentId, int classId)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);

    std::string query = "DELETE FROM Class_Students WHERE class_id = " + std::to_string(classId) +
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
    return exit;
}

//deletar faltas do estudante
int deleteStudentAbsences(const char *s, int studentId, int classId, int numAbsencesToRemove)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error opening database: " << sqlite3_errmsg(DB) << std::endl;
        return exit;
    }

    std::string query = "UPDATE Class_Students SET absences = MAX(absences - " +
                        std::to_string(numAbsences) + ", 0) WHERE class_id = " +
                        std::to_string(classId) + " AND student_id = " +
                        std::to_string(studentId) + ";";

    char *errMsg = nullptr;
    exit = sqlite3_exec(DB, query.c_str(), nullptr, nullptr, &errMsg);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error updating student absences: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
    else
    {
        std::cout << numAbsences << " absence(s) removed from student " << studentId
                  << " in class " << classId << ".\n";
    }

    sqlite3_close(DB);
    return exit;
}


//atrelar um professor a uma classe
int insertTeacherFromClass(const char *s, int teacherId, int classId, const std::string name)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);
    std::string query = "INSERT INTO Classes (id, teacher_id) VALUES (" +
                        std::to_string(classId) + ", " + std::to_string(teacherId) + ");";

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
    return exit;
}
//inserir nota
int insertGrades(const char *s, int classId, int studentId, int grade)
{
    sqlite3 *DB;
    char *errMsg;

    int exit = sqlite3_open(s, &DB);

    std::string query = "UPDATE Class_Students SET grade = " + std::to_string(grade) +
                        " WHERE class_id = " + std::to_string(classId) +
                        " AND student_id = " + std::to_string(studentId) + ";";

    if (sqlite3_exec(DB, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Nota " << grade << " atribuída ao estudante " << studentId << " na classe " << classId << " no banco de dados.\n";
    }
    else
    {
        std::cerr << "Error attributing grade  to database: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
    return exit;
}

//deletar notas do estudante
int deleteGradeStudent(const char *s, int studentId, int classId)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);

    std::string query = "UPDATE Class_Students SET grade = NULL WHERE class_id = " +
                        std::to_string(classId) + " AND student_id = " + std::to_string(studentId) + ";";

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
    return exit;
}

//inserir faltas do estudante
int insertAbsencesStudent(const char *s, int studentId, int classId, int numAbsences)
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
                  << " in class " << classId << ".\n";
    }

    sqlite3_close(DB);
    return exit;
}

//função para imprimir os resultados da pesquisa de sqlite
int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; i++)
    {
        std::cout << azColName[i] << ":" << argv[i] << std::endl;
    }

    std::cout << std::endl;

    return 0;
} 

//função para pegar as faltas de uma classe

int readClassAbsences(const char *s, int classId)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error opening database: " << sqlite3_errmsg(DB) << std::endl;
        return exit;
    }

    std::string query = "SELECT student_id, absences FROM Class_Students WHERE class_id = " + std::to_string(classId) + ";";
    exit = sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Erro ao consultar faltas dos alunos.\n";
    }

    sqlite3_close(DB);
    return exit;
}

// exibir as notas de todos os alunos em uma classe
int readClassGrades(const char *s, int classId)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error opening database: " << sqlite3_errmsg(DB) << std::endl;
        return exit;
    }

    std::string query = "SELECT student_id, grade FROM Class_Students WHERE class_id = " + std::to_string(classId) + ";";
    exit = sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Erro ao consultar notas dos alunos.\n";
    }

    sqlite3_close(DB);
    return exit;
}

// exibir  a nota de um estudante específico em uma classe
int readStudentGrade(const char *s, int classId, int studentId)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error opening database: " << sqlite3_errmsg(DB) << std::endl;
        return exit;
    }

    std::string query = "SELECT grade FROM Class_Students WHERE class_id = " + std::to_string(classId) +
                        " AND student_id = " + std::to_string(studentId) + ";";
    exit = sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Erro ao consultar nota do estudante.\n";
    }

    sqlite3_close(DB);
    return exit;
}

// exibir todas as classes de um aluno
int readStudentClasses(const char *s, int studentId)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error opening database: " << sqlite3_errmsg(DB) << std::endl;
        return exit;
    }

    std::string query = "SELECT class_id FROM Class_Students WHERE student_id = " + std::to_string(studentId) + ";";
    exit = sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Erro ao listar classes do estudante.\n";
    }

    sqlite3_close(DB);
    return exit;
}

// ler todas as classes de um professor
int readTeacherClasses(const char *s, int teacherId)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error opening database: " << sqlite3_errmsg(DB) << std::endl;
        return exit;
    }

    std::string query = "SELECT id FROM Classes WHERE teacher_id = " + std::to_string(teacherId) + ";";
    exit = sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Erro ao listar classes do professor.\n";
    }

    sqlite3_close(DB);
    return exit;
}

// ler todas as classes registradas no sistema
int readAllClasses(const char *s)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error opening database: " << sqlite3_errmsg(DB) << std::endl;
        return exit;
    }

    std::string query = "SELECT id, name FROM Classes;";
    exit = sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Erro ao listar todas as classes.\n";
    }

    sqlite3_close(DB);
    return exit;
}
//ver se a classe está na base de dados
int checkClassInDatabase(const char *s, int classId)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);
    if (exit != SQLITE_OK)
    {
        std::cerr << "Erro ao abrir o banco de dados: " << sqlite3_errmsg(DB) << std::endl;
        return 0;
    }

    std::string query = "SELECT COUNT(*) FROM Classes WHERE id = " + std::to_string(classId) + ";";
    int classExists = 0;
    auto callback = [](void *data, int argc, char **argv, char **azColName) -> int
    {
        if (argc > 0)
        {
            *(int *)data = std::stoi(argv[0]);
        }
        return 0;
    };

    exit = sqlite3_exec(DB, query.c_str(), callback, &classExists, nullptr);
    sqlite3_close(DB);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Erro ao verificar a existência da classe no banco de dados.\n";
        return 0;
    }

    return classExists > 0;
}
// ver se o estudante está na base de dados
int checkStudentInDatabase(const char *s, int studentId)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);
    if (exit != SQLITE_OK)
    {
        std::cerr << "Erro ao abrir o banco de dados: " << sqlite3_errmsg(DB) << std::endl;
        return 0;
    }

    std::string query = "SELECT COUNT(*) FROM Students WHERE id = " + std::to_string(studentId) + ";";
    int studentExists = 0;
    auto callback = [](void *data, int argc, char **argv, char **azColName) -> int
    {
        if (argc > 0)
        {
            *(int *)data = std::stoi(argv[0]);
        }
        return 0;
    };

    exit = sqlite3_exec(DB, query.c_str(), callback, &studentExists, nullptr);
    sqlite3_close(DB);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Erro ao verificar a existência do estudante no banco de dados.\n";
        return 0;
    }

    return studentExists > 0;
}
