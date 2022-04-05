#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "displayInfo.h"
#include <cstring>
#include <fstream>


ZorkUL t;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//displayInfo hd;
//buttons

void MainWindow::on_northButton_clicked()
{
    Command command("go", "north");
    t.processCommand(command);
    setText(hd.getMessage());
    setRoomItems();
}

void MainWindow::on_southButton_clicked()
{
     Command command("go", "south");
     t.processCommand(command);
     setText(hd.getMessage());
     setRoomItems();
}

void MainWindow::on_westButton_clicked()
{
    Command command("go", "west");
    t.processCommand(command);
    setText(hd.getMessage());
    setRoomItems();
}

void MainWindow::on_eastButton_clicked()
{
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


//output for display
void MainWindow::setText(string content){
    ui->displayWindow->setFont(QFont("Monospace",9));
    ui->displayWindow->setText(QString::fromStdString(content)); //std string to qstring
    //ui->displayWindow->
}

//inventory display
void MainWindow::setInventory(string content){
    ui->inventoryView->addItem(QString::fromStdString(content));
}

//room View
void MainWindow::setRoomItems() {
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



