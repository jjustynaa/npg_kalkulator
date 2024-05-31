cmake_minimum_required(VERSION 3.13)

project(projekt)

set(PROJECT_ID projekt)

set(SOURCE_FILES
        src/projekt.cpp
)

set(SOURCES_FILES_TESTS
        test/test_kalkulator_prosty.cpp
        test/test_zespolone.cpp
        test/test_kalkulator_macierzy.cpp
        test/test_pola.cpp
)

include(SetCommonConfig.cmake)
