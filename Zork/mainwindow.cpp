#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_northButton_clicked()
{
    ui->displayWindow->setText("test");
}


void MainWindow::on_southButton_clicked()
{

}


void MainWindow::on_westButton_clicked()
{

}


void MainWindow::on_eastButton_clicked()
{

}



