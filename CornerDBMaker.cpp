//
// Created by Ayushi Saha on 16-12-2022.
//

#include "CornerDBMaker.h"

using namespace std;

CornerDBMaker::CornerDBMaker(string _fileName) {
    fileName = _fileName;
}

CornerDBMaker::CornerDBMaker(string _fileName, uint8_t init_val) {
    fileName = _fileName;
    cornerDB = CornerPatternDatabase(init_val);
}

//Performs bfs to reach every attainable Rubik's Cube Configuration and stores its heuristic value
bool CornerDBMaker::bfsAndStore() {
    Rubiks_Cube_Bit_Representation cube;
    queue<Rubiks_Cube_Bit_Representation> q;
    q.push(cube);
    cornerDB.setNumMoves(cube, 0);
    int curr_depth = 0;
    while (!q.empty()) {
        int n = q.size();
        curr_depth++;
        if (curr_depth == 9) break;
        for (int counter = 0; counter < n; counter++) {
            Rubiks_Cube_Bit_Representation node = q.front();
            q.pop();
            for (int i = 0; i < 18; i++) {
                auto curr_move = Rubiks_Cube_Bit_Representation::MOVE(i);
                node.move(curr_move);
                if ((int) cornerDB.getNumMoves(node) > curr_depth) {
                    cornerDB.setNumMoves(node, curr_depth);
                    q.push(node);
                }
                node.invert(curr_move);
            }
        }
    }

    cornerDB.toFile(fileName);
    return true;
}