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
#include "Matrix.h"


class MatrixHandler : public ClientHandler<Matrix*,string> {
    //CacheManager* cm;
    //Solver<Matrix*,string>* solver;
    //Matrix* myProblem;
public:
    MatrixHandler(Solver<Matrix*,string>* , CacheManager*);
    Solver<Matrix*,string>* getSolver();
    void setSolver(Solver<Matrix*,string>*);
    CacheManager* getCacheManager();
    void setCacheManager(CacheManager*);
    Matrix* getProblem();
    void setProblem(Matrix*);
    string execute();
    string convertListStateToString(list<State<Point>>, Searchable<Point>*);


};



#endif //PROJ2_MATRIXHANDLER_H
