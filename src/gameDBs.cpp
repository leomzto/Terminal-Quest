#include "GameDBs.hpp"

ClassInfo searchClassInDB(int classId)
{
    sqlite3* db;
    ClassInfo c;
    c.name = "";
    c.stats = {0,0,0,0};
    
    if (sqlite3_open(CLASSES_PATH, &db) != SQLITE_OK)
    {
        cerr << "Erro ao abrir classes.db: " << sqlite3_errmsg(db) << endl;
        return c;
    }

    sqlite3_stmt* stmt;
    const char* sql = "SELECT name, life, attack, defense, speed FROM classes WHERE id = ?";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
    {
        cerr << "Erro ao preparar a query: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return c;
    }

    sqlite3_bind_int(stmt, 1, classId);

    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        c.name           = (const char*)sqlite3_column_text(stmt, 0);
        c.stats.life     = sqlite3_column_int(stmt, 1);
        c.stats.attack   = sqlite3_column_int(stmt, 2);
        c.stats.defense  = sqlite3_column_int(stmt, 3);
        c.stats.speed    = sqlite3_column_int(stmt, 4);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return c;
}
 
void printClasses()
{
    sqlite3* db;

    Stats stats = {0, 0, 0, 0};

    if (sqlite3_open(CLASSES_PATH, &db) != SQLITE_OK)
    {
        cerr << "Erro ao abrir classes.db" << sqlite3_errmsg(db) << endl;
        return;
    }

    sqlite3_stmt* stmt;
    const char* sql = "SELECT id, name, life, attack, defense, speed FROM classes";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
    {
        cerr << "Erro ao preparar a query: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return;
    }

    cout << "-= Classes Disponiveis -=" << endl;
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(stmt, 0);
        const char* name = (const char*) sqlite3_column_text(stmt, 1);
        int life = sqlite3_column_int(stmt, 2);
        int attack = sqlite3_column_int(stmt, 3);
        int defense = sqlite3_column_int(stmt, 4);
        int speed = sqlite3_column_int(stmt, 5);

        cout << "ID: " << id 
             << " | Nome: " << name
             << " | Vida: " << life
             << " | Ataque: " << attack
             << " | Defesa: " << defense
             << " | Velocidade: " << speed
             << endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}