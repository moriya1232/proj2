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
    bool run;
    //char* input;
public:
    Server(int p);
    static void openServer(int, ClientHandler);
    bool getRun();
    virtual int open(int, ClientHandler) = 0;
    static void start(int ,int);
    bool isOpen();
    int stop();
    static bool endReceived(char*, int);
    void setInput(char*);
    ClientHandler* getClientHandler();
    void setClientHandler(ClientHandler*);





};

#endif //UNTITLED6_SERVER_H
