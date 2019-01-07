//
// Created by omer on 1/6/19.
//

#ifndef UNTITLED6_BFS_H
#define UNTITLED6_BFS_H

#include "Searcher.h"
#include "Searchable.h"

using namespace std;



class BFS: public Searcher {

public:  string search(Searchable<T>* searchable);
};



#endif //UNTITLED6_BFS_H
