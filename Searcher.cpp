//
// Created by moriya on 06/01/19.
//
#include "Searcher.h"


/**
 * this function is a constractor of searcher.
 */
Searcher:: Searcher(){
    this->myPriorityQueue = new MyPriorityQueue();
    this->evaluatedNodes = 0;

}

/**
 * this function returns the number of nodes that we get until here.
 * @return number of nodes we get until here.
 */
int Searcher:: getNumberOfNodesEvaluated() {
return this->evaluatedNodes;
}