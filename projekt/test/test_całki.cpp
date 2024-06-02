#include "gtest/gtest.h"
#include "main.hpp"

TEST(Calki, Liniowa){
    EXPECT_NEAR(calka_liniowa(2,3,-3,-2), -2, 0.01);
    EXPECT_NEAR(calka_liniowa(2.3,4,1,6), 60.250, 0.01);
}

TEST(Calki, Kwadratowa){
    EXPECT_NEAR(calka_kwadratowa(1,6,4,5,15), 1723.333, 0.02);
    EXPECT_NEAR(calka_kwadratowa(2,7.1,3.4,-2,6), 290.133, 0.02);
}

TEST(Calki, Cos ){
    EXPECT_NEAR(calka_cos(-2.3,5), -0.213, 0.001);
    EXPECT_NEAR(calka_cos(1,3), -0.7, 0.001);
}

TEST(Calki, Sin){
    EXPECT_NEAR(calka_sin(7,8), 0.899, 0.001);
    EXPECT_NEAR(calka_sin(-1.2,3.5), 1.299, 0.001);
}