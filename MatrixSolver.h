//
// Created by moriya on 09/01/19.
//

#ifndef PROJ2_MATRIXSOLVER_H
#define PROJ2_MATRIXSOLVER_H

#include <sstream>
#include "Matrix.h"
#include "Solver.h"

class MatrixSolver : public server_side::Solver<Matrix*,list<State<Point>*>> {
    static bool endReceived(char *buffer, int n) {
        string str = "end";
        if (str.compare(buffer) == 0) {
            return true;
        }
        return false;
    }

    static vector<string> split(vector<string> v, const std::string& s, char delimiter)
    {
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter))
        {
            v.push_back(token);
        }
        return v;
    }

    static vector<vector<int>> mergeVectors(vector<vector<int>> v1, vector<string> v2) {
        vector<int> temp;
        for (int i = 0; i < v2.size(); i++) {
            temp.push_back(stoi(v2[i]));
        }
        v1.push_back(temp);
        return v1;
    }

    static vector<int> convertStringToLine(vector<string> v) {
        vector<int> result;
        for (int i = 0; i < v.size(); i++) {
            int value = stoi(v[i]);
            result.push_back(value);
        }
        return result;
    }

    string solve(string problem){
        vector<vector<int>> matrixHolder;
        vector<string> tempVector;
        vector<string> parts = split(parts,problem, ';');
        for (int i = 0; i < parts.size(); i++) {
            vector<string> v = split(v, parts[i], ' ');
            vector<int> currLine = convertStringToLine(v);
            matrixHolder.push_back(currLine);
        }
        int n = matrixHolder.size();
        Matrix* m = new Matrix(matrixHolder, n, n);
        BFS<Point>* bfs = new BFS<Point>();
        string solution = bfs->search(m);
        return solution;
    }

};


#endif //PROJ2_MATRIXSOLVER_H