#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <string>
#include <QMainWindow>
#include <QListWidget>
#include "Command.h"
#include "ZorkUL.h"
#include "displayInfo.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setText(string content);
    void setInventoryItems();
    void setRoomItems();



private slots:
    void on_northButton_clicked();

    void on_southButton_clicked();

    void on_westButton_clicked();

    void on_eastButton_clicked();

    void on_mapButton_clicked();


    void on_infoButton_clicked();

    void on_roomView_itemClicked(QListWidgetItem *item);

    void on_pickupButton_clicked();

    void on_dropButton_clicked();

    void on_inventoryView_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    std::string getRoomItem();
    std::string getInventoryItem();
};
#endif // MAINWINDOW_H
