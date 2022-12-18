//
// Created by Ayushi Saha on 01-12-2022.
//

#ifndef RUBIK_S_CUBE_SOLVER_GENERIC_RUBIKS_CUBE_H
#define RUBIK_S_CUBE_SOLVER_GENERIC_RUBIKS_CUBE_H
#include <random>
#include <cstdlib>
#include "bits/stdc++.h"

using namespace std;

class Generic_Rubiks_Cube {

public:
    enum class FACE {
        UP,DOWN,LEFT,RIGHT,FRONT,BACK
    };

    enum class COLOR {
        RED, BLUE, GREEN, YELLOW, ORANGE, WHITE
    };

    enum class MOVE {
        L,L2,L3,
        R,R2,R3,
        U,U2,U3,
        D,D2,D3,
        F,F2,F3,
        B,B2,B3
    };

    // Cube Representation:
    //
    //    U          0
    //  L F R B    1 2 3 4
    //    D          5

    virtual COLOR getColor(FACE face,int row,int col)
    const=0;

    static char getColorLetter(COLOR color);

    virtual bool isSolved()  const=0;

    static int faceToIndex(FACE face);

    static string getMove(MOVE ind);

    void print() const;

    vector<MOVE> Shuffle(int times);

    Generic_Rubiks_Cube &move(MOVE ind);

    Generic_Rubiks_Cube &invert(MOVE ind);

    virtual Generic_Rubiks_Cube &l()=0;
    virtual Generic_Rubiks_Cube &l2()=0;
    virtual Generic_Rubiks_Cube &l3()=0;

    virtual Generic_Rubiks_Cube &r()=0;
    virtual Generic_Rubiks_Cube &r2()=0;
    virtual Generic_Rubiks_Cube &r3()=0;

    virtual Generic_Rubiks_Cube &u()=0;
    virtual Generic_Rubiks_Cube &u2()=0;
    virtual Generic_Rubiks_Cube &u3()=0;

    virtual Generic_Rubiks_Cube &d()=0;
    virtual Generic_Rubiks_Cube &d2()=0;
    virtual Generic_Rubiks_Cube &d3()=0;

    virtual Generic_Rubiks_Cube &f()=0;
    virtual Generic_Rubiks_Cube &f2()=0;
    virtual Generic_Rubiks_Cube &f3()=0;

    virtual Generic_Rubiks_Cube &b()=0;
    virtual Generic_Rubiks_Cube &b2()=0;
    virtual Generic_Rubiks_Cube &b3()=0;

    string getCornerColorString(uint8_t ind) const;

    uint8_t getCornerIndex(uint8_t ind) const;

    uint8_t getCornerOrientation(uint8_t ind) const;


};


#endif //RUBIK_S_CUBE_SOLVER_GENERIC_RUBIKS_CUBE_H
