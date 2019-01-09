//
// Created by moriya on 06/01/19.
//

#ifndef PROJ2_SEARCHER_H
#define PROJ2_SEARCHER_H

#include "Searchable.h"
//#include "MyPriorityQueue.h"
#include "ISearcher.h"

class Searcher: public ISearcher{
    //MyPriorityQueue* myPriorityQueue;
    int evaluatedNodes;
public:
    Searcher();
    int getNumberOfNodesEvaluated();

};
#endif //PROJ2_SEARCHER_H
