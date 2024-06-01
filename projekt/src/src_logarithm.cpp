#include "logarithm.hpp"
#include "accessory.hpp"

#include <iostream>
#include <cmath>

double logarithm(double liczba_logarytmowana, double podstawa_logarytmu ){
    double wynik = log(liczba_logarytmowana) / log(podstawa_logarytmu);
    return wynik;
}

void logarithm_user(){
    double ll, base;

    logarithm_ll:
    std::cout << "Podaj liczbe do zlogarytmowanie:" << std::endl;
    std::cin >> ll;
    if(ll < 0){
        mistake_value();
        goto logarithm_ll;
    }

    logarithm_base:
    std::cout << "Podaj podstawe logarytmu:" << std::endl;
    std::cin >> base;
    if(base == 1 or base <= 0){
        mistake_value();
        goto logarithm_base;
    }

    std::cout << "Wynik logarytmu to " << logarithm(ll,base) << std::endl;
}