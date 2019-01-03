//
// Created by moriya on 02/01/19.
//

#include "Solution.h"
#include <string>


Solution:: Solution(string re) {
    this->result = re;
}

string Solution::getSolution() {
    return this->result;
}