#include "displayInfo.h"

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
