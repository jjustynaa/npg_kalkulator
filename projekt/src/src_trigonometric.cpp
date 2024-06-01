#include "trigonometric.hpp"
#include "accessory.hpp"

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

void cykl_o_tryg() {
    std::string choose;
    std::cout << "Chcesz skorzystac z funkcji cyklometrycznej (CYLKO) czy trygonometrycznej (TRYGO):" << std::endl;
    std::cin >> choose;
    if (lower(choose) == "cyklo") {
        cykl();
    }
    else if (lower(choose) == "trygo") {
        tryg();
    }
        else if (choose == "back"){}
            else{
                mistake();
                cykl_o_tryg();
    }
}

void tryg() {
    double num;
    int fun_tryg;
    std::string wyb;
    std::cout << "Podaj funkcje trygonometryczna, ktora chcesz wykorzystac (1. sin, 2. cos, 3. tan, 4. ctag):"
              << std::endl;
    std::cin >> fun_tryg;
    std::cout << "Podaj liczbe:" << std::endl;
    std::cin >> num;

    std::cout << "Liczbe podajesz w radianach (RAD) czy stopniach (STO)?" << std::endl;
    std::cin >> wyb;

    if (lower(wyb) == "RAD") {
        num = num / (360 / 2 / 3.1415);
    } else if (lower(wyb) == "STO") {}
    else {
        mistake();
        tryg();
    }

    switch (fun_tryg) {
        case 1:
            std::cout << "Wartosc sinusa podanego kata wynosi " << sin(num) << std::endl;
            break;
        case 2:
            std::cout << "Wartosc cosinsusa podanego kata wynosi " << cos(num) << std::endl;
            break;
        case 3:
            std::cout << "Wartosc tangensa podanego kata wynosi " << tan(num) << std::endl;
            break;
        case 4:
            std::cout << "Wartosc cotangensa podanego kata wynosi " << 1 / tan(num) << std::endl;
            break;
        default:
            mistake();
            tryg();
    }
}

void cykl() {
    double num;
    int fun_cyk;
    std::cout << "Podaj funkcje cyklometyczna, ktora chcesz wykorzystac (1. sin, 2. cos, 3. tan, 4. ctag):" << std::endl;
    std::cin >> fun_cyk;
    std::cout << "Podaj liczbe:" << std::endl;
    std::cin >> num;

    switch (fun_cyk) {
        case 1:
            if(-1 > num or num > 1){
                mistake_value();
                cykl();
            }
            std::cout << "Wartosc arcusasinusa podanego kata wynosi " << std::fixed << std::setprecision(1)
                      << asin(num) * (360 / 2 / 3.1415) << "°" << std::endl;
            break;
        case 2:
            if(-1 > num or num > 1){
                mistake_value();
                cykl();
            }
            std::cout << "Wartosc arcusacosinusa podanego kata wynosi " << std::fixed << std::setprecision(1)
                      << acos(num) * (360 / 2 / 3.1415) << "°" << std::endl;
            break;
        case 3:
            std::cout << "Wartosc arcusatangensa podanego kata wynosi " << std::fixed << std::setprecision(1)
                      << atan(num) * (360 / 2 / 3.1415) << "°" << std::endl;
            break;
        case 4:
            std::cout << "Wartosc arcusacotangensa podanego kata wynosi " << std::fixed << std::setprecision(1)
                      << M_PI / 2 - atan(num) * (360 / 2 / 3.1415) << "°" << std::endl;
            break;
        default:
            mistake();
            cykl();
    }

}