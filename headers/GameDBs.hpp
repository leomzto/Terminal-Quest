#ifndef GAMEDBS_HPP
#define GAMEDBS_HPP

#include "Character.hpp"
#include <sqlite3.h>
#include <iostream>

#define CLASSES_PATH "database/classes"
#define ENEMIES_PATH "database/enemies"
#define ITEMS_PATH "database/items"

ClassInfo searchClassInDB(int classId);
 
void printClasses();

#endif