//
// Created by moriya on 07/01/19.
//
#include "BFS.h"
#include <iostream>
/*
template <class T>
list<State<T>*> BFS<T>:: search(Searchable<T>* searchable) {
    list<State<T>*> myList = searchable->getAllStates();
    for (auto it = myList.begin(); it !=myList.end();++it) {
        (*it)->setVisited(false);
    }
    State<T>* current = searchable->getInitialState();
    // Create a queue for BFS
    list<State<T>*> queue;
    // Mark the current node as visited and enqueue it
    current->setVisited(true);
    current->setCameFrom(nullptr);
    current->setCostUntilHere(current->getCost());
    queue.push_back(current);
    if (current == searchable->getGoalState()) {
        return queue;
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
        list<State<T>*> adj = searchable->getAllPossibleStates(*current);
        for (State<T>* t : adj) {
            if(t->getState()->getI() == searchable->getInitialState()->getState()->getI()
            && t->getState()->getJ() == searchable->getInitialState()->getState()->getJ()) {
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
        queue.pop_front();
    }
    queue.clear();
    State<T>* back = searchable->getGoalState();
    while (back->getState()->getI()!=searchable->getInitialState()->getState()->getI()
    || back->getState()->getJ()!=searchable->getInitialState()->getState()->getJ()) {
        queue.push_front(back);
        back = back->getCameFrom();
    }
    queue.push_front(back);
    return queue;

}*/