#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

using namespace std;

typedef struct sCharacterStats {
    int life;
    int attack;
    int defense;
    int speed;
    
} cStats;

class Character {

public:
    string name;
    int classId;
    cStats stats;
    string className;

    Character(string n, int cId);
    Character buildCharacter();
    void printStats();

};

typedef struct sClassInfo {
    string name;
    cStats stats;
    
} ClassInfo;

#endif