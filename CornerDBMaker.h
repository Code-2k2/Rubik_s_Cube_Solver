//
// Created by Ayushi Saha on 16-12-2022.
//

#ifndef RUBIK_S_CUBE_SOLVER_CORNER_DBMAKER_H
#define RUBIK_S_CUBE_SOLVER_CORNER_DBMAKER_H

#include "CornerPatternDatabase.h"
#include "Rubiks_Cube_Bit_Representation.cpp"

using namespace std;

class CornerDBMaker {
private:
    string fileName;
    CornerPatternDatabase cornerDB;

public:

    CornerDBMaker(string _fileName);
    CornerDBMaker(string _fileName, uint8_t init_val);

    //Performs the heuristic calculation of every Rubik's Cube configuration and stores them in a file
    bool bfsAndStore();
};


#endif //RUBIK_S_CUBE_SOLVER_CORNER_DBMAKER_H
