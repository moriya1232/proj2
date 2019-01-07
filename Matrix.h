//
// Created by moriya on 07/01/19.
//

#ifndef PROJ2_MATRIX_H
#define PROJ2_MATRIX_H

using namespace std;
#include "State.h"
#include <list>
#include "Searchable.h"


class Matrix : public Searchable<int> {
State<int>** arr;
public:
    size_t n;
    size_t m;
    Matrix(int** arr, size_t m, size_t n);
    State<int> getInitialState();
    list<State<int>> getAllPossibleStates(State<int>);
    State<int> getGoalState();
    size_t getSize();
};
#endif //PROJ2_MATRIX_H
