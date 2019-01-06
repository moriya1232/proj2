//
// Created by moriya on 02/01/19.
//

#ifndef UNTITLED6_CACHEMANAGER_H
#define UNTITLED6_CACHEMANAGER_H

#include <unordered_map>
using namespace std;

class CacheManager {
unordered_map< string, string> cm;
virtual void wirteToFile() = 0;

};

#endif //UNTITLED6_CACHEMANAGER_H
