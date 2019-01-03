//
// Created by omer on 12/15/18.
//

#include "UnaryExpression.h"

UnaryExpression::UnaryExpression(double d) {
    this->val = d;
}

UnaryExpression::UnaryExpression(string s) {
    this->val = stod(s);
}

double UnaryExpression:: calculate() {
    return this->val;
}