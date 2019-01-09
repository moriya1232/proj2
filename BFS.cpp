//
// Created by moriya on 07/01/19.
//
#include "BFS.h"
#include <iostream>


list<State> BFS:: search(Searchable* searchable) {
    int counter = 0;
    bool *visited = new bool[searchable->getSize()];
    for (int i = 0; i < searchable->getSize(); i++) {
        visited[i] = false;
    }
    State current = searchable->getInitialState();
    // Create a queue for BFS
    list<State> queue;
    // Mark the current node as visited and enqueue it
    //current.setVisited(true);
    visited[0];
    queue.push_back(current);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    while (!queue.empty()) {
        // Dequeue a vertex from queue and print it
        current = queue.front();
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it

        for (State t : queue) {
            if (!visited[counter]) {
                visited[counter] = true;
                queue.push_back(t);
            }
            cout << "(" << t.getState()->getI() << "," << t.getState()->getJ() << ")"<< endl;
            ++counter;
        }
    }
    return queue;

}