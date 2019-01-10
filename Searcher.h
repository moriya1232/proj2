//
// Created by moriya on 06/01/19.
//

#ifndef PROJ2_SEARCHER_H
#define PROJ2_SEARCHER_H

#include "Searchable.h"
#include "ISearcher.h"


template <class T,class solution>
class Searcher: public ISearcher<T,solution>{

protected:
    int evaluatedNodes;

public:
    /**
    * this function is a constractor of searcher.
    */
    Searcher(this->evaluatedNodes=0;);
    /**
     * this function returns the number of nodes that we get until here.
     * @return number of nodes we get until here.
     */
    int getNumberOfNodesEvaluated(){return this->evaluatedNodes;}


    static string convertListStateToString(vector<State<T>*> list1 , Searchable<T>* searchable) {
        string result="";
        for (auto it = list1.begin(); it!=(list1.end());++it){
            if ( ++it == list1.end()) {
                break;
            }
            --it;
            State< after = (**(++it));
            it--;
            if (after.getState()->getI()> (*it)->getState()->getI()) {
                result+="down";
            } else if (after.getState()->getI() < (*it)->getState()->getI()) {
                result+="up";
            } else if (after.getState()->getJ()> (*it)->getState()->getJ()) {
                result+="right";
            } else if (after.getState()->getJ()< (*it)->getState()->getJ()) {
                result+="left";
            }
            result+=",";
        }
        result = result.substr(0,result.length()-1);
        return result;
    }

};
#endif //PROJ2_SEARCHER_H