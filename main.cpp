#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#include "Generic_Rubiks_Cube.h"
#include "Solver_IDAstar.cpp"
#include "CornerDBMaker.h"
//#include "Rubiks_Cube_Bit_Representation.cpp"

int main() {

    Rubiks_Cube_Bit_Representation obj;
    obj.print();

    if(obj.isSolved()) cout<<"Solved initially!"<<'\n'<<'\n';

    vector<Generic_Rubiks_Cube::MOVE> movesToShuffle=obj.Shuffle(12);
    for(auto it:movesToShuffle) cout<<obj.getMove(it)<<" ";
    cout<<'\n'<<'\n';

    cout<<"Shuffled Rubiks Cube"<<'\n'<<'\n';
    obj.print();

    CornerDBMaker cor("Hello");
    if(!cor.bfsAndStore()) cout<<"Sorry";

    Solver_IDAstar <Rubiks_Cube_Bit_Representation,Rubiks_Cube_Bit_Representation::HashBit>
            IDAstarSolver (obj,"Hello");
    vector<Generic_Rubiks_Cube::MOVE> solution = IDAstarSolver.solve();
    cout<<'\n';

    IDAstarSolver.rc.print();
    if( IDAstarSolver.rc.isSolved()) cout<<"Solved again!"<<'\n'<<'\n';

    cout<<"Sequential solving moves:";
    for(auto it:solution)
        cout<<Rubiks_Cube_Bit_Representation::getMove(it)<<" ";
    cout<<'\n'<<'\n';


   //obj.f3();
   //obj.print();





    return 0;
}
