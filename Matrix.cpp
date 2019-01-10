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

Matrix:: Matrix(vector<vector<int>> arr, size_t m ,size_t n) {
    //State<Point>** states;
    this->m = m;
    this->n = n;
    vector<vector<State*>> vec;
    vector<State*> v;
    //State** temp = *this->states;
    for (int i=0; i< m ;++i) {
        for (int j=0; j< n; ++j) {
            Point* p = new Point(i,j);
            int bla = arr[i][j];
            State* s = new State(p, bla);
            v.push_back(s);
        }
        vec.push_back(v);
        v.clear();
    }
    this->states = vec;
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
list<State*> Matrix:: getAllPossibleStates(State t){
    list<State*> result;
    int y, j = t.getState()->getJ(), i = t.getState()->getI();
    // get the neighbors
    int row_limit = n-1;
    if(row_limit > 0){
        int column_limit = m-1;
        for(int x = max(0, i-1); x <= min(i+1, row_limit); x++){
            for(y = max(0, j-1); y <= min(j+1, column_limit); y++){
                if((x != i && y == j) || (j!=y && x==i)) {
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
    return this->states[m-1][n-1];
}


/**
 * this function returns how much nodes we have.
 * @return
 */
size_t Matrix:: getSize(){
    return this->m * this->n;
}

list<State*> Matrix:: getAllStates(){
    list<State*> li;
    for(vector<vector<State*>>::iterator it = this->states.begin(); it!=this->states.end();++it) {
        for(vector<State*>:: iterator it2 = (*it).begin(); it2!=(*it).end();++it2) {
            li.push_back(*it2);
        }
    }
    return li;
}



