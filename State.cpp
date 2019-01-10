//
// Created by moriya on 07/01/19.
//
#include "State.h"

/**
 * this function is a constractor for state.
 * @tparam T
 * @param t
 */

State:: State(Point* t, int c){
    this->state = t;
    this->cost=c;
    this->cameFrom = nullptr;
    this->costUntilHere = -1;
}

/**
 * this function return the state
 * @return state
 */
Point* State:: getState(){
    return this->state;
}

/**
 * this function check whether
 * @tparam T - state in type of
 * @param s
 * @return
 */
bool State:: equal(State s){
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
void State:: setCameFrom(State* cf){
    this->cameFrom = cf;
}

/**
 * this function returns came from
 * @tparam T
 * @return State of T
 */
//template<typename T>
State* State:: getCameFrom(){
    return this->cameFrom;
}

/**
 * return the cost
 * @tparam T
 * @return
 */

double State:: getCost(){
    return this->cost;
}

/**
 * this function set the cost
 * @tparam T
 * @param d - cost
 */
void State:: setCost(double d){
    this->cost = d;
}


bool State:: getVisited(){
    return this->visited;
}

void State:: setVisited(bool b){
    this->visited=b;
}

void State:: setCostUntilHere(double d){
    this->costUntilHere = d;
}
double State:: getCostUntilHere(){
    return this->costUntilHere;
}