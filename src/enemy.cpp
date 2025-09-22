#include "Enemy.hpp"
#include "GameMenus.hpp"
#include "GameDBs.hpp"
#include <iostream>

void Enemy::printEnemyStats()
{
    cout << "=== Inimigo ===" << endl;
    cout << "Nome: " << name << endl;
    cout << "Tipo: " << type << endl;
    cout << "Vida: " << stats.life << endl;
    cout << "Ataque: " << stats.attack << endl;
    cout << "Defesa: " << stats.defense << endl;
    cout << "Velocidade: " << stats.speed << endl;
    cout << "ID: " << enemyId << endl;
}