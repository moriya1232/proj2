//
// Created by moriya on 07/01/19.
//

#ifndef PROJ2_MATRIX_H
#define PROJ2_MATRIX_H

using namespace std;
#include "State.h"
#include <string>
#include <vector>
#include "Searchable.h"

class Matrix : public Searchable<Point> {
    vector<vector<State<Point>*>> states;
    Point start;
    Point goal;
public:
    size_t n;
    size_t m;
    Matrix(vector<vector<int>>, size_t m, size_t n);
    State<Point>* getInitialState();
    vector<State<Point>*> getAllPossibleStates(State<Point>);
    State<Point>* getGoalState();
    size_t getSize();
    vector<State<Point>*> getAllStates();
};
#endif //PROJ2_MATRIX_H