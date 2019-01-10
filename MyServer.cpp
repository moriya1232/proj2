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
#include "MatrixHandler.h"

using namespace std;
    template<typename problem,typename solution>
    MyServer<problem,solution>::MyServer() {
        // put a default value
        this->sockfd = 0;
        this->run = true;
    }

    //void MyServer::open(int port, MatrixHandler<Matrix*, list<State*>>* ch) {
    template<typename problem,typename solution>
    void MyServer<problem,solution>::open(int port, Solver<problem,solution>* ch) {
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

template<typename problem,typename solution>
    //void MyServer::start(MatrixHandler<Matrix*, list<State*>>* ch) {
    void MyServer<problem,solution>::start(Solver<problem,solution>* ch) {
        struct sockaddr_in cli_addr;
        int newsockfd, clilen = sizeof(cli_addr);
        while (run) {
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
                    cout << "Timeout bro!\n";
                    exit(2);
                } else {
                    perror("ERROR");
                    exit(1);
                }
            }
            handleClient(newsockfd, ch);
        }
    }
template<typename problem,typename solution>
        void MyServer<problem,solution>::stop() {
            this->run = false;
        }
