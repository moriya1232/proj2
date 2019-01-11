//
// Created by omer on 1/11/19.
//

#ifndef PROJ2_MAIN_H
#define PROJ2_MAIN_H

#include "ClientHandler.h"
#include "MatrixHandler.h"
#include <iostream>

namespace boot {
    class Main {
        static int main() {
            ClientHandler* clientHandler = new MatrixHandler();
            clientHandler->handleClient(cin, cout);
        }
    };
}

#endif //PROJ2_MAIN_H
