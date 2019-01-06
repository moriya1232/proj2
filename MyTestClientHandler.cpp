//
// Created by moriya on 02/01/19.
//
#include "MyTestClientHandler.h"


/**
 * this function returns the solver of this client server
 * @return the solver
 */
Solver* MyTestClientServer:: getSolver(){
return this->solver;
}

/**
 * this function set the solver of this client server.
 * @param solver1 - new Solver;
 */
void MyTestClientServer:: setSolver(Solver* solver1){
this->solver=solver1;
}

/**
 * this fucntion get the cache manager.
 * @return cach manager
 */
CacheManager* MyTestClientServer:: getCacheManager(){
return this->cm;
}

/**
 * this function set the cache manager.
 * @param cacheManager
 */
void MyTestClientServer:: setCacheManager(CacheManager* cacheManager){
this->cm = cacheManager;
}