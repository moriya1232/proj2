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
    MyPair(T1, T2);
    T1 getLeft();
    T2 getRight();
    void setLeft(T1);
    void setRight(T2);
};

#endif //PROJ2_PAIR_H
