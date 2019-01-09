//
// Created by moriya on 09/01/19.
//

#include "MatrixHandler.h"
#include "CacheManager.h"
#include "Solver.h"

template <typename problem, typename solution>
MatrixHandler<problem,solution>:: MatrixHandler
(Solver<problem,solution>* sol, CacheManager* cacheManager1) : ClientHandler<problem,solution>(sol,cacheManager1){}

template <typename problem, typename solution>
Solver<problem,solution>* MatrixHandler<problem,solution>:: getSolver(){
    return this->solver;
}

template <typename problem, typename solution>
void MatrixHandler<problem,solution>:: setSolver(Solver<problem,solution>* solver1){
    this->solver= solver1;
}


template <typename problem, typename solution>
CacheManager* MatrixHandler<problem,solution>::getCacheManager(){
return this->cm;
}


template <typename problem, typename solution>
void MatrixHandler<problem,solution>::setCacheManager(CacheManager* cache){
    this->cm = cache;
}


template <typename problem, typename solution>
void MatrixHandler<problem,solution>:: setProblem(problem problem1){
this->problem = problem1;
}

template <typename problem, typename solution>
problem MatrixHandler<problem,solution>:: getProblem(){
    return this->problem;
}

/**
 * this is the function that does execute!
 * @tparam problem
 * @tparam solution
 */
template <typename problem, typename solution>
void MatrixHandler<problem,solution>::execute(){
    this->getSolver()->solve(this->getProblem());
}