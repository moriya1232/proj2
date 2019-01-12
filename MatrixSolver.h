//
// Created by moriya on 09/01/19.
//

#ifndef PROJ2_MATRIXSOLVER_H
#define PROJ2_MATRIXSOLVER_H

#include <sstream>
#include "Matrix.h"
#include "Solver.h"
#include <iostream>
#include <fstream>
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
            if (isDigit(c)) {
                result += c;
                c = line[++i];
            } else if (c == ';') {
                result += c;
                c = line[++i];
            } else {
                result += ' ';
                // skeep anything until you reach a digit again or the line is over
                while (i < line.length() && !isDigit(c)) {
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
        int m = matrixHolder[0].size();
        Matrix<Point>* matrix = new Matrix<Point>(matrixHolder, n, m);
        // now set the initial state and the goal state
        vector<State<Point>*> specialStates = getSpecialStates(parts, matrix->getAllTheStates());
        State<Point>* start = specialStates[0];
        State<Point>* goal = specialStates[1];
        matrix->setInitialState(start);
        matrix->setGoalState(goal);
        return matrix;
    }

    static bool isDigit(char c) {
        return (c - '0' >= 0 && c - '0' <= 9);
    }

    static void writeMatrixToFile(int num, int n, int m, string start, string end, Matrix<Point>* matrix) {
        ofstream file("graphs.txt", ios::app);
        file << to_string(num) << endl;
        file << to_string(n) + ", " + to_string(m) << endl;
        file << start << endl;
        file << end << endl;
        vector<vector<State<Point>*>> states = matrix->getAllTheStates();
        string temp = "";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp += to_string((int) states[i][j]->getCost());
                if (j + 1 < n) {
                    temp += ", ";
                }
            }
            file << temp << endl;
            temp = "";
        }
        file.close();
    }

    void updateGraph(string s) override {
        Matrix<Point>* matrix = getMatrix(s);
        // 1- number of matrix - we need to count it somehow WE SHOULD WRITE IT WITH A COUNTER
        int numberOfMatrix = 1;
        // get the line number
        int n = matrix->getNOrder();
        // get the columns numbers
        int m = matrix->getMOrder();
        // get the string representation of the initial state
        string start = matrix->getStateAsString(matrix->getInitialState());
        // get the string representation of the goal state
        string end = matrix->getStateAsString(matrix->getGoalState());
        // write down the matrix
        writeMatrixToFile(numberOfMatrix, n, m, start, end, matrix);
        // 2- all the graphs in this way:
        //          -
    }


    string solve(string pro) override {
        bool save = true;
        string sol = "";
        // if we already solve this problem
        if (this->cm->alreadySolved(pro)) {
            cout << "We took the solution from the files." << endl;
            sol = this->cm->getSolution(pro);
            save = false;
        }
        // if its a new problem
        Matrix<Point>* m = getMatrix(pro);
        BFS<Point>* bfs = new BFS<Point>();
        sol = bfs->search(m);
        if (save) {
            this->cm->save(pro, sol);
        }
        this->updateGraph(pro);
        return sol;
    }
};


#endif //PROJ2_MATRIXSOLVER_H