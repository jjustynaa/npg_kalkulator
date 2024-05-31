#ifndef PROJEKT_EQUATION_HPP
#define PROJEKT_EQUATION_HPP

#include <vector>
#include <complex>
#include "complex.hpp"

//kwadratowa
void kwadratowa(double a, double b, double c);
void kwadratowa(Complex a, Complex b, Complex c);

//równianie wielomianowe stopnia 3
std::vector<double> solveCubic(double a, double b, double c, double d);

void equation();

#endif //PROJEKT_EQUATION_HPP
