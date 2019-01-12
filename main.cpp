#include <iostream>
#include "BFS.h"
#include "ClientHandler.h"
#include "Matrix.h"
#include "MatrixHandler.h"
#include "FileCacheManager.h"
#include "ParallelServer.h"

int main() {
    CacheManager* cm = new FileCacheManager();
    server_side::ParallelServer* ps = new server_side::ParallelServer();
    ClientHandler* ch = new (nothrow) MatrixHandler(cm);
    t::Solver<string, string>* ms = new MatrixSolver<string, string>(cm);
    ms->solve("3 4 5;1 0 6;0 7 1;7 3 1;3,1;0,2");
    //ps->open(5402, ch);
    //Matrix<Point>* m = getMatrix("83 86 77;15 93 35;86 92 49;");
    //BFS<Point>* bfs = new BFS<Point>();
    // string solution = bfs->search(m);
    //cout << solution << endl;
    return 0;
}