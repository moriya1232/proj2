cmake_minimum_required(VERSION 3.13)
project(untitled6)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled6 main.cpp
            Server.cpp Server.h
            ClientHandler.cpp ClientHandler.h
            MySerialServer.h MySerialServer.cpp
        MyTestClientHandler.cpp MyTestClientHandler.h
            Solver.cpp Solver.h
        CacheManager.cpp CacheManager.h
        ExpressionSolver.h ExpressionSolver.cpp
        Expression.h Expression.cpp
        BinaryExpression.h BinaryExpression.cpp
        Plus.h Plus.cpp
        Minus.h Minus.cpp
        Divide.h Divide.cpp
        Multiplication.h Multiplication.cpp
        Number.h Number.cpp
        UnaryExpression.h UnaryExpression.cpp
        UsefulFunctions.h)