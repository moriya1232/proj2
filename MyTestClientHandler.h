//
// Created by moriya on 02/01/19.
//

#ifndef UNTITLED6_MYTESTCLIENTSERVER_H
#define UNTITLED6_MYTESTCLIENTSERVER_H

#include "ClientHandler.h"

class MyTestClientHandler: public ClientHandler {
    Solver<problem,solution>* solver;
    CacheManager* cm;
public:
    Solver<problem,solution>* getSolver();
    void setSolver(Solver<problem,solution>*);
    CacheManager* getCacheManager();
    void setCacheManager(CacheManager*);



};
#endif //UNTITLED6_MYTESTCLIENTSERVER_H
