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
        src/src_accessory.cpp
        src/src_value_conventer.cpp
)

set(SOURCES_FILES_TESTS
        test/test_kalkulator_prosty.cpp
        test/test_zespolone.cpp
        test/test_kalkulator_macierzy.cpp
        test/test_pola.cpp
        test/test_przelicznik_wartosci.cpp
        test/test_logarytmy.cpp
        test/test_całki.cpp
        test/test_rownania.cpp
)

include(SetCommonConfig.cmake)
