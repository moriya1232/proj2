//
// Created by moriya on 02/01/19.
//

#ifndef UNTITLED6_MYTESTCLIENTSERVER_H
#define UNTITLED6_MYTESTCLIENTSERVER_H

#include "ClientHandler.h"
#include "MatrixSolver.h"
#include "MatrixHandler.h"
template <class problem,class solution>
class MyTestClientHandler: public MatrixHandler<Matrix*, MatrixSolver*> {
    Solver<string, string>* solver;
    //CacheManager<string, string>* cm;
public:
    MyTestClientHandler(Solver<string, string>*);
    virtual void handleClient(int);
    /*
    Solver<problem,solution>* getSolver();
    void setSolver(Solver<problem,solution>*);
    CacheManager* getCacheManager();
    void setCacheManager(CacheManager*);*/



};
#endif //UNTITLED6_MYTESTCLIENTSERVER_H