//
// Created by omer on 1/12/19.
//

#ifndef PROJ2_SERIALSERVER_H
#define PROJ2_SERIALSERVER_H

#include "MyServer.h"

class SerialServer : public MyServer {
protected:
    bool handleClient(ClientHandler* ch, int newsockfd) override {
        ch->handleClient(newsockfd);
    }
};



#endif //PROJ2_SERIALSERVER_H
