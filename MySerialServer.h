//
// Created by moriya on 02/01/19.
//

#ifndef UNTITLED6_MYSERIALSERVER_H
#define UNTITLED6_MYSERIALSERVER_H

#include "Server.h"

template <class problem, class solution>
class MySerialServer :public Server<problem,solution> {
int open(int, ClientHandler<problem,solution>);

};
#endif //UNTITLED6_MYSERIALSERVER_H
