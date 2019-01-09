#include <iostream>
#include "BFS.h"
#include "ClientHandler.h"
#include "Matrix.h"


namespace  create_script {
    static void writeScript() {
        ofstream script("script.txt", ios::app);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                script << rand() % 100;
                script << " ";
            }
            //script << '\n';
        }
        script.close();
    }
}

int main() {
    create_script::writeScript();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}