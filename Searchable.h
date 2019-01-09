//
// Created by omer on 1/6/19.
//

#ifndef UNTITLED6_SEARCHABLE_H
#define UNTITLED6_SEARCHABLE_H

using namespace std;
#include "list"
#include "State.h"


class Searchable {
    unsigned int size;

public:
    virtual  State* getInitialState()=0;
    virtual list<State*> getAllPossibleStates(State)=0;
    virtual State* getGoalState()=0;
    virtual size_t getSize()=0;
};

#endif //UNTITLED6_SEARCHABLE_H

