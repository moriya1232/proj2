//
// Created by moriya on 02/01/19.
//
/*
#ifndef UNTITLED6_CACHEMANAGER_H
#define UNTITLED6_CACHEMANAGER_H

#include <unordered_map>
using namespace std;
template  <class problem, class solution>
class CacheManager {
protected:
    unordered_map< pair<string,string>, string> m;

public:
    CacheManager();
    virtual bool alreadySolved(problem) = 0;
    virtual solution getSolution(problem) = 0;
    virtual void save(problem, solution) = 0;
};

#endif //UNTITLED6_CACHEMANAGER_H*/