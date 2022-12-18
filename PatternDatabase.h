//
// Created by Ayushi Saha on 16-12-2022.
//


#ifndef RUBIKS_CUBE_SOLVER_PATTERN_DATABASE_H
#define RUBIKS_CUBE_SOLVER_PATTERN_DATABASE_H

#include "Generic_Rubiks_Cube.h"
#include "Nibble Array.h"
#include "bits/stdc++.h"

using namespace std;

class PatternDatabase {

    NibbleArray database;
    size_t size;
    size_t numItems;

    PatternDatabase();

public:
    PatternDatabase(const size_t size);
//    Testing for init_val
    PatternDatabase(const size_t size, uint8_t init_val);

    virtual uint32_t getDatabaseIndex(const Generic_Rubiks_Cube &cube) const = 0;

    virtual bool setNumMoves(const Generic_Rubiks_Cube  &cube, const uint8_t numMoves);

    virtual bool setNumMoves(const uint32_t ind, const uint8_t numMoves);

    virtual uint8_t getNumMoves(const Generic_Rubiks_Cube  &cube) const;

    virtual uint8_t getNumMoves(const uint32_t ind) const;

    virtual size_t getSize() const;

    virtual size_t getNumItems() const;

    virtual bool isFull() const;

    virtual void toFile(const string &filePath) const;

    virtual bool fromFile(const string &filePath);

    virtual vector<uint8_t> inflate() const;

    virtual void reset();
};


#endif //RUBIK_S_CUBE_SOLVER_PATTERN_DATABASE_H
