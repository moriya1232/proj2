//
// Created by moriya on 07/01/19.
//

#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * this is the constractor of matrix
 * @param arr - 2D array.
 * @param m - rows
 * @param n - columns.
 */
template <class T>
Matrix<T>:: Matrix(T** arr, size_t m ,size_t n) {
    this->m = m;
    this->n = n;
    this->arr = arr;

}

/**
 * this function return the start of the matrix.
 * this is in (0,0)
 * @return
 */
template <class T>
State<T> Matrix<T>:: getInitialState(){
    return this->arr[0][0];
}


/**
 * this function return all the adj
 * @return the adj
 */
template <class T>
list<State<T>> Matrix<T>:: getAllPossibleStates(State<T>){
    list<State<T>> result;
    int y, j = 0, i = 0;
    // get the neighbors
    int row_limit = n;
    if(row_limit > 0){
        int column_limit = m;
        for(int x = max(0, i-1); x <= min(i+1, row_limit); x++){
            for(y = max(0, j-1); y <= min(j+1, column_limit); y++){
                if(x != i || y != j && abs(x-i) == 0 && abs(y-1) == 0){
                    State<T> tempState(this->arr[x][y]);
                    result.push_back(tempState);
                }
            }
        }
    }
    return result;
}

/**
 * this function return the goal of where we need to go.
 * @return he goal
 */
template <class T>
State<T> Matrix<T>:: getGoalState(){
return this->arr[m][n];
}


/**
 * this function returns how much nodes we have.
 * @return
 */
template <class T>
size_t Matrix<T>:: getSize(){
    return this->m * this->n;
}





