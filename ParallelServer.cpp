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
    if (str.compare(buffer)) {
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

static void openServer(int newsockfd, ClientHandler* ch) {
    char buffer[100];
    bool end = false;
    vector<string> matrixHolder;
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
            matrixHolder = split(matrixHolder, tempString, ',');
        // here i should execute the ch with the proper matrix
        } else {

        }
    }
}

void ParallelServer::handleClient(int newsockfd, ClientHandler* ch) {
    thread t(openServer, newsockfd, ch);
    t.detach();
}
