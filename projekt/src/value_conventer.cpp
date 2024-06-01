#include "value_conventer.hpp"

#include <iostream>


void value_conventer(){
    std::cout << "Wybierz jaki rodzaj przelicznika cię interesuje.\n Wpisz liczbę odpowiadajaca twojemu wyborowi\n"
                 "1. Predkosci\n"
                 "2. Dlugosci\n"
                 "3. Czasu\n" << std::endl;
    int choice;
    std::cin >> choice;

    double result;
    switch (choice) {
        case 1:
            result = conventer_speed();
            std::cout << "Wynik konwersji: " << result << std::endl;
            break;
        case 2:
            result = conventer_length();
            std::cout << "Wynik konwersji: " << result << std::endl;
            break;
        case 3:
            result = conventer_time();
            std::cout << "Wynik konwersji: " << result << std::endl;
            break;
    }
}
double conventer_speed(){
    std::cout << "Wybierz konwersje prędkosci:\n"
                 "1. km/h -> m/s\n"
                 "2. m/s -> km/h\n" << std::endl;
    int choice;
    std::cin >> choice;

    double value, result;
    switch (choice) {
        case 1:
            std::cout << "Podaj predkosc w km/h: ";
            std::cin >> value;
            result = value / 3.6;
            std::cout << value << " km/h to " << result << " m/s" << std::endl;
            return result;
        case 2:
            std::cout << "Podaj predkosc w m/s: ";
            std::cin >> value;
            result = value * 3.6;
            std::cout << value << " m/s to " << result << " km/h" << std::endl;
            return result;
        default:
            std::cout << "Nieprawidłowy wybór." << std::endl;
            return 0.0;
    }
}

double conventer_length() {
    std::cout << "Wybierz konwersję długości:\n"
                 "1. km -> mile\n"
                 "2. mile -> km\n"
                 "3. km -> m\n"
                 "4. m -> km\n" << std::endl;
    int choice;
    std::cin >> choice;

    double value, result;
    switch (choice) {
        case 1:
            std::cout << "Podaj długość w km: ";
            std::cin >> value;
            result = value * 0.621371;
            std::cout << value << " km to " << result << " mile" << std::endl;
            return result;
        case 2:
            std::cout << "Podaj długość w milach: ";
            std::cin >> value;
            result = value / 0.621371;
            std::cout << value << " mile to " << result << " km" << std::endl;
            return result;
        case 3:
            std::cout << "Podaj długość w km: ";
            std::cin >> value;
            result = value * 1000;
            std::cout << value << " km to " << result << " m" << std::endl;
            return result;
        case 4:
            std::cout << "Podaj długość w metrach: ";
            std::cin >> value;
            result = value / 1000;
            std::cout << value << " m to " << result << " km" << std::endl;
            return result;
        default:
            std::cout << "Nieprawidłowy wybór." << std::endl;
            return 0.0;
    }
}

double conventer_time(){

}