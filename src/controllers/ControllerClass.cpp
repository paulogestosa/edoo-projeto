#include "ControllerClass.h"
#include "ControllerStudent.h"

// Adiciona uma nova classe
void ControllerClass::addClass(const std::string &name) {
    
    int Id = classes.size() + 1; // Por enquanto vamos usar o classes.size para saber quantas classes tem, no entanto depois vamos botar para ver todas as classes do db + 1
    classes[Id] = Class(Id, name);
    std::cout << "Classe '" << name << "' adicionada com ID " << Id << ".\n";

    // Aqui entra o CRUD 
    // Cria a classe no db

}

// Adiciona um estudante a uma classe pelo ID
void ControllerClass::addStudentToClass(int classId, int studentId) {
    
    if (classes[classId] == NULL) { // Conferir a existência da classe dentro do db, por enquanto o classes

        return -1; 
    }
    else if (students[studentId] == NULL) // Conferir a existência do estudante dentro do db, por enquanto usar o students
    { // Controller class não tem acesso ao controller do students, então tem que usar uma função de verificação intermediária 
        return -1;
    }

    classes[classId].enrollStudent(studentId); // A função deveria receber um objeto de student, mas é melhor receber o Id, corrigir

}

// Atribui um professor a uma classe
void ControllerClass::assignTeacher(int classId, int teacherId) {
    
}

// Define uma nota para um estudante em uma classe
void ControllerClass::setStudentGrade(int classId, int studentId, int grade) {

}

// Atualiza a nota de um estudante
void ControllerClass::updateStudentGrade(int classId, int studentId, int newGrade) {

}

// Remove a nota de um estudante
void ControllerClass::removeStudentGrade(int classId, int studentId) {

}

// Exibe informações de uma classe pelo ID
void ControllerClass::getClassbyId(int id) {

}
