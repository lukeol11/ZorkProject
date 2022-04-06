#include "displayInfo.h"
#include <iostream>
#include <string>
#include <sstream>
#include "wordle.h"

//void setOutput(string Text){w.setText(Text);}
std::string outMessage;



displayInfo::displayInfo(){
    //outMessage = "Welcome to Zork!";
}

//Setting Message to show in main window
void displayInfo::setMessage(std::string text){
    if (outMessage != ""){
        outMessage = outMessage+"<br>"+text;
    } else {
        outMessage = text;
    }
}

std::string displayInfo::getMessage(){
    return outMessage;
    outMessage = "";
}

std::string roomInventory;

void displayInfo::emptyRoom(){
    roomInventory = "";
}


void displayInfo::setRoomItems(std::string text){
    //roomInventory = "";
    if (roomInventory != ""){
        roomInventory = roomInventory+","+text;
    } else {
        roomInventory = text;
    }
}

void displayInfo::resetRoomItems(){
    roomInventory = "";
}



void displayInfo::removeRoomItems(std::string text){
    std::string s = getRoomItems();
    hd.resetRoomItems();
    std::string delimiter = ",";
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        if (token == text){
            //std::cout << token;
        } else {
            hd.setRoomItems(token);
        }
        s.erase(0, pos + delimiter.length());
    }
}


std::string displayInfo::getRoomItems(){
    return roomInventory;
    //roomInventory = "";
}

std::string playerInventory;

void displayInfo::setInventoryItems(std::string text){
    //playerInventory = "";
    /*if (text == "Puzzle") {

    }*/
    if (playerInventory != ""){
        playerInventory = playerInventory+","+text;
    } else {
        playerInventory = text;
    }
}

void displayInfo::resetInventoryItems(){
    playerInventory = "";
}

void displayInfo::removeInventoryItems(std::string text){
    std::string s = getInventoryItems();
    hd.resetInventoryItems();
    std::string delimiter = ",";
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        if (token == text){
            //std::cout << token;
        } else {
            hd.setInventoryItems(token);
        }
        s.erase(0, pos + delimiter.length());
    }
}

std::string displayInfo::getInventoryItems(){
    return playerInventory;
    //playerInventory = "";
}

