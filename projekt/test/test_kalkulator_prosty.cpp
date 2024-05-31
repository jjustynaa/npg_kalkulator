#include "gtest/gtest.h"
#include "projekt.hpp"

TEST(KalkulatorProsty, DodawnieLiczb){
    EXPECT_EQ(addition(4.43,3.21), 7.64);
}

TEST(KalkulatorProsty, OdejmowanieLiczb){
    EXPECT_EQ(subtraction(7,5), 2);
}

TEST(KalkulatorProsty, MnozenieLiczb){
    EXPECT_EQ(multiplication(6,3), 18);
}

TEST(KalkulatorProsty, DzielenieLiczb){
    EXPECT_EQ(division(6,3), 2);
}

TEST(KalkulatorProsty, ResztaDzielenia){
    EXPECT_EQ(modulo(6,5), 1);
}

TEST(KalkulatorProsty, Potegowanie){
    EXPECT_EQ(potegowanie(6,3), 216);
    EXPECT_EQ(potegowanie(1.2,2),1.44);
    EXPECT_EQ(potegowanie(4,-2), 0.0625);
}

TEST(KalkulatorProsty, Pierwiastkowanie){
    EXPECT_EQ(pierwiastkowanie(16,2), 4);
    EXPECT_EQ(pierwiastkowanie(3,2),1.7321);
    EXPECT_EQ(pierwiastkowanie(1.44,2), 1.2);
    EXPECT_EQ(pierwiastkowanie(-8,3), -2);
}
