cmake_minimum_required(VERSION 3.23)
project(TRABALHOAED)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(TRABALHOAED
        src/Models/Student.cpp
        src/Models/Student.h
        main.cpp src/Utils/FileMan.cpp src/Models/Uc.cpp src/Models/Uc.h src/Models/Class.cpp src/Models/Class.h src/Utils/FileMan.h)
