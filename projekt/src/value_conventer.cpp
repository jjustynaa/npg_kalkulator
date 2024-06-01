#include "value_conventer.hpp"
#include <iostream>

double conventer_speed(){
    conventer_speed_start:
    std::cout << "Wybierz konwersje predkosci:\n"
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
            std::cout << "Nieprawidlowy wybor. Sprobuj ponownie" << std::endl;
            goto conventer_speed_start;
    }
}

double conventer_length() {
    conventer_length_start:
    std::cout << "Wybierz konwersje dlugosci:\n"
                 "1. km -> mile\n"
                 "2. mile -> km\n"
                 "3. km -> m\n"
                 "4. m -> km\n"
                 "5. km -> cm\n"
                 "6. cm -> km\n"
                 "7. m -> cm\n"
                 "8. cm -> m\n" << std::endl;
    int choice;
    std::cin >> choice;

    double value, result;
    switch (choice) {
        case 1:
            std::cout << "Podaj długosc w km: ";
            std::cin >> value;
            result = value * 0.621371;
            std::cout << value << " km to " << result << " mile" << std::endl;
            return result;
        case 2:
            std::cout << "Podaj długosc w milach: ";
            std::cin >> value;
            result = value / 0.621371;
            std::cout << value << " mile to " << result << " km" << std::endl;
            return result;
        case 3:
            std::cout << "Podaj długosc w km: ";
            std::cin >> value;
            result = value * 1000;
            std::cout << value << " km to " << result << " m" << std::endl;
            return result;
        case 4:
            std::cout << "Podaj długosc w metrach: ";
            std::cin >> value;
            result = value / 1000;
            std::cout << value << " m to " << result << " km" << std::endl;
            return result;
        case 5:
            std::cout << "Podaj długosc w km: ";
            std::cin >> value;
            result = value * 100000;
            std::cout << value << " km to " << result << " cm" << std::endl;
            return result;
        case 6:
            std::cout << "Podaj długosc w centymetrach: ";
            std::cin >> value;
            result = value / 100000;
            std::cout << value << " cm to " << result << " km" << std::endl;
            return result;
        case 7:
            std::cout << "Podaj długosc w metrach: ";
            std::cin >> value;
            result = value * 100;
            std::cout << value << " m to " << result << " cm" << std::endl;
            return result;
        case 8:
            std::cout << "Podaj długosc w centymetrach: ";
            std::cin >> value;
            result = value / 100;
            std::cout << value << " cm to " << result << " m" << std::endl;
            return result;
        default:
            std::cout << "Nieprawidlowy wybor. Sprobuj ponownie" << std::endl;
            goto conventer_length_start;
    }
}

double conventer_time() {
    conventer_time_start:
    std::cout << "Wybierz konwersje czasu:\n"
                 "1. h -> min\n"
                 "2. min -> h\n"
                 "3. min -> sek\n"
                 "4. sek -> min\n" << std::endl;
    int choice;
    std::cin >> choice;

    double value, result;
    switch (choice) {
        case 1:
            std::cout << "Podaj czas w godzinach: ";
            std::cin >> value;
            result = value * 60;
            std::cout << value << " h to " << result << " min" << std::endl;
            return result;
        case 2:
            std::cout << "Podaj czas w minutach: ";
            std::cin >> value;
            result = value / 60;
            std::cout << value << " min to " << result << " h" << std::endl;
            return result;
        case 3:
            std::cout << "Podaj czas w minutach: ";
            std::cin >> value;
            result = value * 60;
            std::cout << value << " min to " << result << " sek" << std::endl;
            return result;
        case 4:
            std::cout << "Podaj czas w sekundach: ";
            std::cin >> value;
            result = value / 60;
            std::cout << value << " sek to " << result << " min" << std::endl;
            return result;
        default:
            std::cout << "Nieprawidlowy wybor. Sprobuj ponownie." << std::endl;
            goto conventer_time_start;
    }
}

void value_conventer(){

    value_conventer_start:
    std::cout << "Wybierz jaki rodzaj przelicznika cie interesuje.\n Wpisz liczbe odpowiadajaca twojemu wyborowi\n"
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
        default:
            std::cout << "Nieprawidlowy wybor. Sprobuj jeszcze raz" << std::endl;
            goto value_conventer_start;
    }
}