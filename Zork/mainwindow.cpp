#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"


ZorkUL t;
Character steve;
string roomItem;
string inventoryItem;




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*wordleGame = new wordle(this);
    wordleGame->show();
    wordleGame->readFile();*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update(){
    setRoomItems();
    setText(hd.getMessage());
    setInventoryItems();
}

std::string MainWindow::getRoomItem(){
    return roomItem;
}
std::string MainWindow::getInventoryItem(){
    return inventoryItem;
}
//displayInfo hd;
//buttons

void MainWindow::on_northButton_clicked()
{
    hd.emptyRoom();
    Command command("go", "north");
    t.processCommand(command);
    setText(hd.getMessage());
    setRoomItems();
}

void MainWindow::on_southButton_clicked()
{
    hd.emptyRoom();
     Command command("go", "south");
     t.processCommand(command);
     setText(hd.getMessage());
     setRoomItems();
}

void MainWindow::on_westButton_clicked()
{
    hd.emptyRoom();
    Command command("go", "west");
    t.processCommand(command);
    setText(hd.getMessage());
    setRoomItems();
}

void MainWindow::on_eastButton_clicked()
{
    hd.emptyRoom();
    Command command("go", "east");
    t.processCommand(command);
    setText(hd.getMessage());
    setRoomItems();
}

void MainWindow::on_mapButton_clicked()
{
    Command command("map","");
    t.processCommand(command);
    setText(hd.getMessage());
}

void MainWindow::on_infoButton_clicked()
{
    Command command("info","");
    t.processCommand(command);
    setText(hd.getMessage());
}

void MainWindow::wordleLaunch(){
    wordleGame = new wordle(this);
    wordleGame->show();
    wordleGame->readFile();
}

void MainWindow::on_pickupButton_clicked(){
    if (getRoomItem() == "Puzzle"){
        wordleLaunch();
    }
    if (getRoomItem() != ""){
    hd.setInventoryItems(getRoomItem());
    hd.removeRoomItems(getRoomItem());
    //steve.addItem(new Item(getInventoryItem(),1,1));
    t.removeRoomItem(Item(getRoomItem(),1,1));
    setInventoryItems();
    setRoomItems();
    }
}


void MainWindow::on_dropButton_clicked(){
    if (getInventoryItem() != ""){
    hd.setRoomItems(getInventoryItem());
    hd.removeInventoryItems(getInventoryItem());
    //steve.removeItem(Item(getInventoryItem(),1,1));
    t.addRoomItem(new Item(getInventoryItem(),1,1));
    setInventoryItems();
    setRoomItems();
    }
}



//output for display
void MainWindow::setText(string content){
    ui->displayWindow->setFont(QFont("Monospace",9));
    ui->displayWindow->setText(QString::fromStdString(content)); //std string to qstring
    //ui->displayWindow->
}



//room View
void MainWindow::setRoomItems() {
    ui->roomView->clear();
    ui->roomView->update();
    string content = hd.getRoomItems();
    if (content != ""){
        char stra[1000];
        const char *str = content.c_str();
        std::strcpy(stra, str);
        char *ptr;
        ptr = strtok(stra, ",");
        while (ptr != NULL) {
            ui->roomView->addItem(ptr);
            ptr = strtok(NULL, ",");
    }}
    //ui->roomView->addItem();
}

void MainWindow::setInventoryItems() {
    ui->inventoryView->clear();
    ui->inventoryView->update();
    string content = hd.getInventoryItems();
    if (content != ""){
        char stra[1000];
        const char *str = content.c_str();
        std::strcpy(stra, str);
        char *ptr;
        ptr = strtok(stra, ",");
        while (ptr != NULL) {
            ui->inventoryView->addItem(ptr);
            ptr = strtok(NULL, ",");
    }}
    //ui->roomView->addItem();
}




void MainWindow::on_roomView_itemClicked(QListWidgetItem *item)
{
    roomItem = item->text().toStdString();
}



void MainWindow::on_inventoryView_itemClicked(QListWidgetItem *item)
{
    inventoryItem = item->text().toStdString();
}

