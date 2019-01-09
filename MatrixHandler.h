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


class MatrixHandler : public ClientHandler<Matrix*,list<State>> {
    CacheManager* cm;
    MatrixSolver* solver;
    Matrix* myProblem;
public:
    MatrixHandler(MatrixSolver* , CacheManager*, Matrix* m);
    MatrixSolver* getSolver();
    void setSolver(MatrixSolver*);
    CacheManager* getCacheManager();
    void setCacheManager(CacheManager*);
    Matrix* getProblem();
    void setProblem(Matrix*);
    string execute();
    string convertListStateToString(list<State*>, Searchable*);


};



#endif //PROJ2_MATRIXHANDLER_H
