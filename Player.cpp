#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include "Item.h"
#include "Player.h"
using namespace std; //Made a separate class for the player

Player::Player(Room* room){ //Room constructor that makes the room
  currentRoom = room;
}
Room* Player::getCurrentRoom(){ //Prints the current room
  return currentRoom;	
}
void Player::setCurrentRoom(Room* newRoom) { //Used for movement between rooms
  currentRoom = newRoom;
}
void Player::addItem(Item* item) { //Adds an item to the player
  items.push_back(item);
}
Item* Player::takeItem(char* itemName){ //Drops the item
  vector<Item*>::iterator i;
  for(i = items.begin(); i != items.end(); i++){
    if(strcmp((*i)->getName(), itemName) == 0){
      Item* item = (*i);
      i = items.erase(i); //Erases the array
      return(item);
    }
  }
  return 0;
}
void Player::printInventory(){ //Prints inventory using iterator
  vector<Item*>::iterator i;
  for(i = items.begin(); i != items.end(); i++){
    cout << (*i)->getName() << " ";
  }
}
void Player::checkWin() { //Checkwin function that didn't end up being used
  vector<Item*>::iterator i;
  for (i = items.begin(); i!= items.end(); i++) {
    if ((strcmp((*i)->getName(), "Infinity_Edge") == 0)) {
      cout << "You have found the Infinity Edge and are able to kill anything!" << endl;
    }
  }
}
bool Player::validItem(char* itemName) { //Checks if the player has the item before dropping (else segfault)
  vector<Item*>::iterator i;
  for (i = items.begin(); i != items.end(); i++) {
    if (strcmp((*i)->getName(), itemName) == 0) {
      return true;
    } else {
      return false;
    }
  }
}
bool Player::won(char* itemName) { //CHecks if the player has the item
  if (strcmp(itemName, "Infinity_Edge") == 0) {
    return true;
  } else {
    return false;
  }
}
