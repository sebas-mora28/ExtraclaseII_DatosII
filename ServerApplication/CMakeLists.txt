cmake_minimum_required(VERSION 3.15)
project(ServerApplication)

set(CMAKE_CXX_STANDARD 14)

add_executable(ServerApplication main.cpp "Server_/ServerSocket.cpp" Graph/GraphNodo.cpp
        Graph/GraphEdge.cpp Graph/Graph.cpp Graph/GraphLoader.cpp Headers/GraphLoader.h Headers/Graph.h Headers/GraphEdge.h
        Headers/GraphNodo.h)

