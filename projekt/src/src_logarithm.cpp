#include "logarithm.hpp"
#include "accessory.hpp"

#include <iostream>
#include <cmath>

double logarithm(double liczba_logarytmowana, double podstawa_logarytmu ){
    double wynik = log(liczba_logarytmowana) / log(podstawa_logarytmu);
    return wynik;
}

void logarithm_user(){
    logaritm:
    std::cout << "Podaj liczbe do zlogarytmowanie i podstawe logarytmu:" << std::endl;
    double ll, base;
    std::cin >> ll >> base;
    if(base == 1 or base < 0 or ll < 0){
        mistake_value();
        goto logaritm;
    }
    std::cout << "Wynik logarytmu to" << logarithm(ll,base);
}