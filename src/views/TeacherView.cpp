#include "/home/beatrizanjos/edoo-projeto-1/src/views/TeacherView.h"

// Menu principal
void TeacherView::mainTeacherView() {

    while (true) {

        std::cout << "\nBem-vindo(a) ao gerenciamento de professores, o que você pretende fazer?\n";
        std::cout << "1. Visualizar os dados de um professor específico\n";
        std::cout << "2. Adicionar um professor ao banco de dados\n";
        std::cout << "3. Remover um professor do banco de dados\n";
        std::cout << "4. Visualizar todos os professores registrados no banco de dados\n";
        std::cout << "5. Sair do gerenciamento de professores\n";
        std::cout << "Escolha uma opção: ";

        int input;
        std::cin >> input;

        switch (input) {
            case 1:
                singleTeacherView();
                break;
            case 2:
                addTeacher();
                break;
            case 3:
                deleteTeacher();
                break;
            case 4:
                seeTeachers();
                break;
            case 5:
                std::cout << "Saindo do sistema...\n";
                return;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }
    }
}

// Visualizar os dados de um professor específico
void TeacherView::singleTeacherView() {

    while (true) {

        std::cout << "Digite o ID do professor que você gostaria de visualizar: ";
        int teacherId;
        std::cin >> teacherId;

        // Verifica se o ID do professor é válido
        if (!controller.teacherController.verifyTeacherId(teacherId)) {
            
            std::cout << "Professor com ID " << teacherId << " não encontrado.\n";
            return; // Retorna ao menu principal
        }

        // Exibe as informações básicas do professor
        Teacher* teacher = controller.teacherController.returnTeacher(teacherId);
        std::cout << "\nInformações do Professor:\n";
        std::cout << "ID: " << teacher->getId() << "\n";
        std::cout << "Nome: " << teacher->getName() << "\n";
        std::cout << "Email: " << teacher->getEmail() << "\n";

        // Perguntar se o usuário deseja ver informações adicionais (disciplinas, etc.)
        while (true) {

            std::cout << "\nO que você deseja fazer?\n";
            std::cout << "1. Ver as disciplinas do professor\n";
            std::cout << "2. Voltar ao menu principal\n";
            std::cout << "Escolha uma opção: ";

            int choice;
            std::cin >> choice;

            switch (choice) {

                case 1: {

                    std::cout << "\nDisciplinas do professor:\n";
                    std::vector<int> teacherClasses = controller.showTeacherClasses(teacherId);

                    for (int classe : teacherClasses) {
                        std::cout << "Classe: " << classe <<"\n";
                    }

                    break;
                }
                case 2:

                    return; // Volta ao menu principal
                default:

                    std::cout << "Opção inválida. Tente novamente.\n";
            }
        }

        return;
    }
}

// Adicionar um professor ao banco de dados
void TeacherView::addTeacher() {
    std::cin.ignore(); // Limpa o buffer antes de capturar strings

    std::cout << "Digite o nome do professor: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Digite o email do professor: ";
    std::string email;
    std::getline(std::cin, email);

    // Cria o professor e adiciona ao "banco de dados"
    controller.teacherController.addTeacher(currentId, name, email);

    std::cout << "Professor adicionado com sucesso! ID do professor: " << currentId << "\n";
    currentId++;
}

// Remover um professor do banco de dados
void TeacherView::deleteTeacher() {
    std::cout << "Digite o ID do professor que você gostaria de remover: ";
    
    int teacherId;
    std::cin >> teacherId;

    controller.teacherController.removeTeacher(teacherId);
}

// Visualizar todos os professores registrados
void TeacherView::seeTeachers() {

    controller.teacherController.listTeachers();
}
