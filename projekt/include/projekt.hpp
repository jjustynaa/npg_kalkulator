//
// Created by Marek Generowicz on 27/04/2024.
//

#ifndef PROJEKT_PROJEKT_HPP
#define PROJEKT_PROJEKT_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstddef>
#include <iomanip>

void cykl_o_tryg();
void cykl();
void tryg();


void blankspace_deleter(std::string);
//podstawy
double potegowanie (double liczba, int potega);
double pierwiastkowanie(double liczba, int stopien);
void kalk_poteg();
void print_zao();
double addition(double num1, double num2);
double subtraction(double num1, double num2);
double division(double num1, double num2);
double multiplication(double num1, double num2);
double exponential(double num1, double num2);
int modulo(int num1, int num2);


//matrix
std::vector<std::vector<int>> createMatrix(std::size_t rows, std::size_t col);
void showMatrix(std::vector<std::vector<int>> matrix, std::size_t rows, std::size_t col);
void addMatrix();
void substractMatrix();
void multiMatrix();
void matrix();


//kwadratowa
std::vector<double> kwadratowa(double a, double b, double c);
std::vector<double> kwadratowa(const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c);


//zespolone

class Complex {
public:
    double Re;
    double Im;
    double Phi;

    Complex(double re, double im) : Re(re), Im(im), Phi(clasic_to_tryg()) {};

    Complex(double alfa) : Re(cos(alfa)), Im(sin(alfa)), Phi(alfa) {};

    double cpx_lg() const { return sqrt(Re * Re + Im * Im); }

    double clasic_to_tryg() const;
};

Complex add_complex(Complex& cpx_1, Complex& cpx_2){
    return {cpx_1.Re + cpx_2.Re, cpx_1.Im + cpx_2.Im};
}

Complex sub_complex(Complex& cpx_1, Complex& cpx_2){
    return {cpx_1.Re - cpx_2.Re, cpx_1.Im - cpx_2.Im};
}

Complex multi_complex(Complex& cpx_1, Complex& cpx_2){
    return {cpx_1.Re * cpx_2.Re - cpx_1.Im * cpx_2.Im, cpx_1.Re * cpx_2.Im + cpx_1.Im * cpx_2.Re};
}

Complex div_complex(Complex& cpx_1, Complex& cpx_2){
    return {((cpx_1.Re * cpx_2.Re) + (cpx_1.Im * cpx_2.Im)) / (cpx_2.Re * cpx_2.Re + cpx_2.Im * cpx_2.Im),
            ((cpx_1.Im * cpx_2.Re) - (cpx_1.Re * cpx_2.Im)) / (cpx_2.Re * cpx_2.Re + cpx_2.Im * cpx_2.Im)};
}

Complex inerface_complex(Complex& cpx){
    return {cpx.Re, -cpx.Im};
}

void print_complex(Complex cpx);

void complex_choice();

#endif //PROJEKT_PROJEKT_HPP
