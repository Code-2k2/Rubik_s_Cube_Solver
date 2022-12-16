//
// Created by Ayushi Saha on 13-12-2022.
//


#include "Generic_Rubiks_Cube.h"

class Rubiks_Cube_1D_Representation : public Generic_Rubiks_Cube {
private:

    static int Index(int faceIndex,int row,int col)
    {return faceIndex*9 + row*3 +col;}

    void rotateFace(int ind) {
        char temp_arr[9] = {};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp_arr[Index(0,i,j)] = cube[Index(ind,i,j)];
            }
        }
        for (int i = 0; i < 3; i++) cube[Index(ind,0,i)] = temp_arr[Index(0,2-i,0)];
        for (int i = 0; i < 3; i++) cube[Index(ind,i,2)] = temp_arr[Index(0,0,i)];
        for (int i = 0; i < 3; i++) cube[Index(ind,2,2-i)] = temp_arr[Index(0,i,2)];
        for (int i = 0; i < 3; i++) cube[Index(ind,2-i,0)] = temp_arr[Index(0,2,2-i)];
    }

public:
    char cube[54]{};

    Rubiks_Cube_1D_Representation() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++)
                    cube[9*i + 3*j + k] = getColorLetter(COLOR(i));
            }
        }
    }

    COLOR getColor(FACE face,int row,int col) const override {
        char color = cube[Index((int)face,row,col)];
        switch (color) {
            case 'B':                return COLOR::BLUE;
            case 'R':                return COLOR::RED;
            case 'G':                return COLOR::GREEN;
            case 'O':                return COLOR::ORANGE;
            case 'Y':                return COLOR::YELLOW;
            default:                 return COLOR::WHITE;
        }
    }

    [[nodiscard]] bool isSolved() const override {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (this->cube[Index(i,j,k)] == getColorLetter(COLOR(i))) continue;
                    return false;
                }
            }
        }
        return true;
    }

    Generic_Rubiks_Cube &u() override {
        this->rotateFace(0);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[Index(4,0,2-i)];
        for (int i = 0; i < 3; i++) cube[Index(4,0,2-i)] = cube[Index(1,0,2-i)];
        for (int i = 0; i < 3; i++) cube[Index(1,0,2-i)] = cube[Index(2,0,2-i)];
        for (int i = 0; i < 3; i++) cube[Index(2,0,2-i)] = cube[Index(3,0,2-i)];
        for (int i = 0; i < 3; i++) cube[Index(3,0,2-i)] = temp_arr[i];

        return *this;
    }

    Generic_Rubiks_Cube &u2() override {
        this->u();
        this->u();

        return *this;
    }

    Generic_Rubiks_Cube &u3() override {
        this->u();
        this->u();
        this->u();

        return *this;
    }

    Generic_Rubiks_Cube &l() override {
        this->rotateFace(1);

        char temp_arr[3] = {};
        for (char & i : temp_arr)  i = cube[Index(0, 1, 0)];
        for (int i = 0; i < 3; i++) cube[Index(0,1,0)] = cube[Index(4,2-i,2)];
        for (int i = 0; i < 3; i++) cube[Index(4,2-i,2)] = cube[Index(5,i,0)];
        for (int i = 0; i < 3; i++) cube[Index(5,i,0)] = cube[Index(2,i,0)];
        for (char i : temp_arr) cube[Index(2,1,0)] = i;

        return *this;
    }

    Generic_Rubiks_Cube &l2() override {
        this->l();
        this->l();

        return *this;
    }

    Generic_Rubiks_Cube &l3() override {
        this->l();
        this->l();
        this->l();

        return *this;
    }

    Generic_Rubiks_Cube &f() override {
        this->rotateFace(2);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[Index(0,2,i)];
        for (int i = 0; i < 3; i++) cube[Index(0,2,i)]= cube[Index(1,2-i,2)];
        for (int i = 0; i < 3; i++) cube[Index(1,2-i,2)] = cube[Index(5,0,2-i)];
        for (int i = 0; i < 3; i++) cube[Index(5,0,2-i)] = cube[Index(3,i,0)];
        for (int i = 0; i < 3; i++) cube[Index(3,i,0)] = temp_arr[i];

        return *this;
    }

    Generic_Rubiks_Cube &f2() override {
        this->f();
        this->f();

        return *this;
    }

    Generic_Rubiks_Cube &f3() override {
        this->f();
        this->f();
        this->f();

        return *this;
    }

    Generic_Rubiks_Cube &r() override {
        this->rotateFace(3);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[Index(0,2-i,2)];
        for (int i = 0; i < 3; i++) cube[Index(0,2-i,2)] = cube[Index(2,2-i,2)];
        for (int i = 0; i < 3; i++) cube[Index(2,2-i,2)] = cube[Index(5,2-i,2)];
        for (int i = 0; i < 3; i++) cube[Index(5,2-i,2)] = cube[Index(4,i,0)];
        for (int i = 0; i < 3; i++) cube[Index(4,i,0)] = temp_arr[i];

        return *this;
    }

    Generic_Rubiks_Cube &r2() override {
        this->r();
        this->r();

        return *this;
    }

    Generic_Rubiks_Cube &r3() override {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    Generic_Rubiks_Cube &b() override {
        this->rotateFace(4);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[Index(0,0,2-i)];
        for (int i = 0; i < 3; i++) cube[Index(0,0,2-i)] = cube[Index(3,2-i,2)];
        for (int i = 0; i < 3; i++) cube[Index(3,2-i,2)] = cube[Index(5,2,i)];
        for (int i = 0; i < 3; i++) cube[Index(5,2,i)] = cube[Index(1,i,0)];
        for (int i = 0; i < 3; i++) cube[Index(1,i,0)] = temp_arr[i];

        return *this;
    }


    Generic_Rubiks_Cube &b2() override {
        this->b();
        this->b();

        return *this;
    }

    Generic_Rubiks_Cube &b3() override {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    Generic_Rubiks_Cube &d() override {
        this->rotateFace(5);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[Index(2,2,i)];
        for (int i = 0; i < 3; i++) cube[Index(2,2,i)] = cube[Index(1,2,i)];
        for (int i = 0; i < 3; i++) cube[Index(1,2,i)] = cube[Index(4,2,i)];
        for (int i = 0; i < 3; i++) cube[Index(4,2,i)] = cube[Index(3,2,i)];
        for (int i = 0; i < 3; i++) cube[Index(3,2,i)] = temp_arr[i];

        return *this;
    }

    Generic_Rubiks_Cube &d2() override {
        this->d();
        this->d();

        return *this;
    }

    Generic_Rubiks_Cube &d3() override {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    bool operator==(const Rubiks_Cube_1D_Representation &r1) const {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (r1.cube[Index(i,j,k)] != cube[Index(i,j,k)]) return false;
                }
            }
        }
        return true;
    }

    Rubiks_Cube_1D_Representation &operator = (const Rubiks_Cube_1D_Representation &r1) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[Index(i,j,k)] = r1.cube[Index(i,j,k)];
                }
            }
        }
        return *this;
    }

    struct Hash1D {
        size_t operator()(const Rubiks_Cube_1D_Representation &r1) const {
            string str;
            for (int i = 0; i < 54; i++)
                str += r1.cube[i];

            return hash<string>()(str);
        }
    };

};