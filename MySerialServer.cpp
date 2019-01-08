//
// Created by moriya on 02/01/19.
//
#include <thread>
#include "MySerialServer.h"

template<typename problem, typename solution>
int MySerialServer<problem,solution>:: open(int port, ClientHandler<problem,solution> ch) {
    //thread listenToServer(openServer, port, ch);
    //listenToServer.detach();
}