//
// Created by moriya on 02/01/19.
//

#ifndef UNTITLED6_SERVER_H
#define UNTITLED6_SERVER_H

class Server{
int port;
public:
    Server(int p);
int open(int port);
bool isOpen();
int stop();




};

#endif //UNTITLED6_SERVER_H
