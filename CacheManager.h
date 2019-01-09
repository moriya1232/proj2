//
// Created by moriya on 02/01/19.
//

#ifndef UNTITLED6_CACHEMANAGER_H
#define UNTITLED6_CACHEMANAGER_H

#include <unordered_map>
using namespace std;

class CacheManager {
protected:
unordered_map< pair<string,string>, string> cm;

public:
    CacheManager();
    CacheManager(unordered_map<pair<string,string>,string>);
    unordered_map<pair<string,string>,string> getMap();
    void insertToMap(pair<pair<string,string>,string>);
    void insertToMap(string , string, string);

};

#endif //UNTITLED6_CACHEMANAGER_H
