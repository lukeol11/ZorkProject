#include "Character.h"

Character::Character(){

}

Character::Character(string description) {
    this->description = description;
}

void Character::addItem(Item *inItem) {
    itemsInInventory.push_back(*inItem);
}



void Character::removeItem(Item *inItem) {
    for (auto it = begin (itemsInInventory); it != end (itemsInInventory); ++it){
        if (it->getLongDescription() == inItem->getLongDescription()){
            itemsInInventory.erase(it);
            break;
        }
    }




    /*auto itr = std::find(itemsInInventory.begin(),itemsInInventory.end(), *inItem);
    if (itr != itemsInInventory.end()) itemsInInventory.erase(itr);*/
    //itemsInInventory.erase(std::remove(itemsInInventory.begin(), itemsInInventory.end(), *inItem),itemsInInventory.end());
    /*itemsInInventory.erase(std::remove_if(itemsInInventory.begin(), itemsInInventory.end(),
                                          [&inItem](Character * i){} ));*/
    //auto itr = std::find(itemsInInventory.begin(),itemsInInventory.end(), *inItem);
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
            tempString = tempString + "," ;
            x++;
            }
        }
    return tempString;
    }


