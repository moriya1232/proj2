//
// Created by moriya on 07/01/19.
//

#ifndef PROJ2_STATE_H
#define PROJ2_STATE_H

#include <list>
#include "Point.h"

using namespace std;

template  <class T>
class State{
    T state;
    double cost;
    State<T>* cameFrom;
    double costUntilHere;


    /**
 * this function is a constractor for state.
 * @tparam T
 * @param t
 */

     State(T t){
        this->state = t;
        this->cameFrom = nullptr;
        this->cost=0;
        this->costUntilHere = -1;
    }

    bool operator==(const State<T> &other) const {
        if (this == nullptr || &other == nullptr) return false;
        return this->state == other.state;
    }
    /**
    * this function return the state
 * @return state
 */
    Point*  getState(){
        return this->state;
    }

/**
 * this function check whether
 * @tparam T - state in type of
 * @param s
 * @return
 */
    bool  equal(State s){
        if(this->state->getI() == s.getState()->getI() &&this->state->getJ() == s.getState()->getJ() ) {
            return true;
        }
        return false;
    }

/**
 * this function set the came from
 * @tparam T
 * @param cf - state in type of T
 */
//template<typename T>
    void  setCameFrom(State* cf){
        this->cameFrom = cf;
    }

/**
 * this function returns came from
 * @tparam T
 * @return State of T
 */
//template<typename T>
    State*  getCameFrom(){
        return this->cameFrom;
    }

/**
 * return the cost
 * @tparam T
 * @return
 */

    double  getCost(){
        return this->cost;
    }

/**
 * this function set the cost
 * @tparam T
 * @param d - cost
 */
    void  setCost(double d){
        this->cost = d;
    }


    bool  getVisited(){
        return this->visited;
    }

    void  setVisited(bool b){
        this->visited=b;
    }

    void  setCostUntilHere(double d){
        this->costUntilHere = d;
    }
    double  getCostUntilHere(){
        return this->costUntilHere;
    }
};


#endif //PROJ2_STATE_H