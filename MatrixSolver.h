//
// Created by moriya on 09/01/19.
//

#ifndef PROJ2_MATRIXSOLVER_H
#define PROJ2_MATRIXSOLVER_H

#include <sstream>
#include "Matrix.h"
#include "Solver.h"
#include <iostream>
#include "BFS.h"
#include "AbstractClientHandler.h"

template <class problem, class solution>
class MatrixSolver : public t::Solver<string, string> {
public:
    MatrixSolver(CacheManager* cm) : Solver(cm) {}

    static Matrix<Point>* getMatrix(string pro) {
        vector<vector<int>> matrixHolder;
        vector<string> tempVector;
        vector<string> parts;
        parts = omer::split(parts,pro, ';');
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

    string solve(string pro) override{
        // if we already solve this problem
        if (this->cm->alreadySolved(pro)) {
            cout << "We took the solution from the files." << endl;
            return this->cm->getSolution(pro);
        }
        // if its a new problem
        Matrix<Point>* m = getMatrix(pro);
        BFS<Point>* bfs = new BFS<Point>();
        string sol = bfs->search(m);
        this->cm->save(pro, sol);
        return sol;
    }
//public: MatrixSolver() = default;
};


#endif //PROJ2_MATRIXSOLVER_H