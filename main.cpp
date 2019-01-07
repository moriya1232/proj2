#include <iostream>
#include "BFS.h"
#include "Matrix.h"

namespace Just_For_Now {
    T** createMatrix() {
        T** result = { 0 };
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                result[i][j] = rand() % 100;
            }
        }
        return result;
    }
}

int main() {
    BFS bfs();
    size_t n = 10, m = 10;
    Matrix<T>* matrix = new (nothrow) Matrix<T>(Just_For_Now::createMatrix(), n, m);
    bfs().search(matrix);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}