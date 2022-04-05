#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "ZorkUL.h"
#include <map>
#include <string>
using namespace std;
#include <vector>
#include "item.h"
using std::vector;


class Character {
private:
    Character(string description);
    string description;
    vector <Item> itemsInInventory;
public:
    void addItem(Item *inItem);
    void removeItem(Item *inItem);
    string displayItem();

};

#endif /*CHARACTER_H_*/
