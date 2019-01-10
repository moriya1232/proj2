//
// Created by moriya on 06/01/19.
//

#ifndef PROJ2_SEARCHER_H
#define PROJ2_SEARCHER_H

#include "Searchable.h"
//#include "MyPriorityQueue.h"
#include "ISearcher.h"

template <class T>
class Searcher: public ISearcher<T>{
    //MyPriorityQueue* myPriorityQueue;
    int evaluatedNodes;
public:
    Searcher(){this->evaluatedNodes = 0;}
    int getNumberOfNodesEvaluated();
    string convertListStateToString(list<State<Point*>*> list1 , Searchable<T>* searchable);

};
#endif //PROJ2_SEARCHER_H
