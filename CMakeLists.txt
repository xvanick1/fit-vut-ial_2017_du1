cmake_minimum_required(VERSION 3.8)
project(ial_2017_du1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        c202/c202-test.c
        c202/c202.c
        c202/c202.h
        c204/c204-test.c
        c204/c204.c
        c204/c204.h
        c206/c206-test.c
        c206/c206.c
        c206/c206.h)

add_executable(ial_2017_du1 ${SOURCE_FILES})