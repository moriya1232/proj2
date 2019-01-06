//
// Created by moriya on 07/01/19.
//
#include "State.h"


template<class T>
State:: State(T state) {
    this->state = state;

}

template<class T>
bool State:: Equals(State<T> s) {
    return this->state.Equals(s.state);
}