//
// Created by moriya on 09/01/19.
//

#ifndef PROJ2_ASTAR_H
#define PROJ2_ASTAR_H

#include "Searcher.h"

template <class T>
class Astar: public Searcher<T> {

public:  string search(Searchable<T>* searchable);
};



#endif //PROJ2_ASTAR_H
