//
// Created by moriya on 07/01/19.
//

#include "Matrix.h"



/**
 * this is the constractor of matrix
 * @param arr - 2D array.
 * @param m - rows
 * @param n - columns.
 */
Matrix:: Matrix(int** arr, size_t m ,size_t n) {
    this->m = m;
    this->n = n;
    State<int>** array2;
    for (int i=0; i < m; ++i){
        for (int j=0; j<n; ++j) {
            array2[i][j] = State<int>(**arr);
        }
    }
    this->arr = array2;

}

/**
 * this function return the start of the matrix.
 * this is in (0,0)
 * @return
 */
State<int> Matrix:: getInitialState(){
    return this->arr[0][0];
}


/**
 * this function return all the adj
 * @return the adj
 */
list<State<int>> Matrix:: getAllPossibleStates(State<int>){
list<State<int>>;


// do it!
}

/**
 * this function return the goal of where we need to go.
 * @return he goal
 */
State<int> Matrix:: getGoalState(){
return this->arr[m][n];
}

/**
 * this function returns how much nodes we have.
 * @return
 */
size_t Matrix:: getSize(){
    return this->m * this->n;
}





