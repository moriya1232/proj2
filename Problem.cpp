//
// Created by moriya on 02/01/19.
//

#include "Problem.h"
#include <string>


string Problem::getProblem() {
    return this->problem;
}

string Problem:: setProblem(string s) {
    this->problem = s;
}