cmake_minimum_required(VERSION 3.29)
project(vertinimas)

set(CMAKE_CXX_STANDARD 14)

# Define the main project executable
add_executable(vertinimas
    studentas.h
    studentas.cpp
    main.cpp
    duomenys.cpp
    duomenys.h
    rezultatas.cpp
    rezultatas.h
    rikiavimas.cpp
    rikiavimas.h
    vertinimas.cpp
    vertinimas.h
    ivedimas.cpp
    ivedimas.h
    zmogus.h
    zmogus.cpp
)

