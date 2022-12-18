//
// Created by Ayushi Saha on 16-12-2022.
//

#ifndef RUBIK_S_CUBE_SOLVER_NIBBLE_ARRAY_H
#define RUBIK_S_CUBE_SOLVER_NIBBLE_ARRAY_H

#include <bits/stdc++.h>

using namespace std;

class NibbleArray {
    //The nibble array stores the number of moves it takes to solve the corners of the Rubik's Cube
    //Since the number of moves don't exceed 15, each position of the array stores the count of moves for 2 configurations.
    //This nibble array gives the heuristic value to complete the IDAstar algorithm.
    size_t size;
    vector<uint8_t> arr;

public:
    NibbleArray(const size_t size, const uint8_t val = 0xFF);

    uint8_t get(const size_t pos) const;

    void set(const size_t pos, const uint8_t val);

    unsigned char *data();

    const unsigned char *data() const;

    size_t storageSize() const;

    void inflate(vector<uint8_t> &dest) const;

    void reset(const uint8_t val = 0xFF);

};



#endif //RUBIK_S_CUBE_SOLVER_NIBBLE_ARRAY_H

