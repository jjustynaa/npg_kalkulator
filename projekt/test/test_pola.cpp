#include "gtest/gtest.h"

#include "main.hpp"

TEST(KalkulatorPola, Prostokat){
    double a, b;
    a = 5;
    b = 10;
    double area = rectangularArea(a,b);

    EXPECT_EQ(area, 50);
}

TEST(KalkulatorPola, Trojkat){
    double a, b, c, h, angle;
    a = 3;
    b = 4;
    c = 5;
    h = 4;
    angle = 90;
    double area1 = triangleArea1(a, h);
    double area2 = triangleArea2(a, b, c);
    double area3 = triangleArea3(a, b, angle);

    EXPECT_EQ(area1, 6);
    EXPECT_EQ(area2, 6);
    EXPECT_EQ(area3, 6);
}

TEST(KalkulatorPola, Romb){
    double a, h, e, f;
    a = 5;
    h = 10;
    e = 10;
    f = 10;
    double area1 = diamondArea1(a,h);
    double area2 = diamondArea2(e,f);

    EXPECT_EQ(area1, 50);
    EXPECT_EQ(area2, 50);
}

TEST(KalkulatorPola, Trapez){
    double a, b, h;
    a = 10;
    b = 10;
    h = 5;
    double area = trapezeArea(a,b,h);

    EXPECT_EQ(area, 50);

}