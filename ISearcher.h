//
// Created by moriya on 07/01/19.
//

#ifndef PROJ2_ISEARCHER_H
#define PROJ2_ISEARCHER_H

#include "Searchable.h"
#include "Searcher.h"
#include "string"


class ISearcher{

public:
    virtual list<State*> search(Searchable*)=0;
};

#endif //PROJ2_ISEARCHER_H