#include "database.h"
#include <stdio.h>
#include <sqlite3.h>
#include <string>
static int createDB(const char *s)
{
    sqlite3 *DB;
    int exit = 0;

    exit = sqlite3_open(s, &DB);
    sqlite3_close(DB);
    return 0;
}

sqlite3 *connectToDatabase(const char *databaseName)
{
    sqlite3 *db;
    int rc = sqlite3_open(databaseName, &db);

    if (rc)
    {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        return nullptr;
    }
    else
    {
        fprintf(stdout, "Database successfully opened!\n");
        return db;
    }
}

void closeDatabase(sqlite3 *db)
{
    if (db)
    {
        sqlite3_close(db);
        fprintf(stdout, "Database closed!\n");
    }
}

// isso vai ser usado no arquivo principal