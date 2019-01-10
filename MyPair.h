//
// Created by omer on 1/9/19.
//

#ifndef PROJ2_PAIR_H
#define PROJ2_PAIR_H

#include <string>

using namespace std;

template <class T1, class T2>
class MyPair {
protected:
    T1 left;
    T2 right;
public:

    MyPair(T1 s1, T2 s2) {
        this->left = s1;
        this->right = s2;
    }
    
    T1 getLeft() {
        return this->left;
    }
    
    T2 getRight() {
        return this->right;
    }
    
    void setLeft(T1 s) {
        this->left = s;
    }
    
    void setRight(T2 s) {
        this->right = s;
    }
};

#endif //PROJ2_PAIR_H