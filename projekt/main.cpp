#include "projekt.hpp"

//Jeśli ktoś to czyta to tłumacze te 4 błędy co są
//dwa z nich pojawiają się przez puste swiche i nimi się wgl nie przejmujemy
//dwa pozostałe są bo używamy comon configa z PSiO i niepodoba mu się że porównujemy coś do NULLa dla charów
// więc można spróbować go jakoś ładnie upakować żeby się nie czepiało ale raczej nic to nie zepsuje
void czyszczenie(){
    for (int i = 0; i < 25; i++) {
        std::cout << std::endl;
    }
}

void blad(){
    std::cout << "Nie znana komenda \nspróbuj jeszcze raz" << std::endl;
}

int repet(){
    std::string con;
    std::cout << "Chcesz kontunuować? [T/N]" << std::endl;
    std::cin >> con;
    if (con == "T"){
        return 1;
    } else{
        return 0;
}}


int main() {

    start:
    czyszczenie();
    std::cout << "<<Witaj w kalkulatorze>>\n\nAby przejść dalej wpisz NEXT" << std::endl;
    goto next;

    next:
    std::string t;
    std::cin >> t;
    if (t == "NEXT" || t == "Next" || t == "next"){
        czyszczenie();
        goto p_menu ;
    } else{
        blad();
        goto next;
    }

    p_menu:
    std::cout << "Jakiej funkcji chcesz użyć:\n 1. Kalkulator prosty \n 2. Kalkulator macierzowy\n 3. Potęgowanie i pierwiastkowanie\n 4. Przelicznik wartości"
                 "\n 5. Porównywanie liczb \n 6. Zaokrąglenia \n 7. Kalkulator rówań kwadratowych \n 8. Kalkulator pól i objętości"
                 "\n 9. Kalkulator logarytmiczny \n10. Kalkulator do funkcji trygonometrycznych oraz funkcji cyklometrycznych\n\nAby dowiedzieć się jak działają dane funkcje i jak poprawnie z nich kożystać wpisz help\n"<<std::endl;
    goto menu;
// menu i p_menu osobne, żeby móc je w razie złego wpisania przeskakiwać do menu a nie od początki p_menu
    menu:
    char fun;
    int ans;
    std::string funk;
    std::cin >> fun;
    std::cin >> funk;
    czyszczenie();
    switch (fun)
    {
        case '1': //// ten case sprawdza i 1 i 10
            if (funk == "0"){
                std::cout << "10";
                break;
            }else if (funk == "\0") {
                std::cout << "1";
                break;
            }
        case '2':
            //przerzut na macierzowy
            break;
        case '3':
            //przerzut na potęgi
            break;
        case '4':
            //przerzut na przelicznik
            break;
        case '5':
            //przerzut na porówania
            break;
        case '6':
            //przerzut na zaokrąglenia
            break;
        case '7':
            //przerzut na funkcje kwadratową
            break;
        case '8':
            //przerzut na pola
            break;
        case '9':
            //perzut na logarytmy
            break;
        case 'h':
            if (funk == "elp"){
                goto p_help;
            }
        case 'r':
            if (funk == "eset"){
                goto start;
            }
        default:
            blad();
            goto menu;
    }
    ans = repet();
    if (ans == 1){
        goto p_menu;
    } else{
        return EXIT_SUCCESS;
    }


    p_help:
    std::cout << "Którą funkcje wytłumaczyć:\n 1. Kalkulator prosty \n 2. Kalkulator macierzowy\n 3. Potęgowanie i pierwiastkowanie\n 4. Przelicznik wartości"
                 "\n 5. Porównywanie liczb \n 6. Zaokrąglenia \n 7. Kalkulator rówań kwadratowych \n 8. Kalkulator pól i objętości"
                 "\n 9. Kalkulator logarytmiczny \n10. Kalkulator do funkcji trygonometrycznych oraz funkcji cyklometrycznych\n\nAby wrócić do wyboru kalkulatora wpisz back\n" << std::endl;

    help:
    char com;
    std::string comend;
    std::cin >> com;
    std::cin >> comend;
    switch (com) {
        case '1':
            if (comend == "0"){
                std::cout << "10"; // zmienić 10 na opis co robi ta funkcja
                break;
            }else if (comend == "\0") {
                std::cout << "1"; // analogicznie jak wyżej ale to co wyrzej
                 break;
            }
            goto p_menu;
        case '2':
            //przerzut na macierzowy
            goto p_menu;

        case '3':
            //przerzut na potęgi
            goto p_menu;
        case '4':
            //przerzut na przelicznik
            goto p_menu;
        case '5':
            //przerzut na porówania
            goto p_menu;
        case '6':
            //przerzut na zaokrąglenia
            goto p_menu;
        case '7':
            //przerzut na funkcje kwadratową
            goto p_menu;
        case '8':
            //przerzut na pola
            goto p_menu;
        case '9':
            //perzut na logarytmy
            goto p_menu;
        case '10':
            //przerzut na sin i arcsin
            goto p_menu;
        case 'b':
            if (comend == "ack") {
                goto p_menu;
            }
        case 'r':
            if (comend == "eset") {
                goto start;
            }
        default:
            blad();
            goto help;

    }

//    finish:
//    std::string con;
//    std::cout << "Chcesz kontunuować? [T/N]";
//    std::cin >> con;
//    if (con == "T"){
//        goto p_menu;
//    } else{
//        return 0;
//    }




}
