//
// Created by moriya on 06/01/19.
//
#include "StringReverser.h"

string solve(string line) {
    string result = "";
    char c;
    for (int i = line.length() - 1; i >= 0; i--) {
        c = line[i];
        result += c;
    }
    return result;
}