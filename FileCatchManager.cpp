//
// Created by omer on 1/6/19.
//



#include "FileCacheManager.h"
#include "vector"
#include "sstream"

using namespace std;
/*
//FileCacheManager:: FileCacheManager(unordered_map<pair<string,string>,string> ma) : CacheManager(ma){
//}
void FileCacheManager:: write(string nameFile){
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

void FileCacheManager:: load(string nameFile) {
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

/*void FileCacheManager:: insertToMap(string s1 , string s2, string s3){
    pair<string,string> pair1 = make_pair(s1,s2);
    pair<pair<string,string>,string> pair2 = make_pair(pair1,s3);
    this->cm.insert(pair2);

}*/