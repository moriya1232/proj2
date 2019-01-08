//
// Created by moriya on 07/01/19.
//
#include "State.h"

/**
 * this function is a constractor for state.
 * @tparam T
 * @param t
 */
template<typename T>
State<T>:: State(T t, int c){
this->state = t;
this->cost=c;
//this->cameFrom = nullptr;
}

/**
 * this function return the state
 * @return state
 */
template<typename T>
T State<T>:: getState(){
    return this->state;
}

/**
 * this function check whether
 * @tparam T - state in type of
 * @param s
 * @return
 */
template<typename T>
bool State<T>:: equal(State<T> s){
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
//template<typename T>
//void State<T>:: setCameFrom(State<T>* cf){
//    this->cameFrom = cf;
//}

/**
 * this function returns came from
 * @tparam T
 * @return State of T
 */
//template<typename T>
//State<T> State<T>:: getCameFrom(){
//    return this->cameFrom;
//}

/**
 * return the cost
 * @tparam T
 * @return
 */

template<typename T>
double State<T>:: getCost(){
    return this->cost;
}

/**
 * this function set the cost
 * @tparam T
 * @param d - cost
 */
template<typename T>
void State<T>:: setCost(double d){
    this->cost = d;
}

























/*State:: State(int v , Point* p) {
    this->value = v;
    this->point = p;
}

int State:: getValue() {
    return this->value;
}

Point* State:: getPoint(){
    return this->point;
}
bool State:: Equals(Point* p) {
    if (p->getI() == this->point->getI() && p->getJ() == this->point->getJ()) {
        return true;
    }
    return false;
}*/

/*template<typename T>
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

list<State<T>> State<T>:: getAdj() {
    return this->adj;
}

template<typename  T>
double State<T>:: getCost() {
    return this->cost;
}*/
