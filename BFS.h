//
// Created by omer on 1/6/19.
//

#ifndef UNTITLED6_BFS_H
#define UNTITLED6_BFS_H

#include "Searcher.h"
#include "Searchable.h"
#include <vector>
#include <queue>

using namespace std;

template<class T>
class BFS: public Searcher<T> {

public:

    static string convertVectorStateToString(vector<State<T>*> list1 , Searchable<T>* searchable) {
        string result="";
        for (auto it = list1.begin(); it!=(list1.end());++it){
            if ( ++it == list1.end()) {
                break;
            }
            --it;
            State<T>* after = (*(++it));
            it--;
            State<T>* curr = *it;
            if (after->getI()> curr->getI()) {
                result+="down";
            } else if (after->getI() < curr->getI()) {
                result+="up";
            } else if (after->getJ()> curr->getJ()) {
                result+="right";
            } else if (after->getJ()< curr->getJ()) {
                result+="left";
            }
            result+=",";
        }
        result = result.substr(0,result.length()-1);
        return result;
    }

    string search(Searchable<T>* searchable) {
        vector<State<T>*> myList = searchable->getAllStates();
        for (State<T>* adj : myList) {
            adj->setVisited(false);
        }
        State<T>* current = searchable->getInitialState();
        // Create a queue for BFS
        vector<State<T>*> queue;
        // Mark the current node as visited and enqueue it
        current->setVisited(true);
        current->setCameFrom(nullptr);
        current->setCostUntilHere(current->getCost());
        queue.push_back(current);
        if (current == searchable->getGoalState()) {
            return this->convertListStateToString(queue, searchable);
        }

        State<T>* before;
        // 'i' will be used to get all adjacent
        // vertices of a vertex
        while (!queue.empty()) {
            // Dequeue a vertex from queue and print it
            current = queue.front();
            if(current==searchable->getGoalState()) {
                current->setCameFrom(before);
                current->setCostUntilHere(current->getCost());
                break;
            }
            // Get all adjacent vertices of the dequeued
            // vertex s. If a adjacent has not been visited,
            // then mark it visited and enqueue it
            vector<State<T>*> adj = searchable->getAllPossibleStates(*current);
            for (State<T>* t : adj) {
                if(t->getI() == searchable->getInitialState()->getI()
                   && t->getJ() == searchable->getInitialState()->getJ()) {
                    continue;
                }
                if (t->getCameFrom() == nullptr) {t->setCameFrom(current); t->setCostUntilHere(t->getCost()+current->getCostUntilHere());}
                else {
                    if(t->getCostUntilHere() > current->getCostUntilHere() + t->getCost()) {
                        t->setCameFrom(current);
                        t->setCostUntilHere(current->getCostUntilHere() + t->getCost());
                    }
                }
                if (!t->getVisited()) {
                    t->setVisited(true);
                    queue.push_back(t);
                    //cout << "(" << t->getState()->getI() << "," << t->getState()->getJ() << ")"<< endl;
                }
            }
            before = queue.front();
            queue.erase(queue.begin());
        }
        queue.clear();
        State<T>* back = searchable->getGoalState();
        while (back->getI()!=searchable->getInitialState()->getI()
               || back->getJ()!=searchable->getInitialState()->getJ()) {
            queue.push_back(back);
            back = back->getCameFrom();
        }
        queue.push_back(back);
        vector<State<T>*> tempVector;
        for (int i = queue.size() - 1; i >= 0; --i) {
            tempVector.push_back(queue[i]);
        }
        return this->convertListStateToString(tempVector, searchable);

    }
};



#endif //UNTITLED6_BFS_H