
#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h> //sql connections

sqlite3 *connectToDatabase(const char *databaseName);

void closeDatabase(sqlite3 *db);

#endif
