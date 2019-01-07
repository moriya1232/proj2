//
// Created by moriya on 02/01/19.
//
#include <thread>
#include "MySerialServer.h"

int MySerialServer:: open(int port, ClientHandler ch) {
    thread listenToServer(openServer, port, ch);
    listenToServer.detach();
}