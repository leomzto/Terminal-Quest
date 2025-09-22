#include "Character.hpp"
#include "GameMenus.hpp"
#include "GameDBs.hpp"
#include <iostream>


Character::Character(string n, int cId) : name(n), classId(cId) {};

void Character::printStats()
{
    cout << "Nome: " << name << endl;
    cout << "Classe: " << className << endl;
    cout << "Vida: " << stats.life << endl;
    cout << "Ataque: " << stats.attack << endl;
    cout << "Defesa: " << stats.defense << endl;
    cout << "Velocidade: " << stats.speed << endl;
    cout << "Id: " << classId << endl;
}

Character Character::buildCharacter()
{
    string pName;
    cout << "Nome do personagem: ";
    cin >> pName;

    int pClass = classMenu();

    Character p(pName, pClass);

    ClassInfo info = searchClassInDB(pClass);
    p.stats = info.stats;
    p.className = info.name;

    return p;
}