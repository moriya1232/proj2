//
// Created by moriya on 09/01/19.
//

#ifndef PROJ2_MATRIXHANDLER_H
#define PROJ2_MATRIXHANDLER_H

using namespace std;

#include <list>
#include "ClientHandler.h"
#include "Point.h"
#include "State.h"
#include "Searchable.h"

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
    string execute();
    string convertListStateToString(list<State<Point>>, Searchable<Point>*);


};



#endif //PROJ2_MATRIXHANDLER_H
