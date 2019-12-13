#include <iostream>
#include <cstring>
#include "Room.h"
#include "Item.h"

using namespace std;

Item::Item(char* itemname){ //Item constructor
  name = itemname;
}

char* Item::getName(){ //Returns the item name
  return name;
}
