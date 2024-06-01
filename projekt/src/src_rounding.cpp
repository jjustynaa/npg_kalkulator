#include "rounding.hpp"

#include <iostream>
#include <cmath>
#include <iomanip>

void rounding(){
    double num;
    int m_p_p;
    std::cout << "Wpisz liczbe, ktora chcesz zaokraglic: " << std::endl;
    std::cin >> num;
    std::cout << "Podaj ilosc miejsc po przecinku: " << std::endl;
    std::cin >> m_p_p;
    std::cout << "Liczba po zaokragleniu wynosi: " << std::fixed << std::setprecision(m_p_p) << num << std::endl;
}

double significant_figure(double n, int sig_digits){
    if (n == 0)
        return 0;
    double exponent = std::floor(log10(std::abs(n)));
    double multiplier = pow(10, (sig_digits - 1 - exponent));
    return std::round(n * multiplier) / multiplier;
}