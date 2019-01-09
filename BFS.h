//
// Created by omer on 1/6/19.
//

#ifndef UNTITLED6_BFS_H
#define UNTITLED6_BFS_H

#include "Searcher.h"
#include "Searchable.h"

using namespace std;

template <class T>
class BFS: public Searcher<T> {

public:  list<State<T>> search(Searchable<T>* searchable);
};



#endif //UNTITLED6_BFS_H
