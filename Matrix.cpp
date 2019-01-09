//
// Created by moriya on 07/01/19.
//

#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "State.h"

/**
 * this is the constractor of matrix
 * @param arr - 2D array.
 * @param m - rows
 * @param n - columns.
 */

Matrix:: Matrix(int** arr, size_t m ,size_t n) {
    //State<Point>** states;
    this->m = m;
    this->n = n;
    this->states = (State***) malloc (sizeof(State*)*m*n);
    for (int i=0; i<this->m ;++i) {
        for (int j=0; j<this->n; ++j) {
            Point p(i,j);
            Point* pp= &p;
            int bla = arr[m][n];
            State s(pp, bla);
            State* ps = &s;
            this->states[i][j] = ps;
        }
    }
}

/**
 * this function return the start of the matrix.
 * this is in (0,0)
 * @return
 */
State* Matrix:: getInitialState(){
    return this->states[0][0];
}


/**
 * this function return all the adj
 * @return the adj
 */
list<State*> Matrix:: getAllPossibleStates(State){
    list<State*> result;
    int y, j = 0, i = 0;
    // get the neighbors
    int row_limit = n;
    if(row_limit > 0){
        int column_limit = m;
        for(int x = max(0, i-1); x <= min(i+1, row_limit); x++){
            for(y = max(0, j-1); y <= min(j+1, column_limit); y++){
                if(x != i || y != j && abs(x-i) == 0 && abs(y-1) == 0){
                    State* tempState(this->states[x][y]);
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
State* Matrix:: getGoalState(){
return this->states[m][n];
}


/**
 * this function returns how much nodes we have.
 * @return
 */
size_t Matrix:: getSize(){
    return this->m * this->n;
}





