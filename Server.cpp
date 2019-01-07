//
// Created by moriya on 01/01/19.
//

#include <unistd.h>
#include <stdio.h>
#include <thread>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include "ClientHandler.h"

using namespace std;
namespace Server_side {
    int open(int port, ClientHandler* ch) {
        int sockfd, newsockfd, portno, clilen;
        char buffer[100];
        struct sockaddr_in serv_addr, cli_addr;
        int n;

        /* First call to socket() function */
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd < 0) {
            perror("ERROR opening socket");
            exit(1);
        }

        /* Initialize socket structure */
        bzero((char *) &serv_addr, sizeof(serv_addr));
        portno = stod(to_string(port).c_str());

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(portno);

        /* Now bind the host address using bind() call.*/
        if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            perror("ERROR on binding");
            exit(1);
        }
        /* Now start listening for the clients, here process will
           * go in sleep mode and will wait for the incoming connection
        */

        listen(sockfd, 5);
        clilen = sizeof(cli_addr);
        /* Accept actual connection from the client */
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }
        this->sockfd = sockfd;
        this->newsockfd = newsockfd;
        //start(sockfd, newsockfd);}
    }

    void Server::openServer(int port, ClientHandler cl) {

    }

    void Server::start(int sockfd, int newsockfd) {
        char buffer[100] = {'\0'};
        /* Accept actual connection from the client */
        /*int newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }
        while (true) {
            /* If connection is established then start communicating */
        /*bzero(buffer, 100);
        int n = read(newsockfd, buffer, 99);
        if (endReceived(buffer, n)) {
            break;
        }
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        // here we supposed to create a ClientHandler and execute it
    }*/
        while (true) {
            /* If connection is established then start communicating */
            bzero(buffer, 100);
            int n = read(newsockfd, buffer, 99);

            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }

        }
        bool Server::endReceived(char *buffer, int n) {
            // if buffer has the word 'end' and a \0 return true
            if (buffer[0] == 'e' && buffer[1] == 'n' && buffer[2] == 'd' && n == 4) {
                return true;
            }
        }

        int Server::stop() {
            this->run = false;
        }

        bool Server::isOpen() {
            return this->run;
        }
    }
}