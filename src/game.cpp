#include "Character.hpp"
#include "GameMenus.hpp"
#include "GameDBs.hpp"
#include <iostream>

using namespace std;

int main()
{
    int op = homeMenu();

    if(op == 1)
    { 
        Character jogador = jogador.buildCharacter();
        cout << "\n=== Personagem Criado ===\n";
        jogador.printStats();
    }
    else if(op == 2)
        cout << "Carregar jogo ainda não implementado.\n";
    else
        cout << "Saindo do jogo...\n";

    return 0;
}
