//
// Created by omer on 1/11/19.
//

#ifndef PROJ2_FILECACHEMANAGER_H
#define PROJ2_FILECACHEMANAGER_H
#include "CacheManager.h"

class FileCacheManager : public CacheManager {
    int indx;
public:
    FileCacheManager() {
        ifstream file("Problems.txt");
        if (file.is_open()) {
            return;
        }
        ofstream file1("Problems.txt", ios::app);
        ofstream file2("Solutions.txt", ios::app);
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

    static string getIndex(string s, string filename) {
        ifstream file(filename);
        if (file.is_open()) {
            string temp = "";
            string line = "";
            getline(file, line);
            while (line != "") {
                temp = getNumber(line);
                line = line.substr(temp.length() + 1);
                if (line.compare(s) == 0) {
                    file.close();
                    return temp;
                }
                getline(file, line);
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
                string temp = getNumber(line);
                line = line.substr(temp.length() + 1);
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
                string temp = getNumber(line);
                if (temp.compare(indx) == 0) {
                    file.close();
                    return line.substr(temp.length() + 1);
                }
            }
        }
    }

    // Assuming we already checked that the problem was solved
    string getSolution(string problem) override {
        if (!alreadySolved(problem)) { return ""; }
        string indx = getIndex(problem, "Problems.txt");
        return getSolutionByIndex(indx);
    }

    static int getLastID(string filename) {
        ifstream file("Problems.txt");
        if (file.is_open()) {
            string line = "";
            getline(file, line);
            while (line != "") {
                string temp = line;
                getline(file, line);
                if (line == ""){
                    return stoi(getNumber(temp)) + 1;
                }
            }
        }
        return 1;
    }

    // Assuming we call save method only when we see a new problem
    void save(string problem, string solution) override{
        // something that gives me IDs
        int id = getLastID("Problems.txt");
        cout << "The id is: " << to_string(id) << endl;
        ofstream file1("Problems.txt", ios::app);
        file1 << to_string(id) + " " + problem << endl;
        ofstream file2("Solutions.txt", ios::app);
        file2 << to_string(id) + " " + solution << endl;
        cout << "Item saved." << endl;
        file1.close();
        file2.close();
    }
};

#endif //PROJ2_FILECACHEMANAGER_H
