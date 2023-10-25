#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "mainwindow.h"
#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
#include "displayInfo.h"
#include "Character.h"
#include <QApplication>



class ZorkUL {
private:
	Parser parser;
	void createRooms();
	void printWelcome();
	void printHelp();
    void goRoom(Command command);
    void createItems();
    void displayItems();






public:
    Room *currentRoom;
	ZorkUL();
	void play();
	string go(string direction);
    bool processCommand(Command command);
    void removeRoomItem(Item temp);
    void addRoomItem(Item *temp);
};


#endif /*ZORKUL_H_*/
