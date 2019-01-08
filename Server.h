//
// Created by omer on 1/9/19.
//

#ifndef PROJ2_SERVER_H
#define PROJ2_SERVER_H

#include "ClientHandler.h"

namespace  server_side {
    class Server{
    protected:
        virtual void start(ClientHandler) = 0;
        virtual void solveClientsProblem(int, ClientHandler) = 0;
    public:
        virtual void open(int, ClientHandler) = 0;
        virtual void stop() = 0;
    };
}

#endif //PROJ2_SERVER_H
