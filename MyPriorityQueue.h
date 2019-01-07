//
// Created by moriya on 07/01/19.
//

#ifndef PROJ2_MYPRIORITYQUEUE_H
#define PROJ2_MYPRIORITYQUEUE_H

#include "queue"
#include "list"
#include "State.h"
using namespace std;



class MyPriorityQueue {
    queue<State<class T>> queue;
    int nodes;
public:
    MyPriorityQueue();
    State<T> getTheNextElement();
    void insertAnElement(State<T>);
    int getNumberOfNodes();

};
#endif //PROJ2_MYPRIORITYQUEUE_H