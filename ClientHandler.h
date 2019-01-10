//
// Created by moriya on 02/01/19.
//

#ifndef UNTITLED6_CLIENDHANDLER_H
#define UNTITLED6_CLIENDHANDLER_H

#include <iostream>
#include <fstream>
#include "Solver.h"
#include "CacheManager.h"
#include "Server.h"

using namespace server_side;

class ClientHandler {
protected:
    Solver<problem, solution> *solver;
    CacheManager <problem,solution>* cachemanager;
public:
    virtual void handleClient(std::istream,std::ostream) = 0;

};
#endif //UNTITLED6_CLIENDHANDLER_H