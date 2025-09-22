#include "Loot.hpp"
#include <iostream>

void Item::collectLoot()
{
    collected = true;
}

bool Item::lootCollected() 
{
    return collected;
}

void Item::printItemStats()
{
    cout << "=== Item ===\n";
    cout << "Nome: " << name << "\n";
    cout << "Modificadores: "
         << "Vida: " << mods.life_mod
         << " | Ataque: " << mods.attack_mod
         << " | Defesa: " << mods.defense_mod
         << " | Velocidade: " << mods.speed_mod
         << "\n";
    cout << "Coletado: " << (collected ? "Sim" : "Não") << "\n";
}

