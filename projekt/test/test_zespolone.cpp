#include "gtest/gtest.h"
#include "main.hpp"

TEST(Zespolone, Dodawanie){
    Complex a (15, 3);
    Complex b (3, 1);
    Complex w = a + b;
    EXPECT_EQ(w.Re, 18);
    EXPECT_EQ(w.Im, 4);
}

TEST(Zespolone, Odejmowanie){
    Complex a (15, 3);
    Complex b (3, 1);
    Complex w = a - b;
    EXPECT_EQ(w.Re, 12);
    EXPECT_EQ(w.Im, 2);
}

TEST(Zespolone, Mnozenie){
    Complex a (15, 3);
    Complex b (3, 1);
    Complex w = a * b;
    EXPECT_EQ(w.Re, 42);
    EXPECT_EQ(w.Im, 24);
}


TEST(Zespolone, Dzielenie){
    Complex a (15, 3);
    Complex b (3, 1);
    Complex w = a / b;
    EXPECT_EQ(w.Re, 4.8);
    EXPECT_EQ(w.Im, -0.6);
}
