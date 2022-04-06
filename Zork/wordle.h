#ifndef WORDLE_H
#define WORDLE_H

#include <QWidget>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <QFile>

namespace Ui {
class wordle;
}

class wordle : public QWidget
{
    Q_OBJECT

public:
    explicit wordle(QWidget *parent = nullptr);
    ~wordle();
    std::string compareStrings(std::string input);
    std::string readFile();

private slots:
    void on_entryBox_textChanged(const QString &arg1);


    void on_entryBox_returnPressed();

private:
    Ui::wordle *ui;
};

#endif // WORDLE_H
