//
// Created by omer on 1/6/19.
//
#include <thread>
#include <strings.h>
#include <string>
#include "ParallelServer.h"
#include <vector>

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

static void solveClientsProblem(ClientHandler* ch, int newsockfd) {
    ch->handleClient(newsockfd);
}

void ParallelServer::handleClient(ClientHandler* ch, int newsockfd) {
    //openServer(newsockfd, ms);
    thread t(solveClientsProblem, ch, newsockfd);
    t.detach();
}