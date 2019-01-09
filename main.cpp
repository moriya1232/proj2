#include <iostream>
#include "BFS.h"
#include "ClientHandler.h"
#include "Matrix.h"
#include <vector>
#include <sstream>
#include "MatrixHandler.h"

namespace  create_script {
    static void writeScript() {
        ofstream script("script.txt", ios::app);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                script << rand() % 100;
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

    static int** readMatrixFromScript(string filename) {
        ifstream inFile(filename);
        int i = 0;
        int n = getNumberOfLines(filename);
        int m = getNumberOfColumns(filename);
        int** result = (int**) malloc (sizeof(int) * n * m);
        string line = "";
        vector<string> vec;
        // open the file
        if (inFile.is_open()) {
            getline(inFile, line);
            vec = split(vec, line, ' ');
            vector<string>::iterator it = vec.begin();
            for (int j = 0; j < vec.size(); j++) {
                string tempString = *it;
                int bla = stoi(tempString);
                result[i][j] = bla;
            }
            i++;
        }
        return result;
    }
}

int main() {
    // JUST A REPLACEMENT FOR THE REAL SCRIPT
    create_script::writeScript();
    CacheManager* cm = new(nothrow) CacheManager();
    int** arr = create_script::readMatrixFromScript("script.txt");
    Matrix* m = new (nothrow) Matrix(arr, 3, 3);
    BFS* bfs = new(nothrow) BFS();
    MatrixHandler* ch = new (nothrow) MatrixHandler(bfs,cm , m);
    //std::cout << "Hello, World!" << std::endl;
    create_script::clearFile("script.txt");
    return 0;
}