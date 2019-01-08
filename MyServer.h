//
// Created by moriya on 02/01/19.
//

#ifndef UNTITLED6_SERVER_H
#define UNTITLED6_SERVER_H


#include "Server.h"
/**
 * the missiom of the server is to care of getting values from the client
 */
class MyServer : public server_side::Server {
    ClientHandler clientHandler;
    int sockfd;
    bool run;
    //char* input;
public:
    MyServer();
    void stop() override;
    void open(int, ClientHandler) override;
    static bool endReceived(char*, int);





};

#endif //UNTITLED6_SERVER_H
