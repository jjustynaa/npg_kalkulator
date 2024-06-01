#include "main.hpp"
#include <iostream>
#include <string>
#include <cctype>

int main() {

    start:
    clear();
    std::cout << "<<Witaj w kalkulatorze>>\n\nAby przejsc dalej wpisz NEXT\n\nAby zatwierdzic komende i (pozniej) wartosci liczbowe po kazdej wcisnij ENTER" << std::endl;
    std::string t;
    std::cin >> t;
    t = lower(t);
    if (t != "next") {
        mistake();
        goto start;
    }

    clear();
    p_menu:
    std::cout << "Jakiej funkcji chcesz uzyc:\n"
                 " 0. Help\n"
                 " 1. Kalkulator prosty\n"
                 " 2. Kalkulator macierzowy\n"
                 " 3. Potegowanie i pierwiastkowanie\n"
                 " 4. Przelicznik wartosci\n"
                 " 5. Zaokraglenia i cyfry znaczace\n"
                 " 6. Kalkulator rownan kwadratowych lub rownan trzeciego stopnia\n"
                 " 7. Kalkulator pol\n"
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
            value_conventer();
            if (!repeat()) goto quit;
            clear();
            goto p_menu;
        case 5:
            round_significant();
            if (!repeat()) goto quit;
            clear();
            goto p_menu;
        case 6:
            equation();
            if (!repeat()) goto quit;
            clear();
            goto p_menu;
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
                 " 1. Kalkulator prosty\n"
                 " 2. Kalkulator macierzowy\n"
                 " 3. Potegowanie i pierwiastkowanie\n"
                 " 4. Przelicznik wartosci\n"
                 " 5. Zaokraglenia i cyfry znaczace\n"
                 " 6. Kalkulator rownan kwadratowych lub rownan trzeciego stopnia\n"
                 " 7. Kalkulator pol\n"
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
            std::cout << "Program dodaje, odejmuje, mnozy macierze i liczy wyznacznik macierzy\nNa poczatku nalezy wybrac znak, pozniej wprowadzic odpowiednie macierze\n\n"
                         "Nalezy pamietac ze wielkosc macierzy w dodawaniu i odejmowaniu musi sie pokrywac\n"
                         "W mnozeniu zas te wielkosci sa odwrotne: wiersze jednej = kolumny drugiej, kolumny pierwszej = wiersze drugiej.\n"
                         "Obliczanie wyznacznika odbywa sę tylko dla macierzy kwadratowych" << std::endl;
            break;
        case 3:
            std::cout << "Funkcja oblicza potegi oraz pierwiastki liczb zmienno przecinkowych, wynik podaje z dokladnoscia do czterech miejsc po przecinku\n"
                         "Pierwsze co nalezy zrobic to wybrac czy chcemy aby funkcja obliczyla pierwastek czy potege.\n"
                         "Pierwsza wpisywana przez nas wartosc to liczba ktora program ma podniesc do potegi, badz spierwiastkowac.\n"
                         "Druga wpisywana wartosc to stopien do jakiego ma byc podniesiona liczba, badz stopien pierwiastka"<< std::endl;
            break;
        case 4:
            std::cout << "Program przelicza wartosci z danych jednostek na inne. Musisz wybrac jakiego rodzaju wartosci cie interesuja\n"
                         "Program obsluguje wartosci predkosci, dlugosci oraz czasu\n"
                         "Po zdecydowaniu sie na jedna z tych trzech opcji nalezy wybrac dokladny rodzaj jednostek do przeliczenia, a nastepnie wpisac wartosc, ktora nalezy przeliczyc" << std::endl;
            break;
        case 5:
            std::cout << "Zaokraglenie przyjmuje dwie wartosci: liczbe do zaokraglania oraz liczbe miejsc po przecinku, ile oczekujesz otrzymac\n"
                         "Cyfry znaczace - podaj liczbe i ilosc cyfr, ile chcesz uzyskac w wyniku koncowym (cyfry liczone sa od pierwszej wartosci niezerowej od lewej strony" << std::endl;
            break;
        case 6:
            std::cout << "Funkcja rozwiazuje rownania, ale najpierw musisz wybrac typ: kwadratowe - okreslone rownaniem 'ax^2 + bx + c' lub szescienne - 'ax^3 + bx^2 + cx + d" << std::endl;
            break;
        case 7:
            std::cout << "Program oblicza pole wybranej figury: prostokat, trojkat, romb i trapez.\n"
                         "W obliczaniu pola prostokata wystarczy podac dlugosciu obu bokow po odpowiedniej komendzie.\n"
                         "Pole trojkata mozna obliczyc na 3 sposoby: 1. majac dlugosc boku i jego prostopadla wysokosc, 2. majac wszystkie dlugosci bokow, 3. majac dlugosci dwoch bokow i kat pomiedzy nimi.\n"
                         "Przy rombie pola mozna obliczyc na 2 sposoby: 1. znajac dlugosc boku i wysokosc, 2. znane sa dlugosci jego przekatnych.\n"
                         "Natomiast pole trapezu obliczamy znajac dlugosci jego postaw i wysokosc." << std::endl;
            break;
        case 8:
            std::cout << "Kalkulator pozwalajacy obliczyc numeryczna wartosc logaytmu\n"
                         "Uzytkownik wpisuje logarytmowana liczbe i podstawe logarytmu" << std::endl;
            break;
        case 9:
            std::cout << "Program tworzy funkcje cyklometryczna lub trygonometryczna\nNalezy najpierw wpisac rodzaj funkcji a nastepnie wartosc\n\n"
                         "Dodatkowo do wyboru w funkcji trygonometrycznej mozna wybrac czy wpisuje sie kat w radianach czy w stopniach\nFunkcja cyklometryczna podaje wartosc w stopniach." << std::endl;
            break;
        case 10:
            std::cout << "Za kazdym razem w funkcji najpierw nalezy podac czesc rzeczywistą a następnie cześć urojona.\nPierwsza funkcja kalkulatora jesli w częsci urojonej otrzyma zero to potraktuje pierwszy argument jako kat i nalezy podac go w stopniach\n"
                         "Jesli funkcja przyjmuje dwie liczby zespolone to napierw nalezy podac obie wartosci jednej a nastepnie obie wartosci drugiej" << std::endl;
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
