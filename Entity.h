#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
using namespace std;

class Entity {

private:
	//private member variables
	int m_hp, m_atk, m_def, m_x, m_y;
	string m_name;
	char m_sprite;

public:
	//Constructor
	Entity(int hp, int atk, int def, int x, int y, string name, char sprite);

	//Class definitions
	int getHp();
	int getAtk();
	int getDef();
	int getX();
	int getY();
	string getName();
	char getSprite();

	void setHp(int hp);
	void setAtk(int atk);
	void setDef(int def);
	void setX(int x);
	void setY(int y);
	void setName(string name);
	void setSprite(char sprite);
	void move(char dir);
};

#endif