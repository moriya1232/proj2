//
// Created by moriya on 08/01/19.
//
#include "Point.h"


Point:: Point(int x, int y){
    this->i =x;
    this->j =y;
}

int Point:: getI(){
    return this->i;
}

int Point:: getJ(){
    return this->j;
}

void Point:: setI(int i){
    this->i = i;
}

void Point:: setJ(int j){
    this->j=j;
}