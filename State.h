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
    bool visited;
    State* cameFrom;
    double costUntilHere;
    /*double value;
    Point* point;
    //list<State> adj;*/
public:
    State(T t, int c){
        this->state = t;
        this->cost=c;
        this->cameFrom = nullptr;
        this->costUntilHere = -1;
    }

    T getState(){
        return this->state;
    }

    /**
 * this function check whether
 * @tparam T - state in type of
 * @param s
 * @return
 */

    bool equal(State<T> s){
        if(this->state == s.getState()) {
            return true;
        }
        return false;
    }

/**
 * this function set the came from
 * @tparam T
 * @param cf - state in type of T
 */
    void setCameFrom(State<T>* cf){
        this->cameFrom = cf;
    }

/**
 * this function returns came from
 * @tparam T
 * @return State of T
 */
    State<T>* getCameFrom(){
        return this->cameFrom;
    }

/**
 * return the cost
 * @tparam T
 * @return
 */
    double getCost(){
        return this->cost;
    }

/**
 * this function set the cost
 * @tparam T
 * @param d - cost
 */

    void setCost(double d){
        this->cost = d;
    }

    bool getVisited(){
        return this->visited;
    }

    void setVisited(bool b){
        this->visited=b;
    }

    void setCostUntilHere(double d){
        this->costUntilHere = d;
    }

    double  getCostUntilHere(){
        return this->costUntilHere;
    }
};


#endif //PROJ2_STATE_H
