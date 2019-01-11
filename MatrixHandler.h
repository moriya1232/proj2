//
// Created by moriya on 09/01/19.
//

#ifndef PROJ2_MATRIXHANDLER_H
#define PROJ2_MATRIXHANDLER_H

using namespace std;

#include <list>

#include "Matrix.h"
#include "MatrixSolver.h"
#include "AbstractClientHandler.h"
#include <string.h>
#include "Solver.h"
#include <unistd.h>
#include <sstream>

class MatrixHandler : public omer::AbstractClientHandler<string, string> {

public:
    MatrixHandler(CacheManager* cm) : AbstractClientHandler(cm) {}

    static string addLine(string origin, string addition) {
        vector<string> v = omer::split(v,addition, ' ');
        for (int i = 0; i < v.size(); i++) {
            origin += v[i];
        }
        return origin;
    }

    string getStringMatrixFromServer(int newsockfd) {
        char buffer[100];
        bool end = false;
        string result = "";
        while (!end) {
            /* If connection is established then start communicating */
            bzero(buffer, 100);
            int n = read(newsockfd, buffer, 99);
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }
            // check if the input has the end word
            if (omer::endReceived(buffer, n)) {
                end = true;
            }
            // if buffer doesnt have "end" in it
            if (!end) {
                // here the reading action went succesfully
                result += string(buffer);
                result += ';';
                // here i should execute the ch with the proper matrix
            } else {
                return result;
            }
        }
    }

    void handleClient(int newsockfd) {
        t::Solver<string, string>* ms = new (nothrow) MatrixSolver<string, string>(this->cm);
        string matrix = getStringMatrixFromServer(newsockfd);
        string sol = ms->solve(matrix);
    }

};



#endif //PROJ2_MATRIXHANDLER_H