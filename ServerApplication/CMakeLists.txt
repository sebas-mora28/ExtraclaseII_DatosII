cmake_minimum_required(VERSION 3.15)
project(ServerApplication)

set(CMAKE_CXX_STANDARD 14)

add_executable(ServerApplication main.cpp "Server /ServerSocket.cpp")