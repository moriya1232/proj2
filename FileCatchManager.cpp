//
// Created by omer on 1/6/19.
//

/*

#include "FileCacheManager.h"
#include "vector"
#include "sstream"

using namespace std;
template <>
FileCacheManager<string, string>:: FileCacheManager() {}
template <>
void FileCacheManager<string, string>:: write(string nameFile){
    /*ofstream out (nameFile, ios::trunc);
    for(auto it = this->cm.begin();it != this->cm.end(); ++it) {
        string input = (it)->first.first;
        string solver =  (it)->first.second;
        string solu = it->second;
        out << input << "," << solver << "," << solu <<"," <<endl;
    }*/
/*
}
static vector<string> split(vector<string> v, const std::string& s, char delimiter)
{
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        v.push_back(token);
    }
    return v;
}
template <>
bool FileCacheManager<string, string>::alreadySolved(string s) {
return false;
}
template <>
string FileCacheManager<string, string>::getSolution(string problem) {
    return "";
}

template <>
void FileCacheManager<string, string>::save(string, string) {
    ;
}

template<>
void FileCacheManager<string, string>:: load(string nameFile) {
    ifstream in(nameFile);
    string line;
    if (in.is_open()) {
        getline(in, line);
        while (line.length()>3) {
            vector<string> vect;
            vect = split(vect, line, ',');
            string s1 = vect[0];
            string s2 = vect[1];
            string s3 = vect[2];
            insertToMap(s1,s2,s3);
            getline(in, line);
        }

    }

}*/
/*
template <>
void FileCacheManager<string, string>::insertToMap(string s1 , string s2, string s3){
   pair<string,string> pair1 = make_pair(s1,s2);
    pair<pair<string,string>,string> pair2 = pair<pair<string, string>, string>(pair1,s3);
    //this->m.insert(pair2);

}*/