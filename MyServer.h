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
class MyServer : public server_side::Server {
protected:
    MatrixHandler<Matrix*, MatrixSolver*>* clientHandler;
    int sockfd;
    bool run;
    virtual void handleClient(ClientHandler*, int) = 0;
public:
    MyServer();
    void stop() override;
    //void open(int, MatrixHandler<Matrix*, list<State*>>*) override;
    void open(int, MatrixHandler<Matrix*, MatrixSolver*>*) override;
    void start(MatrixHandler<Matrix*, MatrixSolver*>* ch) override;
    //void start(MatrixSolver*);
};

#endif //UNTITLED6_SERVER_H