#include "ControllerClass.h"

// Confere se a classe está dentro do banco de dados
bool ControllerClass::checkClass(int classId) {

    if (classes.find(classId) == classes.end()) {

        std::cerr << "Erro: Classe com ID " << classId << " não encontrada.\n";
        return false;
    }

    return true;
}

// Confere se o estudante está dentro do banco de dados
bool ControllerClass::checkStudent(int studentId) {

    if (!studentController.verifyStudentId(studentId)) {

        std::cerr << "Erro: Estudante com ID " << studentId << " não encontrado.\n";
        return false;
    }

    return true;
}

// Confere se o estudante está dentro do banco de dados
bool ControllerClass::checkTeacher(int teacherId) {

    if (!teacherController.verifyTeacherId(teacherId)) {

        std::cerr << "Erro: professor com ID " << teacherId << " não encontrado.\n";
        return false;
    }

    return true;
}


// Adiciona uma nova classe
void ControllerClass::addClass(const std::string &name) {

    int Id = classes.size() + 1; // Usa o tamanho atual do mapa para gerar o ID
    classes[Id] = Class(Id, name);
    std::cout << "Classe '" << name << "' adicionada com ID " << Id << ".\n";

    // TODO: Adicionar lógica para salvar no banco de dados
}

// Adiciona um estudante a uma classe pelo ID
void ControllerClass::addStudentToClass(int classId, int studentId) {

    if (!checkClass(classId)) {
        return;
    }

    if (!checkStudent(studentId)) {
        return;
    }

    // Adiciona o estudante à classe
    classes[classId].enrollStudent(studentId);

    // Adiciona a classe dentro da aba do estudante
    Student* studentObj = studentController.returnStudent(studentId);
    studentObj->updateClassesJoined(classId);

    std::cout << "Estudante com ID " << studentId << " adicionado à classe com ID " << classId << ".\n";

    // TODO: Atualizar no banco de dados
}

// Remove um estudante de uma classe
void ControllerClass::removeStudentOfClass(int  classId, int studentId) {

    if (!checkClass(classId)) {
        return;
    }

    if (!checkStudent(studentId)) {
        return;
    }

    //Exclui o estudante da classe
    classes[classId].removeStudent(studentId);

    //Adicionar uma parte para excluir a classe de dentro do estudante classe -> Student

}

// Atribui um professor a uma classe
void ControllerClass::assignTeacher(int classId, int teacherId) {

    if (!checkClass(classId)) {
        return;
    }

    if (!checkTeacher(teacherId)) {
        return;
    }

    // Adiciona o professor a classe
    classes[classId].setEnrolledTeacher(teacherId);
    std::cout << "Professor com ID " << teacherId << " atribuído à classe com ID " << classId << ".\n";

    //Adicionar no model do professor 

    // TODO: Atualizar no banco de dados
}

// Define uma nota para um estudante em uma classe --> pode atualizar
void ControllerClass::setStudentGrade(int classId, int studentId, int grade) {

    if (!checkClass(classId)) {
        return;
    }

    if (!checkStudent(studentId)) {
        return;
    }

    classes[classId].setGradeByStudent(studentId, grade);
    std::cout << "Nota " << grade << " atribuída ao estudante " << studentId << " na classe " << classId << ".\n";

    // TODO: Atualizar no banco de dados
}

// Remove a nota de um estudante
void ControllerClass::removeStudentGrade(int classId, int studentId) {

    if (!checkClass(classId)) {
        return;
    }

    if (!checkStudent(studentId)) {
        return;
    }

    classes[classId].setGradeByStudent(studentId, -1);
    std::cout << "Nota do estudante " << studentId << " removida da classe " << classId << ".\n";

    // TODO: Atualizar no banco de dados
}

// Atribui faltas a um estudante
void ControllerClass::atributeStudentAbssences(int classId, int studentId, int numAbssences) {

    if (!checkClass(classId)) {
        return;
    }

    if (!checkStudent(studentId)) {
        return;
    }

    classes[classId].setAbsencesByStudent(studentId, numAbssences);
    std::cout << numAbssences << " falta(s) atribuída(s) ao estudante " << studentId << " na classe " << classId << ".\n";

    // TODO: Atualizar no banco de dados
}

