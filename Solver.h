//
// Created by moriya on 02/01/19.
//

#ifndef UNTITLED6_SOLVER_H
#define UNTITLED6_SOLVER_H

#include "string"


namespace server_side {


    template<class problem, class solution>
    class Solver {
    public:

        /*
         * by this function we solve the problem.
         */
        virtual solution solve(problem) = 0;
    };
}
#endif //UNTITLED6_SOLVER_H