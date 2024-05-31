cmake_minimum_required(VERSION 3.13)

project(projekt)

set(PROJECT_ID projekt)

set(SOURCE_FILES
        src/src_matrix.cpp
        src/src_area.cpp
        src/src_extraction_exponentiation.cpp
        src/src_logarithm.cpp
        src/src_simple.cpp
        src/src_complex.cpp
        src/src_integral.cpp
        src/src_equation.cpp
        src/src_rounding.cpp
        src/src_trigonometric.cpp
)

set(SOURCES_FILES_TESTS
        test/test_kalkulator_prosty.cpp
        test/test_zespolone.cpp
        test/test_kalkulator_macierzy.cpp
        test/test_pola.cpp
)

include(SetCommonConfig.cmake)
