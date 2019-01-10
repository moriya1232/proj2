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
public:
    virtual void handleClient(int) = 0;
    /*
    virtual Solver<problem,solution>* getSolver() = 0;
    virtual void setSolver(Solver<problem,solution>*) = 0;
    virtual CacheManager* getCacheManager()=0;
    virtual void setCacheManager(CacheManager*)=0;
    virtual string execute() =0;
    virtual void setProblem(problem)=0;
    virtual problem getProblem()=0;*/

};
#endif //UNTITLED6_CLIENDHANDLER_H