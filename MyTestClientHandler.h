//
// Created by moriya on 02/01/19.
//

#ifndef UNTITLED6_MYTESTCLIENTSERVER_H
#define UNTITLED6_MYTESTCLIENTSERVER_H

#include "ClientHandler.h"

class MyTestClientServer : public ClientHandler {
    Solver* solver;
    CacheManager* cm;
public:
    Solver* getSolver();
    void setSolver(Solver*);
    CacheManager* getCacheManager();
    void setCacheManager(CacheManager*);



};
#endif //UNTITLED6_MYTESTCLIENTSERVER_H
