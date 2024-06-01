#include "gtest/gtest.h"
#include "main.hpp"

TEST(Logarytmy, Calkowite){
    EXPECT_NEAR(logarithm(3,10), 0.477121, 0.000001);
    EXPECT_NEAR(logarithm(7,3), 1.771243, 0.000001);
}

TEST(Logarytmy, Zmiennoprzecinkowe){
    EXPECT_NEAR(logarithm(10.12,4), 1.669568, 0.000001);
    EXPECT_NEAR(logarithm(10,2.1),3.103476, 0.000001);
}
