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


static Matrix<Point>* getMatrix(string problem) {
    vector<vector<int>> matrixHolder;
    vector<string> tempVector;
    vector<string> parts;
    parts = omer::split(parts,problem, ';');
    for (int i = 0; i < parts.size(); i++) {
        vector<string> v;
        v = omer::split(v, parts[i], ' ');
        vector<int> currLine = omer::convertStringToLine(v);
        matrixHolder.push_back(currLine);
    }
    int n = matrixHolder.size();
    Matrix<Point>* m = new Matrix<Point>(matrixHolder, n, n);
    return m;
}

int main() {
    /*ParallelServer* ps = new ParallelServer();
    ClientHandler* ch = new (nothrow) MatrixHandler();
    ps->open(5402, ch);*/
    Matrix<Point>* m = getMatrix("83 86 77;15 93 35;86 92 49;");
    BFS<Point>* bfs = new BFS<Point>();
    string solution = bfs->search(m);
    cout << solution << endl;
    return 0;
}