//
// Created by moriya on 06/01/19.
//

#ifndef UNTITLED6_STRINGREVERSER_H
#define UNTITLED6_STRINGREVERSER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class StringReverser : public Solver<string,string> {
public:
    string solve(string line) {
        string result = "";
        char c;
        for (int i = line.length() - 1; i >= 0; i--) {
            c = line[i];
            result += c;
        }
        return result;
    }
};





#endif //UNTITLED6_STRINGREVERSER_H