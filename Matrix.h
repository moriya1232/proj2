//
// Created by moriya on 07/01/19.
//

#ifndef PROJ2_MATRIX_H
#define PROJ2_MATRIX_H

using namespace std;
#include "State.h"
#include <string>
#include <vector>
#include "Searchable.h"
#include "Point.h"

template <class T>
class Matrix : public Searchable<Point> {
    using StateOfPoint = State<Point>;
    vector<vector<State<Point>*>> states;
public:
    size_t n;
    size_t m;
    State<Point>* start;
    State<Point>* goal;

    State<Point>* getInitialState() {
        return start;
    }

    bool isGoalState(State<Point>* state) {
        return state == this->goal;
    }

    Matrix(vector<vector<int>> arr, size_t m ,size_t n) {
        this->n = n;
        this->m = m;
        vector<vector<State<Point>*>> vec;
        vector<State<Point>*> v;
        //State** temp = *this->states;
        for (int i=0; i< m ;++i) {
            for (int j=0; j< n; ++j) {
                string str = to_string(i) + " " + to_string(j);
                int bla = arr[i][j];
                State<Point>* s = new StateOfPoint(Point(i,j));
                s->setCost(bla);
                s->setI(i);
                s->setJ(j);
                v.push_back(s);
            }
            vec.push_back(v);
            v.clear();
        }
        this->states = vec;
    }

    vector<vector<State<Point>*>> getAllTheStates() {
        return  this->states;
    }

    vector<State<Point>*> getAllPossibleStates(State<Point> t){
        vector<State<Point>*> result;
        int y;
        // get the neighbors
        int row_limit = n-1;
        if(row_limit > 0){
            int column_limit = m-1;
            int i = t.getState().getI();
            int j = t.getState().getJ();
            for(int x = max(0, i-1); x <= min(i+1, row_limit); x++){
                for(y = max(0, j-1); y <= min(j+1, column_limit); y++){
                    if((x != i && y == j) || (j!=y && x==i)) {
                        State<Point>* tempState(this->states[x][y]);
                        result.push_back(tempState);
                    }
                }
            }
        }
        return result;
    }

    State<Point>* getGoalState(){
        return this->goal;
    }

    size_t getSize(){
        return this->m * this->n;
    }

    void setInitialState(State<Point>* p) {
        this->start = p;
    }

    void setGoalState(State<Point>* p) {
        this->goal = p;
    }

    vector<State<Point>*> getAllStates(){
        vector<State<Point>*> li;
        for(vector<vector<State<Point>*>>::iterator it = this->states.begin(); it!=this->states.end();++it) {
            for(vector<State<Point>*>:: iterator it2 = (*it).begin(); it2!=(*it).end();++it2) {
                li.push_back(*it2);
            }
        }
        return li;
    }



};
#endif //PROJ2_MATRIX_H