//
// Created by moriya on 07/01/19.
//
#include "State.h"

template<typename T>
State<T>:: State(T t) {
this->state = t;
}

bool State<class T>:: Equals(State<T> s) {
    return (this->state == (s.state));
}


/*list<State<T>> State<T>:: getAdj() {
    return this->adj;
}*/