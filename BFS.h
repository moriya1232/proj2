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
                current->setCostUntilHere(current->getCost() + before->getCostUntilHere());
                break;
            }
            // Get all adjacent vertices of the dequeued
            // vertex s. If a adjacent has not been visited,
            // then mark it visited and enqueue it
            vector<State<T>*> adj = searchable->getAllPossibleStates(*current);
            /*for (State<T>* t : adj) {
                if (this->checkIfCanPass(t)){
                    break;
                }

            }*/
            for (State<T>* t : adj) {
                if(t == searchable->getInitialState()) {
                    continue;
                }
                if (!this->checkIfCanPass(t)) {
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
                }
            }
            before = current;
            queue.erase(queue.begin());
        }
        if(searchable->getGoalState()->getCameFrom() == nullptr) {
            cout << "this problem doesn't has a solution!" <<endl;
            return "-1";
        }
        queue.clear();
        queue = this->goBack(searchable);
        vector<State<T>*> tempVector;
        for (int i = queue.size() - 1; i >= 0; --i) {
            tempVector.push_back(queue[i]);
        }
        int totalCost = searchable->getGoalState()->getCostUntilHere();
        int numNodes = queue.size();
        return this->convertListStateToString(tempVector, searchable) + " " + to_string(totalCost) + "," + to_string(numNodes);

    }
};



#endif //UNTITLED6_BFS_H