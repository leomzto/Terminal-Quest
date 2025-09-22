#ifndef LOOT_HPP
#define LOOT_HPP

#include <string>

using namespace std;

typedef struct sModifiers {
    int life_mod;
    int attack_mod;
    int defense_mod;
    int speed_mod;

} Modifiers;

class Item {

public:
    string name;
    Modifiers mods;
    int itemId;

    Item() = default;

    static Item generateLoot();
    void printItemStats();

    void collectLoot();
    bool lootCollected();

private:
    bool collected = false;

};


#endif