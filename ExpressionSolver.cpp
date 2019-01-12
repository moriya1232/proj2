//
// Created by omer on 1/3/19.
//

#include "ExpressionSolver.h"
#include "UsefulFunctions.h"
#include "Expression.h"

using namespace std;

string ExpressionSolver::solve(string problem) {
    Expression* e = Expression::makeExpression(problem);
    string solution = to_string(e->calculate());
    return solution;
}
