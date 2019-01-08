//
// Created by moriya on 06/01/19.
//

#ifndef PROJ2_SEARCHER_H
#define PROJ2_SEARCHER_H

#include "Searchable.h"
//#include "MyPriorityQueue.h"
#include "ISearcher.h"

template<class T>
class Searcher: public ISearcher<T> {
    //MyPriorityQueue* myPriorityQueue;
    int evaluatedNodes;
public:
    Searcher();
    int getNumberOfNodesEvaluated();

};
#endif //PROJ2_SEARCHER_H
