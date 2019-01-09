//
// Created by moriya on 09/01/19.
//

#include "MatrixHandler.h"
#include "ClientHandler.h"

using namespace std;

template  <class problem, class solution>
MatrixHandler<problem, solution>:: MatrixHandler
(solution sol, CacheManager* cacheManager1, problem m) {//: ClientHandler<Matrix*,vector<State*>>(sol,cacheManager1, m){}
    this->solver= sol;
    this->cm = cacheManager1;
    this->problem = m;
}

template< typename
MatrixSolver<Matrix*, list<State*>>* MatrixHandler<Matrix*, MatrixSolver<Matrix*, list<State*>>>:: getSolver(){
    return this->solver;
}
template  <class problem, class solution>
void MatrixHandler<problem, solution>:: setSolver(Solver<problem, solution>* solver1){
    this->solver= solver1;
}

template  <class problem, class solution>
CacheManager* MatrixHandler<problem, solution>::getCacheManager(){
return this->cm;
}

template  <class problem, class solution>
void MatrixHandler<problem, solution>::setCacheManager(CacheManager* cache){
    this->cm = cache;
}

template  <class problem, class solution>
void MatrixHandler<problem, solution>:: setProblem(Matrix* problem1){
this->myProblem = problem1;
}

template  <class problem, class solution>
Matrix* MatrixHandler<problem, solution>:: getProblem(){
    return this->myProblem;
}

/**
 * this is the function that does execute!
 * @tparam problem
 * @tparam solution
 */
template  <class problem, class solution>
string MatrixHandler<problem, solution>::execute(){
    return convertListStateToString(this->getSolver()->solve(this->getProblem()), this->getProblem());
}


template  <class problem, class solution>
string MatrixHandler<problem, solution>:: convertListStateToString(list<State*> list1 , Searchable* searchable){
    string result="";

    for (list<State*>:: iterator it = list1.begin(); it!=(list1.end()); ++it){
        if ( it == list1.end()) {
            return result;
        }

        State after = (**(++it));
        it--;
        if (after.getState()->getI()> (*it)->getState()->getI()) {
            result+="down";
        } else if (after.getState()->getI() < (*it)->getState()->getI()) {
            result+="up";
        } else if (after.getState()->getJ()> (*it)->getState()->getJ()) {
            result+="right";
        } else if (after.getState()->getJ()< (*it)->getState()->getJ()) {
        result+="left";
        }
        result+=",";
    }
    result = result.substr(0,result.length()-2);
    return result;
    }