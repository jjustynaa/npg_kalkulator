#include "projekt.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

//Jeśli ktoś to czyta to tłumacze te 4 błędy co są
//dwa z nich pojawiają się przez puste swiche i nimi się wgl nie przejmujemy
//dwa pozostałe są bo używamy comon configa z PSiO i niepodoba mu się że porównujemy coś do NULLa dla charów
// więc można spróbować go jakoś ładnie upakować żeby się nie czepiało ale raczej nic to nie zepsuje
void czyszczenie(){
    for (int i = 0; i < 25; i++) {
        std::cout << std::endl;
    }
}

void blad() {
    std::cout << "Nie znana komenda \nspróbuj jeszcze raz" << std::endl;
}

int repet() {
    std::string con;
    std::cout << "Chcesz kontynuować? [T/N]" << std::endl;
    std::cin >> con;
    return (con == "T" || con == "t") ? 1 : 0;
}

int main() {

    start:
    czyszczenie();
    std::cout << "<<Witaj w kalkulatorze>>\n\nAby przejść dalej wpisz NEXT" << std::endl;
    std::string t;
    std::cin >> t;
    if (t != "NEXT" && t != "Next" && t != "next") {
        blad();
        goto start;
    }

    p_menu:
    czyszczenie();
    std::cout << "Jakiej funkcji chcesz użyć:\n"
                 " 0. Help\n"
                 " 1. Kalkulator prosty \n"
                 " 2. Kalkulator macierzowy\n"
                 " 3. Potęgowanie i pierwiastkowanie\n"
                 " 4. Przelicznik wartości\n"
                 " 5. Porównywanie liczb\n"
                 " 6. Zaokrąglenia\n"
                 " 7. Kalkulator równań kwadratowych lub równań trzeciego stopnia\n"
                 " 8. Kalkulator pól i objętości\n"
                 " 9. Kalkulator logarytmów\n"
                 "10. Kalkulator do funkcji trygonometrycznych oraz funkcji cyklometrycznych\n"
                 "11. Kalkulator do liczb zespolonych\n"
                 "12. Kalkulator do calek oznaczonych\n"
                 "13. Reset\n" << std::endl;

    int fun;
    std::cin >> fun;

    czyszczenie();
    switch (fun) {
        case 1:
            std::cout << "1";
            // Wstaw funkcję kalkulatora prostego
            break;
        case 2:
            matrix();
            break;
        case 3:
            kalk_poteg();
            break;
        case 4:
            // Przerzut na przelicznik
            break;
        case 5:
            // Przerzut na porównania
            break;
        case 6:
            print_zao();
            break;
        case 7: {
            char choice;
            std::cout << "Wybierz typ równania: (1) kwadratowe, (2) sześcienne: ";
            std::cin >> choice;
            if (choice == '1') {
                double a, b, c;
                std::cout << "Podaj współczynniki a, b, c: ";
                std::cin >> a >> b >> c;
                kwadratowa(a, b, c);
            } else if (choice == '2') {
                double a, b, c, d;
                std::cout << "Podaj współczynniki a, b, c, d: ";
                std::cin >> a >> b >> c >> d;
                try {
                    std::vector<double> roots = solveCubic(a, b, c, d);
                    std::cout << "Pierwiastki równania: ";
                    for (double root : roots) {
                        std::cout << root << " ";
                    }
                    std::cout << std::endl;
                } catch (const std::invalid_argument &e) {
                    std::cerr << e.what() << std::endl;
                }
            } else {
                blad();
            }
            break;
        }
        case 8:
            area();
            break;
        case 9:
            logarytmy_by_Natalia();
            break;
        case 10:
            cykl_o_tryg();
            break;
        case 11:
            complex_choice();
            break;
        case 12:
            calki();
            break;
        case 0:
            goto p_help;
        case 13:
            goto start;
        default:
            blad();
            goto p_menu;
    }

    p_help:
    std::cout << "Którą funkcje wytłumaczyć:\n"
                 " 1. Kalkulator prosty \n"
                 " 2. Kalkulator macierzowy\n"
                 " 3. Potęgowanie i pierwiastkowanie\n"
                 " 4. Przelicznik wartości\n"
                 " 5. Porównywanie liczb\n"
                 " 6. Zaokrąglenia\n"
                 " 7. Kalkulator równań kwadratowych lub równań trzeciego stopnia\n"
                 " 8. Kalkulator pól i objętości\n"
                 " 9. Kalkulator logarytmów\n"
                 "10. Kalkulator do funkcji trygonometrycznych oraz funkcji cyklometrycznych\n"
                 "11. Kalkulator do liczb zespolonych\n"
                 "12. Kalkulator do calek oznaczonych\n"
                 "13. Powrót na start\n"
                 "14. Powrót do wyboru kalkulatora \n" << std::endl;

    int help_fun;
    std::cin >> help_fun;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character

    switch (help_fun) {
        case 1:
            std::cout << "Program tworzy funkcje cyklometryczną lub trygonometryczną\nNależy najpierwy wpisać rodzaj funkcji a następnie wartość np.:\nsin( 90\n\n"
                         "Dodatkowo do wyboru w funkcji trygonometrycznej można wybrać czy wpisuje się kąt w radianach czy w stopniach\nFunkcja cyklometryczna podaje wartość w stopniach." << std::endl;
            break;
        case 2:
            std::cout << "Program dodaje, odejmuje i mnoży macierze\nNa początku należy wybrać znak, później wprowadzić odpowiednie macierze\n\n"
                         "Należy pamiętać że wielkość macierzy w dodawaniu i odejmowaniu musi się pokrywać\n"
                         "W mnożeniu zaś te wielkości są odwrotne: wiersze jednej = kolumny drugiej, kolumny pierwszej = wiersze drugiej." << std::endl;
            break;
        case 3:
            std::cout << "help do potęgowania i pierwiastkowania" << std::endl;
            break;
        case 4:
            std::cout << "help do przelicznika wartości" << std::endl;
            break;
        case 5:
            std::cout << "help do porównywania liczb" << std::endl;
            break;
        case 6:
            std::cout << "Zaokrąglenie przyjmuje dwie wartości: liczbę do zaokrąglania oraz liczbę miejsc po przecinku, ile oczekujesz otrzymać" << std::endl;
            break;
        case 7:
            std::cout << "Funkcja rozwiązuje równania, ale najpierw musisz wybrać typ" << std::endl;
            break;
        case 8:
            std::cout << "Kalkulator pól i objętości" << std::endl;
            break;
        case 9:
            std::cout << "Kalkulator logarytmów" << std::endl;
            break;
        case 10:
            std::cout << "Kalkulator do funkcji trygonometrycznych oraz funkcji cyklometrycznych" << std::endl;
            break;
        case 11:
            // std::cout << "help do liczb zespolonych" << std::endl;
            break;
        case 12:
            // std::cout << "help do calek " << std::endl;
            break;
        case 13:
            goto start;
        case 14:
            goto p_menu;
        default:
            blad();
            goto p_help;
    }
    goto p_menu;
}
