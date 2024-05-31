#include "main.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

void clear(){
    for (int i = 0; i < 25; i++) {
        std::cout << std::endl;
    }
}

void mistake() {
    std::cout << "Nie znana komenda \nsprobuj jeszcze raz" << std::endl;
}

int repeat() {
    std::string con;
    std::cout << "Chcesz kontynuowac? [T/N]" << std::endl;
    std::cin >> con;
    return (con == "N" || con == "n") ? 0 : 1;
}

int main() {

    start:
    clear();
    std::cout << "<<Witaj w kalkulatorze>>\n\nAby przejsc dalej wpisz NEXT\n\nPo wprowadzonych wartosciach wcisnij ENTER" << std::endl;
    std::string t;
    std::cin >> t;
    if (t != "NEXT" && t != "Next" && t != "next") {
        mistake();
        goto start;
    }

    clear();
    p_menu:
    std::cout << "Jakiej funkcji chcesz uzyc:\n"
                 " 0. Help\n"
                 " 1. Kalkulator prosty \n"
                 " 2. Kalkulator macierzowy\n"
                 " 3. Potegowanie i pierwiastkowanie\n"
                 " 4. Przelicznik wartosci\n"
                 " 5. Zaokraglenia\n"
                 " 6. Kalkulator rownan kwadratowych lub rownan trzeciego stopnia\n"
                 " 7. Kalkulator pol i objetosci\n"
                 " 8. Kalkulator logarytmow\n"
                 " 9. Kalkulator do funkcji trygonometrycznych oraz funkcji cyklometrycznych\n"
                 "10. Kalkulator do liczb zespolonych\n"
                 "11. Kalkulator do calek oznaczonych\n"
                 "12. Reset\n" << std::endl;

    int fun;
    std::cin >> fun;

    clear();
    switch (fun) {
        case 1:
            simple();
            if (!repeat()) goto quit;
            clear();
            goto p_menu;
        case 2:
            matrix();
            if (!repeat()) goto quit;
            clear();
            goto p_menu;
        case 3:
            extraction_exponentiation();
            if (!repeat()) goto quit;
            clear();
            goto p_menu;
        case 4:
            // Przerzut na przelicznik
            goto p_menu;
        case 5:
            rounding();
            if (!repeat()) goto quit;
            clear();
            goto p_menu;
        case 6: {
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
                mistake();
            }
            if (!repeat()) goto quit;
            clear();
            goto p_menu;
        }
        case 7:
            area();
            if (!repeat()) goto quit;
            clear();
            goto p_menu;
        case 8:
            logarithm_user();
            if (!repeat()) goto quit;
            clear();
            goto p_menu;
        case 9:
            cykl_o_tryg();
            if (!repeat()) goto quit;
            clear();
            goto p_menu;
        case 10:
            complex_choice();
            if (!repeat()) goto quit;
            clear();
            goto p_menu;
        case 11:
            calki();
            if (!repeat()) goto quit;
            clear();
            goto p_menu;
        case 0:
            goto p_help;
        case 12:
            goto start;
        default:
            mistake();
            goto p_menu;
    }

    p_help:
    std::cout << "Ktora funkcje wytlumaczyc:\n"
                 " 1. Kalkulator prosty \n"
                 " 2. Kalkulator macierzowy\n"
                 " 3. Potegowanie i pierwiastkowanie\n"
                 " 4. Przelicznik wartosci\n"
                 " 5. Zaokraglenia\n"
                 " 6. Kalkulator rownan kwadratowych lub rownan trzeciego stopnia\n"
                 " 7. Kalkulator pol i objetosci\n"
                 " 8. Kalkulator logarytmow\n"
                 " 9. Kalkulator do funkcji trygonometrycznych oraz funkcji cyklometrycznych\n"
                 "10. Kalkulator do liczb zespolonych\n"
                 "11. Kalkulator do calek oznaczonych\n"
                 "12. Powrot na start\n"
                 "13. Powrot do wyboru kalkulatora \n" << std::endl;

    int help_fun;
    std::cin >> help_fun;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character

    switch (help_fun) {
        case 1:
            std::cout << "Kalkulator prosty, ktory obsluguje: dodawanie, odejmowanie, mnozenie, dzielenie oraz obliczanie reszty z dzielenia." << std::endl;
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
            std::cout << "Zaokraglenie przyjmuje dwie wartosci: liczbe do zaokraglania oraz liczbe miejsc po przecinku, ile oczekujesz otrzymac" << std::endl;
            break;
        case 6:
            std::cout << "Funkcja rozwiazuje rownania, ale najpierw musisz wybrac typ" << std::endl;
            break;
        case 7:
            std::cout << "Kalkulator pol i objetosci" << std::endl;
            break;
        case 8:
            std::cout << "Kalkulator pozwalajacy obliczyc numeryczna wartosc logaytmu" << std::endl;
            break;
        case 9:
            std::cout << "Program tworzy funkcje cyklometryczna lub trygonometryczna\nNalezy najpierw wpisac rodzaj funkcji a nastepnie wartosc np.:\nsin( 90\n\n"
                         "Dodatkowo do wyboru w funkcji trygonometrycznej mozna wybrac czy wpisuje sie kat w radianach czy w stopniach\nFunkcja cyklometryczna podaje wartosc w stopniach." << std::endl;
            break;
        case 10:
            std::cout << "Za każdym razem w funkcji najperw należy podać część rzeczywistą a następnie część urojoną.\nPierwsza funkcja kalkulatora jeśli w części urojonej otrzyma zero to potraktuje pierwszy argument jako kąt i należy podać go w stopniach\n"
                         "Jeśli funkcja przyjmuje dwie liczby zespolone to napierw należy podać obie wartości jednej a następnie obie wartości drugiej" << std::endl;
            break;
        case 11:
             std::cout << "Funkcja umozliwia wybor i obliczenie calki oznaczonej z funkcji: liniowej, kwadratowej, sinusa lub cosinusa." << std::endl;
            break;
        case 12:
            goto start;
        case 13:
            goto p_menu;
        default:
            mistake();
            goto p_help;
    }
    char mark;
    std::cout << "Chcialbys zobaczyc wytlumaczenie kolejnej funkcji? [T/N]" << std::endl;
    std::cin >> mark;
    if(std::tolower(mark) == 't')
        goto p_help;
    else
        goto p_menu;

    quit:
        return 1;
}

