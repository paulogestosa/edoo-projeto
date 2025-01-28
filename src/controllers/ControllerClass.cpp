#include "src/controllers/ControllerClass.h"
#include "sqlite3.h"

// Adiciona uma nova classe
void ControllerClass::addClass(const std::string &name)
{
    int Id = classes.size() + 1;
    classes[Id] = Class(Id, name);

    // Query para inserir a nova classe no banco de dados
    std::string query = "INSERT INTO Classes (id, name) VALUES (" +
                        std::to_string(Id) + ", '" + name + "');";

    char *errMsg = nullptr;
    if (sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Classe '" << name << "' adicionada com sucesso ao banco de dados!\n";
    }
    else
    {
        std::cerr << "Erro ao adicionar classe no banco de dados: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
}

// Adiciona um estudante a uma classe pelo ID
void ControllerClass::addStudentToClass(int classId, int studentId)
{
    if (classes.find(classId) == classes.end())
    {
        std::cerr << "Erro: Classe com ID " << classId << " não encontrada.\n";
        return;
    }

    StudentControllerCPP studentController;
    if (!studentController.verifyStudentId(studentId))
    {
        std::cerr << "Erro: Estudante com ID " << studentId << " não encontrado.\n";
        return;
    }

    classes[classId].enrollStudent(studentId);

    // Query para inserir a relação no banco de dados
    std::string query = "INSERT INTO Attendance (class_id, student_id, absence_count) VALUES (" +
                        std::to_string(classId) + ", " + std::to_string(studentId) + ", 0);";

    char *errMsg = nullptr;
    if (sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Estudante com ID " << studentId << " adicionado à classe com ID " << classId << " no banco de dados!\n";
    }
    else
    {
        std::cerr << "Erro ao adicionar estudante à classe no banco de dados: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
}

// Remove um estudante de uma classe
void ControllerClass::removeStudentOfClass(int classId, int studentId)
{
    if (classes.find(classId) == classes.end())
    {
        std::cerr << "Erro: Classe com ID " << classId << " não encontrada.\n";
        return;
    }

    classes[classId].removeStudent(studentId);

    // Query para remover a relação no banco de dados
    std::string query = "DELETE FROM Attendance WHERE class_id = " + std::to_string(classId) +
                        " AND student_id = " + std::to_string(studentId) + ";";

    char *errMsg = nullptr;
    if (sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Estudante com ID " << studentId << " removido da classe com ID " << classId << " no banco de dados.\n";
    }
    else
    {
        std::cerr << "Erro ao remover estudante da classe no banco de dados: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
}

// Atribui um professor a uma classe
void ControllerClass::assignTeacher(int classId, int teacherId)
{
    if (classes.find(classId) == classes.end())
    {
        std::cerr << "Erro: Classe com ID " << classId << " não encontrada.\n";
        return;
    }

    TeacherController teacherController_;
    if (!teacherController_.verifyTeacherId(teacherId))
    {
        std::cerr << "Erro: Professor com ID " << teacherId << " não encontrado.\n";
        return;
    }

    classes[classId].setEnrolledTeacher(teacherId);

    // Query para atualizar o professor na tabela Classes
    std::string query = "UPDATE Classes SET teacher_id = " + std::to_string(teacherId) +
                        " WHERE id = " + std::to_string(classId) + ";";

    char *errMsg = nullptr;
    if (sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Professor com ID " << teacherId << " atribuído à classe com ID " << classId << " no banco de dados.\n";
    }
    else
    {
        std::cerr << "Erro ao atribuir professor à classe no banco de dados: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
}

// Define uma nota para um estudante em uma classe
void ControllerClass::setStudentGrade(int classId, int studentId, int grade)
{
    if (classes.find(classId) == classes.end())
    {
        std::cerr << "Erro: Classe com ID " << classId << " não encontrada.\n";
        return;
    }

    StudentControllerCPP studentController;
    if (!studentController.verifyStudentId(studentId))
    {
        std::cerr << "Erro: Estudante com ID " << studentId << " não encontrado.\n";
        return;
    }

    classes[classId].setGradeByStudent(studentId, grade);

    // Query para inserir ou atualizar a nota no banco de dados
    std::string query = "INSERT INTO Grades (class_id, student_id, grade) VALUES (" +
                        std::to_string(classId) + ", " + std::to_string(studentId) + ", " + std::to_string(grade) +
                        ") ON CONFLICT(class_id, student_id) DO UPDATE SET grade = " + std::to_string(grade) + ";";

    char *errMsg = nullptr;
    if (sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Nota " << grade << " atribuída ao estudante " << studentId << " na classe " << classId << " no banco de dados.\n";
    }
    else
    {
        std::cerr << "Erro ao atribuir nota no banco de dados: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
}

// Atualiza a nota de um estudante
void ControllerClass::updateStudentGrade(int classId, int studentId, int newGrade)
{
    if (classes.find(classId) == classes.end())
    {
        std::cerr << "Erro: Classe com ID " << classId << " não encontrada.\n";
        return;
    }

    StudentControllerCPP studentController;
    if (!studentController.verifyStudentId(studentId))
    {
        std::cerr << "Erro: Estudante com ID " << studentId << " não encontrado.\n";
        return;
    }

    classes[classId].setGradeByStudent(studentId, newGrade);

    // Query para atualizar a nota no banco de dados
    std::string query = "UPDATE Grades SET grade = " + std::to_string(newGrade) +
                        " WHERE class_id = " + std::to_string(classId) +
                        " AND student_id = " + std::to_string(studentId) + ";";

    char *errMsg = nullptr;
    if (sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Nota do estudante " << studentId << " na classe " << classId << " atualizada para " << newGrade << " no banco de dados.\n";
    }
    else
    {
        std::cerr << "Erro ao atualizar nota no banco de dados: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
}

// Remove a nota de um estudante
void ControllerClass::removeStudentGrade(int classId, int studentId)
{
    if (classes.find(classId) == classes.end())
    {
        std::cerr << "Erro: Classe com ID " << classId << " não encontrada.\n";
        return;
    }

    StudentControllerCPP studentController;
    if (!studentController.verifyStudentId(studentId))
    {
        std::cerr << "Erro: Estudante com ID " << studentId << " não encontrado.\n";
        return;
    }

    classes[classId].setGradeByStudent(studentId, -1);

    // Query para remover a nota do banco de dados
    std::string query = "DELETE FROM Grades WHERE class_id = " + std::to_string(classId) +
                        " AND student_id = " + std::to_string(studentId) + ";";

    char *errMsg = nullptr;
    if (sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << "Nota do estudante " << studentId << " na classe " << classId << " removida do banco de dados.\n";
    }
    else
    {
        std::cerr << "Erro ao remover nota no banco de dados: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
}

// Atribui faltas a um estudante
void ControllerClass::atributeStudentAbssences(int classId, int studentId, int numAbssences)
{
    if (classes.find(classId) == classes.end())
    {
        std::cerr << "Erro: Classe com ID " << classId << " não encontrada.\n";
        return;
    }

    classes[classId].setAbsencesByStudent(studentId, numAbssences);

    // Query para atualizar o número de faltas no banco de dados
    std::string query = "UPDATE Attendance SET absence_count = " + std::to_string(numAbssences) +
                        " WHERE class_id = " + std::to_string(classId) +
                        " AND student_id = " + std::to_string(studentId) + ";";

    char *errMsg = nullptr;
    if (sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK)
    {
        std::cout << numAbssences << " falta(s) atribuída(s) ao estudante com ID " << studentId << " na classe com ID " << classId << ".\n";
    }
    else
    {
        std::cerr << "Erro ao atribuir faltas no banco de dados: " << errMsg << '\n';
        sqlite3_free(errMsg);
    }
}

// Remove faltas de um estudante
void ControllerClass::removeStudentAbssences(sqlite3 *db, int classId, int studentId, int numAbssencesToRemove)
{

    if (classes.find(classId) == classes.end())
    {
        std::cerr << "Erro: Classe com ID " << classId << " não encontrada.\n";
        return;
    }

    // Verifica se o estudante existe (simulando acesso ao ControllerStudent)
    StudentControllerCPP studentController;
    if (!studentController.verifyStudentId(studentId))
    {
        std::cerr << "Erro: Estudante com ID " << studentId << " não encontrado.\n";
        return;
    }

    classes[classId].setAbsencesByStudent(studentId, classes[classId].getAbsencesByStudent(studentId) - numAbssencesToRemove);
    std::cout << numAbssencesToRemove << " falta(s) removida(s) do estudante " << studentId << " na classe " << classId << ".\n";

    // lógica db
    const char *sql = "UPDATE Class_Students SET absences = absences + ? WHERE class_id = ? AND student_id = ?;";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt, 1, numAbssences);
    sqlite3_bind_int(stmt, 2, classId);
    sqlite3_bind_int(stmt, 3, studentId);

    if (sqlite3_step(stmt) == SQLITE_DONE)
    {
        std::cout << numAbssences << " falta(s) atribuída(s) ao estudante " << studentId << " na classe " << classId << " no banco de dados.\n";
    }
    else
    {
        std::cerr << "Erro ao atualizar faltas no banco de dados: " << sqlite3_errmsg(db) << "\n";
    }

    sqlite3_finalize(stmt);
}

// Exibe informações de uma classe pelo ID
void ControllerClass::getClassbyId(int id)
{
    std::string query = "SELECT * FROM Classes WHERE id = " + std::to_string(id) + ";";

    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            std::cout << "ID: " << sqlite3_column_int(stmt, 0)
                      << ", Nome: " << reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)) << '\n';
        }
        else
        {
            std::cerr << "Classe com ID " << id << " não encontrada no banco de dados.\n";
        }
    }
    else
    {
        std::cerr << "Erro ao buscar classe no banco de dados: " << sqlite3_errmsg(db) << '\n';
    }

    sqlite3_finalize(stmt);
}
