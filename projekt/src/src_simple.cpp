#include "simple.hpp"
#include "accessory.hpp"
#include <iostream>

double addition(double num1, double num2) {
    return num1 + num2;
}

double subtraction(double num1, double num2) {
    return num1 - num2;
}

double division(double num1, double num2) {
    return num1 / num2;
}

double multiplication(double num1, double num2) {
    return num1 * num2;
}

int modulo(int num1, int num2) {
    return num1 % num2;
}

void simple() {
    prosty:
    int wyb;
    double x, y;
    std::cout << "Jakie dzialanie chcesz wykonac? \n"
                 "1. Dodawanie\n"
                 "2. Odejmowanie\n"
                 "3. Mnozenie\n"
                 "4. Dzielenie\n"
                 "5. Znalezienie reszty z dzielenia\n";
    std::cin >> wyb;

    switch(wyb) {
        case 1:
            std::cout << "Podaj liczby, ktore chcesz dodac" << std::endl;
            std::cin >> x >> y;
            std::cout << "Wynik: " << addition(x, y) << std::endl;
            break;
        case 2:
            std::cout << "Podaj liczby, ktore chcesz odjac" << std::endl;
            std::cin >> x >> y;
            std::cout << "Wynik: " << subtraction(x, y) << std::endl;
            break;
        case 3:
            std::cout << "Podaj liczby, ktore chcesz pomnozyc" << std::endl;
            std::cin >> x >> y;
            std::cout << "Wynik: " << multiplication(x, y) << std::endl;
            break;
        case 4:
            dzielenie:
            std::cout << "Podaj liczby, ktore chcesz podzielic" << std::endl;
            std::cin >> x >> y;
            if (y == 0) {
                mistake_value();
                goto dzielenie;
            } else {
                std::cout << "Wynik: " << division(x, y) << std::endl;
            }
            break;
        case 5:
            int a, b;
            reszta:
            std::cout << "Podaj liczby, ktore chcesz podzielic i obliczyc reszte" << std::endl;
            std::cin >> a >> b;
            if (b == 0) {
                mistake_value();
                goto reszta;
            } else {
                std::cout << "Wynik: " << modulo(a, b) << std::endl;
            }
            break;
        default:
            mistake();
            goto prosty;
    }
}
