
#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h> //sql connections
int main()
{
    const char *dir = "C://pasta";
    sqlite3 *connectToDatabase(const char *databaseName);

    void closeDatabase(sqlite3 * db);
    int createDB(const char *s);
    int createStudentsTable(const char *s); // criar tabela de estudantes
    int createClassTable(const char *s);    // criar tabela de classes
    int createTeacherTable(const char *s); //cria tabelad de professores
    return 0;
#endif
}
