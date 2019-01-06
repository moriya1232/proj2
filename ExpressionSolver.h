//
// Created by omer on 1/3/19.
//

#ifndef UNTITLED6_EXPRESSIONSOLVER_H
#define UNTITLED6_EXPRESSIONSOLVER_H

#include <list>
#include "Solver.h"
#include "Expression.h"
using  namespace std;

class ExpressionSolver : public Solver<string,Expression*> {
    string problem;
public:
    Expression* solve();
    ExpressionSolver(string);
};

#endif //UNTITLED6_EXPRESSIONSOLVER_H
