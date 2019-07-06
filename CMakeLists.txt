cmake_minimum_required(VERSION 3.7)
project(Project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Home.cpp
        Home.h
        Main.cpp
        MyExc.cpp
        MyExc.h
        Plot.cpp
        Plot.h
        Shop.cpp
        Shop.h
        Statement.cpp
        Statement.h
        Thing.cpp
        Thing.h)

add_executable(Project ${SOURCE_FILES})