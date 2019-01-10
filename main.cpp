#include <iostream>
#include "BFS.h"
#include "ClientHandler.h"
#include "Matrix.h"
#include <vector>
#include <sstream>
#include "MatrixHandler.h"
#include "ParallelServer.h"

namespace  create_script {
    static void writeScript() {
        ofstream script("script.txt", ios::app);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                script << rand() % 21;
                script << ' ';
            }
            script << '\n';
        }
        script.close();
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

    static void clearFile(string filename) {
        ofstream inFile;
        inFile.open(filename, ofstream::out | ofstream::trunc);
        inFile.close();
    }

    static int getNumberOfLines(string filename) {
        ifstream inFile(filename);
        int count = 0;
        string line = "";
        if (inFile.is_open()) {
            getline(inFile, line);
            while (line != "") {
                getline(inFile, line);
                count++;
            }
        }
        return count;
    }

    static int getNumberOfColumns(string filename) {
        ifstream inFile(filename);
        string line = "";
        vector<string> vec;
        if (inFile.is_open()) {
            getline(inFile, line);
            vec = split(vec, line, ' ');
            return vec.size();
        }
    }

    static vector<vector<int>> readMatrixFromScript(string filename) {
        ifstream inFile(filename);
        int i = 0, n = getNumberOfLines(filename);
        vector<vector<int>> vec;
        string line = "";
        vector<string> v;
        vector<int> tempVector;
        // open the file
        if (inFile.is_open()) {
            getline(inFile, line);
            while (i < n) {
                v = split(v, line, ' ');
                for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
                    string tempString = *it;
                    int bla = stoi(tempString);
                    tempVector.push_back(bla);
                }
                vec.push_back(tempVector);
                tempVector.clear();
                v.clear();
                getline(inFile, line);
                i++;
            }
        }
        return vec;
    }

    static string convertListStateToString(list<State*> list1 , Searchable* searchable){
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

    static void printMatrix(vector<vector<int>> arr, string str) {
        for (int i = 0;i < 3; i++) {
            for (int j=0; j< 3; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "" << endl;
        }
        cout << "" << endl;
        cout << "And the best path for you is: " << str << endl;
    }
}

static vector<vector<int>> theProblematicMatrix() {
    vector<vector<int>> result;
    vector<int> temp;
    temp.push_back(11);
    temp.push_back(5);
    temp.push_back(67);
    result.push_back(temp);
    temp.clear();
    temp.push_back(26);
    temp.push_back(14);
    temp.push_back(32);
    result.push_back(temp);
    temp.clear();
    temp.push_back(12);
    temp.push_back(4);
    temp.push_back(1);
    result.push_back(temp);
    return result;
}

int main() {
    // JUST A REPLACEMENT FOR THE REAL SCRIPT
    /*int x = 5;
    MatrixSolver* ms = new(nothrow) MatrixSolver();
    ParallelServer* tempServer = new ParallelServer();
    tempServer->open(5402, ms);*/
    create_script::writeScript();
    CacheManager* cm = new(nothrow) CacheManager();
    MatrixSolver* ms = new(nothrow) MatrixSolver();
    //vector<vector<int>> arr = create_script::readMatrixFromScript("script.txt");
    vector<vector<int>> arr = theProblematicMatrix();
    Matrix* m = new (nothrow) Matrix(arr, 3, 3);
    //system("open");
    list<State*> result1 = ms->solve(m);
    string result2 = create_script::convertListStateToString(result1, m);
    create_script::printMatrix(arr, result2);
    //MatrixHandler<Matrix*, MatrixSolver*>* ch = new (nothrow) MatrixHandler<Matrix*, MatrixSolver*>(ms,cm , m);
    //std::cout << "Hello, World!" << std::endl;
    create_script::clearFile("script.txt");
    return 0;
}