#include "wordle.h"
#include "ZorkUL.h"
//#include "fiveLetterWords.txt"

wordle::wordle()
{

}

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

    return lines[random_number];
}
