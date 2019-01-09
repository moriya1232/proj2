//
// Created by moriya on 09/01/19.
//


#include "MatrixSolver.h"
#include "BFS.h"


list<State<Point>> MatrixSolver:: solve(Matrix* m ){
    BFS<Point>* bfs = new BFS<Point>();
    return bfs->search(m);
}