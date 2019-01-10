//
// Created by moriya on 02/01/19.
//
#include "MyTestClientHandler.h"
#include <string.h>
#include <unistd.h>
#include <sstream>

using namespace std;

template<>
MyTestClientHandler<string, string>::MyTestClientHandler(Solver<string, string>* sol) {
    //this->cm = cm;
    this->solver = sol;
}

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

template <>
void MyTestClientHandler<string, string>::handleClient(int newsockfd) {
    char buffer[100];
    bool end = false;
    string problem = "";
    string solution = "";
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
            problem += tempString;
            problem += ';';
        } else {
            // check if we already solved this problem before
            //if (this->cm->alreadySolved(problem)) {
                // fill in
           // } else {
                solution = this->solver->solve(problem);
            }
            // save the problem with its solution
           // this->cm->save(problem, solution);
        }
    }
}