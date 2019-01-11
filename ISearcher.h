//
// Created by moriya on 07/01/19.
//

#ifndef PROJ2_ISEARCHER_H
#define PROJ2_ISEARCHER_H

#include "Searchable.h"
#include "Searcher.h"
#include "string"

template<class T>
class ISearcher{
public:
    /**
     * search by ant searcher.
     * @return the solution.
     */
    virtual string search(Searchable<T>*)=0;
};

#endif //PROJ2_ISEARCHER_H