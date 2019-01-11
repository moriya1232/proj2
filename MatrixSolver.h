//
// Created by moriya on 09/01/19.
//

#ifndef PROJ2_MATRIXSOLVER_H
#define PROJ2_MATRIXSOLVER_H

#include <sstream>
#include "Matrix.h"
#include "Solver.h"
#include "BFS.h"
#include "AbstractClientHandler.h"

class MatrixSolver : public t::Solver<string, string> {
public:
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


    string solve(string problem) override{
        Matrix<Point>* m = getMatrix(problem);
        BFS<Point>* bfs = new BFS<Point>();
        string solution = bfs->search(m);
        return solution;
    }
//public: MatrixSolver() = default;
};


#endif //PROJ2_MATRIXSOLVER_H