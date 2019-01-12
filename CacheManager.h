//
// Created by moriya on 02/01/19.
//

#ifndef UNTITLED6_CACHEMANAGER_H
#define UNTITLED6_CACHEMANAGER_H

#include <unordered_map>
#include <string>
using namespace::std;

class CacheManager {
public:
    virtual bool alreadySolved(string) = 0;
    virtual string getSolution(string) = 0;
    virtual void save(string, string) = 0;
};


#endif //UNTITLED6_CACHEMANAGER_H