#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    int id;
    std::string name;
    int absences; // Quantidade de faltas

public:
    // Nos models teremos somente os modelos, então terão somente os atributos da classe como privado e os setters and getters
    Student(int id, const std::string& name);
    int getId() const;
    std::string getName() const;
    int getAbsences() const;
    void addAbsence(); // Incrementa as faltas --> função que vai estar no controller, tudo em relação a lógica é no controller, isso foi meramente um exemplo
};

#endif
