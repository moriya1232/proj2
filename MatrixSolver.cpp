//
// Created by moriya on 09/01/19.
//


#include "MatrixSolver.h"
#include "BFS.h"


list<State*> MatrixSolver:: solve(Matrix* m ){
    BFS* bfs = new BFS();
    return bfs->search(m);
}