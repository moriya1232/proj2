//
// Created by moriya on 02/01/19.
//

#ifndef UNTITLED6_CLIENDHANDLER_H
#define UNTITLED6_CLIENDHANDLER_H

using namespace std;
#include <iostream>
#include <fstream>
#include "Solver.h"
#include "CacheManager.h"

class ClientHandler {
//ifstream in;
//ofstream out;
public:
virtual Solver* getSolver() = 0;
virtual void setSolver(Solver*) = 0;
virtual CacheManager* getCacheManager()=0;
virtual void setCacheManager(CacheManager)=0;



};
#endif //UNTITLED6_CLIENDHANDLER_H
