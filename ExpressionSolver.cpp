//
// Created by omer on 1/3/19.
//

#include "ExpressionSolver.h"
#include "UsefulFunctions.h"
#include "Expression.h"

using namespace std;

ExpressionSolver::ExpressionSolver(string s) {
    this->problem = s;

}

Expression* ExpressionSolver::solve() {
    Expression* e = Expression::makeExpression(this->problem);
    return e;
}

