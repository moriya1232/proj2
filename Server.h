//
// Created by moriya on 02/01/19.
//

#ifndef UNTITLED6_SERVER_H
#define UNTITLED6_SERVER_H


#include "ClientHandler.h"
/**
 * the missiom of the server is to care of getting values from the client
 */
class Server{
    ClientHandler* clientHandler;
    int port;
    bool stillOpen;
    char* input;
public:
    Server(int p);
    bool getStillOpen();
    int open(int);
    bool isOpen();
    int stop();
    void setInput(char*);
    ClientHandler* getClientHandler();
    void setClientHandler(ClientHandler*);





};

#endif //UNTITLED6_SERVER_H
