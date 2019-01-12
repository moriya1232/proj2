//
// Created by omer on 1/12/19.
//

#ifndef PROJ2_SERIALSERVER_H
#define PROJ2_SERIALSERVER_H

#include "MyServer.h"
#include <unistd.h>
#include <stdio.h>
#include <thread>
#include <netinet/in.h>
#include <string>
#include <string.h>
#include "Server.h"
#include <errno.h>
#include <list>
#include "MatrixHandler.h"

using namespace std;
namespace server_side {

    class SerialServer : public server_side::Server {
        bool busy;
        int port;
        int sockfd;
    public:
        SerialServer() {}

        void open(int port, ClientHandler *ch) {
            this->port = port;
            int sockfd, clilen;
            char buffer[100];
            struct sockaddr_in serv_addr, cli_addr;
            int n;
            /* First call to socket() function */
            sockfd = socket(AF_INET, SOCK_STREAM, 0);
            while (sockfd < 0) {
                sockfd = socket(AF_INET, SOCK_STREAM, 0);
            }
            /* Initialize socket structure */
            bzero((char *) &serv_addr, sizeof(serv_addr));
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_addr.s_addr = INADDR_ANY;
            serv_addr.sin_port = htons(port);
            /* Now bind the host address using bind() call.*/
            if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
                perror("ERROR on binding");
                exit(1);
            }
            /* Now start listening for the clients, here process will
               * go in sleep mode and will wait for the incoming connection
            */
            listen(sockfd, 1);
            this->sockfd = sockfd;
            thread t(&SerialServer::start, this, ch);
            t.join();
            //start(ch);
        }

        void stop() {
            this->busy = false;
            close(this->port);
        }

        void start(ClientHandler* ch) {
            struct sockaddr_in cli_addr;
            int newsockfd, clilen = sizeof(cli_addr);
            this->busy = true;
            while (busy) {
                //timeval timeout;
                //timeout.tv_sec = 10;
                ///timeout.tv_usec = 0;

                //setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
                /* Accept actual connection from the client */
                cout << "waiting for a connection..." << endl;
                newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
                cout << "connection went successfully" << endl;
                if (newsockfd < 0) {
                    if (errno == EWOULDBLOCK) {
                        cout << "Timeout!\n";
                        stop();
                        break;
                    } else {
                        perror("Something went wrong\n");
                        stop();
                        break;
                    }
                }
                ch->handleClient(newsockfd);
            }
        }
    };
}



#endif //PROJ2_SERIALSERVER_H