//
// Created by :
// omer shitrit 206333015
// and
// moriya leopold 208116483
//
//


#ifndef PROJECT_EXPRESSION_H
#define PROJECT_EXPRESSION_H
#include "Expression.h"
#include "UsefulFunctions.h"
// this is an absrucat class so we dont have any implemention.

static Expression* getExpression(list<string> exp) {
    if(exp.size()==0) {
        return NULL;
    }
    BinaryExpression* a;
    string temp = exp.front();
    if (!existNum(temp) && checkIfOperator(temp[0])) {
        string oper = temp;
        if (oper == "+") {
            a = new(nothrow) Plus();
        } else if (oper == "-") {
            a = new(nothrow) Minus();
        } else if (oper == "*") {
            a = new( nothrow) Multiplication();
        } else if (oper == "/") {
            a = new(nothrow) Divide();
        }
    } else {
        if (existNum(temp) && !checkIfLetter(temp[0])) {
            Number *num = new(nothrow) Number(temp);
            return num;
        }
    }
    exp.pop_front();
    Expression* ex1 = getExpression(exp);
    a->setRight(ex1);
    Expression* ex2 = getExpression(exp);
    a->setLeft(ex2);
    return a;
}

Expression* Expression:: makeExpression(string line) {
    line = removeSpaces(line);
    if (checkIfOperator(line[0])) {
        line = "0" + line;
    }
    queue<string> numbers;
    stack<string> operators;
    queue<string> tempQueue;
    int indx = 0;
    int length = line.length();
    int temp = 0;
    char c;
    string s = "";
    bool forMinusAndPlus = false;
    bool changeToMinus = false;
    while (indx < length) {
        c = line[indx];
        s += c;
        indx++;
        // if c is a digit
        if (checkIfDigit(c)) {
            forMinusAndPlus = false;
            string takeNum = line.substr(indx - 1, line.length());
            takeNum = extractNum(takeNum);
            indx += takeNum.length() - 1;
            if (takeNum != "") {
                if (changeToMinus) {
                    takeNum = "-" + takeNum;
                }
                numbers.push(takeNum);
                changeToMinus = false;
            }
        } else if (checkOpenClosure(c)) {
            operators.push(s);
        } else if (checkCloseClosure(c)) {
            if (forMinusAndPlus) {
                throw "illigal exception: +) or -)";
            }
            string tempString = operators.top();
            while (!checkOpenClosure(tempString[0])) {
                numbers.push(tempString);
                operators.pop();
                if (!operators.empty()) {
                    tempString = operators.top();
                }
            }
            operators.pop();
        } else if (checkIfOperator(c)) {
            if (forMinusAndPlus) {
                if (operators.top() == "-" && c == '-') {
                    operators.pop();
                    operators.push("+");
                    continue;
                } else if (operators.top() == "-" && c == '+' || operators.top() == "+" && c == '-') {
                    operators.pop();
                    operators.push("+");
                    continue;
                } else if (operators.top() == "+" && c == '+') {
                    continue;
                } else if (c == '-' || c == '+') {
                    if (c == '-') {
                        changeToMinus = true;
                    }
                    continue;
                } else {
                    throw "illigal expression ** */ -* -/ +* +/";
                }
            }
            forMinusAndPlus = true;
            if (!operators.empty() && ifStackHasGreaterOperator(c, operators.top())) {
                while (!operators.empty() && ifStackHasGreaterOperator(c, operators.top())) {
                    numbers.push(operators.top());
                    operators.pop();
                }
            }
            operators.push(s);
        }
        s = "";
    }
    while (!operators.empty()) {
        string tempString = operators.top();
        numbers.push(tempString);
        operators.pop();
    }
    list <string> lis;
    while (!numbers.empty()) {
        string tempStr = numbers.front();
        if (tempStr != "(") {
            lis.push_back(tempStr);
        }
        numbers.pop();
    }
    lis.reverse();
    Expression *e = getExpression(lis);
    return e;
}



#endif //PROJECT_EXPRESSION_H