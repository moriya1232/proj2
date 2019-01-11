//
// Created by moriya on 02/01/19.
//

#ifndef UNTITLED6_CLIENDHANDLER_H
#define UNTITLED6_CLIENDHANDLER_H

#include "CacheManager.h"

class ClientHandler {
public:
    virtual void handleClient(int) = 0;

};
#endif //UNTITLED6_CLIENDHANDLER_H