cmake_minimum_required(VERSION 3.23)
project(EuroDiffusion)

set(CMAKE_CXX_STANDARD 20)

FILE(COPY data DESTINATION ${CMAKE_BINARY_DIR})

add_executable(EuroDiffusion main.cpp
        parser/CaseParser.cpp
        parser/CaseParser.h
        parser/ParsedCountry.cpp
        parser/ParsedCountry.h
        Vector2.cpp
        Vector2.h
        solver/CountrySolution.cpp
        solver/CountrySolution.h
        solver/DiffusionSolver.cpp
        solver/DiffusionSolver.h
        solver/Grid.cpp
        solver/Grid.h
        solver/City.cpp
        solver/City.h
        solver/Country.cpp
        solver/Country.h solver/CoinChange.cpp solver/CoinChange.h)

