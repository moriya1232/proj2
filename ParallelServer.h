//
// Created by omer on 1/6/19.
//

#ifndef UNTITLED6_PARALLELSERVER_H
#define UNTITLED6_PARALLELSERVER_H

#include "MyServer.h"

template<class problem, class solution>
class ParallelServer : public MyServer<problem,solution> {
protected:
    //void handleClient(int, MatrixHandler<Matrix*, list<State*>>*);
    void handleClient(int, Solver<problem,solution>*);
};

#endif //UNTITLED6_PARALLELSERVER_H
