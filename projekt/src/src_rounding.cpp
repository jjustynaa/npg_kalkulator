#include "projekt.hpp"

void rounding(){
    double num;
    int m_p_p;
    std::cin >> num >> m_p_p;
    std::cout << "Liczba po zaokrągleniu wynosi: " << std::fixed << std::setprecision(m_p_p) << num << std::endl;
}

double significant_figure(double n, int sig_digits){
    if (n == 0)
        return 0;
    double exponent = std::floor(log10(abs(n)));
    double multiplier = pow(10, (sig_digits - 1 - exponent));
    return std::round(n * multiplier) / multiplier;
}