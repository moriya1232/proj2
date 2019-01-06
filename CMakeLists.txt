cmake_minimum_required(VERSION 3.13)
project(proj2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(proj2
        BFS.h
        BinaryExpression.cpp
        BinaryExpression.h
        CacheManager.cpp
        CacheManager.h
        ClientHandler.cpp
        ClientHandler.h
        Divide.cpp
        Divide.h
        Expression.cpp
        Expression.h
        ExpressionSolver.cpp
        ExpressionSolver.h
        FileCacheManager.h
        FileCatchManager.cpp
        main.cpp
        Minus.cpp
        Minus.h
        Multiplication.cpp
        Multiplication.h
        MySerialServer.cpp
        MySerialServer.h
        MyTestClientHandler.cpp
        MyTestClientHandler.h
        Number.cpp
        Number.h
        ParallelServer.cpp
        ParallelServer.h
        Plus.cpp
        Plus.h
        Searchable.cpp
        Searchable.h
        Server.cpp
        Server.h
        Solver.cpp
        Solver.h
        StringReverser.cpp
        StringReverser.h
        UnaryExpression.cpp
        UnaryExpression.h
        UsefulFunctions.h)
