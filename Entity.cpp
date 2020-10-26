#include <iostream>
#include "Entity.h"
#include "map.h"

using namespace std;
	
//Entity class constructor
Entity::Entity(int hp, int atk, int def, int x, int y, string name, char sprite){
	m_hp = hp;
	m_atk = atk;
	m_def = def;
	m_x = x;
	m_y = y;
	m_name = name;
	m_sprite = sprite;
}

//getters
int Entity::getHp() { return m_hp; }
int Entity::getAtk() { return m_atk; }
int Entity::getDef() { return m_def; }
int Entity::getX() { return m_x; }
int Entity::getY() { return m_y; }
string Entity::getName() { return m_name; }
char Entity::getSprite() { return m_sprite; }

//setters
void Entity::setHp(int hp) { m_hp = hp; }
void Entity::setAtk(int atk) { m_atk = atk; }
void Entity::setDef(int def) { m_def = def; }
void Entity::setX(int x) { m_x = x; }
void Entity::setY(int y) { m_y = y; }
void Entity::setName(string name) { m_name = name; }
void Entity::setSprite(char sprite) { m_sprite = sprite; }

//Moves the entity based on the direction sent
void Entity::move(char dir) {
	if (dir == 'w') { 
		if (getPosition(m_x, m_y-1)){
			--m_y; 
		}
		else{
			// cout << "Sorry, but that is a wall." << endl;
		}
		
	}
	else if (dir == 'a') { 
		if (getPosition(m_x-2, m_y)){
			--m_x;
			--m_x;
		}
		else{
			// cout << "Sorry, but that is a wall." << endl;
		}
	}
	else if (dir == 's') { 
		if (getPosition(m_x, m_y+1)){
			++m_y; 
		}
		else{
			// cout << "Sorry, but that is a wall." << endl;
		}
	}
	else if (dir == 'd') { 
		if (getPosition(m_x+2, m_y)){
			++m_x;
			++m_x;
		}
		else{
			// cout << "Sorry, but that is a wall." << endl;
		}
	}
	else { cout << "Invalid Key Press. Try Again." << endl; }
}