//
// Created by moriya on 07/01/19.
//

#ifndef PROJ2_DFS_H
#define PROJ2_DFS_H

#include "Searcher.h"
#include "Searchable.h"

using namespace std;


template <class T>
class DFS: public Searcher<T> {

    list<State<T>> search(Searchable<T>* searchable);
};



#endif //PROJ2_DFS_H
