//
// Created by moriya on 07/01/19.
//


#include "DFS.h"


void DFSUtil(State<T> state, bool visited[], Searchable<T>* searchable, int counter) {
    // Mark the current node as visited and
    // print it
    visited[state] = true;
    // Recur for all the vertices adjacent
    // to this vertex
    list<State<T>>::iterator i;
    for (i = searchable->getAllPossibleStates(state).begin(); i != searchable->getAllPossibleStates(state).end(); ++i) {
        if (!visited[*i]) {
            DFSUtil(*i, visited, searchable, ++counter);
        }
    }
}

string DFS:: search(Searchable<T>* searchable) {
    int counter = 0;
    bool *visited = new bool[searchable->getSize()];
    for (int i = 0; i < searchable->getSize(); i++)
        visited[i] = false;

    // Call the recursive helper function
    // to print DFS traversal
    DFSUtil(searchable->getInitialState(), visited, counter);
}