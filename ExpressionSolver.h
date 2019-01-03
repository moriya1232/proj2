//
// Created by omer on 1/3/19.
//

#ifndef UNTITLED6_EXPRESSIONSOLVER_H
#define UNTITLED6_EXPRESSIONSOLVER_H

#include "Solver.h"
#include "Problem.h"
#include <list>
#include <queue>
#include <stack>
#include "Expression.h"
#include <string>
#include "ExpressionSolution.h"
#include "Minus.h"
#include "Plus.h"
#include "Multiplication.h"
#include "Divide.h"
#include "Var.h"
#include "Number.h"
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
