#include "logarithm.hpp"

double logarithm(double liczba_logarytmowana, double podstawa_logarytmu ){
    double wynik = log(liczba_logarytmowana) / log(podstawa_logarytmu);
    return wynik;
}

void logarithm_user(){
    std::cout << "Podaj liczbe do zlogarytmowanie i podstawe logarytmu:" << std::endl;
    double ll, base;
    std::cin >> ll >> base;
    std::cout << "Wynik logarytmu to" << logarithm(ll,base);
}