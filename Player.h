#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"

using namespace std;

class Player{ //Variable and function definitions
 public:
  Player(Room*);
  char* getName();
  Room* getCurrentRoom();
  vector<Item*>* getItems();
  void setCurrentRoom(Room*);
  Item* takeItem(char*);
  void addItem(Item*);
  void printInventory();
  void checkWin();
  bool won(char*);
  bool validItem(char*);
private: //Private variable and vector definitions
  char name[20];
  vector<Item*> items;
  Room* currentRoom;
  Room* newRoom;
};

#endif
