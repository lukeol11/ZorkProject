#ifndef DISPLAYINFO_H
#define DISPLAYINFO_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>




class displayInfo
{
public:
    void setMessage(std::string Text);
    std::string getMessage();
    void setRoomItems(std::string Text);
    std::string getRoomItems();
    void setInventoryItems(std::string Text);
    std::string getInventoryItems();
    displayInfo();
    void removeInventoryItems(std::string content);
    void removeRoomItems(std::string content);
    void emptyRoom();
    void resetRoomItems();
    void resetInventoryItems();

private:

};

extern displayInfo hd;
#endif // DISPLAYINFO_H
