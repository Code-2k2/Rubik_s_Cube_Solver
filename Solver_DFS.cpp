//
// Created by Ayushi Saha on 14-12-2022.
//

#include<bits/stdc++.h>
#include "Generic_Rubiks_Cube.h"

#ifndef RUBIKS_CUBE_SOLVER_DFS_SOLVER_H
#define RUBIKS_CUBE_SOLVER_DFS_SOLVER_H

// Typename T: RubiksCube Representation used (3D 1D, Bitboard)
// Typename H: Corresponding Hash function

template<typename T, typename H>
class Solver_DFS {
private:

    vector<Generic_Rubiks_Cube::MOVE> moves;
    int max_search_depth;

    //max_search_depth-> takes the maximum depth to which DFS is permitted
    //dfs()-> performs depth-first-search and returns a solved Rubik's Cube if it finds it within the specified maximum depth

    bool dfs(int depth) {
        if (rc.isSolved()) return true;
        if (depth > max_search_depth) return false;

        for (int i = 0; i < 18; i++) {
            rc.move(Generic_Rubiks_Cube::MOVE(i));
            moves.push_back(Generic_Rubiks_Cube::MOVE(i));
            if (dfs(depth + 1)) return true;
            moves.pop_back();
            rc.invert(Generic_Rubiks_Cube::MOVE(i));
        }
        return false;
    }

public:
    T rc;

    explicit Solver_DFS(T _rubiksCube, int _max_search_depth = 8) {
        rc = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

    vector<Generic_Rubiks_Cube::MOVE> solve() {
        dfs(1);
        return moves;
    }

};


#endif //RUBIKS_CUBE_SOLVER_DFS_SOLVER_H