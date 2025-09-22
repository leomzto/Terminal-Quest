#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>

using namespace std;

typedef struct sEnemyStats {
    int life;
    int attack;
    int defense;
    int speed;
    
} eStats;

class Enemy {

public:
    string name;
    string type;
    int enemyId;
    eStats stats;

    Enemy() = default;

    static Enemy generateEnemy();
    void printEnemyStats();

    void takeDamage(int dmg);
    bool isDead();
};

#endif