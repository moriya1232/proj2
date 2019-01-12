//
// Created by omer on 1/11/19.
//

#ifndef PROJ2_ABSTRACTCLIENTHANDLER_H
#define PROJ2_ABSTRACTCLIENTHANDLER_H

#include "ClientHandler.h"
#include <vector>
#include "Solver.h"
#include <sstream>

namespace  omer {

    template<class problem, class solution>
    class AbstractClientHandler : public ClientHandler {
    protected:
        t::Solver<problem, solution> *solver;
        CacheManager* cm;
        AbstractClientHandler(CacheManager* cm) { this->cm = cm; }
    };

    static bool endReceived(char *buffer, int n) {
        std::string str = "end";
        if (str.compare(buffer) == 0) {
            return true;
        }
        return false;
    }

    static std::vector<std::string> split(std::vector<std::string> v, const std::string& s, char delimiter)
    {
        std::string token;
        std::stringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter))
        {
            v.push_back(token);
        }
        return v;
    }

    static std::vector<std::vector<int>> mergeListTovectors(std::vector<std::vector<int>> v1, std::vector<std::string> v2) {
        std::vector<int> temp;
        for (int i = 0; i < v2.size(); i++) {
            temp.push_back(stoi(v2[i]));
        }
        v1.push_back(temp);
        return v1;
    }

    static std::vector<int> convertStringToLine(std::vector<std::string> v) {
        std::vector<int> result;
        for (int i = 0; i < v.size(); i++) {
            int value = stoi(v[i]);
            result.push_back(value);
        }
        return result;
    }

}



#endif //PROJ2_ABSTRACTCLIENTHANDLER_H