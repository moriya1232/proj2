//
// Created by moriya on 01/01/19.
//

#include "Server.h"
#include <unistd.h>
#include <stdio.h>
#include <thread>
//#include <iostream>
//#include <sys/types.h>
//#include <sys/socket.h>
#include <netinet/in.h>
//#include <strings.h>
//#include <stdlib.h>
#include <string.h>
//#include <unistd.h>
//#include <pthread.h>
#include <errno.h>
//#include <ctype.h>

using namespace std;

Server:: Server(int p) {
 this->port = p;
 this->stillOpen = true;
}

void Server:: setInput(char* toInput) {
 this->input = toInput;
}

bool Server:: getStillOpen() {
 return this->stillOpen;
}
static void openServer(int port, Server* server) {
 int sockfd, newsockfd, portno, clilen;
 char buffer[100];
 struct sockaddr_in serv_addr, cli_addr;
 int  n;

 /* First call to socket() function */
 sockfd = socket(AF_INET, SOCK_STREAM, 0);

 if (sockfd < 0) {
  perror("ERROR opening socket");
  exit(1);
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

 listen(sockfd,5);
 clilen = sizeof(cli_addr);
 /* Accept actual connection from the client */
 newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

 if (newsockfd < 0) {
  perror("ERROR on accept");
  exit(1);
 }
 while (server->getStillOpen()) {
  /* If connection is established then start communicating */
  bzero(buffer, 100);
  n = read(newsockfd, buffer, 99);

  if (n < 0) {
   perror("ERROR reading from socket");
   exit(1);
  }

  // the reciever from the client (just 100 chars) has in the input !
  server->setInput(buffer);



 }
}
ClientHandler* Server:: getClientHandler() {return this->clientHandler;}

void Server:: setClientHandler(ClientHandler* ch){this->clientHandler = ch;}

int Server:: open(int port) {
 thread listenToServer(openServer, this);
 listenToServer.detach();
};
int Server:: stop() {
 this->stillOpen = false;
};

bool Server:: isOpen() {
 return this->stillOpen;
}