#include "gtest/gtest.h"
#include "main.hpp"

TEST(RownanieSzescienne, TrzyWyniki){
    std::vector<double> oczekiwany_wynik = {1.0, -2.0, -1.0};
    std::vector<double> dane = solveCubic(1, 2, -1, -2);

    EXPECT_EQ(dane, oczekiwany_wynik);
}