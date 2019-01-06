//
// Created by moriya on 02/01/19.
//

#ifndef UNTITLED6_SOLVER_H
#define UNTITLED6_SOLVER_H
template <class problem, class solution>
class Solver {

public:
    virtual solution solve(problem)=0;

};
#endif //UNTITLED6_SOLVER_H
