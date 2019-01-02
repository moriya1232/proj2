cmake_minimum_required(VERSION 3.13)
project(untitled6)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled6 main.cpp
            Server.cpp Server.h
            ClientHandler.cpp ClientHandler.h
            MySerialServer.h MySerialServer.cpp
            MyTestClientServer.cpp MyTestClientServer.h
            Solver.cpp Solver.h
        Problem.cpp Problem.h
        Solution.cpp Solution.h
        CacheManager.cpp CacheManager.h)