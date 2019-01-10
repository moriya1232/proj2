//
// Created by omer on 1/6/19.
//
#include <thread>
#include <strings.h>
#include <string>
#include "ParallelServer.h"
#include <vector>

static string convertListStateToString(list<State*> list1 , Searchable* searchable) {
    string result = "";
    for (list<State *>::iterator it = list1.begin(); it != (list1.end()); ++it) {
        if (++it == list1.end()) {
            break;
        }
        --it;
        State after = (**(++it));
        it--;
        if (after.getState()->getI() > (*it)->getState()->getI()) {
            result += "down";
        } else if (after.getState()->getI() < (*it)->getState()->getI()) {
            result += "up";
        } else if (after.getState()->getJ() > (*it)->getState()->getJ()) {
            result += "right";
        } else if (after.getState()->getJ() < (*it)->getState()->getJ()) {
            result += "left";
        }
        result += ",";

    }
    result = result.substr(0, result.length() - 1);
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

static void solveClientsProblem(ClientHandler* ch, int newsockfd) {
    ch->handleClient(newsockfd);
}

void ParallelServer::handleClient(ClientHandler* ch, int newsockfd) {
    //openServer(newsockfd, ms);
    thread t(solveClientsProblem, ch, newsockfd);
    t.detach();
}