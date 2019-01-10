//
// Created by moriya on 02/01/19.
//

#ifndef UNTITLED6_SERVER_H
#define UNTITLED6_SERVER_H


#include "Server.h"
#include <time.h>
/**
 * the missiom of the server is to care of getting values from the client
 */
 template<class problem,class solution>
class MyServer : public server_side::Server {
    ClientHandler<problem,solution>* clientHandler;
    int sockfd;
    bool run;
public:
    MyServer();
    void stop() override;
    //void open(int, MatrixHandler<Matrix*, list<State*>>*) override;
    void open(int, Solver<problem,solution>*) override;
    //void start(MatrixHandler<Matrix*, list<State*>>* ch);
    void start(Solver<problem,solution>*);
};

#endif //UNTITLED6_SERVER_H
