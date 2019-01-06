//
// Created by moriya on 07/01/19.
//

#ifndef PROJ2_ISEARCHER_H
#define PROJ2_ISEARCHER_H

#include "Searchable.h"
#include "Searcher.h"
class ISearcher {

public:
    virtual void search(Searchable*)=0;
};

#endif //PROJ2_ISEARCHER_H