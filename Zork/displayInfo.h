#ifndef DISPLAYINFO_H
#define DISPLAYINFO_H

#include <iostream>
#include <string>



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

private:

};

extern displayInfo hd;
#endif // DISPLAYINFO_H
