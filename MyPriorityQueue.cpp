//
// Created by moriya on 07/01/19.
//

#include "MyPriorityQueue.h"
#include "State.h"

//using namespace std;


/**
 * this function is a constractor to MyPriorityQueue
 */
/*MyPriorityQueue:: MyPriorityQueue() {
    ::queue<State<T>> qu;
    this->queue = qu;
    this->nodes = 0;
}*/


/**
 * this function get the next element in the best solution,
 * ***we pop and returns the elemnts! ***
 * @return the element
 */
/*State<T> MyPriorityQueue:: getTheNextElement() {
    //??????
    --this->nodes;
    State<T> temp = this->queue.front();
    this->queue.pop();
    return temp;

}

/**
 * this function insernt an elemant to the queue by push it to the queue.
 * @param state - the state to insert
 */
/*void MyPriorityQueue:: insertAnElement(State<T> state){
    ++this->nodes;
    this->queue.push(state);
}

/**
 * this function returns how much nodes we has in the best solution.
 * @return number of nodes of the best solution.
 */
/*int MyPriorityQueue:: getNumberOfNodes(){
    return this->nodes;
}*/