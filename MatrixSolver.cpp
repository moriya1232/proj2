//
// Created by moriya on 09/01/19.
//


#include "MatrixSolver.h"
#include "BFS.h"

template  <class problem, class solution>
list<State*> MatrixSolver<problem, solution>:: solve(Matrix* m){
    BFS* bfs = new BFS();
    return bfs->search(m);
}