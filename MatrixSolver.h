//
// Created by moriya on 09/01/19.
//

#ifndef PROJ2_MATRIXSOLVER_H
#define PROJ2_MATRIXSOLVER_H

#include "Matrix.h"
#include "Solver.h"

class MatrixSolver : public Solver<Matrix*,list<State>> {

public:
     list<State> solve(Matrix* m );



};


#endif //PROJ2_MATRIXSOLVER_H
