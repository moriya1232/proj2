//
// Created by moriya on 02/01/19.
//

#include "CacheManager.h"


CacheManager:: CacheManager(unordered_map<pair<string,string>,string> m) {
    this->cm=m;
}

CacheManager:: CacheManager() {
    this->cm=unordered_map<pair<string,string>,string>;
}

unordered_map<pair<string,string>,string> CacheManager:: getMap() {
return this->cm;
}


void CacheManager:: insertToMap(pair<pair<string,string>,string> pair1) {
this->cm.insert(pair1);
}

void CacheManager:: insertToMap(string s1 , string s2, string s3){
    pair<string,string> pair1 = make_pair(s1,s2);
    pair<pair<string,string>,string> pair2 = make_pair(pair1,s3);
    this->cm.insert(pair2);

}
