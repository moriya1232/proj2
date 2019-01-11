//
// Created by omer on 1/6/19.
//

#ifndef UNTITLED6_PARALLELSERVER_H
#define UNTITLED6_PARALLELSERVER_H

#include "MyServer.h"
class ParallelServer : public MyServer {
protected:
    void handleClient(ClientHandler*, int) override;
};

#endif //UNTITLED6_PARALLELSERVER_H