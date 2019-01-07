//
// Created by moriya on 07/01/19.
//

#ifndef PROJ2_STATE_H
#define PROJ2_STATE_H

#include <list>

using namespace std;

template <class T>
class State{
    T state;
    //double cost;
    //State<T> comeFrom;
    //list<State<T>> adj;
public:
    State(T);
    bool Equals(State<T>);
    //list<State<T>> getAdj();
};


#endif //PROJ2_STATE_H
