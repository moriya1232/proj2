//
// Created by omer on 1/3/19.
//

#include "ExpressionSolver.h"
#include "UsefulFunctions.h"
#include "Expression.h"

using namespace std;

Expression* ExpressionSolver::solve(string problem) {
    Expression* e = Expression::makeExpression(problem);
    return e;
}

