//
// Created by omer on 1/3/19.
//

#ifndef UNTITLED6_EXPRESSIONSOLVER_H
#define UNTITLED6_EXPRESSIONSOLVER_H

#include <list>
#include "Solver.h"
#include "Expression.h"
using  namespace std;

class ExpressionSolver : public t::Solver<string,string> {
public:
    string solve(string) override;
};

#endif //UNTITLED6_EXPRESSIONSOLVER_H