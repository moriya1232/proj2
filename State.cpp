//
// Created by moriya on 07/01/19.
//
#include "State.h"

template<typename T>
State<T>:: State(T t) {
this->state = t;
}

template<typename T>
bool State<T>:: Equals(State<T> s) {
    return (this->state == (s.state));
}

template<typename  T>
T State<T>::getState() {
    return this->state;
}

/*list<State<T>> State<T>:: getAdj() {
    return this->adj;
}*/

template<typename  T>
double State<T>:: getCost() {
    return this->cost;
}
