//
// Created by moriya on 09/01/19.
//

#ifndef PROJ2_MATRIXSOLVER_H
#define PROJ2_MATRIXSOLVER_H

#include "Matrix.h"
#include "Solver.h"

class MatrixSolver : public Solver<Matrix*,list<State*>> {
    string convertListStateToString(list<State*> list1 , Searchable* searchable);
public:
    string solve(string);

};


#endif //PROJ2_MATRIXSOLVER_H