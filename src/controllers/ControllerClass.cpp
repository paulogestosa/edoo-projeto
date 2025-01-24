#include "ControllerClass.h"

// Adiciona uma nova classe
void ControllerClass::addClass(const std::string &name) {

    int Id = classes.size() + 1; // Usa o tamanho atual do mapa para gerar o ID
    classes[Id] = Class(Id, name);
    std::cout << "Classe '" << name << "' adicionada com ID " << Id << ".\n";

    // TODO: Adicionar lógica para salvar no banco de dados
}

// Adiciona um estudante a uma classe pelo ID
void ControllerClass::addStudentToClass(int classId, int studentId) {

    // Verifica se a classe existe
    if (classes.find(classId) == classes.end()) {
        std::cerr << "Erro: Classe com ID " << classId << " não encontrada.\n";
        return;
    }

    // Verifica se o estudante existe (simulando acesso ao ControllerStudent)
    StudentControllerCPP studentController;
    if (!studentController.verifyStudentId(studentId)) {
        std::cerr << "Erro: Estudante com ID " << studentId << " não encontrado.\n";
        return;
    }

    // Adiciona o estudante à classe
    classes[classId].enrollStudent(studentId);

    std::cout << "Estudante com ID " << studentId << " adicionado à classe com ID " << classId << ".\n";

    // TODO: Atualizar no banco de dados
}

// Atribui um professor a uma classe
void ControllerClass::assignTeacher(int classId, int teacherId) {

    if (classes.find(classId) == classes.end()) {
        std::cerr << "Erro: Classe com ID " << classId << " não encontrada.\n";
        return;
    }

    TeacherController teacherController_;
    if (!teacherController_.verifyTeacherId(teacherId)) {
        std::cerr << "Erro: professor com ID " << teacherId << " não encontrado.\n";
        return;
    }

    // Adiciona o professor a classe
    classes[classId].setEnrolledTeacher(teacherId);
    std::cout << "Professor com ID " << teacherId << " atribuído à classe com ID " << classId << ".\n";

    // TODO: Atualizar no banco de dados
}

// Define uma nota para um estudante em uma classe
void ControllerClass::setStudentGrade(int classId, int studentId, int grade) {

    if (classes.find(classId) == classes.end()) {
        std::cerr << "Erro: Classe com ID " << classId << " não encontrada.\n";
        return;
    }

    // Verifica se o estudante existe (simulando acesso ao ControllerStudent)
    StudentControllerCPP studentController;
    if (!studentController.verifyStudentId(studentId)) {
        std::cerr << "Erro: Estudante com ID " << studentId << " não encontrado.\n";
        return;
    }

    classes[classId].setGradeByStudent(studentId, grade);
    std::cout << "Nota " << grade << " atribuída ao estudante " << studentId << " na classe " << classId << ".\n";

    // TODO: Atualizar no banco de dados
}

// Atualiza a nota de um estudante
void ControllerClass::updateStudentGrade(int classId, int studentId, int newGrade) {

    if (classes.find(classId) == classes.end()) {
        std::cerr << "Erro: Classe com ID " << classId << " não encontrada.\n";
        return;
    }

    // Verifica se o estudante existe (simulando acesso ao ControllerStudent)
    StudentControllerCPP studentController;
    if (!studentController.verifyStudentId(studentId)) {
        std::cerr << "Erro: Estudante com ID " << studentId << " não encontrado.\n";
        return;
    }

    classes[classId].setGradeByStudent(studentId, newGrade);
    std::cout << "Nota do estudante " << studentId << " na classe " << classId << " atualizada para " << newGrade << ".\n";

    // TODO: Atualizar no banco de dados
}

// Remove a nota de um estudante
void ControllerClass::removeStudentGrade(int classId, int studentId) {

    if (classes.find(classId) == classes.end()) {
        std::cerr << "Erro: Classe com ID " << classId << " não encontrada.\n";
        return;
    }

    // Verifica se o estudante existe (simulando acesso ao ControllerStudent)
    StudentControllerCPP studentController;
    if (!studentController.verifyStudentId(studentId)) {
        std::cerr << "Erro: Estudante com ID " << studentId << " não encontrado.\n";
        return;
    }

    classes[classId].setGradeByStudent(studentId, -1);
    std::cout << "Nota do estudante " << studentId << " removida da classe " << classId << ".\n";

    // TODO: Atualizar no banco de dados
}

// Atribui faltas a um estudante
void ControllerClass::atributeStudentAbssences(int classId, int studentId, int numAbssences) {

    if (classes.find(classId) == classes.end()) {
        std::cerr << "Erro: Classe com ID " << classId << " não encontrada.\n";
        return;
    }

    // Verifica se o estudante existe (simulando acesso ao ControllerStudent)
    StudentControllerCPP studentController;
    if (!studentController.verifyStudentId(studentId)) {
        std::cerr << "Erro: Estudante com ID " << studentId << " não encontrado.\n";
        return;
    }

    classes[classId].setAbsencesByStudent(studentId, numAbssences);
    std::cout << numAbssences << " falta(s) atribuída(s) ao estudante " << studentId << " na classe " << classId << ".\n";

    // TODO: Atualizar no banco de dados
}

// Remove faltas de um estudante
void ControllerClass::removeStudentAbssences(int classId, int studentId, int numAbssencesToRemove) {

    if (classes.find(classId) == classes.end()) {
        std::cerr << "Erro: Classe com ID " << classId << " não encontrada.\n";
        return;
    }

    // Verifica se o estudante existe (simulando acesso ao ControllerStudent)
    StudentControllerCPP studentController;
    if (!studentController.verifyStudentId(studentId)) {
        std::cerr << "Erro: Estudante com ID " << studentId << " não encontrado.\n";
        return;
    }
    
    classes[classId].setAbsencesByStudent(studentId, classes[classId].getAbsencesByStudent(studentId) - numAbssencesToRemove);
    std::cout << numAbssencesToRemove << " falta(s) removida(s) do estudante " << studentId << " na classe " << classId << ".\n";

    // TODO: Atualizar no banco de dados
}

// Exibe informações de uma classe pelo ID
void ControllerClass::getClassbyId(int id) {
    if (classes.find(id) == classes.end()) {
        std::cerr << "Erro: Classe com ID " << id << " não encontrada.\n";
        return;
    }

    classes[id].printDetails(); // Criar método de printar detalhes da classe
}
