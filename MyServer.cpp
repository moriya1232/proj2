//
// Created by moriya on 01/01/19.
//

#include <unistd.h>
#include <stdio.h>
#include <thread>
#include <netinet/in.h>
#include <string>
#include <string.h>
#include <errno.h>
#include "MyServer.h"
#include <list>
#include "ClientHandler.h"

using namespace std;

    MyServer::MyServer() {
        // put a default value
        this->sockfd = 0;
    }

    void MyServer::open(int port, ClientHandler ch) {
        int sockfd, clilen;
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

        listen(sockfd, 5);
        this->sockfd = sockfd;
        start(ch);
    }
}
    // basically runs for 10 seconds and somehow should stop the operation after 10 sec
    static void isTimeOut() {
        time_t start, end;
        double elapsed;

        time(&start);  /* start the timer */

        do {
            time(&end);

            elapsed = difftime(end, start);
            /* For most data types one could simply use
                elapsed = end - start;
                but for time_t one needs to use difftime(). */

           // printf("Time elapsed: &#37;f\n", elapsed);
        } while(elapsed < 10);  /* run for ten seconds */
    }

    void MyServer::start(ClientHandler ch) {
        struct sockaddr_in cli_addr;
        int newsockfd, clilen = sizeof(cli_addr);
        while (run) {
            /* Accept actual connection from the client */
            newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
            if (newsockfd < 0) {
                perror("ERROR");
                exit(1);
            }
            solveClientsProblem(newsockfd, ch);
        }
    }
        bool MyServer::endReceived(char *buffer, int n) {
            string str = "end";
            if (str.compare(buffer)) {
                return true;
            }
            return false;
        }

        int MyServer::stop() {
            this->run = false;
        }
    }
}