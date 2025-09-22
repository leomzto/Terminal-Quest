#ifndef GAMEDBS_HPP
#define GAMEDBS_HPP

#include "Character.hpp"
#include "Enemy.hpp"
#include "Loot.hpp"
#include <sqlite3.h>
#include <iostream>

#define CLASSES_PATH "database/classes.db"
#define ENEMIES_PATH "database/enemies.db"
#define ITEMS_PATH "database/items.db"
#define CHARACTERS_PATH "database/characters.db"

ClassInfo searchClassInDB(int classId);
void printClasses();

Enemy generateEnemy();

Item generateLoot();

#endif