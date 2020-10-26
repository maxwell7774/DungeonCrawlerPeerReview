#ifndef MAP_H
#define MAP_H

#include "Entity.h"

void printMap();
void updateObject(Entity entityArr[], int size);
void clearMap();
bool getPosition(int x, int y);
extern char basearr[14][35];

#endif