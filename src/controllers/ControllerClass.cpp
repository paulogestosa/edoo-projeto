#include "ControllerClass.h"
#include "sqlite3.h"
// Adiciona uma nova classe
void ControllerClass::addClass(sqlite3 *db, std::string &name)
{

    int Id = classes.size() + 1; // Usa o tamanho atual do mapa para gerar o ID
    classes[Id] = Class(Id, name);
    std::cout << "Classe '" << name << "' adicionada com ID " << Id << ".\n";

    // lógica db
    const char *sql = "INSERT INTO Classes (id, name) VALUES (?, ?);";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt, 1, Id);
    sqlite3_bind_text(stmt, 2, name.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_DONE)
    {
        std::cout << "Classe '" << name << "' salva no banco de dados com sucesso.\n";
    }
    else
    {
        std::cerr << "Erro ao salvar a classe no banco de dados: " << sqlite3_errmsg(db) << "\n";
    }

    sqlite3_finalize(stmt);
}

// Adiciona um estudante a uma classe pelo ID
void ControllerClass::addStudentToClass(sqlite3 *db, int classId, int studentId)
{

    // Verifica se a classe existe
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

    // Adiciona o estudante à classe
    classes[classId].enrollStudent(studentId);

    std::cout << "Estudante com ID " << studentId << " adicionado à classe com ID " << classId << ".\n";

    // lógica db
    const char *sql = "INSERT INTO Class_Students (class_id, student_id, absences, grade) VALUES (?, ?, 0, -1);";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt, 1, classId);
    sqlite3_bind_int(stmt, 2, studentId);

    if (sqlite3_step(stmt) == SQLITE_DONE)
    {
        std::cout << "Estudante com ID " << studentId << " adicionado à classe com ID " << classId << " no banco de dados.\n";
    }
    else
    {
        std::cerr << "Erro ao adicionar estudante à classe no banco de dados: " << sqlite3_errmsg(db) << "\n";
    }

    sqlite3_finalize(stmt);
}

// Remove um estudante de uma classe
void ControllerClass::removeStudentOfClass(sqlite3 *db, int classId, int studentId)
{

    // Verifica se a classe existe
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

    // Exclui o estudante da classe
    classes[classId].removeStudent(studentId);
    // lógica db
    const char *sql = "DELETE FROM Class_Students WHERE class_id = ? AND student_id = ?;";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt, 1, classId);
    sqlite3_bind_int(stmt, 2, studentId);

    if (sqlite3_step(stmt) == SQLITE_DONE)
    {
        std::cout << "Estudante com ID " << studentId << " removido da classe com ID " << classId << " no banco de dados.\n";
    }
    else
    {
        std::cerr << "Erro ao remover estudante da classe no banco de dados: " << sqlite3_errmsg(db) << "\n";
    }

    sqlite3_finalize(stmt);
}

// Atribui um professor a uma classe
void ControllerClass::assignTeacher(sqlite3 *db, int classId, int teacherId)
{

    if (classes.find(classId) == classes.end())
    {
        std::cerr << "Erro: Classe com ID " << classId << " não encontrada.\n";
        return;
    }

    TeacherController teacherController_;
    if (!teacherController_.verifyTeacherId(teacherId))
    {
        std::cerr << "Erro: professor com ID " << teacherId << " não encontrado.\n";
        return;
    }

    // Adiciona o professor a classe
    classes[classId].setEnrolledTeacher(teacherId);
    std::cout << "Professor com ID " << teacherId << " atribuído à classe com ID " << classId << ".\n";

    // lógica db
    const char *sql = "UPDATE Classes SET teacher_id = ? WHERE id = ?;";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt, 1, teacherId);
    sqlite3_bind_int(stmt, 2, classId);

    if (sqlite3_step(stmt) == SQLITE_DONE)
    {
        std::cout << "Professor com ID " << teacherId << " atribuído à classe com ID " << classId << " no banco de dados.\n";
    }
    else
    {
        std::cerr << "Erro ao atribuir professor à classe no banco de dados: " << sqlite3_errmsg(db) << "\n";
    }

    sqlite3_finalize(stmt);
}

