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
    std::cout << "Jakie dzialanie chcesz wykonac?\n"
                 "1. Dodawanie\n"
                 "2. Odejmowanie\n"
                 "3. Mnozenie\n"
                 "4. Dzielenie\n"
                 "5. Znalezienie reszty z dzielenia" << std::endl;
    std::cin >> wyb;

    switch(wyb) {
        case 1:
            std::cout << "Podaj liczby, ktore chcesz dodac:" << std::endl;
            std::cout << "Pierwsza liczba:" << std::endl;
            std::cin >> x;
            std::cout << "Druga liczba:" << std::endl;
            std::cin >> y;
            std::cout << "Wynik: " << addition(x, y) << std::endl;
            break;
        case 2:
            std::cout << "Podaj liczby, ktore chcesz odjac:" << std::endl;
            std::cout << "Pierwsza liczba:" << std::endl;
            std::cin >> x;
            std::cout << "Druga liczba:" << std::endl;
            std::cin >> y;
            std::cout << "Wynik: " << subtraction(x, y) << std::endl;
            break;
        case 3:
            std::cout << "Podaj liczby, ktore chcesz pomnozyc:" << std::endl;
            std::cout << "Pierwsza liczba:" << std::endl;
            std::cin >> x;
            std::cout << "Druga liczba:" << std::endl;
            std::cin >> y;
            std::cout << "Wynik: " << multiplication(x, y) << std::endl;
            break;
        case 4:
            std::cout << "Podaj liczby, ktore chcesz podzielic:" << std::endl;
            std::cout << "Pierwsza liczba:" << std::endl;
            std::cin >> x;
            dzielenie:
            std::cout << "Druga liczba:" << std::endl;
            std::cin >> y;
            if (y == 0) {
                mistake_value();
                goto dzielenie;
            } else {
                std::cout << "Wynik: " << division(x, y) << std::endl;
            }
            break;
        case 5:
            int a, b;
            std::cout << "Podaj liczby, ktore chcesz podzielic i obliczyc reszte:" << std::endl;
            std::cout << "Pierwsza liczba:" << std::endl;
            std::cin >> x;
            reszta:
            std::cout << "Druga liczba:" << std::endl;
            std::cin >> y;
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
