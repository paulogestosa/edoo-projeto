#include "MainView.h"
#include <iostream>

void MainView::mainScreen() {
    int choice;
    while (true) {
        std::cout << "====================================\n";
        std::cout << "Bem-vindo ao sistema de gerenciamento\n";
        std::cout << "Escolha uma opção:\n";
        std::cout << "1. Alunos\n";
        std::cout << "2. Turmas\n";
        std::cout << "3. Professores\n";
        std::cout << "4. Sair\n";
        std::cout << "====================================\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                studentScreen();  // Chama a tela de alunos
                break;
            case 2:
                classeScreen();   // Chama a tela de turmas
                break;
            case 3:
                teacherScreen();  // Chama a tela de professores
                break;
            case 4:
                std::cout << "Saindo...\n";
                return;  // Sai do programa
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    }
}

void MainView::classeScreen() {
    classView.mainClassView();
}

void MainView::studentScreen() {
    studentView.mainStudentView();
}

void MainView::teacherScreen() {
    teacherView.mainTeacherView();
}
