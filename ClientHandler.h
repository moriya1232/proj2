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

template <class problem, class solution>
class ClientHandler {
protected:
    CacheManager* cm;
    Solver<problem,solution>* solver;
    problem myProblem;
public:
    ClientHandler(Solver<problem,solution>* ,CacheManager* , problem p);
    virtual Solver<problem,solution>* getSolver() = 0;
    virtual void setSolver(Solver<problem,solution>*) = 0;
    virtual CacheManager* getCacheManager()=0;
    virtual void setCacheManager(CacheManager*)=0;
    virtual string execute() =0;
    virtual void setProblem(problem)=0;
    virtual problem getProblem()=0;

};
#endif //UNTITLED6_CLIENDHANDLER_H