#include "wordle.h"
#include "ZorkUL.h"
//#include "fiveLetterWords.txt"

wordle::wordle()
{

}

std::string randomWord = "";
const int MAX_CHAR = 26;

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
    return randomWord;
}

std::string wordle::compareStrings(std::string input) {
    std::string returnString = "";
    int r1 = input.size();
    int r2 = randomWord.size();
    if (randomWord == input) {
        returnString = randomWord;
    } else if (r2 != 5) {
        returnString = "error";
    } else{
        for (int i=0;i<r1;i++){
           for (int i1=0;i1<r2;i1++){
               if (input[i] == randomWord[i1]){
                   returnString= returnString + input[i];
               }
           }
        }
    }
    return returnString;;
}
