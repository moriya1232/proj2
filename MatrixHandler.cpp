//
// Created by moriya on 09/01/19.
//

#include "MatrixHandler.h"
#include "ClientHandler.h"

using namespace std;


MatrixHandler:: MatrixHandler
(MatrixSolver* sol, CacheManager* cacheManager1, Matrix* m) : ClientHandler<Matrix*,list<State>>(sol,cacheManager1, m){}

/*Solver<Matrix*, list<State<Point>>> MatrixHandler:: getSolver(){
    return this->solver;
}

void MatrixHandler:: setSolver(Solver<Matrix*, string>* solver1){
    this->solver= solver1;
}


CacheManager* MatrixHandler::getCacheManager(){
return this->cm;
}


void MatrixHandler::setCacheManager(CacheManager* cache){
    this->cm = cache;
}


void MatrixHandler:: setProblem(Matrix* problem1){
this->myProblem = problem1;
}


Matrix* MatrixHandler:: getProblem(){
    return this->myProblem;
}
*/
/**
 * this is the function that does execute!
 * @tparam problem
 * @tparam solution
 */

string MatrixHandler::execute(){
    return convertListStateToString(this->getSolver()->solve(this->getProblem()), this->getProblem());
}



string MatrixHandler:: convertListStateToString(list<State> list1 , Searchable* searchable){
    string result="";

    for (list<State>:: iterator it = list1.begin(); it!=(list1.end()); ++it){
        if ( it == list1.end()) {
            return result;
        }

        State after = (*(++it));
        it--;
        if (after.getState()->getI()> it->getState()->getI()) {
            result+="down";
        } else if (after.getState()->getI() < it->getState()->getI()) {
            result+="up";
        } else if (after.getState()->getJ()> it->getState()->getJ()) {
            result+="right";
        } else if (after.getState()->getJ()< it->getState()->getJ()) {
        result+="left";
        }
        result+=",";

    }
    result = result.substr(0,result.length()-2);
    return result;

    }