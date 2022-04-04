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



class ZorkUL {
private:
	Parser parser;
	Room *currentRoom;
	void createRooms();
	void printWelcome();
	void printHelp();
    void goRoom(Command command);
    void createItems();
    void displayItems();





public:
	ZorkUL();
	void play();
	string go(string direction);
    bool processCommand(Command command);
};

#endif /*ZORKUL_H_*/
