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

    static string convertListStateToString(vector<State<T>*> list1 , Searchable<T>* searchable) {
        string result="";
        for (auto it = list1.begin(); it!=(list1.end());++it){
            if ( ++it == list1.end()) {
                break;
            }
            --it;
            State<T>* after = (*(++it));
            it--;
            if (after->getI()> (*it)->getI()) {
                result+="down";
            } else if (after->getI() < (*it)->getI()) {
                result+="up";
            } else if (after->getJ()> (*it)->getJ()) {
                result+="right";
            } else if (after->getJ()< (*it)->getJ()) {
                result+="left";
            }
            result+=",";
        }
        result = result.substr(0,result.length()-1);
        return result;
    }

    string search(Searchable<T>* searchable){
        vector<State<T>*> myList = searchable->getAllStates();
        for (auto it = myList.begin(); it !=myList.end();++it) {
            (*it)->setVisited(false);
        }
        State<T>* current = searchable->getInitialState();
        // Create a queue for BFS
        vector<State<T>*> q;
        // Mark the current node as visited and enqueue it
        current->setVisited(true);
        current->setCameFrom(nullptr);
        current->setCostUntilHere(current->getCost());
        q.push_back(current);
        if (current == searchable->getGoalState()) {
            string solution = convertListStateToString(q, searchable);
            return solution;
        }

        State<T>* before;
        // 'i' will be used to get all adjacent
        // vertices of a vertex
        while (!q.empty()) {
            // Dequeue a vertex from queue and print it
            current = q.front();
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
                    q.push_back(t);
                    //cout << "(" << t->getState()->getI() << "," << t->getState()->getJ() << ")"<< endl;
                }
            }
            before = q.front();
            q.erase(q.begin());
        }
        q.clear();
        State<T>* back = searchable->getGoalState();
        while (back->getI()!=searchable->getInitialState()->getI()
               || back->getJ()!=searchable->getInitialState()->getJ()) {
            q.push_back(back);
            back = back->getCameFrom();
        }
        q.push_back(back);
        return convertListStateToString(q, searchable);


    }
};



#endif //UNTITLED6_BFS_H