//
// Created by omer on 1/3/19.
//

#ifndef UNTITLED6_EXPRESSIONSOLVER_H
#define UNTITLED6_EXPRESSIONSOLVER_H

#include <list>
#include "Solver.h"
#include "Expression.h"
using  namespace std;

class ExpressionSolver : public Solver {
    list<string> exp;
    Solution* solve(Problem*);
    Expression* makeExpression(string);
    Expression* getExpression(list<string>);
public:
    ExpressionSolver();
};

#endif //UNTITLED6_EXPRESSIONSOLVER_H
