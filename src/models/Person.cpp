#include "/home/beatrizanjos/edoo-projeto-1/src/models/Person.h"

// Construtor
Person::Person(const std::string &name, int id, const std::string &email)
    : name(name), id(id), email(email) {}

// Getters
std::string Person::getName() const
{
    return name;
}

int Person::getId() const
{
    return id;
}

std::string Person::getEmail() const
{
    return email;
}

// Setters
void Person::setName(const std::string &newName)
{
    name = newName;
}

void Person::setId(int newId)
{
    id = newId;
}

void Person::setEmail(const std::string &newEmail)
{
    email = newEmail;
}
