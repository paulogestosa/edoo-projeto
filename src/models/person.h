#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string name;
    int id;
    std::string email;

public:
    // Construtor
    Person() = default;
    Person(const std::string &name, int id, const std::string &email);

    // Getters
    std::string getName() const;
    int getId() const;
    std::string getEmail() const;

    // Setters
    void setName(const std::string &newName);
    void setId(int id);
    void setEmail(const std::string &newEmail);
};

#endif // PERSON_H
