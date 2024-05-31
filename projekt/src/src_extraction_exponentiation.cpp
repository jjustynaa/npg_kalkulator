#include "extraction_exponentiation.hpp"

double exponentiation(double liczba, int potega){
    double wynik = 1.0;
    if (potega < 0){
        for (int i = 0; - potega > i; i++){
            wynik /= liczba;
        }
    }
    else if (potega == 0){
        wynik = 1.0;
    }
    else {
        for (int i = 0; potega > i; i++) {
            wynik *= liczba;
        }
    }
    return wynik;
}

double extraction(double liczba, int stopien){
    if (liczba < 0 && (stopien % 2) == 0 ) {
        return NAN;
    }

    double wynik = liczba / 2.0;
    double przyblizenie = 0.00001;

    while (std::abs(exponentiation(wynik, stopien) - liczba) > przyblizenie) {
        wynik = ((stopien - 1.0) * wynik + liczba / exponentiation(wynik, stopien - 1)) / stopien;
    }

    wynik = std::round(wynik * 10000.0) / 10000.0;

    return wynik;
}

void extraction_exponentiation(){
    kalk_poteg:
    std::cout <<"Wprowadz co chcesz zrobić\n* - potegowanie\ns - pierwiastkowanie" << std::endl;

    char znak;
    std::cin >> znak;
    switch(znak){
        case '*':
            std::cout << "Podaj wartość jaką chcesz podnieść do potęgi" << std::endl;
            double liczba;
            std::cin >> liczba;
            std::cout << "Podaj stopień do jakiego chcesz podnieść wcześniejszą wartość" << std::endl;
            int stopien;
            std::cin >> stopien;
            std::cout << exponentiation(liczba, stopien) << std::endl;
            break;

        case 's':
            std::cout << "Podaj wartość jaką chcesz pierwiastkowac" << std::endl;
            double wartosc;
            std::cin >> wartosc;
            std::cout << "Podaj stopień piewiastka" << std::endl;
            int pierw;
            std::cin >> pierw;
            std::cout << extraction(wartosc, pierw) << std::endl;
            break;

        default:
            std::cout << "Nie znana komenda \nspróbuj jeszcze raz" << std::endl;
            goto kalk_poteg;
    }
}