//
// Created by omer on 1/11/19.
//

#ifndef PROJ2_POINT_H
#define PROJ2_POINT_H

class Point {
    unsigned int i;
    unsigned int j;
public: Point(int i, int j) { this->i = i; this->j = j; }
Point() { this->i = 0; this->j = 0; }
    int getI() { return this->i; }
    int getJ() { return this->j; }
    inline bool operator==(const Point &other) const { return this->i == other.i && this->j == other.j; }
    inline bool operator<(const Point &other) const { return !(*this == other); }
};

#endif //PROJ2_POINT_H
