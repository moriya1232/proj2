//
// Created by omer on 1/6/19.
//
/*
#ifndef UNTITLED6_FILECACHEMANAGER_H
#define UNTITLED6_FILECACHEMANAGER_H

#include "CacheManager.h"
#include "fstream"
#include "iostream"
template  <class problem, class solution>
class FileCacheManager : public CacheManager<string, string> {

public:
    FileCacheManager();
    void write(string nameFile);
    void load(string nameFile);
    void insertToMap(string s1 , string s2, string s3);
    bool alreadySolved(problem);
    solution getSolution(problem);
    void save(problem, solution);
};

#endif //UNTITLED6_FILECACHEMANAGER_H*/