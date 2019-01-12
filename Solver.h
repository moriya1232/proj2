//
// Created by aviv on 12/31/18.
//

#ifndef SECONDYEARPROJECT_BIU_SOLVER_H
#define SECONDYEARPROJECT_BIU_SOLVER_H



/**
 * Solver Interface
 */
#include "CacheManager.h"

namespace t {
    template <class problem, class solution>
    class Solver {
    protected: CacheManager* cm;
    public:
        Solver(CacheManager* cm) { this->cm = cm;}
        virtual solution solve(problem) = 0;
        virtual void updateGraph(problem) = 0;

    };

}
#endif //SECONDYEARPROJECT_BIU_SOLVER_H