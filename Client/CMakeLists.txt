cmake_minimum_required(VERSION 3.27)
project(Client)

set(CMAKE_CXX_STANDARD 17)

add_executable(Client client.cpp
        tcpSocket.cpp
        tcpSocket.h
)
target_link_libraries(Client ws2_32)