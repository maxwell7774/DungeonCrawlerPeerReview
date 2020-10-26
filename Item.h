#ifndef ITEM_H
#define ITEM_H

using namespace std;

//Use of enum right here
enum ItemType { key, smallHealth, mediumHealth, bigHealth };

//Use of a struct right here
struct Item {

	ItemType itemType = smallHealth;
	char sprite = 'I';
	int x = 0;
	int y = 0;
	bool picked_up = false;
};

#endif