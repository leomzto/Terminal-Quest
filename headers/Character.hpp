#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

using namespace std;

typedef struct sStats {
    int life;
    int attack;
    int defense;
    int speed;
    
} Stats;

class Character {

public:
    string name;
    int classId;
    Stats stats;
    string className;

    Character(string n, int cId);
    Character buildCharacter();
    void printStats();

};

typedef struct sClassInfo {
    std::string name;
    Stats stats;
} ClassInfo;

#endif