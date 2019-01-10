//
// Created by moriya on 07/01/19.
//
#include "BFS.h"
#include <iostream>


list<State*> BFS:: search(Searchable* searchable) {
    list<State*> myList = searchable->getAllStates();
    for (list<State*>:: iterator it = myList.begin(); it !=myList.end();++it) {
        (*it)->setVisited(false);
    }
    State* current = searchable->getInitialState();
    // Create a queue for BFS
    list<State*> queue;
    // Mark the current node as visited and enqueue it
    current->setVisited(true);
    current->setCameFrom(nullptr);
    queue.push_back(current);
    if (current == searchable->getGoalState()) {
        return queue;
    }

    State* before;
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
        list<State*> adj = searchable->getAllPossibleStates(*current);
        for (State* t : adj) {
            if(t->getState()->getI() == searchable->getInitialState()->getState()->getI()
            && t->getState()->getJ() == searchable->getInitialState()->getState()->getJ()) {
                continue;
            }
            if (t->getCameFrom() == nullptr) {t->setCameFrom(current); t->setCostUntilHere(t->getCost()+current->getCost());}
            else {
                if(t->getCameFrom()->getCostUntilHere() > current->getCostUntilHere() + t->getCost()) {
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
    State* back = searchable->getGoalState();
    while (back->getState()->getI()!=searchable->getInitialState()->getState()->getI()
    || back->getState()->getJ()!=searchable->getInitialState()->getState()->getJ()) {
        queue.push_front(back);
        back = back->getCameFrom();
    }
    queue.push_front(back);
    return queue;

}