//
// Created by omer on 1/6/19.
//

#ifndef UNTITLED6_FILECACHEMANAGER_H
#define UNTITLED6_FILECACHEMANAGER_H

#include "CacheManager.h"
#include "fstream"
#include "iostream"

class FileCacheManager : public CacheManager {

public:
FileCacheManager(unordered_map<pair<string,string>,string>);
void write(string nameFile);
void load(string nameFile);
void insertToMap(string s1 , string s2, string s3);
};

#endif //UNTITLED6_FILECACHEMANAGER_H
