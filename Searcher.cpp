//
// Created by moriya on 06/01/19.
//
#include "Searcher.h"


/**
 * this function is a constractor of searcher.
 */
//template <typename T>
//Searcher<T>:: Searcher(){
    //this->myPriorityQueue = new MyPriorityQueue();
//    this->evaluatedNodes = 0;
//
//}

/**
 * this function returns the number of nodes that we get until here.
 * @return number of nodes we get until here.
 */
template <typename T>
int Searcher<T>:: getNumberOfNodesEvaluated() {
return this->evaluatedNodes;
}

template <typename T>
string Searcher<T>:: convertListStateToString(list<State<Point*>*> list1 , Searchable<T>* searchable){
    string result="";
    for (auto it = list1.begin(); it!=(list1.end());++it){
        if ( ++it == list1.end()) {
            break;
        }
        --it;
        State<Point*> after = (**(++it));
        it--;
        if (after.getState()->getI()> (*it)->getState()->getI()) {
            result+="down";
        } else if (after.getState()->getI() < (*it)->getState()->getI()) {
            result+="up";
        } else if (after.getState()->getJ()> (*it)->getState()->getJ()) {
            result+="right";
        } else if (after.getState()->getJ()< (*it)->getState()->getJ()) {
            result+="left";
        }
        result+=",";

    }
    result = result.substr(0,result.length()-1);
    return result;
}

