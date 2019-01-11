//
// Created by omer on 1/11/19.
//

#ifndef PROJ2_FILECACHEMANAGER_H
#define PROJ2_FILECACHEMANAGER_H
#include "CacheManager.h"

class FileCacheManager : public CacheManager {
public:
    FileCacheManager() {
        ifstream file("Problems.txt");
        if (file.is_open()) {
            return;
        }
        ofstream file1("Problems.txt", ios::app);
        file1 << "Problems" << endl;
        ofstream file2("Solutions.txt", ios::app);
        file2 << "Solutions" << endl;
        file1.close();
        file2.close();
    }

    static string getNumber(string &line) {
        int i = 0;
        string result = "";
        char c = line[i];
        while (c != ' ') {
            result += c;
            c = line[++i];
        }
        return result;
    }

    static string getIndex(string s, int i) {
        ifstream file;
        if (i == 1) {
            ifstream file("Problems.txt");
        } else {
            ifstream file("Solutions.txt");
        }
        if (file.is_open()) {
            string s = "";
            string line = "";
            getline(file, line);
            while (line != "") {
                s = getNumber(line);
                if (line.compare(s) == 0) {
                    file.close();
                    return s;
                }
            }
        } else {
            return "";
        }
    }

    bool alreadySolved(string problem) override {
        ifstream inFile("Problems.txt");
        if (inFile.is_open()) {
            string line = "";
            getline(inFile, line);
            while (line != ""){
                string temp = getIndex(problem, 1);
                line = line.substr(temp.length());
                if (problem.compare(line) == 0) {
                    inFile.close();
                    return true;
                }
                getline(inFile, line);
            }
            return false;
        }
        else {
            cout << "The problem has not solved yes." << endl;
            inFile.close();
            return false;
        }
    }

    static string getSolutionByIndex(string indx) {
        ifstream file("Solutions.txt");
        if (file.is_open()) {
            string line = "";
            getline(file, line);
            while (line != "") {
                string temp = getIndex(line, 0);
                if (temp.compare(indx) == 0) {
                    file.close();
                    return line.substr(temp.length());
                }
            }
        }
    }

    // Assuming we already checked that the problem was solved
    string getSolution(string problem) override {
        if (!alreadySolved(problem)) { return ""; }
        string indx = getIndex(problem, 1);
        return getSolutionByIndex(indx);
    }

    // Assuming we call save method only when we see a new problem
    void save(string problem, string solution) override{
        // something that gives me IDs
        int id = 1;
        ofstream file1("Problems.txt", ios::app);
        file1 << to_string(id) + " The problem: " + problem << endl;
        ofstream file2("Solutions.txt", ios::app);
        file2 << to_string(id) + " The solution: " + solution << endl;
        cout << "Item saved." << endl;
        file1.close();
        file2.close();
    }
};

#endif //PROJ2_FILECACHEMANAGER_H
