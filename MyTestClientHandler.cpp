//
// Created by moriya on 02/01/19.
//
#include "MyTestClientHandler.h"

using namespace std;

/**
 * this function returns the solver of this client server
 * @return the solver
 */
template<typename problem, typename solution>
Solver<problem,solution>* MyTestClientHandler<problem, solution>:: getSolver(){
return this->solver;
}

/**
 * this function set the solver of this client server.
 * @param solver1 - new Solver;
 */
template<typename problem, typename solution>
void MyTestClientHandler<problem,solution>:: setSolver(Solver<problem,solution>* solver1){
this->solver=solver1;
}

/**
 * this fucntion get the cache manager.
 * @return cach manager
 */
template<typename problem, typename solution>
CacheManager* MyTestClientHandler<problem,solution>:: getCacheManager(){
return this->cm;
}

/**
 * this function set the cache manager.
 * @param cacheManager
 */
template<typename problem, typename solution>
void MyTestClientHandler<problem,solution>:: setCacheManager(CacheManager* cacheManager){
this->cm = cacheManager;
}