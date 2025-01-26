#include "database.h"
#include <stdio.h>

sqlite3* connectToDatabase(const char* databaseName) {
    sqlite3* db;
    int rc = sqlite3_open(databaseName, &db);

    if (rc) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        return nullptr;
    } else {
        fprintf(stdout, "Database successfully opened!\n");
        return db;
    }
}

void closeDatabase(sqlite3* db) {
    if (db) {
        sqlite3_close(db);
        fprintf(stdout, "Database closed!\n");
    }
}
