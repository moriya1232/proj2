//
// Created by moriya on 07/01/19.
//

#ifndef PROJ2_MATRIX_H
#define PROJ2_MATRIX_H

using namespace std;
#include "State.h"
#include <list>
#include "Searchable.h"

template <class T>
class Matrix : public Searchable<T> {
State<T>** arr;
public:
    size_t n;
    size_t m;
    Matrix(T** arr, size_t m, size_t n);
    State<T> getInitialState();
    list<State<T>> getAllPossibleStates(State<T>);
    State<T> getGoalState();
    size_t getSize();
};
#endif //PROJ2_MATRIX_H
