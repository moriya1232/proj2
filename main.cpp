#include <iostream>
#include "BFS.h"
#include "ClientHandler.h"
#include "Matrix.h"
#include <vector>
#include <fstream>
#include <sstream>
#include "MatrixHandler.h"
#include "FileCacheManager.h"
#include "ParallelServer.h"

int main() {
    CacheManager* cm = new FileCacheManager();
    ParallelServer* ps = new ParallelServer();
    ClientHandler* ch = new (nothrow) MatrixHandler(cm);
    ps->open(5402, ch);
    /*Matrix<Point>* m = getMatrix("83 86 77;15 93 35;86 92 49;");
    BFS<Point>* bfs = new BFS<Point>();
    string solution = bfs->search(m);
    cout << solution << endl;*/
    return 0;
}