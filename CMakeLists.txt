cmake_minimum_required(VERSION 3.13)
project(proj2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

include_directories(.)

add_executable(proj2
        Astar.h
        BestFirstSearch.h
        BFS.h
        BinaryExpression.cpp
        BinaryExpression.h
        CacheManager.h
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
        SerialServer.h
        ISearcher.h
        main.cpp
        MatrixSolver.h
        Point.h
        Matrix.h
        MatrixHandler.h
        Minus.cpp
        Minus.h
        Multiplication.cpp
        Multiplication.h
        MyServer.cpp
        MyServer.h
        Number.cpp
        Number.h
        ParallelServer.cpp
        ParallelServer.h
        Plus.cpp
        Plus.h
        Searchable.h
        Searcher.h
        Server.h
        Solver.h
        State.h
        StringReverser.h
        UnaryExpression.cpp
        UnaryExpression.h
        UsefulFunctions.h
        MyPair.h
        AbstractClientHandler.h
        Main.h)