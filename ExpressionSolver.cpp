//
// Created by omer on 1/3/19.
//

#include "ExpressionSolver.h"

ExpressionSolver::ExpressionSolver() {
    list<string> lis;
    this->exp = lis;
}

Solution* ExpressionSolver::solve(Problem* p) {
    string s = p->getProblem();
    Expression* e = makeExpression(s);
    Solution* sol = new (nothrow) Solution(to_string(e->calculate()));
    return sol;
}

Expression* ExpressionSolver::makeExpression(string line) {
    line = removeSpaces(line);
    if (checkIfOperator(line[0])) {
        line = "0" + line;
    }
    string forVar = "";
    forVar = extractVar(line);
    queue<string> numbers;
    stack<string> operators;
    queue<string> tempQueue;
    int indx = 0;
    int length = line.length();
    int temp = 0;
    char c;
    string s = "";
    bool indicator = true;
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
        } else if (checkIfLetter(c)) {
            forMinusAndPlus = false;
            string takeVar = line.substr(indx - 1, line.length());
            takeVar = extractVar(takeVar);
            if (changeToMinus) {
                takeVar = "-" + takeVar;
            }
            //var1 =  new (nothrow) Var(forVar,DataManager->getSymbolTable()->at(takeVar));
            numbers.push(takeVar);
            indx += takeVar.length() - 1;
            changeToMinus = false;
        }
        s = "";
        indicator = true;
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
    this->exp.clear();
    this->exp = lis;
    Expression *e = getExpression(lis);
    return e;
}

Expression* ExpressionSolver::getExpression(list<string> exp) {
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
        } else {
            //Var *var = new (nothrow) Var(temp, dataManager->getSymbolTable()->at(temp));
            //return var;
        }
    }
    exp.pop_front();
    Expression* ex1 = getExpression(exp);
    a->setRight(ex1);
    Expression* ex2 = getExpression(exp);
    a->setLeft(ex2);
    return a;
}