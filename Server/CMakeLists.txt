cmake_minimum_required(VERSION 3.27)
project(Server)

set(CMAKE_CXX_STANDARD 17)

add_executable(Server server.cpp
        tcpSocket.h
        tcpSocket.cpp
)

target_link_libraries(Server ws2_32)
