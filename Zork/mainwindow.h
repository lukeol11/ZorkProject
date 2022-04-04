#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <string>
#include <QMainWindow>
#include "Command.h"
#include "ZorkUL.h"
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

private slots:
    void on_northButton_clicked();

    void on_southButton_clicked();

    void on_westButton_clicked();

    void on_eastButton_clicked();

    void on_mapButton_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
