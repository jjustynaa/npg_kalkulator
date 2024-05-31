#include "integral.hpp"

#include <iostream>
#include <string>
#include <cmath>

double calka_liniowa(double a, double b, double x1, double x2){
    double dx = 0.0001;
    double wynik = 0;
    if (x1 > x2){
        return -1;
    } else if (x1 == x2){
        return 0;
    } else{
        while (x1 < x2){
            wynik += (x1 * a + b) * dx;
            x1 += dx;
        }
        return wynik;
    }
}

double calka_kwadratowa(double a, double b, double c, double x1, double x2){
    double dx = 0.0001;
    double wynik = 0;
    if (x1 > x2){
        return -1;
    } else if (x1 == x2){
        return 0;
    } else{
        while (x1 < x2){
            wynik += (pow(x1, 2) * a + x1 * b + c) * dx;
            x1 += dx;
        }
        return wynik;
    }
}

double calka_sin(double x1, double x2){
    double dx = 0.0001;
    double wynik = 0;
    if (x1 > x2){
        return -1;
    } else if (x1 == x2){
        return 0;
    } else{
        while (x1 < x2){
            wynik += sin(x1) * dx;
            x1 += dx;
        }
        return wynik;
    }
}

double calka_cos(double x1, double x2){
    double dx = 0.0001;
    double wynik = 0;
    if (x1 > x2){
        return -1;
    } else if (x1 == x2){
        return 0;
    } else{
        while (x1 < x2){
            wynik += cos(x1) * dx;
            x1 += dx;
        }
        return wynik;
    }
}


//obsługa całek:
void calki() {
    calki:
    std::cout << "Wybierz rodzaj calki:\nL - calka z funkcji liniowej\nK - calka z funkcji kwadratowej\nS - calka z sinusa\nC - calka z cosinusa" << std::endl;
    char mark;
    std::cin >> mark;
    switch (std::tolower(mark)) {
        case 'l': {
            double a, b, x1, x2;
            std::cout << "Podaj kolejno: wspolczynnik a, wspolczynnik b, poczatek oraz koniec przedzialu calkowania" << std::endl;
            std::cin >> a >> b >> x1 >> x2;
            std::cout << "Wynik: " << calka_liniowa(a, b, x1, x2) << std::endl;
            break;
        }
        case 'k': {
            double a, b, c, x1, x2;
            std::cout << "Podaj kolejno: wspolczynnik a, wspolczynnik b, wspolczynnik c, poczatek oraz koniec przedzialu calkowania" << std::endl;
            std::cin >> a >> b >> c >> x1 >> x2;
            std::cout << "Wynik: " << calka_kwadratowa(a, b, c, x1, x2) << std::endl;
            break;
        }
        case 's': {
            double x1, x2;
            std::cout << "Podaj kolejno: poczatek oraz koniec przedzialu calkowania" << std::endl;
            std::cin >> x1 >> x2;
            std::cout << "Wynik: " << calka_sin(x1, x2) << std::endl;
            break;
        }
        case 'c': {
            double x1, x2;
            std::cout << "Podaj kolejno: poczatek oraz koniec przedzialu calkowania" << std::endl;
            std::cin >> x1 >> x2;
            std::cout << "Wynik: " << calka_cos(x1, x2) << std::endl;
            break;
        }
        default:
            std::cout << "Wybrano nieprawidlowa operacje" << std::endl;
            goto calki;
    }
}