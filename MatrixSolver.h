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

    static string makeDelimiterSpace(string line) {
        int i = 0;
        string result = "";
        char c = line[i];
        while (i < line.length()) {
            if (c - '0' >= 0 && c - '0' <= 9) {
                result += c;
                c = line[++i];
            } else if (c == ';') {
                result += c;
                c = line[++i];
            } else {
                result += ' ';
                // skeep anything until you reach a digit again or the line is over
                while (i < line.length() && c - '0' < 0 || c - '0' > 9) {
                    c = line[++i];
                }
            }
        }
        return result;
    }

    static vector<string> getMatrixParts(vector<string> vec) {
        vector<string> result;
        for (int i = 0;i < vec.size() - 2; i++) {
            result.push_back(vec[i]);
        }
        return result;
    }

    static vector<State<Point>*> getSpecialStates(vector<string> parts, vector<vector<State<Point>*>> m) {
        vector<State<Point>*> result;
        int n = parts.size();
        for (int k = n - 2; k < n; k++) {
            vector<string> tempVector;
            tempVector = omer::split(tempVector, parts[k], ' ');
            int i = stoi(tempVector[0]);
            int j = stoi(tempVector[1]);
            result.push_back(m[i][j]);
        }
        return result;
    }

    static Matrix<Point>* getMatrix(string pro) {
        pro = makeDelimiterSpace(pro);
        vector<vector<int>> matrixHolder;
        vector<string> tempVector;
        vector<string> parts;
        parts = omer::split(parts,pro, ';');
        // get only the matrix parts
        vector<string> matrixParts = getMatrixParts(parts);
        for (int i = 0; i < parts.size(); i++) {
            vector<string> v;
            v = omer::split(v, parts[i], ' ');
            vector<int> currLine = omer::convertStringToLine(v);
            matrixHolder.push_back(currLine);
        }
        int n = matrixParts.size();
        Matrix<Point>* m = new Matrix<Point>(matrixHolder, n, n);
        // now set the initial state and the goal state
        vector<State<Point>*> specialStates = getSpecialStates(parts, m->getAllTheStates());
        State<Point>* start = specialStates[0];
        State<Point>* goal = specialStates[1];
        m->setInitialState(start);
        m->setGoalState(goal);
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