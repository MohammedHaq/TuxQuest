/**
 *
 *@file inventory.h
 *@author haqm8
 *@date August 7 2021
 *@brief the header file initializes the invNode struct as well as initilizes the default goblin and orc loot
 *
 */

struct invNode {
	char* name;
	char* description;
	int value;
	struct invNode *next;
} 
goblin_loot = {"Necklace Of Teeth", "A necklace made of human teeth.   Perhaps this goblin was a dentist.", 6, NULL},
orc_loot = {"Orcish Romance Novel", "Ooooo... Steamy!", 13, NULL};

typedef struct invNode InvNode;

void addItem (int which, InvNode **inventory); // Question 3 Part I
int sellItem(int number, InvNode **inventory); // Question 3 Part II
void displayInventory(InvNode *inventory, int number);
