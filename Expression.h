//
// Created by moriya on 08/12/18.
//

#ifndef MY_PROJECT_EXPRESSION_H
#define MY_PROJECT_EXPRESSION_H


#include <queue>
#include <stack>
#include <list>
#include "iostream"
#include <string>

using namespace std;


class Expression {
    list<string> exp;
public:
    virtual double calculate()=0;
    static Expression* makeExpression(string);


};


#endif //MY_PROJECT_EXPRESSION_H