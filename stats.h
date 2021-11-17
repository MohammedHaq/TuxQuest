#ifndef STATS_HEADER
#define STATS_HEADER 1
#include"inventory.c"

/**
 * \brief the struct creates stats for an entity in the game including its health, name. and XP
 *
 *The struct creates a pointer for the entity's name
 *uses an integer value for the entity's Max HP, HP, XP, ATK, and DEF
 *
 */

struct statblock {
  char *NAME; /**< initializes a pointer to a char value which stores an entity's name */ 
  int MAX_HP; /**< initializes MAX HP of an entity as an integer */
  int HP; /**< initializes the HP of an entity as an integer */
  int XP; /**< initializes the Xp of an entity as an integer */
  int ATK; /**< initializes the ATK of an entity as an integer */
  int DEF; /**< initializes the DEF of an entity as an integer */
}
  
goblin_init = {"goblin", 20, 20, 20, 8, 6},
orc_init = {"orc", 50, 50, 50, 15, 8},
dragon_init = {"dragon", 250, 250, 250, 35, 28};

typedef struct statblock Statblock;

/**
 *\brief initializes a struct to capture player-specific values such as level, gold, inventory, and the players stats
 *
 *The struct is initialized to hold values of the player which can be updated and retrieved throughout the progression of the game
 *
 */

struct player { 
  int level; /**< initializes a players level as an integer value */
  int gold; /**< initializes a players amount of gold as an integer value */
  InvNode *inventory; /**< initializes inventory as an InvNode data type */
  Statblock stats; /**< initializes a players stats which is a part of the Statblock struct */
} player_init = {1, 50, NULL, {"Tux", 25, 25, 0, 10, 5}};

typedef struct player Player;

void displayStats(Player *tux);

#endif
