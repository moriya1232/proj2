//
// Created by moriya on 02/01/19.
//
#include "ClientHandler.h"

template <typename problem,typename solution>
ClientHandler<problem,solution>:: ClientHandler(Solver<problem,solution>* sol,CacheManager* cache){
    this->solver = sol;
    this->cm = cache;
}