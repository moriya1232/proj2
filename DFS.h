//
// Created by moriya on 07/01/19.
//

#ifndef PROJ2_DFS_H
#define PROJ2_DFS_H

#include "Searcher.h"
#include "Searchable.h"

using namespace std;



class DFS: public Searcher {

    list<State> search(Searchable* searchable);
};



#endif //PROJ2_DFS_H