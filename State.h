//
// Created by moriya on 07/01/19.
//

#ifndef PROJ2_STATE_H
#define PROJ2_STATE_H


template <class T>
class State {
    T state;
    double cost;
    State<T> comeFrom;

public:
    State(T);
    bool Equals(State<T> s);
};


#endif //PROJ2_STATE_H
