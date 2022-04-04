#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "displayInfo.h"


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
}

void MainWindow::on_southButton_clicked()
{
     Command command("go", "south");
     t.processCommand(command);
     setText(hd.getMessage());
}

void MainWindow::on_westButton_clicked()
{
    Command command("go", "west");
    t.processCommand(command);
    setText(hd.getMessage());
}

void MainWindow::on_eastButton_clicked()
{
    Command command("go", "east");
    t.processCommand(command);
    setText(hd.getMessage());
}

void MainWindow::on_mapButton_clicked()
{
    Command command("map","");
    t.processCommand(command);
    setText(hd.getMessage());
}


//output for display
void MainWindow::setText(string content){
    ui->displayWindow->appendPlainText(QString::fromStdString(content)); //std string to qstring
    //ui->displayWindow->
}

//inventory display
void MainWindow::setInventory(string content){
    ui->inventoryView->addItem(QString::fromStdString(content));
}
