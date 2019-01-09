//
// Created by omer on 1/9/19.
//

#include "MyPair.h"
template <class T1, class T2>
MyPair<T1, T2>::MyPair(T1 s1, T2 s2) {
    this->left = s1;
    this->right = s2;
}
template <class T1, class T2>
T1 MyPair<T1, T2>::getLeft() {
    return this->left;
}
template <class T1, class T2>
T2 MyPair<T1, T2>::getRight() {
    return this->right;
}
template <class T1, class T2>
void MyPair<T1, T2>::setLeft(T1 s) {
    this->left = s;
}
template <class T1, class T2>
void MyPair<T1, T2>::setRight(T2 s) {
    this->right = s;
}