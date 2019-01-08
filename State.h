//
// Created by moriya on 07/01/19.
//

#ifndef PROJ2_STATE_H
#define PROJ2_STATE_H

#include <list>
#include "Point.h"

using namespace std;

template <class T>
class State{
    T state;
    double cost;
    //State<T> cameFrom;
    /*double value;
    Point* point;
    //list<State> adj;*/
public:
    State(T, int);
    T getState();
    bool equal(State<T>);
    //void setCameFrom(State<T>*);
    //State<T> getCameFrom();
    double getCost();
    void setCost(double);
    /*State(int, Point*);
    Point* getPoint();
    int getValue();
    bool Equals(Point*);*/
    //list<State<T>> getAdj();
   // double getCost();
};


#endif //PROJ2_STATE_H
