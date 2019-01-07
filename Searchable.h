//
// Created by omer on 1/6/19.
//

#ifndef UNTITLED6_SEARCHABLE_H
#define UNTITLED6_SEARCHABLE_H

using namespace std;
#include "list"
#include "State.h"

template <class T>
class Searchable {
    unsigned int size;

public:
    virtual  State<T> getInitialState()=0;
    virtual list<State<T>> getAllPossibleStates(State<T>)=0;
    virtual State<T> getGoalState()=0;
    virtual size_t getSize();
};

#endif //UNTITLED6_SEARCHABLE_H

