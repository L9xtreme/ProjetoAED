cmake_minimum_required(VERSION 3.23)
project(PROJETOAED)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(PROJETOAED
        src/Models/Student.cpp
        src/Models/Student.h
        main.cpp
        src/Utils/FileMan.cpp
        src/Models/Uc.cpp
        src/Models/Uc.h
        src/Models/Class.cpp
        src/Models/Class.h
        src/Utils/FileMan.h
        src/Models/Schedule.cpp
        src/Models/Schedule.h
        src/Utils/MenuMan.cpp
        src/Utils/MenuMan.h
        src/Utils/ListMan.cpp
        src/Utils/ListMan.h)
