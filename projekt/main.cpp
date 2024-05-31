#include "projekt.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

// Jesli ktos to czyta to tlumacze te 4 bledy co sa
// dwa z nich pojawiaja sie przez puste swiche i nimi sie wgl nie przejmujemy
// dwa pozostale sa bo uzywamy comon configa z PSiO i nie podoba mu sie ze porownujemy cos do NULLa dla charow
// wiec mozna sprobowac go jakos ladnie upakowac zeby sie nie czepialo ale raczej nic to nie zepsuje
void czyszczenie(){
    for (int i = 0; i < 25; i++) {
        std::cout << std::endl;
    }
}

void blad() {
    std::cout << "Nie znana komenda \nsprobuj jeszcze raz" << std::endl;
}

int repet() {
    std::string con;
    std::cout << "Chcesz kontynuowac? [T/N]" << std::endl;
    std::cin >> con;
    return (con == "T" || con == "t") ? 1 : 0;
}

int main() {

    start:
    czyszczenie();
    std::cout << "<<Witaj w kalkulatorze>>\n\nAby przejsc dalej wpisz NEXT" << std::endl;
    std::string t;
    std::cin >> t;
    if (t != "NEXT" && t != "Next" && t != "next") {
        blad();
        goto start;
    }

    p_menu:
    czyszczenie();
    std::cout << "Jakiej funkcji chcesz uzyc:\n"
                 " 0. Help\n"
                 " 1. Kalkulator prosty \n"
                 " 2. Kalkulator macierzowy\n"
                 " 3. Potegowanie i pierwiastkowanie\n"
                 " 4. Przelicznik wartosci\n"
                 " 5. Porownywanie liczb\n"
                 " 6. Zaokraglenia\n"
                 " 7. Kalkulator rownan kwadratowych lub rownan trzeciego stopnia\n"
                 " 8. Kalkulator pol i objetosci\n"
                 " 9. Kalkulator logarytmow\n"
                 "10. Kalkulator do funkcji trygonometrycznych oraz funkcji cyklometrycznych\n"
                 "11. Kalkulator do liczb zespolonych\n"
                 "12. Kalkulator do calek oznaczonych\n"
                 "13. Reset\n" << std::endl;

    int fun;
    std::cin >> fun;

    czyszczenie();
    switch (fun) {
        case 1:
            prosty();
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
            // Przerzut na porownania
            break;
        case 6:
            print_zao();
            break;
        case 7: {
            char choice;
            std::cout << "Wybierz typ rownania: (1) kwadratowe, (2) szescienne: ";
            std::cin >> choice;
            if (choice == '1') {
                double a, b, c;
                std::cout << "Podaj wspolczynniki a, b, c: ";
                std::cin >> a >> b >> c;
                kwadratowa(a, b, c);
            } else if (choice == '2') {
                double a, b, c, d;
                std::cout << "Podaj wspolczynniki a, b, c, d: ";
                std::cin >> a >> b >> c >> d;
                try {
                    std::vector<double> roots = solveCubic(a, b, c, d);
                    std::cout << "Pierwiastki rownania: ";
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
    std::cout << "Ktora funkcje wytlumaczyc:\n"
                 " 1. Kalkulator prosty \n"
                 " 2. Kalkulator macierzowy\n"
                 " 3. Potegowanie i pierwiastkowanie\n"
                 " 4. Przelicznik wartosci\n"
                 " 5. Porownywanie liczb\n"
                 " 6. Zaokraglenia\n"
                 " 7. Kalkulator rownan kwadratowych lub rownan trzeciego stopnia\n"
                 " 8. Kalkulator pol i objetosci\n"
                 " 9. Kalkulator logarytmow\n"
                 "10. Kalkulator do funkcji trygonometrycznych oraz funkcji cyklometrycznych\n"
                 "11. Kalkulator do liczb zespolonych\n"
                 "12. Kalkulator do calek oznaczonych\n"
                 "13. Powrot na start\n"
                 "14. Powrot do wyboru kalkulatora \n" << std::endl;

    int help_fun;
    std::cin >> help_fun;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character

    switch (help_fun) {
        case 1:
            std::cout << "Kalkulator prosty, ktory obsluguje: dodawanie, odejmowanie, mnozenie, dzielenie, podnoszenie do zadanej potegi oraz obliczanie reszty z dzielenia." << std::endl;
            break;
        case 2:
            std::cout << "Program dodaje, odejmuje i mnozy macierze\nNa poczatku nalezy wybrac znak, pozniej wprowadzic odpowiednie macierze\n\n"
                         "Nalezy pamietac ze wielkosc macierzy w dodawaniu i odejmowaniu musi sie pokrywac\n"
                         "W mnozeniu zas te wielkosci sa odwrotne: wiersze jednej = kolumny drugiej, kolumny pierwszej = wiersze drugiej." << std::endl;
            break;
        case 3:
            std::cout << "help do potegowania i pierwiastkowania" << std::endl;
            break;
        case 4:
            std::cout << "help do przelicznika wartosci" << std::endl;
            break;
        case 5:
            std::cout << "help do porownywania liczb" << std::endl;
            break;
        case 6:
            std::cout << "Zaokraglenie przyjmuje dwie wartosci: liczbe do zaokraglania oraz liczbe miejsc po przecinku, ile oczekujesz otrzymac" << std::endl;
            break;
        case 7:
            std::cout << "Funkcja rozwiazuje rownania, ale najpierw musisz wybrac typ" << std::endl;
            break;
        case 8:
            std::cout << "Kalkulator pol i objetosci" << std::endl;
            break;
        case 9:
            std::cout << "Kalkulator logarytmow" << std::endl;
            break;
        case 10:
            std::cout << "Program tworzy funkcje cyklometryczna lub trygonometryczna\nNalezy najpierw wpisac rodzaj funkcji a nastepnie wartosc np.:\nsin( 90\n\n"
                         "Dodatkowo do wyboru w funkcji trygonometrycznej mozna wybrac czy wpisuje sie kat w radianach czy w stopniach\nFunkcja cyklometryczna podaje wartosc w stopniach." << std::endl;
            break;
        case 11:
            std::cout << "Za każdym razem w funkcji najperw należy podać część rzeczywistą a następnie część urojoną.\nPierwsza funkcja kalkulatora jeśli w części urojonej otrzyma zero to potraktuje pierwszy argument jako kąt i należy podać go w stopniach\n"
                         "Jeśli funkcja przyjmuje dwie liczby zespolone to napierw należy podać obie wartości jednej a następnie obie wartości drugiej" << std::endl;
            break;
        case 12:
             std::cout << "Funkcja umozliwia wybor i obliczenie calki oznaczonej z funkcji: liniowej, kwadratowej, sinusa lub cosinusa." << std::endl;
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

