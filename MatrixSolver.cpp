//
// Created by moriya on 09/01/19.
//


#include "MatrixSolver.h"
#include "BFS.h"
#include <sstream>

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

string MatrixSolver::convertListStateToString(list<State*> list1 , Searchable* searchable) {
    string result="";
    for (list<State*>:: iterator it = list1.begin(); it!=(list1.end());++it){
        if ( ++it == list1.end()) {
            break;
        }
        --it;
        State after = (**(++it));
        it--;
        if (after.getState()->getI()> (*it)->getState()->getI()) {
            result+="down";
        } else if (after.getState()->getI() < (*it)->getState()->getI()) {
            result+="up";
        } else if (after.getState()->getJ()> (*it)->getState()->getJ()) {
            result+="right";
        } else if (after.getState()->getJ()< (*it)->getState()->getJ()) {
            result+="left";
        }
        result+=",";
    }
    result = result.substr(0,result.length()-1);
    return result;
}

string MatrixSolver:: solve(string problem){
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
    BFS* bfs = new BFS();
    string solution = convertListStateToString(bfs->search(m), m);
    return solution;
    }