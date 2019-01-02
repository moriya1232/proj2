//
// Created by moriya on 02/01/19.
//

#ifndef UNTITLED6_SOLVER_H
#define UNTITLED6_SOLVER_H

#include "Problem.h"
#include "Solution.h"

class Solver {

public:

    virtual Solution* solve(Problem* problem)=0;

};
#endif //UNTITLED6_SOLVER_H
