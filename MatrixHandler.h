//
// Created by moriya on 09/01/19.
//

#ifndef PROJ2_MATRIXHANDLER_H
#define PROJ2_MATRIXHANDLER_H


#include "ClientHandler.h"

template <class problem, class solution>
class MatrixHandler : public ClientHandler<problem,solution> {
public:
    MatrixHandler(Solver<problem,solution>* , CacheManager*);
    Solver<problem,solution>* getSolver();
    void setSolver(Solver<problem,solution>*);
    CacheManager* getCacheManager();
    void setCacheManager(CacheManager*);
    problem getProblem();
    void setProblem(problem);
    void execute();
};



#endif //PROJ2_MATRIXHANDLER_H
