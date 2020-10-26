#include <iostream>
#include "Entity.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

/*
Send two entities (the player and an Enemy) and the person chooses an attack or defend or something...
then the enemy goes... repeat until one or the other is dead... yee
*/

void fight(Entity &hero, Entity &enemy){
    srand(time(NULL));
    while(hero.getHp() > 0 && enemy.getHp() > 0){
        // Players turn
        
        char pl_choice = 0;
        cout << "What would you like to do? (Please enter the number.) \n" << "1. Attack!\n" << "2. Defend" << endl;
        

        while (pl_choice != '1' && pl_choice != '2'){
            cin >> pl_choice;

            if(pl_choice != '1' && pl_choice != '2' ){
                cout << "Please enter a 1 or a 2." << endl;
            }
        }
        system("CLS");
        int en_choice = rand() % 2;

        if(pl_choice == '1' && en_choice == 1){
            cout << endl <<"You and the enemy attacked!" << endl << endl;
            hero.setHp(hero.getHp()-enemy.getAtk()-rand()%3);
            enemy.setHp(enemy.getHp()-hero.getAtk()-rand()%3);
        }
        if(pl_choice == '1' && en_choice == 0){
            cout << endl << "You attacked, but the enemy defended!" << endl << endl;
        }
        if(pl_choice == '0' && en_choice == 1){
            cout << endl << "The enemy attacked, but you defended!" << endl << endl;
        }
        if(pl_choice == '0' && en_choice == 0){
            cout << endl << "You and the enemy defended!" << endl << endl;
        }

        cout << endl << "Player Hp: " << hero.getHp() << endl;
        cout << "Enemy Hp: " << enemy.getHp() << endl << endl;

        
    }
}