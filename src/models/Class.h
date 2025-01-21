#ifndef CLASS_H
#define CLASS_H

#include <string>
#include <vector>

class Class {
private:
    int id;
    std::string name;
    std::vector<int> enrolledStudents; // IDs dos alunos inscritos

public:
    Class(int id, const std::string& name);

    // Getters
    int getId() const;
    const std::string& getName() const;
    const std::vector<int>& getEnrolledStudents() const;

    // Setters
    void enrollStudent(int studentId);
};

#endif
