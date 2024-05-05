#ifndef PROJEKT_PROJEKT_HPP
#define PROJEKT_PROJEKT_HPP

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <cstddef>

void cykl_o_tryg();

void cykl();

void tryg();

void print_zao();
double addition(double num1, double num2);
double subtraction(double num1, double num2);
double division(double num1, double num2);
double multiplication(double num1, double num2);
double exponential(double num1, double num2);
int modulo(int num1, int num2);

std::vector<std::vector<int>> createMatrix(std::size_t rows, std::size_t col);
void showMatrix(std::vector<std::vector<int>> matrix, std::size_t rows, std::size_t col);
void addMatrix();
void substractMatrix();
void multiMatrix();
void matrix();

#endif //PROJEKT_PROJEKT_HPP
