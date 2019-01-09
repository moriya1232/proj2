//
// Created by moriya on 06/01/19.
//
#include "Searcher.h"


/**
 * this function is a constractor of searcher.
 */
template<typename T>
Searcher<T>:: Searcher(){
    //this->myPriorityQueue = new MyPriorityQueue();
    this->evaluatedNodes = 0;

}

/**
 * this function returns the number of nodes that we get until here.
 * @return number of nodes we get until here.
 */
template<typename T>
int Searcher<T>:: getNumberOfNodesEvaluated() {
return this->evaluatedNodes;
}



}