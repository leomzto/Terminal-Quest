#include "GameMenus.hpp"
#include "GameDBs.hpp"
#include <iostream>

using namespace std;

int homeMenu()
{
    int op;

    cout << "-=- Terminal Quest -=-" << endl;
    cout << "[1]. Novo Jogo" << endl;
    cout << "[2]. Carregar Jogo" << endl;
    cout << "[3]. Voltar a area de trabalho" << endl;
    cout << "---> ";
    cin >> op;

    return op;
}

int classMenu()
{
    printClasses();

    int choice = -1;

    while(true)
    {
        cout << "Digite o id da classe: ";
        cin >> choice;

        if(cin.fail())
        {    
            cin.clear();       
            cin.ignore(1000,'\n'); 
            cout << "Entrada inválida! Tente novamente.\n";
        }
        else if (choice <= 0) 
            cout << "ID inválido! Tente novamente.\n";
        else 
            break;
    }

    return choice;
}



