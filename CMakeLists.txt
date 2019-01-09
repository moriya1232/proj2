cmake_minimum_required(VERSION 3.13)
project(proj2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

include_directories(.)

add_executable(proj2
        Astar.cpp
        Astar.h
        BestFirstSearch.cpp
        BestFirstSearch.h
        BFS.cpp
        BFS.h
        BinaryExpression.cpp
        BinaryExpression.h
        CacheManager.cpp
        CacheManager.h
        ClientHandler.cpp
        ClientHandler.h
        DFS.cpp
        DFS.h
        Divide.cpp
        Divide.h
        Expression.cpp
        Expression.h
        ExpressionSolver.cpp
        ExpressionSolver.h
        FileCacheManager.h
        FileCatchManager.cpp
        ISearcher.cpp
        ISearcher.h
        main.cpp
        MatrixSolver.cpp
        MatrixSolver.h
        Matrix.cpp
        Matrix.h
        MatrixHandler.cpp
        MatrixHandler.h
        Minus.cpp
        Minus.h
        Multiplication.cpp
        Multiplication.h
        MyPriorityQueue.cpp
        MyPriorityQueue.h
        MyServer.cpp
        MyServer.h
        MyTestClientHandler.cpp
        MyTestClientHandler.h
        Number.cpp
        Number.h
        ParallelServer.cpp
        ParallelServer.h
        Plus.cpp
        Plus.h
        Point.cpp
        Point.h
        Searchable.cpp
        Searchable.h
        Searcher.cpp
        Searcher.h
        Server.h
        Solver.cpp
        Solver.h
        State.cpp
        State.h
        StringReverser.cpp
        StringReverser.h
        UnaryExpression.cpp
        UnaryExpression.h
        UsefulFunctions.h
        MyPair.h MyPair.cpp)
