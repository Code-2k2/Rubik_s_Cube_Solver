//
// Created by Ayushi Saha on 01-12-2022.
//
#include "Generic_Rubiks_Cube.h"

int Generic_Rubiks_Cube::faceToIndex(FACE face) {
    switch (face) {
        case FACE::BACK:            return 4;
        case FACE::FRONT:           return 2;
        case FACE::LEFT:            return 1;
        case FACE::RIGHT:           return 3;
        case FACE::DOWN:            return 5;
        case FACE::UP:              return 0;
    }
}

char Generic_Rubiks_Cube::getColorLetter(COLOR color) {
    switch (color) {
        case COLOR::BLUE:            return 'B';
        case COLOR::GREEN:           return 'G';
        case COLOR::RED:             return 'R';
        case COLOR::YELLOW:          return 'Y';
        case COLOR::WHITE:           return 'W';
        case COLOR::ORANGE:          return 'O';
    }
}

string Generic_Rubiks_Cube::getMove(MOVE ind)
{
    switch (ind) {
        case MOVE::L:            return "L";
        case MOVE::L2:           return "L2'";
        case MOVE::L3:           return "L3";

        case MOVE::R:            return "R";
        case MOVE::R2:           return "R2";
        case MOVE::R3:           return "R3";

        case MOVE::U:            return "U";
        case MOVE::U2:           return "U2";
        case MOVE::U3:           return "U3";

        case MOVE::D:            return "D";
        case MOVE::D2:           return "D2";
        case MOVE::D3:           return "D3";

        case MOVE::F:            return "F";
        case MOVE::F2:           return "F2";
        case MOVE::F3:           return "F3";

        case MOVE::B:            return "B";
        case MOVE::B2:           return "B2";
        case MOVE::B3:           return "B3";
    }
}

Generic_Rubiks_Cube &Generic_Rubiks_Cube::move(MOVE ind) {
    switch (ind) {
        case MOVE::L:            return this->l();
        case MOVE::L2:           return this->l2();
        case MOVE::L3:           return this->l3();

        case MOVE::R:            return this->r();
        case MOVE::R2:           return this->r2();
        case MOVE::R3:           return this->r3();

        case MOVE::U:            return this->u();
        case MOVE::U2:           return this->u2();
        case MOVE::U3:           return this->u3();

        case MOVE::D:            return this->d();
        case MOVE::D2:           return this->d2();
        case MOVE::D3:           return this->d3();

        case MOVE::F:            return this->f();
        case MOVE::F2:           return this->f2();
        case MOVE::F3:           return this->f3();

        case MOVE::B:            return this->b();
        case MOVE::B2:           return this->b2();
        case MOVE::B3:           return this->b3();
    }
}

Generic_Rubiks_Cube &Generic_Rubiks_Cube::invert(MOVE ind) {
    switch (ind) {
        case MOVE::L:            return this->l3();
        case MOVE::L2:           return this->l2();
        case MOVE::L3:           return this->l();

        case MOVE::R:            return this->r3();
        case MOVE::R2:            return this->r2();
        case MOVE::R3:            return this->r();

        case MOVE::U:            return this->u3();
        case MOVE::U2:           return this->u2();
        case MOVE::U3:           return this->u();

        case MOVE::D:            return this->d3();
        case MOVE::D2:           return this->d2();
        case MOVE::D3:           return this->d();

        case MOVE::F:            return this->f3();
        case MOVE::F2:           return this->f2();
        case MOVE::F3:           return this->f();

        case MOVE::B:            return this->b3();
        case MOVE::B2:           return this->b2();
        case MOVE::B3:           return this->b();
    }
}

void Generic_Rubiks_Cube::print() const
{
    cout<<"Rubik's Cube:"<<"\n";
    for (int row = 0; row <= 2; row++) {
        for (int i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++)
            cout << getColorLetter(getColor(FACE::UP, row, col)) << " ";

        cout << "\n";
    }

    cout << "\n";

    for (int row = 0; row <= 2; row++) {

        for (int col = 0; col <= 2; col++)
            cout << getColorLetter(getColor(FACE::LEFT, row, col)) << " ";

        cout << " ";

        for (int col = 0; col <= 2; col++)
            cout << getColorLetter(getColor(FACE::FRONT, row, col)) << " ";

        cout << " ";

        for (int col = 0; col <= 2; col++)
            cout << getColorLetter(getColor(FACE::RIGHT, row, col)) << " ";

        cout << " ";

        for (int col = 0; col <= 2; col++)
            cout << getColorLetter(getColor(FACE::BACK, row, col)) << " ";

        cout << "\n";
    }

    cout << "\n";

    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::DOWN, row, col)) << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}



vector<Generic_Rubiks_Cube::MOVE> Generic_Rubiks_Cube::Shuffle(int times) {
    vector<MOVE> moves_performed;
    srand(time(0));
    for ( int i = 0; i < times; i++) {
         int selectMove = (rand() % 18);
        moves_performed.push_back(static_cast<MOVE>(selectMove));
        this->move(static_cast<MOVE>(selectMove));
    }
    return moves_performed;
}

