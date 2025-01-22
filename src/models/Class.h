#ifndef CLASS_H
#define CLASS_H

#include <string>
#include <vector>
#include <map>
#include "Student.h"
#include "Teacher.h"

class Class {
private:
    int id;
    std::string name;
    std::vector<Student> enrolledStudents; 
    Teacher enrolledTeacher;             
    std::map<int, int> gradeByStudents;  
    std::map<int, int> absencesByStudents;

public:
    // Construtor
    Class(int id, const std::string &name);

    // Getters
    int getId() const;
    std::string getName() const;
    const std::vector<Student>& getEnrolledStudents() const;
    const Teacher& getEnrolledTeacher() const;
    int getGradeByStudent(int studentId) const;
    int getAbsencesByStudent(int studentId) const;

    // Setters
    void setName(const std::string &newName);
    void enrollStudent(const Student &student);
    void setEnrolledTeacher(const Teacher &teacher);
    void setGradeByStudent(int studentId, int grade);
    void setAbsencesByStudent(int studentId, int absences);
};

#endif // CLASS_H
