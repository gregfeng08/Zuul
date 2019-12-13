#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Room.h"
#include "Item.h"

using namespace std;

Room::Room(){ //Empty constructor
}
char* Room::getName(){ //Gets the name of the room
  return name;
}
char* Room::getDescription(){ //Returns the desc of the room
  return description;
}
vector<Item*>* Room::getItems(){ //Gives the items in the room by ref
  return &items;	
}
void Room::addItem(Item* item){ //Adds an item to the room
  items.push_back(item);
}
map<const char*, Room*>* Room::getExits(){ //Uses a map and gives the exits by ref
  return &exits;
}
Room* Room::exitRoom(char* room){ //USed for go command and lets the player exit the room
  map<const char*, Room*>::iterator i;
  for(i = this->exits.begin(); i != this->exits.end(); i++){
    if(strcmp(i->first, room) == 0){
      return i->second;
    }
  }
  return 0;
}
Item* Room::takeItem(char* itemName){ //Similar function for the player so that they can swap items
  vector<Item*>::iterator iterator;
  for(iterator = items.begin(); iterator != items.end(); iterator++){
    if(strcmp((*iterator)->getName(), itemName) == 0){
	  Item* i = (*iterator);
	  iterator:items.erase(iterator);
	  return (i);
    }
  }
}
void Room::getExitDirections(){ //Physically pritns the exits that are available to each room
  int counter = 0;
  map<const char*, Room*>::iterator i;
  for(i = this->exits.begin(); i != this->exits.end(); i++){
    if(counter == 0){
	cout << i->first;
	counter++;
     }
     else{
	   cout << ", " << i->first;
	}
  }
  cout << endl;
}
bool Room::validItem(char* itemName) { //Checks if the Room has the item before picking the item up(else segfault)
  vector<Item*>::iterator i;
  for (i = items.begin(); i != items.end(); i++) {
    if (strcmp((*i)->getName(), itemName) == 0) {
      return true;
    } else {
      return false;
    }
  }
}
bool Room::validExit(char* room) { //Checks if the exit is there before moving (else segfault)
  int counter = 0;
  map<const char*, Room*>::iterator i;
  for (i = this->exits.begin(); i != this->exits.end(); i++) {
    
    if (strcmp(room, i->first) == 0) {
      return true;
    } else {
      return false;
    }
  }
}

void Room::printItems(){ //Prints all of the items in the room
  vector<Item*>::iterator i;
  for(i = items.begin(); i != items.end(); i++){
    cout << (*i)->getName() << ", ";
  }
  cout << endl;
}


