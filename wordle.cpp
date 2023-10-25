#include "wordle.h"
#include "ui_wordle.h"
#include "ZorkUL.h"


wordle::wordle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wordle)
{
    ui->setupUi(this);
    ui->entryBox->setMaxLength(5);

}

wordle::~wordle()
{
    delete ui;
}

std::string randomWord = "";

std::string wordle::readFile(){
    std::vector<string> lines;
    QFile inputFile("fiveLetterWords.txt");
    int total_lines=0;
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          total_lines++;
          lines.push_back(line.toStdString());
          //return line.toStdString();
       }
       inputFile.close();
    }

    int random_number=rand()%total_lines;

    //fetch the line where line index (starting from 0) matches with the random number
    randomWord = lines[random_number];
    std::cout << randomWord;
    std::cout.flush();
    return randomWord;
}


std::string wordle::compareStrings(std::string input) {
    std::string returnString = "";
    int r1 = input.size();
    int r2 = randomWord.size();
        for (int i=0;i<r1;i++){
           for (int i1=0;i1<r2;i1++){
               if (input[i] == randomWord[i1]){
                   returnString= returnString + input[i];
               }
           }
        }
    return returnString;;
}


std::string removeDuplicate(std::string str)
{
    for ( std::string::size_type i = 0; i < str.size(); i++ )
    {
        std::string::size_type j = i + 1;
        while ( j < str.size() )
        {
            if ( str[i] == str[j] )
            {
                str.erase( j, 1 );
            }
            else
            {
                ++j;
            }
        }
    }
    return str;
}

int selectedBox = 0;
std::string guessedCharacters = "";
std::string guessedWord = "";
std::string finalReturn = "";

void wordle::on_entryBox_textChanged(const QString &arg1)
{
    if (arg1.toStdString()==randomWord){
        ui->entryBox->setMaxLength(100);
        ui->entryBox->setText("YOU WIN!!!!!");
        ui->guessedBox->setText(QString::fromStdString(randomWord));
        selectedBox=6;
    }else{
    if (selectedBox == 0){
        ui->label_1->setText(arg1);
        if (arg1.length() == 5) guessedWord = arg1.toStdString();
    }else if (selectedBox == 1) {
        ui->label_2->setText(arg1);
        if (arg1.length() == 5) guessedWord = arg1.toStdString();
    }else if (selectedBox == 2) {
        ui->label_3->setText(arg1);
        if (arg1.length() == 5) guessedWord =arg1.toStdString();
    }else if (selectedBox == 3) {
        ui->label_4->setText(arg1);
        if (arg1.length() == 5) guessedWord = arg1.toStdString();
    }else if (selectedBox == 4) {
        ui->label_5->setText(arg1);
        if (arg1.length() == 5) guessedWord = arg1.toStdString();
    }else if (selectedBox == 5) {
        ui->label_6->setText(arg1);
        if (arg1.length() == 5) guessedWord = arg1.toStdString();
    }else if (selectedBox==6){
        ui->entryBox->setText(QString::fromStdString(randomWord));
    }else if (selectedBox==7){
        this->close();
    }}
}

void wordle::showWindow(){
    this->show();
}

void wordle::on_entryBox_returnPressed()
{
    //moves to next box
    selectedBox++;
    //resets entry box
    ui->entryBox->setText(QString::fromStdString(""));
    //checks to see if any characters match guessed word
    guessedCharacters = this->compareStrings(guessedWord);
    //adds previous guesses
    finalReturn = finalReturn + guessedCharacters;
    //removes duplicate letters
    finalReturn= removeDuplicate(finalReturn);
    //adds to guess box
    ui->guessedBox->setText(QString::fromStdString(finalReturn));
}

