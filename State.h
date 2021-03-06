//
// Created by moriya on 07/01/19.
//

#ifndef PROJ2_STATE_H
#define PROJ2_STATE_H

#include <list>
#include "Point.h"
#include <string>

using namespace std;

template <class T>
class State{
    T state;
    double cost;
    State* cameFrom;
    int i;
    int j;
    double costUntilHere;
    bool visited;

public:
    bool operator==(const State<T> other) const {
        //if (this == nullptr || other == nullptr || this == NULL || other == NULL) return false;
        if (this->i == other.getI() && this->j == other.getJ()) {return true;};
        return false;
    }

    bool operator!=(const State<T> other) const {
        //if (this == nullptr || other == nullptr) return false;
        if (this->i == other.getI() && this->j == other.getJ()) {false;};
        return true;
    }


    void  setCameFrom(State* cf){
        this->cameFrom = cf;
    }


    State*  getCameFrom(){
        return this->cameFrom;
    }

    T getState(){
        return this->state;
    }

    State(T t){
        this->state = t;
        this->cameFrom = nullptr;
        this->cost=0;
        this->costUntilHere = -1;
    }

    void  setCost(double d){
        this->cost = d;
    }
    int getI() const {
        return this->i;
    }

    void setI(int i) {
        this->i = i;
    }

    void setJ(int j) {
        this->j = j;
    }

    int getJ() const {
        return this->j;
    }
    double  getCost(){
        return this->cost;
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