//
// Created by moriya on 09/01/19.
//

#ifndef PROJ2_ASTAR_H
#define PROJ2_ASTAR_H

#include "Searcher.h"

class Astar: public Searcher {

public:  list<State> search(Searchable* searchable);
};



#endif //PROJ2_ASTAR_H
