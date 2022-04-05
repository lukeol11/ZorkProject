#include "Character.h"



Character::Character(string description) {
    this->description = description;
}

void Character::addItem(Item *inItem) {
    itemsInInventory.push_back(*inItem);
}

string Character::displayItem() {
    string tempString; //= "items in inventory = ";
    int sizeItems = (itemsInInventory.size());
    if (itemsInInventory.size() < 1) {
        tempString = "No Items were found";
        }
    else if (itemsInInventory.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + itemsInInventory[x].getShortDescription() + "," ;
            x++;
            }
        }
    return tempString;
    }


