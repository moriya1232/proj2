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


class MatrixHandler : public ClientHandler<Matrix*,vector<State>> {
    CacheManager* cm;
    MatrixSolver* solver;
    Matrix* problem;
public:
    MatrixHandler(MatrixSolver* , CacheManager*, Matrix* m);
    MatrixSolver* getSolver() override;
    void setSolver(MatrixSolver*) override;
    CacheManager* getCacheManager() override;
    void setCacheManager(CacheManager*) override;
    Matrix* getProblem() override;
    void setProblem(Matrix*) override;
    string execute()override;
    string convertListStateToString(list<State*>, Searchable*);


};



#endif //PROJ2_MATRIXHANDLER_H
