#include "value_conventer.hpp"
#include "accessory.hpp"
#include <iostream>
#include <cmath>

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
        speed1:
            std::cout << "Podaj predkosc w km/h:" << std::endl;
            std::cin >> value;

            if (value < 0){
                mistake_value();
                goto speed1;
            }

            result = value / 3.6;
            result = std::round(result * 10000.0) / 10000.0;
            std::cout << value << " km/h to " << result << " m/s" << std::endl;
            break;

        case 2:
        speed2:
            std::cout << "Podaj predkosc w m/s:" << std::endl;
            std::cin >> value;

            if (value < 0){
                mistake_value();
                goto speed2;
            }

            result = value * 3.6;
            result = std::round(result * 10000.0) / 10000.0;
            std::cout << value << " m/s to " << result << " km/h" << std::endl;
            break;

        default:
            mistake();
            goto conventer_speed_start;
    }
    return result;
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
            length1:
            std::cout << "Podaj dlugosc w km:" << std::endl;
            std::cin >> value;

            if (value < 0){
                mistake_value();
                goto length1;
            }

            result = value * 0.621371;
            result = std::round(result * 10000.0) / 10000.0;
            std::cout << value << " km to " << result << " mile" << std::endl;
            break;

        case 2:
            length2:
            std::cout << "Podaj dlugosc w milach:" << std::endl;
            std::cin >> value;

            if (value < 0){
                mistake_value();
                goto length2;
            }

            result = value / 0.621371;
            result = std::round(result * 10000.0) / 10000.0;
            std::cout << value << " mile to " << result << " km" << std::endl;
            break;

        case 3:
            length3:
            std::cout << "Podaj dlugosc w km:" << std::endl;
            std::cin >> value;

            if (value < 0){
                mistake_value();
                goto length3;
            }

            result = value * 1000;
            std::cout << value << " km to " << result << " m" << std::endl;
            break;

        case 4:
            length4:
            std::cout << "Podaj dlugosc w metrach:" << std::endl;
            std::cin >> value;

            if (value < 0){
                mistake_value();
                goto length4;
            }

            result = value / 1000;
            std::cout << value << " m to " << result << " km" << std::endl;
            break;

        case 5:
            length5:
            std::cout << "Podaj dlugosc w km:" << std::endl;
            std::cin >> value;

            if (value < 0){
                mistake_value();
                goto length5;
            }

            result = value * 100000;
            std::cout << value << " km to " << result << " cm" << std::endl;
            break;

        case 6:
            length6:
            std::cout << "Podaj dlugosc w centymetrach:" << std::endl;
            std::cin >> value;

            if (value < 0){
                mistake_value();
                goto length6;
            }

            result = value / 100000;
            std::cout << value << " cm to " << result << " km" << std::endl;
            break;

        case 7:
            length7:
            std::cout << "Podaj dlugosc w metrach:" << std::endl;
            std::cin >> value;

            if (value < 0){
                mistake_value();
                goto length7;
            }

            result = value * 100;
            std::cout << value << " m to " << result << " cm" << std::endl;
            break;

        case 8:
            length8:
            std::cout << "Podaj dlugosc w centymetrach:" << std::endl;
            std::cin >> value;

            if (value < 0){
                mistake_value();
                goto length8;
            }

            result = value / 100;
            std::cout << value << " cm to " << result << " m" << std::endl;
            break;

        default:
            mistake();
            goto conventer_length_start;
    }
    return result;
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
            time1:
            std::cout << "Podaj czas w godzinach:" << std::endl;
            std::cin >> value;

            if (value < 0){
                mistake_value();
                goto time1;
            }

            result = value * 60;
            result = std::round(result * 10000.0) / 10000.0;
            std::cout << value << " h to " << result << " min" << std::endl;
            break;

        case 2:
            time2:
            std::cout << "Podaj czas w minutach:" << std::endl;
            std::cin >> value;

            if (value < 0){
                mistake_value();
                goto time2;
            }

            result = value / 60;
            result = std::round(result * 10000.0) / 10000.0;
            std::cout << value << " min to " << result << " h" << std::endl;
            break;

        case 3:
            time3:
            std::cout << "Podaj czas w minutach:" << std::endl;
            std::cin >> value;

            if (value < 0){
                mistake_value();
                goto time3;
            }

            result = value * 60;
            result = std::round(result * 10000.0) / 10000.0;
            std::cout << value << " min to " << result << " sek" << std::endl;
            break;

        case 4:
            time4:
            std::cout << "Podaj czas w sekundach:" << std::endl;
            std::cin >> value;

            if (value < 0){
                mistake_value();
                goto time4;
            }

            result = value / 60;
            result = std::round(result * 10000.0) / 10000.0;
            std::cout << value << " sek to " << result << " min" << std::endl;
            break;

        default:
            mistake();
            goto conventer_time_start;
    }
    return result;
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
            mistake();
            goto value_conventer_start;
    }
}