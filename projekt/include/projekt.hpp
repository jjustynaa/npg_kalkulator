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
#include <complex>

void cykl_o_tryg();
void cykl();
void tryg();

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
std::vector<std::vector<int>> addMatrix (std::vector<std::vector<int>> matrix1, std::vector<std::vector<int>> matrix2, int rows, int col);
void addMatrix_user();
std::vector<std::vector<int>> substractMatrix (std::vector<std::vector<int>> matrix1, std::vector<std::vector<int>> matrix2, int rows, int col);
void substractMatrix_user();
std::vector<std::vector<int>> multiMatrix(std::vector<std::vector<int>> matrix1, std::vector<std::vector<int>> matrix2, int rows1, int rows2, int col2);
void multiMatrix_user();
void matrix();

//zespolone
class Complex {
public:
    double Re;
    double Im;
    double Phi;

    Complex(double re, double im) : Re(re), Im(im), Phi(clasic_to_tryg()) {};

    Complex(double alfa) : Re(cos(alfa)), Im(sin(alfa)), Phi(alfa) {};

    Complex operator + (const Complex& other) const {return {Re + other.Re,Im + other.Im};}
    Complex operator - (const Complex& other) const {return {Re - other.Re,Im - other.Im};}
    Complex operator * (const Complex& other) const {return {Re * other.Re - Im * other.Im, Re * other.Im + Im * other.Re};}
    Complex operator / (const Complex& other) const {return {((Re * other.Re) + (Im * other.Im)) / (other.Re * other.Re + other.Im * other.Im),
                                                             ((Im * other.Re) - (Re * other.Im)) / (other.Re * other.Re + other.Im * other.Im)};}

    double cpx_lg() const { return sqrt(Re * Re + Im * Im); }

    double clasic_to_tryg() const;
};



//Complex add_complex(Complex& cpx_1, Complex& cpx_2){return {cpx_1.Re + cpx_2.Re, cpx_1.Im + cpx_2.Im};}

//Complex sub_complex(Complex& cpx_1, Complex& cpx_2){return {cpx_1.Re - cpx_2.Re, cpx_1.Im - cpx_2.Im};}

//Complex multi_complex(Complex& cpx_1, Complex& cpx_2){return {cpx_1.Re * cpx_2.Re - cpx_1.Im * cpx_2.Im, cpx_1.Re * cpx_2.Im + cpx_1.Im * cpx_2.Re};}

//Complex div_complex(Complex& cpx_1, Complex& cpx_2){return {((cpx_1.Re * cpx_2.Re) + (cpx_1.Im * cpx_2.Im)) / (cpx_2.Re * cpx_2.Re + cpx_2.Im * cpx_2.Im), ((cpx_1.Im * cpx_2.Re) - (cpx_1.Re * cpx_2.Im)) / (cpx_2.Re * cpx_2.Re + cpx_2.Im * cpx_2.Im)};}

Complex sqrt(Complex& cpx);

Complex inerface_complex(Complex& cpx){return {cpx.Re, -cpx.Im};}

void print_complex(Complex cpx);

void complex_choice();


//kwadratowa
void kwadratowa(double a, double b, double c);
void kwadratowa(Complex a, Complex b, Complex c);

//równianie wielomianowe stopnia 3
std::vector<double> solveCubic(double a, double b, double c, double d);

//pola figur
bool does_triangle_exist(double a, double b, double c);
double triangleArea1(double a, double h);
double triangleArea2(double a, double b, double c);
double triangleArea3(double a, double b, double angle);
void triangle();
double rectangularArea(double a, double b);
void rectangular();
double diamondArea1(double a, double h);
double diamondArea2(double e, double f);
void diamond();
double trapezeArea(double a, double b, double h);
void trapeze();
void area();


#endif //PROJEKT_PROJEKT_HPP