// Define uma nota para um estudante em uma classe
void ControllerClass::setStudentGrade(sqlite3 *db, int classId, int studentId, int grade)
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

    classes[classId].setGradeByStudent(studentId, grade);
    std::cout << "Nota " << grade << " atribuída ao estudante " << studentId << " na classe " << classId << ".\n";

    // lógica db
    const char *sql = "UPDATE Class_Students SET grade = ? WHERE class_id = ? AND student_id = ?;";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt, 1, grade);
    sqlite3_bind_int(stmt, 2, classId);
    sqlite3_bind_int(stmt, 3, studentId);

    if (sqlite3_step(stmt) == SQLITE_DONE)
    {
        std::cout << "Nota " << grade << " atribuída ao estudante " << studentId << " na classe " << classId << " no banco de dados.\n";
    }
    else
    {
        std::cerr << "Erro ao atribuir nota no banco de dados: " << sqlite3_errmsg(db) << "\n";
    }

    sqlite3_finalize(stmt);
}

// Atualiza a nota de um estudante
void ControllerClass::updateStudentGrade(sqlite3 *db, int classId, int studentId, int newGrade)
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

    classes[classId].setGradeByStudent(studentId, newGrade);
    std::cout << "Nota do estudante " << studentId << " na classe " << classId << " atualizada para " << newGrade << ".\n";

    // lógica db
    const char *sql = "UPDATE Class_Students SET grade = ? WHERE class_id = ? AND student_id = ?;";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt, 1, newGrade);
    sqlite3_bind_int(stmt, 2, classId);
    sqlite3_bind_int(stmt, 3, studentId);

    if (sqlite3_step(stmt) == SQLITE_DONE)
    {
        std::cout << "Nota do estudante " << studentId << " na classe " << classId << " atualizada para " << newGrade << " no banco de dados.\n";
    }
    else
    {
        std::cerr << "Erro ao atualizar nota no banco de dados: " << sqlite3_errmsg(db) << "\n";
    }

    sqlite3_finalize(stmt);
}

// Remove a nota de um estudante
void ControllerClass::removeStudentGrade(sqlite3 *db, int classId, int studentId)
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

    classes[classId].setGradeByStudent(studentId, -1);
    std::cout << "Nota do estudante " << studentId << " removida da classe " << classId << ".\n";

    // lógica db
    const char *sql = "UPDATE Class_Students SET grade = -1 WHERE class_id = ? AND student_id = ?;";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt, 1, classId);
    sqlite3_bind_int(stmt, 2, studentId);

    if (sqlite3_step(stmt) == SQLITE_DONE)
    {
        std::cout << "Nota do estudante " << studentId << " removida da classe " << classId << " no banco de dados.\n";
    }
    else
    {
        std::cerr << "Erro ao remover nota no banco de dados: " << sqlite3_errmsg(db) << "\n";
    }

    sqlite3_finalize(stmt);
}

// Atribui faltas a um estudante
void ControllerClass::atributeStudentAbssences(sqlite3 *db, int classId, int studentId, int numAbssences)
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

    classes[classId].setAbsencesByStudent(studentId, numAbssences);
    std::cout << numAbssences << " falta(s) atribuída(s) ao estudante " << studentId << " na classe " << classId << ".\n";

    // TODO: Atualizar no banco de dados
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
void ControllerClass::getClassbyId(sqlite3 *db, int id)
{
    if (classes.find(id) == classes.end())
    {
        std::cerr << "Erro: Classe com ID " << id << " não encontrada no mapa local.\n";

        const char *sql = "SELECT id, name FROM Classes WHERE id = ?;";
        sqlite3_stmt *stmt;
        sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        sqlite3_bind_int(stmt, 1, id);

        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            int classId = sqlite3_column_int(stmt, 0);
            const char *className = (const char *)sqlite3_column_text(stmt, 1);

            std::cout << "ID: " << classId << ", Nome: " << className << "\n";
        }
        else
        {
            std::cerr << "Erro: Classe com ID " << id << " não encontrada no banco de dados.\n";
        }

        sqlite3_finalize(stmt);
        return;
    }

    classes[id].printDetails();
}
