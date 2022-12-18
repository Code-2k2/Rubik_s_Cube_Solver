//
// Created by Ayushi Saha on 18-12-2022.
//

#ifndef RUBIK_S_CUBE_SOLVER_CORNER_PATTERN_DATABASE_H
#define RUBIK_S_CUBE_SOLVER_CORNER_PATTERN_DATABASE_H

#include "Generic_Rubiks_Cube.h"
#include "PatternDatabase.h"
#include "PermutationIndexer.h"
using namespace std;

class CornerPatternDatabase : public PatternDatabase {

    typedef Generic_Rubiks_Cube::FACE F;

    PermutationIndexer<8> permIndexer;

public:

    CornerPatternDatabase();
    CornerPatternDatabase(uint8_t init_val);

    //Calculates the index of every attainable Rubik's Cube configuration by considering the corner indexing and orientation indexing
    uint32_t getDatabaseIndex(const Generic_Rubiks_Cube& cube) const;

};



#endif //RUBIK_S_CUBE_SOLVER_CORNER_PATTERN_DATABASE_H
