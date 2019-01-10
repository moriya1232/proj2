//
// Created by moriya on 09/01/19.
//

#include "MatrixHandler.h"
#include "ClientHandler.h"

using namespace std;

template  <typename problem, typename solution>
MatrixHandler<problem, solution>:: MatrixHandler
        (solution sol, CacheManager* cacheManager1, problem m) {//: ClientHandler<Matrix*,vector<State*>>(sol,cacheManager1, m){}
    this->solver= sol;
    this->cm = cacheManager1;
    this->problem = m;
}

template <typename problem, typename solution>
Solver<problem,solution>* MatrixHandler<problem, solution>:: getSolver(){
    return this->solver;
}
template  <typename problem, typename solution>
void MatrixHandler<problem, solution>:: setSolver(Solver<problem, solution>* solver1){
    this->solver= solver1;
}

template  <typename problem, typename solution>
CacheManager* MatrixHandler<problem, solution>::getCacheManager(){
    return this->cm;
}

template  <typename problem, typename solution>
void MatrixHandler<problem, solution>::setCacheManager(CacheManager* cache){
    this->cm = cache;
}

template  <typename problem, typename solution>
void MatrixHandler<problem, solution>:: setProblem(Matrix* problem1){
    this->myProblem = problem1;
}

template  <typename problem,typename solution>
Matrix* MatrixHandler<problem, solution>:: getProblem(){
    return this->myProblem;
}

/**
 * this is the function that does execute!
 * @tparam problem
 * @tparam solution
 */
template  <typename problem, typename solution>
string MatrixHandler<problem, solution>::execute(){
    return convertListStateToString(this->getSolver()->solve(this->getProblem()), this->getProblem());
}