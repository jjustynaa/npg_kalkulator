#include "gtest/gtest.h"
#include "main.hpp"


TEST(PrzelicznikPredkosc, kmhNAms){
    std::stringstream input("1\n100\n");
    std::cin.rdbuf(input.rdbuf());

    double result = conventer_speed();

    EXPECT_EQ(result, 27.7778);
}

TEST(PrzelicznikPredkosc, msNAkmh) {
    std::stringstream input("2\n10\n");
    std::cin.rdbuf(input.rdbuf());

    double result = conventer_speed();

    EXPECT_EQ(result, 36);
}

TEST(PrzelicznikDlugosc, kmNAmile) {
    std::stringstream input("1\n100\n");
    std::cin.rdbuf(input.rdbuf());

    double result = conventer_length();

    EXPECT_EQ(result, 62.1371);
}

TEST(PrzelicznikDlugosc, mileNAkm) {
    std::stringstream input("2\n100\n");
    std::cin.rdbuf(input.rdbuf());

    double result = conventer_length();

    EXPECT_EQ(result, 160.9344);
}

TEST(PrzelicznikDlugosc, kmNAm) {
    std::stringstream input("3\n18\n");
    std::cin.rdbuf(input.rdbuf());

    double result = conventer_length();

    EXPECT_EQ(result, 18000);
}

TEST(PrzelicznikDlugosc, mNAkm) {
    std::stringstream input("4\n20\n");
    std::cin.rdbuf(input.rdbuf());

    double result = conventer_length();

    EXPECT_EQ(result, 0.02);
}

TEST(PrzelicznikDlugosc, kmNAcm) {
    std::stringstream input("5\n0.6\n");
    std::cin.rdbuf(input.rdbuf());

    double result = conventer_length();

    EXPECT_EQ(result, 60000);
}

TEST(PrzelicznikDlugosc, cmNAkm) {
    std::stringstream input("6\n55\n");
    std::cin.rdbuf(input.rdbuf());

    double result = conventer_length();

    EXPECT_EQ(result, 0.00055);
}

TEST(PrzelicznikDlugosc, mNAcm) {
    std::stringstream input("7\n0.5\n");
    std::cin.rdbuf(input.rdbuf());

    double result = conventer_length();

    EXPECT_EQ(result, 50);
}

TEST(PrzelicznikDlugosc, cmNAm) {
    std::stringstream input("8\n17\n");
    std::cin.rdbuf(input.rdbuf());

    double result = conventer_length();

    EXPECT_EQ(result, 0.17);
}

TEST(PrzelicznikCzasu, hNAmin) {
    std::stringstream input("1\n0.5\n");
    std::cin.rdbuf(input.rdbuf());

    double result = conventer_time();

    EXPECT_EQ(result, 30);
}

TEST(PrzelicznikCzasu, minNAh) {
    std::stringstream input("2\n78\n");
    std::cin.rdbuf(input.rdbuf());

    double result = conventer_time();

    EXPECT_EQ(result, 1.3);
}

TEST(PrzelicznikCzasu, minNAs) {
    std::stringstream input("3\n78\n");
    std::cin.rdbuf(input.rdbuf());

    double result = conventer_time();

    EXPECT_EQ(result, 4680);
}

TEST(PrzelicznikCzasu, sNAmin) {
    std::stringstream input("4\n4\n");
    std::cin.rdbuf(input.rdbuf());

    double result = conventer_time();

    EXPECT_EQ(result, 0.0667);
}

TEST(Przelicznik, CyfryZnaczace){
    double n = 2.137;
    int dig = 2;
    double result = significant_figure(n,dig);

    EXPECT_EQ(result, 2.1);
}