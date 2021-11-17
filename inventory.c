#include"inventory.h"
#include<stdlib.h>
#include<string.h>

void addItem (int which, InvNode **inventory){
  struct invNode* tempNode = (struct invNode*) malloc(sizeof(struct invNode));
  InvNode loot;
  if ((*inventory) == NULL) {
    (*inventory)->next = NULL;
    if (which == 1) {
      loot = goblin_loot;
      (*inventory)->name = loot.name;
      (*inventory)->description = loot.description;
      (*inventory)->value = loot.value;
    }
    else if (which == 2){
      loot = orc_loot;
      (*inventory)->name = loot.name;
      (*inventory)->description = loot.description;
      (*inventory)->value = loot.value;
    }
  }
  else{
    if (which == 1){
      loot = goblin_loot;
      tempNode->name = loot.name;
      tempNode->description = loot.description;
      tempNode->value = loot.value;
    }
    else if (which == 2) {
      loot = goblin_loot;
      tempNode->name = loot.name;
      tempNode->description = loot.description;
      tempNode->value = loot.value;
    }
    tempNode->next = (*inventory);
    (*inventory) = tempNode;
  }
}

int sellItem(int number, InvNode **inventory){
  if ((*inventory) == NULL) {
    return 0;
  }

  InvNode lootgoblin = goblin_loot;
  InvNode lootorc = orc_loot;
  struct invNode* tempNode = (*inventory);
  
  if (number == 0){
    if ((*inventory)->value == lootgoblin.value){
      (*inventory) = tempNode->next;
      free(tempNode);
      return lootgoblin.value;
    }
    else if ((*inventory)->value == lootorc.value){
      (*inventory) = tempNode->next;
      free(tempNode);
      return lootorc.value;
    } 
  }
  int i = 0;
  while (i != number-1 && tempNode != NULL){
    tempNode = tempNode->next;
  }
  struct invNode* nextNode = tempNode->next->next;
  if(tempNode->next->value == lootgoblin.value){
    free(tempNode->next);
    tempNode->next = nextNode;
    return lootgoblin.value;
  }
  else if (tempNode->next->value == lootorc.value){
    free(tempNode->next);
    tempNode->next = nextNode;
    return lootorc.value;
  }
  return 0;
  
}


/**
 *
 *@param *inventory A single pointer to the player's inventory is given as a means to check its current items
 *@param number A number is given as a parameter to determine the number corresponding to the number of items
 *@return the function takes the form of a void to only print the inventory of the player
 *
 */

void displayInventory(InvNode *inventory, int number){
	if (inventory == NULL) {
		printf("*** Inventory Empty ***\n");
		return;
	}
	printf("╔══╤══════════════════════╤════════╗\n");
	printf("║%2.2d|%22.22s│%2d gold ║\n", number, inventory->name, inventory->value);
	printf("╟──┴──────────────────────┴────────╢\n");
	int length = strlen(inventory->description);
	int i = 0;
	while (i < length) {
		printf("║%34.34s║\n", (inventory->description + i));
		i += 34;
	}
	printf("╚══════════════════════════════════╝\n");
	if (inventory->next != NULL) {
		displayInventory(inventory->next, number + 1);
	}	
}
