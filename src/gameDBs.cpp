#include "GameDBs.hpp"
#include <cstdlib>
#include <ctime>

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

    cStats stats = {0, 0, 0, 0};

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

Enemy generateEnemy()
{
    Enemy e;
    sqlite3* db;

    if (sqlite3_open(ENEMIES_PATH, &db) != SQLITE_OK)
    {
        cerr << "Erro ao abrir enemies.db: " << sqlite3_errmsg(db) << endl;
        return e;
    }

    sqlite3_stmt* countStmt;
    const char* countSQL = "SELECT COUNT(*) FROM enemies";
    int total = 0;
    if (sqlite3_prepare_v2(db, countSQL, -1, &countStmt, nullptr) == SQLITE_OK)
    {
        if (sqlite3_step(countStmt) == SQLITE_ROW)
            total = sqlite3_column_int(countStmt, 0);
    }
    sqlite3_finalize(countStmt);

    if (total == 0)
    {
        cerr << "Nenhum inimigo encontrado no banco de dados." << endl;
        sqlite3_close(db);
        return e;
    }

    int randomId = rand() % total + 1;

    sqlite3_stmt* stmt;
    const char* sql = "SELECT id, type, name, life, attack, defense, speed FROM enemies WHERE id = ?";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, randomId);
        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            e.enemyId = sqlite3_column_int(stmt, 0);
            e.type = (const char*)sqlite3_column_text(stmt, 1);
            e.name = (const char*)sqlite3_column_text(stmt, 2);
            e.stats.life = sqlite3_column_int(stmt, 3);
            e.stats.attack = sqlite3_column_int(stmt, 4);
            e.stats.defense = sqlite3_column_int(stmt, 5);
            e.stats.speed = sqlite3_column_int(stmt, 6);
        }
    }
    else
        cerr << "Erro ao preparar a query: " << sqlite3_errmsg(db) << endl;

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return e;
}

Item generateLoot()
{
    Item i;
    sqlite3* db;
    if (sqlite3_open("database/items.db", &db) != SQLITE_OK) {
        cerr << "Erro ao abrir items.db: " << sqlite3_errmsg(db) << endl;
        return i;
    }

    sqlite3_stmt* countStmt;
    const char* countSQL = "SELECT COUNT(*) FROM items";
    int total = 0;
    if (sqlite3_prepare_v2(db, countSQL, -1, &countStmt, nullptr) == SQLITE_OK) {
        if (sqlite3_step(countStmt) == SQLITE_ROW)
            total = sqlite3_column_int(countStmt, 0);
    }
    sqlite3_finalize(countStmt);

    if (total == 0) {
        cerr << "Nenhum item encontrado no banco de dados." << endl;
        sqlite3_close(db);
        return i;
    }

    int randomId = rand() % total + 1;

    sqlite3_stmt* stmt;
    const char* sql = "SELECT id, name, life_mod, attack_mod, defense_mod, speed_mod FROM items WHERE id = ?";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, randomId);
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            i.itemId = sqlite3_column_int(stmt, 0);
            i.name = (const char*)sqlite3_column_text(stmt, 1);
            i.mods.life_mod = sqlite3_column_int(stmt, 2);
            i.mods.attack_mod = sqlite3_column_int(stmt, 3);
            i.mods.defense_mod = sqlite3_column_int(stmt, 4);
            i.mods.speed_mod = sqlite3_column_int(stmt, 5);
        }
    }
    else 
        cerr << "Erro ao preparar query: " << sqlite3_errmsg(db) << endl;
    

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return i;
}

