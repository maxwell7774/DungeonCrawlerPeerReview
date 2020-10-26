//Dungeon Crawler
//Programmed by, Adam Maxwell, Bryce Mecham
//October 5, 2020
/*
Code Quality (including user interface):	
	We have code quality by not having useless code, trying to implement code we use a lot by putting it in functions, 
	implementing header guards and we put comments explaining our code. We have a simple interface that tells the goal of the game, 
	gets input when needed, and displays/ updates the map for visuals.

Logical use of multiple files
	We seperated our code into 8 files. We have a file for the driver (Main.cpp), files for map functions (Map.cpp & map.h),
	files for the fight sequence (Fight.cpp & Fight.h), files for entity functions (Entity & Entity.h), 
	and a file for item creation (item.h).

Overall Functionality (Could I break it)
	We implemented checks to verify that the user inputs correct characters for movement and fighting. 
	We also check to make sure that a move is valid, and won't go out of the map, or through a wall.

Logical use of enum type
	We use an enum to specify the type of item. We can specify what it is and apply effects to the user based on the enum type. 
	The enum is found in our Item.h file.

Proper use of extern variable
	We use extern within out Map.h file on our base map. It allows items to directly be put on the map and be taken off the map.

Proper use of static variable
	We use static within out Map.h file on our actual map. We don't make copies of this map, so it helps us make sure that 
	the map is the same anywhere within our program.

Logical use of a struct
	We use a struct to create our items. It can be found in our Item.h file.
	It makes it easy combined with our enum to create specific items and place them on our map.

Logical use of random number generator
	We use a random number generator a few times within our program. We use it to randomly move the enemies, 
	to pick what the enemies do in the fight sequence, and to help vary the attack damage. 
	These can be found in Main.cpp, and Fight.cpp.
*/
#include <iostream>
#include "map.h"
#include "Fight.h"
#include "Item.h"
#include <stdlib.h>
#include <time.h>

using namespace std;
void win();
void lose();
// Driver of our game. It is the main loop that controls our game, sets up entities, and sets up items.
int main() {
	Entity h1 = Entity(15, 5, 10, 14, 4, "Bob", 'O');
	Entity e1 = Entity(10, 2, 1, 20, 1, "Enemy 1", 'E');
	Entity e2 = Entity(10, 2, 1, 6, 2, "Enemy 2", 'E');
	Entity e3 = Entity(10, 2, 1, 30, 3, "Enemy 3", 'E');
	Entity e4 = Entity(10, 2, 1, 18, 10, "Enemy 4", 'E');
	Entity e5 = Entity(10, 2, 1, 8, 7, "Enemy 5", 'E');

	Entity charArr[6]{ h1, e1, e2, e3, e4, e5 };
	cout << h1.getHp() << endl;

	Item i1;
	Item i2;
	Item i3;

	i1.itemType = smallHealth;
	i1.x = 32;
	i1.y = 1;
	i2.itemType = key;
	i2.x = 28;
	i2.y = 11;
	i3.itemType = bigHealth;
	i3.x = 8;
	i3.y = 9;
	srand(time(NULL));
	// Puts the items in the map.
	Item itemArr[3]{i1,i2,i3};
	for(int item = 0; item < 3; item++){
		basearr[ itemArr[item].y ] [itemArr[item].x ] = itemArr[item].sprite;
	}
	cout << "Welcome to our Dungeon Crawler!" << endl;
	updateObject(charArr, 6);
// While the hero is above 0 hp it will go through the array of entities and move for them using random movement.
	while(charArr[0].getHp() > 0 && itemArr[1].picked_up != true){
		for(int item = 0; item < 3; item++){
		basearr[ itemArr[item].y ] [itemArr[item].x ] = itemArr[item].sprite;
		}
		cout << "Please use WASD to move!" << endl;
		cout << "The goal is to find the key." << endl;
		cout << "I's are items, E's are enemies, and O is you." << endl;
		cout << "Your HP: " << charArr[0].getHp() << endl;
		for(int characters = 0; characters < 6; characters++){
			if(charArr[characters].getName() == h1.getName()){
				char direction;
				cout << "User Entered: ";
				cin >> direction;
				charArr[characters].move(direction);
			}
			else{
				char direction = rand() % 5 + 1;
				switch (direction){
					case 1:
						charArr[characters].move('w');
						break;

					case 2:
						charArr[characters].move('a');
						break;

					case 3:
						charArr[characters].move('s');
						break;

					case 4:
						charArr[characters].move('d');
						break;

					case 5:
						break;
				}	
			}
		}
		// Checks to see if the player is in the same place as an enemy.
		for(int characters = 1; characters < 6; characters++){ 
			if(charArr[0].getX() == charArr[characters].getX() && charArr[0].getY() == charArr[characters].getY()){
				fight(charArr[0], charArr[characters]);
			}
		}
		// Updates the map, which will update positions of entities, clear the screen, and print the map.
		updateObject(charArr, 6);
		// Checks if the player is on the same location as any of the items
		for(int items = 0; items < 3; items++){
			if(charArr[0].getX() == itemArr[items].x && charArr[0].getY() == itemArr[items].y){
				if(itemArr[items].picked_up == false){
						if (itemArr[items].itemType == key){
						win();
						itemArr[1].picked_up = true;
						itemArr[items].sprite = ' ';
					}
					if (itemArr[items].itemType == smallHealth){
						charArr[0].setHp(charArr[0].getHp()+2);
						if(charArr[0].getHp() > 15){
							charArr[0].setHp(15);
						}
						itemArr[items].picked_up = true;
						itemArr[items].sprite = ' ';
						cout << "You picked up a small health potion." << endl;
					}
					if (itemArr[items].itemType == mediumHealth){
						charArr[0].setHp(charArr[0].getHp()+6);
						if(charArr[0].getHp() > 15){
							charArr[0].setHp(15);
						}
						itemArr[items].picked_up = true;
						itemArr[items].sprite = ' ';
						cout << "You picked up a medium health potion." << endl;
					}
					if (itemArr[items].itemType == bigHealth){
						charArr[0].setHp(charArr[0].getHp()+10);
						if(charArr[0].getHp() > 15){
							charArr[0].setHp(15);
						}
						itemArr[items].picked_up = true;
						itemArr[items].sprite = ' ';
						cout << "You picked up a big health potion." << endl;
					}
				}
				
			}
		
		}
		// If an enemy hits 0 hp it will be removed from the map.
		for(int characters = 1; characters < 6; characters++){
			if(charArr[characters].getHp() <= 0){
				charArr[characters].setSprite(' ');
			}
		} 
		if(charArr[0].getHp() <= 0){
			lose();
		}
	}
}

// If the player gets to the key this prints!
void win(){
	system("CLS");
	cout << "Congratulations!" <<endl;
	cout << "You were able to find the key and escape." << endl;
}

// If the player drops to below 0 hp, they will lose and this will print!
void lose(){
	system("CLS");
	cout << "Sorry, but you lost..." << endl;
}