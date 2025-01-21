#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <vector>

class Teacher {
private:
    int id;
    std::string name;
    std::vector<int> classes; // Lista de IDs de classes que o professor gerencia

public:
    Teacher(int id, const std::string& name);

    // Getters
    int getId() const;
    const std::string& getName() const;
    const std::vector<int>& getClasses() const;

    // Setters
    void addClass(int classId);
};

#endif
