//
// Created by moriya on 07/01/19.
//

#ifndef PROJ2_DFS_H
#define PROJ2_DFS_H

#include "Searcher.h"
#include "Searchable.h"
#include "stack"

using namespace std;


template <class T>
class DFS: public Searcher<T> {
public:
    string search(Searchable<T>* searchable){
        vector<State<T>*> myList = searchable->getAllStates();
        vector<State<T>*> result;
        stack<State<T>*> stack;
        State<T>* current = searchable->getInitialState();
        State<T>* goal = searchable->getGoalState();
        vector<State<T>*> adj = searchable->getAllPossibleStates(*current);
        if (!(current == goal)) {
            for (State<T>* currAdj : adj) {
                ::stack<State<T>*> tempStack = stack;
                currAdj->setCameFrom(current);
                stack = myDFS(stack, currAdj, searchable);
                if (compareStacks(stack, tempStack) == 0) {
                    continue;
                } else {
                    result = convertStackToVector(stack);
                    return this->convertListStateToString(result,searchable);
                }
            }
        }
            // in case that the first state is the goal state
        else {
            result.push_back(current);
            return this->convertListStateToString(result,searchable);
        }
    }


    stack<State<T>*> myDFS(stack<State<T>*> stack, State<T>* state, Searchable<T>* s) {
        ::stack<State<T>*> tempStack = stack;
        vector<State<T>*> myList = s->getAllPossibleStates(*state);
        for (State<T>* st : myList) {
            State<T>* temp = st->getCameFrom();
            if (!(*temp == *state)) {
                stack.push(st);
                stack = myDFS(stack, st, s);
            } else {
                continue;
            }
        }
        if (!stack.empty() && stack.top() == s->getGoalState()) {
            return stack;
        } else {
            return tempStack;
        }
    }

    vector<State<T>*> convertStackToVector(stack<State<T>*> stack) {
        vector<State<T>*> result;
        while (!stack.empty()) {
            result.push_back(stack.top());
            stack.pop();
        }
        return result;
    }

// 0 for equation, -1 otherwise
    int compareStacks(stack<State<T>*> s1, stack<State<T>*> s2) {
        if (s1.size() != s2.size()) { return -1; }
        while (!s1.empty()) {
            State<T>* st1 = s1.top();
            s1.pop();
            State<T>* st2 = s2.top();
            s2.top();
            if (!(st1 == st2)) {
                return -1;
            }
        }
        return 0;
    }
};



#endif //PROJ2_DFS_H