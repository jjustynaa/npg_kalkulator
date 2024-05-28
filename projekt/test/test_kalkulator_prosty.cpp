#include "gtest/gtest.h"
#include "projekt.hpp"

TEST(KalkulatorProsty, DodawanieLiczb){
    EXPECT_EQ(addition(1,2),3);
    EXPECT_EQ(addition(10.8562,7.7324),18.5886);
}

TEST(KalkulatorProsty, OdejmowanieLiczb){
    EXPECT_EQ(addition(1,2),-1);
    EXPECT_EQ(addition(10.5,9), 1.5);
}

