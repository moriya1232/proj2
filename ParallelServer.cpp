//
// Created by omer on 1/6/19.
//
#include <thread>
#include <strings.h>
#include <string>
#include "ParallelServer.h"
#include <unistd.h>
#include <vector>
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
template<typename problem,typename solution>
//static void openServer(int newsockfd, MatrixHandler<Matrix*, list<State*>>* ch) {
static void openServer(int newsockfd, Solver<problem,solution>* ch) {
    char buffer[100];
    bool end = false;
    vector<vector<int>> matrixHolder;
    vector<string> tempVector;
    while (!end) {
        /* If connection is established then start communicating */
        bzero(buffer, 100);
        int n = read(newsockfd, buffer, 99);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        // check if the input has the end word
        if (endReceived(buffer, n)) {
            end = true;
        }
        // if buffer doesnt have "end" in it
        if (!end) {
            // here the reading action went succesfully
            string tempString(buffer);
            tempVector = split(tempVector, tempString, ' ');
            matrixHolder = mergeVectors(matrixHolder, tempVector);
            tempVector.clear();
        // here i should execute the ch with the proper matrix
        } else {
            Matrix* m = new Matrix(matrixHolder, 3, 3);
            string solution1 = convertListStateToString(ch->solve(m), m);
            printMatrix(matrixHolder, solution1);
        }
    }
}

template <typename problem,typename solution>
void ParallelServer<problem,solution>::handleClient(int newsockfd, Solver<problem,solution>* c) {
//void ParallelServer<problem,solution>::handleClient(int newsockfd, MatrixSolver* ms) {
    //openServer(newsockfd, ms);
    thread t(openServer, newsockfd, c);
    t.detach();
}