// Remove faltas de um estudante
void ControllerClass::removeStudentAbssences(int classId, int studentId, int numAbssencesToRemove) {

    if (!checkClass(classId)) {
        return;
    }

    if (!checkStudent(studentId)) {
        return;
    }
    
    classes[classId].setAbsencesByStudent(studentId, classes[classId].getAbsencesByStudent(studentId) - numAbssencesToRemove);
    std::cout << numAbssencesToRemove << " falta(s) removida(s) do estudante " << studentId << " na classe " << classId << ".\n";

    // TODO: Atualizar no banco de dados
}

// Exibe as faltas de todos os alunos em uma classe
void ControllerClass::showClassAbsences(int classId) {
    if (classes.find(classId) == classes.end()) {
        std::cerr << "Erro: Classe com ID " << classId << " não encontrada.\n";
        return;
    }

    std::cout << "Faltas dos alunos na classe com ID " << classId << ":\n";

    // Obtém os alunos matriculados e exibe as faltas
    const auto& students = classes[classId].getEnrolledStudents();
    if (students.empty()) {
        std::cout << "Nenhum estudante está matriculado nesta classe.\n";
        return;
    }

    for (int studentId : students) {
        int absences = classes[classId].getAbsencesByStudent(studentId);
        std::cout << "Estudante ID: " << studentId << ", Faltas: " << absences << "\n";
    }
}

// Exibe as faltas de um estudante específico em uma classe
void ControllerClass::showStudentAbsences(int classId, int studentId) {
    if (classes.find(classId) == classes.end()) {
        std::cerr << "Erro: Classe com ID " << classId << " não encontrada.\n";
        return;
    }

    if (!studentController.verifyStudentId(studentId)) {
        std::cerr << "Erro: Estudante com ID " << studentId << " não encontrado.\n";
        return;
    }

    int absences = classes[classId].getAbsencesByStudent(studentId);
    std::cout << "Estudante ID: " << studentId << " tem " << absences << " faltas na classe com ID " << classId << ".\n";
}

// Exibe as notas de todos os alunos em uma classe
void ControllerClass::showClassGrades(int classId) {
    if (classes.find(classId) == classes.end()) {
        std::cerr << "Erro: Classe com ID " << classId << " não encontrada.\n";
        return;
    }

    std::cout << "Notas dos alunos na classe com ID " << classId << ":\n";

    // Obtém os alunos matriculados e exibe as notas
    const auto& students = classes[classId].getEnrolledStudents();
    if (students.empty()) {
        std::cout << "Nenhum estudante está matriculado nesta classe.\n";
        return;
    }

    for (int studentId : students) {
        int grade = classes[classId].getGradeByStudent(studentId);
        std::cout << "Estudante ID: " << studentId << ", Nota: " << grade << "\n";
    }
}

// Exibe a nota de um estudante específico em uma classe
void ControllerClass::showStudentGrade(int classId, int studentId) {
    if (classes.find(classId) == classes.end()) {
        std::cerr << "Erro: Classe com ID " << classId << " não encontrada.\n";
        return;
    }

    if (!studentController.verifyStudentId(studentId)) {
        std::cerr << "Erro: Estudante com ID " << studentId << " não encontrado.\n";
        return;
    }

    int grade = classes[classId].getGradeByStudent(studentId);
    
    std::cout << "Estudante ID: " << studentId << " tem nota " << grade << " na classe com ID " << classId << ".\n";

}

const std::vector<int> ControllerClass::showStudentClasses(int studentId) {
    
    Student* studentObj = studentController.returnStudent(studentId);

    return studentObj->getClassesJoined();
}

const std::vector<int> ControllerClass::showTeacherClasses(int teacherId) {

    Teacher* teacherObj = teacherController.returnTeacher(teacherId);

    return teacherObj->getClasses();
}

void ControllerClass::showAllClasses() {
    // Verifica se há classes registradas
    if (classes.empty()) {
        std::cout << "Nenhuma classe registrada.\n";
        return;
    }

    // Itera sobre o mapa e exibe as informações das classes
    std::cout << "\n----- Todas as Classes -----\n";
    for (const auto& entry : classes) {
        const Class& classe = entry.second;  // Acessa a classe
        std::cout << "ID da Classe: " << classe.getId() << "\n";
        std::cout << "Nome da Classe: " << classe.getName() << "\n";

        // Exibe o número de alunos matriculados
        std::cout << "Número de Alunos Matriculados: " << classe.getEnrolledStudents().size() << "\n";

        // Aqui pode adicionar mais informações à demanda
        std::cout << "---------------------------\n";
    }
}
