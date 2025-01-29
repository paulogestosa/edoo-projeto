#include "ClassView.h"
#include <iostream>

void ClassView::mainClassView() {
    while (true) {
        std::cout << "\n----- Gerenciamento de Turmas -----\n";
        std::cout << "1. Adicionar Turma\n";
        std::cout << "2. Adicionar Professor à Turma\n";
        std::cout << "3. Adicionar Estudante à Turma\n";
        std::cout << "4. Remover Estudante da Turma\n";
        std::cout << "5. Ver Faltas dos Estudantes de uma turma específica\n";
        std::cout << "6. Ver Notas dos Estudantes de uma turma específica\n";
        std::cout << "7. Ver Todas as Turmas\n";
        std::cout << "8. Sair\n";
        std::cout << "Escolha uma opção: ";

        int option;
        std::cin >> option;

        switch (option) {
            case 1:
                addClass();
                break;
            case 2:
                addTeacherToClass();
                break;
            case 3:
                addStudentToClass();
                break;
            case 4:
                removeStudentOfClass();
                break;
            case 5:
                seeStudentsAbsences();
                break;
            case 6:
                seeStudentsGrades();
                break;
            case 7:
                seeClasses();
                break;
            case 8:
                std::cout << "Saindo do sistema...\n";
                return;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }
    }
}

void ClassView::addClass() {
    std::string className;
    std::cout << "Digite o nome da turma: ";
    std::cin >> className;
    controller.addClass(className);
    std::cout << "Turma adicionada com sucesso!\n";
}

void ClassView::addTeacherToClass() {
    int classId, teacherId;
    std::cout << "Digite o ID da turma: ";
    std::cin >> classId;
    std::cout << "Digite o ID do professor: ";
    std::cin >> teacherId;
    controller.assignTeacher(classId, teacherId);
    std::cout << "Professor adicionado à turma!\n";
}

void ClassView::addStudentToClass() {
    int classId, studentId;
    std::cout << "Digite o ID da turma: ";
    std::cin >> classId;
    std::cout << "Digite o ID do estudante: ";
    std::cin >> studentId;
    controller.addStudentToClass(classId, studentId);
    std::cout << "Estudante adicionado à turma!\n";
}

void ClassView::removeStudentOfClass() {
    int classId, studentId;
    std::cout << "Digite o ID da turma: ";
    std::cin >> classId;
    std::cout << "Digite o ID do estudante: ";
    std::cin >> studentId;
    controller.removeStudentOfClass(classId, studentId);
    std::cout << "Estudante removido da turma!\n";
}

void ClassView::seeStudentsAbsences() {
    int classId;
    std::cout << "Digite o ID da turma: ";
    std::cin >> classId;
    controller.showClassAbsences(classId);
}

void ClassView::seeStudentsGrades() {
    int classId;
    std::cout << "Digite o ID da turma: ";
    std::cin >> classId;
    controller.showClassGrades(classId);
}

void ClassView::setStudentAbsence() {
    // Solicitar o ID da classe, o ID do aluno e o número de faltas
    int classId, studentId, numAbsence;

    std::cout << "Digite o ID da classe: ";
    std::cin >> classId;

    std::cout << "Digite o ID do aluno: ";
    std::cin >> studentId;

    std::cout << "Digite o número de faltas: ";
    std::cin >> numAbsence;

    // Usar o controlador para atribuir as faltas ao aluno
    controller.atributeStudentAbssences(classId, studentId, numAbsence);

    std::cout << "Faltas do aluno " << studentId << " na classe " << classId << " atualizadas com sucesso!\n";
}

void ClassView::setStudentGradeView() {
    // Solicitar o ID da classe, o ID do aluno e a nota
    int classId, studentId, grade;

    std::cout << "Digite o ID da classe: ";
    std::cin >> classId;

    std::cout << "Digite o ID do aluno: ";
    std::cin >> studentId;

    std::cout << "Digite a nota do aluno: ";
    std::cin >> grade;

    // Usar o controlador para definir a nota do aluno
    controller.setStudentGrade(classId, studentId, grade);

    std::cout << "Nota do aluno " << studentId << " na classe " << classId << " atualizada com sucesso!\n";
}

void ClassView::seeClasses() {
    controller.showAllClasses(); 
}
