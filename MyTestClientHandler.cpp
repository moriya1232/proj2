//
// Created by moriya on 02/01/19.
//
#include "MyTestClientHandler.h"

using namespace std;

/**
 * this function returns the solver of this client server
 * @return the solver
 */
Solver<class problem,class solution>* MyTestClientHandler:: getSolver(){
return this->solver;
}

/**
 * this function set the solver of this client server.
 * @param solver1 - new Solver;
 */
void MyTestClientHandler:: setSolver(Solver<class problem,class solution>* solver1){
this->solver=solver1;
}

/**
 * this fucntion get the cache manager.
 * @return cach manager
 */
CacheManager* MyTestClientHandler:: getCacheManager(){
return this->cm;
}

/**
 * this function set the cache manager.
 * @param cacheManager
 */
void MyTestClientHandler:: setCacheManager(CacheManager* cacheManager){
this->cm = cacheManager;
}