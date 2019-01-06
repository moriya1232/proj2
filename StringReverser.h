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
   string solve(string);
};





#endif //UNTITLED6_STRINGREVERSER_H
