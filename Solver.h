//
// Created by moriya on 02/01/19.
//

#ifndef UNTITLED6_SOLVER_H
#define UNTITLED6_SOLVER_H

#include "Matrix.h"
template <class problem, class solution>
class Solver {

public:
    virtual list<State*> solve(Matrix*)=0;

};
#endif //UNTITLED6_SOLVER_H
