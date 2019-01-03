//
// Created by moriya on 08/12/18.
//

#ifndef UNTITLED5_Minus_H
#define UNTITLED5_Minus_H

#include "BinaryExpression.h"
#include "Expression.h"

using namespace std;

class Minus: public BinaryExpression {


public:

    Minus(Expression* left, Expression* right);
    double calculate();
    Minus();
};
#endif //UNTITLED5_Minus_H