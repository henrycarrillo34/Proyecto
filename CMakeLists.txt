cmake_minimum_required(VERSION 3.20)
project(blockchain)

set(CMAKE_CXX_STANDARD 17)

add_executable(blockchain main.cpp blockchain.h sha256.h)
