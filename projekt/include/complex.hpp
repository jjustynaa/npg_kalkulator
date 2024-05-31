#ifndef PROJEKT_COMPLEX_HPP
#define PROJEKT_COMPLEX_HPP

#include <cmath>

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
Complex inerface_complex(Complex& cpx);
void print_complex(Complex cpx);
void complex_choice();


#endif //PROJEKT_COMPLEX_HPP
