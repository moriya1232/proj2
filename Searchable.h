//
// Created by omer on 1/6/19.
//

#ifndef UNTITLED6_SEARCHABLE_H
#define UNTITLED6_SEARCHABLE_H

using namespace std;
#include "list"
#include "State.h"

class Searchable {
public:
    virtual  State<class T> getInitialState()=0;
    virtual list<State<class T>> getAllPossibleStates()=0;
    virtual State<class T> getGoalState()=0;

};

#endif //UNTITLED6_SEARCHABLE_H
