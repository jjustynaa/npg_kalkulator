#include "rounding.hpp"
#include "accessory.hpp"

#include <iostream>
#include <cmath>
#include <iomanip>

void rounding(){
    double num;
    int m_p_p;
    std::cout << "Wpisz liczbe, ktora chcesz zaokraglic:" << std::endl;
    std::cin >> num;
    dig:
    std::cout << "Podaj ilosc miejsc po przecinku:" << std::endl;
    std::cin >> m_p_p;
    if(m_p_p < 0){
        mistake_value();
        goto dig;
    }
    std::cout << "Liczba po zaokragleniu wynosi:" << std::fixed << std::setprecision(m_p_p) << num << std::endl;
}

double significant_figure(double n, int sig_digits){
    if (n == 0)
        return 0;
    double exponent = std::floor(log10(std::abs(n)));
    double multiplier = pow(10, (sig_digits - 1 - exponent));
    return std::round(n * multiplier) / multiplier;
}

void significant_figure_user(){
    double n;
    int dig;
    std::cout << "Wpisz liczbe, ktorej chcesz okreslic cyfry znaczace:" << std::endl;
    std::cin >> n;
    sig_dig:
    std::cout << "Podaj ilosc cyfr znaczacych: " << std::endl;
    std::cin >> dig;
    if(dig <= 0){
        mistake_value();
        goto sig_dig;
    }
    double result = significant_figure(n, dig);
    std::cout << "Liczba z okreslona iloscia cyfr znaczacych: " << result << std::endl;
}

void round_significant(){
    area:
    std::cout <<"Wybierz dzialanie programu:\n1. zaokraglanie podanej liczby\n2. cyfry znaczace" << std::endl;

    int mark;
    std::cin >> mark;
    switch(mark){
        case 1:
            rounding();
            break;
        case 2:
            significant_figure_user();
            break;
        default:
            mistake();
            goto area;
    }
}