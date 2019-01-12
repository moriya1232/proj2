//
// Created by omer on 1/6/19.
//

#ifndef UNTITLED6_SEARCHABLE_H
#define UNTITLED6_SEARCHABLE_H

using namespace std;
#include "vector"
#include "State.h"

template <class T>
class Searchable {
    size_t size;

public:
    virtual  State<T>* getInitialState()=0;
    virtual vector<State<T>*> getAllPossibleStates(State<T>)=0;
    virtual State<T>* getGoalState()=0;
    virtual size_t getSize()=0;
    virtual vector<State<T>*> getAllStates()=0;
};

#endif //UNTITLED6_SEARCHABLE_H