#include <iostream>
#include <vector>
#include "src/models/Student.h"

int main() {
    // Criando um vetor de alunos para simular uma "base de dados"
    std::vector<Student> students;

    // Adicionando alguns alunos
    students.emplace_back(1, "Alice");
    students.emplace_back(2, "Bob");

    // Incrementando faltas para o aluno com ID 1
    for (auto& student : students) {
        if (student.getId() == 1) {
            student.addAbsence();
            student.addAbsence(); // Duas faltas
        }
    }

    // Exibindo o número de faltas de todos os alunos
    for (const auto& student : students) {
        std::cout << "Aluno: " << student.getName()
                  << ", Faltas: " << student.getAbsences() << std::endl;
    }

}
