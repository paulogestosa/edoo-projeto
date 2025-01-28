#include "src/controllers/ControllerClass.h"
#include "sqlite3.h"

// Adiciona uma nova classe
void ControllerClass::addClass(const std::string &name)
{
    int Id = classes.size() + 1;
    classes[Id] = Class(Id, name);
    insertClass(const char *s, id, name);
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
    insertStudentToClass(const char *s, studentId, classId);
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
    deleteStudentFromClass(const char *s, studentId, classId);
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
    updateTeacherFromClass(const char *s, teacherId, classId)
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
    insertGrades(const char *s, classId, studentId, grade);
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
    updateGradeFromStudent(const char *s, studentId, classId, newGrade);
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

    deleteGradeStudent(const char *s, studentId, classId)
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
    updateAbsencesStudent(const char *s, studentId, classId, numAbssences);
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


}

// Exibe informações de uma classe pelo ID
void ControllerClass::getClassbyId(int id)
{
    if (classes.find(id) == classes.end())
    {
        std::cerr << "Erro: Classe com ID " << id << " não encontrada.\n";
        return;
    }
    selectClass(const char *s, classId);
    classes[id]
        .printDetails(); // Criar método de printar detalhes da classe
}