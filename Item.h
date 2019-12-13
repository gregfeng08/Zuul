#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>
#include "Room.h"

using namespace std;

class Item{ //variable and constructor definitions etc.
public:
  Item(char*); //COnstructor
  char* getName();
private: //Private variable definitions
  char* name;
};

#endif
