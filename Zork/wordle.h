#ifndef WORDLE_H
#define WORDLE_H

#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <QFile>

class wordle
{
public:
    wordle();
    std::string readFile();

private:
    //std::string v[5757];
};

#endif // WORDLE_H
