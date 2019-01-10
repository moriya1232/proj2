//
// Created by moriya on 09/01/19.
//

#ifndef PROJ2_MATRIXHANDLER_H
#define PROJ2_MATRIXHANDLER_H

using namespace std;

#include <list>
#include "ClientHandler.h"
#include "Matrix.h"
#include "MatrixSolver.h"
#include <string.h>
#include <unistd.h>
#include <sstream>

class MatrixHandler : public ClientHandler {

public:
    MatrixHandler() {
        this->solver= new MatrixSolver();
        this->cachemanager = new CacheManager();
    }


    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11
    void handleClient(istream &inputStream, ostream &outputStream) {
        std::string line, answer;
        getline(inputStream, line);
        std::string sent(line);
        while (sent != "end" || !sent.empty()) {
            if (this->cachemanager->containsSolution(&sent))
                this->cachemanager->getSolution(&sent);
            else
                answer = this->solver->solve(sent);
            this->cachemanager->saveSolution(&sent, &answer);
            getline(cin, sent);
        }
    }

};



#endif //PROJ2_MATRIXHANDLER_H