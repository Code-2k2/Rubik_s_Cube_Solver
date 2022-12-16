//
// Created by Ayushi Saha on 14-12-2022.
//


#include<bits/stdc++.h>
#include "Generic_Rubiks_Cube.h"

#ifndef RUBIKS_CUBE_SOLVER_IDDFS_SOLVER_H
#define RUBIKS_CUBE_SOLVER_IDDFS_SOLVER_H

// Typename T: RubiksCube Representation used (3D,1D,Bitboard)
// Typename H: Corresponding Hash function

template<typename T, typename H>
class Solver_IDDFS {
private:

    vector<Generic_Rubiks_Cube::MOVE> moves;
    int threshold_depth;

    bool iddfs()
    {
        int len=1;
        while(len<=threshold_depth)
        {
            if(dfs(1,len))
                return true;
            else len++;
        }
        return false;
    }

//    DFS code to find the solution at specified depth (helper function)
    bool dfs(int depth,int max_search_depth ) {
        if (rc.isSolved()) return true;

        if (depth > max_search_depth) return false;
        for (int i = 0; i < 18; i++) {
            rc.move(Generic_Rubiks_Cube::MOVE(i));
            moves.push_back(Generic_Rubiks_Cube::MOVE(i));
            if (dfs(depth + 1,max_search_depth)) return true;
            moves.pop_back();
            rc.invert(Generic_Rubiks_Cube::MOVE(i));
        }
        return false;
    }

public:
    T rc;

    Solver_IDDFS(T _rubiksCube, int threshold = 8) {
        rc = _rubiksCube;
        threshold_depth=threshold;
    }

    vector<Generic_Rubiks_Cube::MOVE> solve() {
        iddfs();
        return moves;
    }

};


#endif //RUBIKS_CUBE_SOLVER_IDDFS_SOLVER_H