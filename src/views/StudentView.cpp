#include "StudentView.h"

// Menu principal
void StudentView::mainStudentView() {

    while (true) {

        std::cout << "\nBem vindo(a) ao gerenciamento de alunos, o que você pretende fazer?\n";
        std::cout << "1. Visualizar os dados de um aluno específico\n";
        std::cout << "2. Adicionar um estudante ao banco de dados\n";
        std::cout << "3. Remover um estudante do banco de dados\n";
        std::cout << "4. Visualizar todos os estudantes registrados no banco de dados\n";
        std::cout << "5. Sair do gerenciamento de alunos\n";
        std::cout << "Escolha uma opção: ";

        int input;
        std::cin >> input;

        switch (input) {
            case 1:
                singleStudentView();
                break;
            case 2:
                addStudent();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                seeStudents();
                break;
            case 5:
                std::cout << "Saindo do sistema...\n";
                return;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }
    }
}

// Visualizar os dados de um aluno específico
void StudentView::singleStudentView() {

    while (true) {

        std::cout << "Digite o ID do aluno que você gostaria de visualizar: ";
        int studentId;
        std::cin >> studentId;

        // Verifica se o ID do aluno é válido
        if (!controller.studentController.verifyStudentId(studentId)) {
            
            std::cout << "Aluno com ID " << studentId << " não encontrado.\n";
            return; // Retorna ao menu principal
        }

        // Exibe as informações básicas do aluno
        Student* student = controller.studentController.returnStudent(studentId);
        std::cout << "\nInformações do Aluno:\n";
        std::cout << "ID: " << student->getId() << "\n";
        std::cout << "Nome: " << student->getName() << "\n";
        std::cout << "Email: " << student->getEmail() << "\n";
        std::cout << "Endereço: " << student->getAddressName() << "\n";

        // Perguntar se o usuário deseja ver informações adicionais (notas, faltas etc.)
        while (true) {

            std::cout << "\nO que você deseja fazer?\n";
            std::cout << "1. Ver as notas do aluno\n";
            std::cout << "2. Ver as faltas do aluno\n";
            std::cout << "3. Voltar ao menu principal\n";
            std::cout << "Escolha uma opção: ";

            int choice;
            std::cin >> choice;

            switch (choice) {

                case 1: {

                    std::cout << "\nNotas do aluno:\n";
                    std::vector<int> studentClasses = controller.showStudentClasses(studentId);

                    for (int classe : studentClasses) {
                        controller.showStudentGrade(classe, studentId);
                    }

                    break;
                }
                case 2: {

                    std::cout << "\nFaltas do aluno:\n";
                    std::vector<int> studentClasses = controller.showStudentClasses(studentId);

                    for (int classe : studentClasses) {
                        controller.showStudentAbsences(classe, studentId); 
                    }

                    break;
                }
                case 3:

                    return; // Volta ao menu principal
                default:

                    std::cout << "Opção inválida. Tente novamente.\n";
            }
        }

        return;
    }
}


// Adicionar um estudante ao banco de dados
void StudentView::addStudent() {

    std::cout << "Digite o nome do estudante: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Digite o email do estudante: ";
    std::string email;
    std::getline(std::cin, email);


    std::cout << "Digite o endereço do estudante: ";
    std::string address;
    std::getline(std::cin, address);

    // Cria o estudante e adiciona ao "banco de dados"
    controller.studentController.addStudent(currentId, name, email, address);

    std::cout << "Estudante adicionado com sucesso! ID do estudante: " << currentId << "\n";
    currentId++;
}

// Remover um estudante do banco de dados
void StudentView::deleteStudent() {
    std::cout << "Digite o ID do aluno que você gostaria de remover: ";
    
    int studentId;
    std::cin >> studentId;

    if (controller.studentController.deleteStudent(studentId)) {
        std::cout << "Estudante com ID " << studentId << " foi removido com sucesso.\n";
    } else {
        std::cout << "Aluno com ID " << studentId << " não encontrado.\n";
    }
}

// Visualizar todos os estudantes registrados
void StudentView::seeStudents() {

    controller.studentController.listStudents();
}
