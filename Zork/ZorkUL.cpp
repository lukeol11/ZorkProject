#include <iostream>
#include "mainwindow.h"
#include <QApplication>
#include "ZorkUL.h"
#include "displayInfo.h"

displayInfo hd;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    ZorkUL t;
    t.play();
    return a.exec();
}

ZorkUL::ZorkUL() {
	createRooms();
}

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;

	a = new Room("a");
        a->addItem(new Item("Stick", 1, 11));
        a->addItem(new Item("Rock", 2, 22));
	b = new Room("b");
        b->addItem(new Item("String", 3, 33));
        b->addItem(new Item("Shovel", 4, 44));
	c = new Room("c");
        c->addItem(new Item("Feather", 5, 55));
        c->addItem(new Item("Screw", 6, 66));
	d = new Room("d");
        d->addItem(new Item("Wire", 5, 55));
        d->addItem(new Item("Cheese", 6, 66));
	e = new Room("e");
        e->addItem(new Item("Boots", 5, 55));
        e->addItem(new Item("Bolt", 6, 66));
	f = new Room("f");
        f->addItem(new Item("Snake", 5, 55));
        f->addItem(new Item("Jar", 6, 66));
	g = new Room("g");
        g->addItem(new Item("Plastic Wrapping", 5, 55));
        g->addItem(new Item("Bottle", 6, 66));
	h = new Room("h");
        h->addItem(new Item("Wheel", 5, 55));
        h->addItem(new Item("Box", 6, 66));
	i = new Room("i");
        i->addItem(new Item("Key", 5, 55));
        i->addItem(new Item("Timber", 6, 66));
    j = new Room("j");
        j->addItem(new Item("Nail", 5, 55));
        j->addItem(new Item("Screwdriver", 6, 66));

//             (N, E, S, W)
	a->setExits(f, b, d, c);
	b->setExits(NULL, NULL, NULL, a);
	c->setExits(NULL, a, NULL, NULL);
	d->setExits(a, e, NULL, i);
	e->setExits(NULL, NULL, NULL, d);
    f->setExits(j, g, a, h);
	g->setExits(NULL, NULL, NULL, f);
	h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
    j->setExits(NULL, NULL, f, NULL);

        currentRoom = a;
}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
	printWelcome();
	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

    /*bool finished = false;
	while (!finished) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
        delete command;
    }*/
    //cout << endl;
    //cout << "end" << endl;
    //setMessage("end");
}

void ZorkUL::printWelcome() {
    hd.setMessage("Start!");
    hd.setMessage("Press Info for help");
    hd.setMessage(" ");
    hd.setMessage(currentRoom->longDescription());
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        hd.setMessage("|        [j]        |");
        hd.setMessage("|         |         |");
        hd.setMessage("|         |         |");
        hd.setMessage("|[h] --- [f] --- [g]|");
        hd.setMessage("|         |         |");
        hd.setMessage("|         |         |");
        hd.setMessage("|[c] --- [a] --- [b]|");
        hd.setMessage("|         |         |");
        hd.setMessage("|         |         |");
        hd.setMessage("|[i] --- [d] --- [e]|");
		}

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
        hd.setMessage("incomplete input");
        }
        else
         if (command.hasSecondWord()) {
        hd.setMessage("you're trying to take " + command.getSecondWord());
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            hd.setMessage("item is not in room");
        else
            hd.setMessage("item is in room");

        hd.setMessage("index number ");
        hd.setMessage(" ");
        hd.setMessage(currentRoom->longDescription());
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
            hd.setMessage("overdefined input");
		else
			return true; /**signal to quit*/
	}
	return false;
}
/** COMMANDS **/
void ZorkUL::printHelp() {
    hd.setMessage("valid inputs are; ");
	parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
        hd.setMessage("incoming input");
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
        hd.setMessage("underdefined input");
	else {
		currentRoom = nextRoom;
        hd.setMessage(currentRoom->longDescription());
        hd.setRoomItems(currentRoom->displayItem());
	}
}

string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;

		return currentRoom->longDescription();
	}
}

