#include "gtest/gtest.h"
#include "main.hpp"

TEST(Macierze, Dodawanie){
    std::size_t n = 2;
    std::vector<std::vector<int>> m1 {{1,2},{3,4}};
    std::vector<std::vector<int>> m2 {{1,2},{3,4}};

    std::vector<std::vector<int>> m_expect {{2,4},{6,8}};
    std::vector<std::vector<int>> new_m = addMatrix(m1, m2, n, n);

    EXPECT_EQ(new_m,  m_expect);
}

TEST(Macierze, Odejmowanie){
    std::size_t n = 2;
    std::vector<std::vector<int>> m1 {{1,2},{3,4}};
    std::vector<std::vector<int>> m2 {{1,2},{3,4}};

    std::vector<std::vector<int>> m_expect {{0,0},{0,0}};
    std::vector<std::vector<int>> new_m = substractMatrix(m1, m2, n, n);

    EXPECT_EQ(new_m,  m_expect);

}

TEST(Macierze, Mnozenie){
    std::size_t n = 2;
    std::vector<std::vector<int>> m1 {{1,2},{3,1}};
    std::vector<std::vector<int>> m2 {{0,3},{2,1}};

    std::vector<std::vector<int>> m_expect {{4,5},{2,10}};
    std::vector<std::vector<int>> new_m = multiMatrix(m1, m2, n, n,n);

    EXPECT_EQ(new_m,  m_expect);
}

TEST(Macierze, Wyznacznik){
    std::vector<std::vector<int>> m2 {{1,2},{3,1}};
    std::vector<std::vector<int>> m3 {{1,2,3},{9,8,7},{5,6,7}};
    std::vector<std::vector<int>> m4 {{6,5,3,4},{9,8,7,6},{4,5,6,7},{1,9,2,6}};

    EXPECT_EQ(determinant(m2), -5);
    EXPECT_EQ(determinant(m3), 0);
    EXPECT_EQ(determinant(m4), 442);
}