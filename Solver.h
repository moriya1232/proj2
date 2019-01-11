//
// Created by aviv on 12/31/18.
//

#ifndef SECONDYEARPROJECT_BIU_SOLVER_H
#define SECONDYEARPROJECT_BIU_SOLVER_H



/**
 * Solver Interface
 */
namespace t {
    template <class problem, class solution>
    class Solver {
    public:
        Solver() {}
        virtual solution solve(problem) = 0;

    };

}
#endif //SECONDYEARPROJECT_BIU_SOLVER_H