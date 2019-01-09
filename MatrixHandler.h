//
// Created by moriya on 09/01/19.
//

#ifndef PROJ2_MATRIXHANDLER_H
#define PROJ2_MATRIXHANDLER_H

using namespace std;

#include <list>
#include "ClientHandler.h"
#include "Matrix.h"
#include "MatrixSolver.h"

template <class problem, class solution>
class MatrixHandler {//: public ClientHandler<Matrix*,list<State*>> {
    CacheManager* cm;
    MatrixSolver<Matrix*, list<State*>>* solver;
    Matrix* MyProblem;
public:
    MatrixHandler(solution , CacheManager*, problem);
    Solver<problem, solution>* getSolver();
    void setSolver(Solver<problem, solution>*);
    CacheManager* getCacheManager();
    void setCacheManager(CacheManager*);
    Matrix* getProblem();
    void setProblem(Matrix*);
    string execute();
    string convertListStateToString(list<State*>, Searchable*);


};



#endif //PROJ2_MATRIXHANDLER_H
