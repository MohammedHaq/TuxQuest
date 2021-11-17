/**
 *@file locations.h
 *@author haqm8
 *@date August 7 2021
 *@brief header file used to read town and travel option while the town and encounter loops to keep the game running
 *
 */

enum Area {town,camp,fort,cave};
enum TownOption{rest,sell,atk,def,leave};

enum TownOption readTownOption (char resp[50]);
void townLoop (Player *tux);
bool runEncounter (enum Area type, Player *tux);
enum Area readTravelOption (char resp[50]);
bool travelDispatch (Player *tux);
