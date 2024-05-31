#include "area.hpp"
#include "rounding.hpp"

#include <iostream>
#include <string>
#include <cmath>

bool does_triangle_exist(double a, double b, double c){
    if (a + b > c) return true;
    return false;
}

double triangleArea1(double a, double h){
    return a * h / 2;
}

double triangleArea2(double a, double b, double c){
    double p = (a + b + c) / 2;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
    return significant_figure(area, 8);
}

double triangleArea3(double a, double b, double angle){
    double area = a * b * sin(angle*3.14159/180) / 2;
    return significant_figure(area, 8);
}

void triangle(){
    triangle:
    std::cout << "Wybierz jakim sposobem chcialbys obliczyc pole trojkata\n1 - dlugosc boku i wysokosci na niej opuszczonej\n"
                 "2 - znane sa wszystkie dlugosci bokow trojkata\n3 - posiadamy dlugosci dwoch bokow i miare kata pomiedzy nimi" << std::endl;
    int mark;
    std::cout << "Wybierz cyfre:\n";
    std::cin >> mark;

    double a, b, c, h, angle;
    double area;

    switch( mark ){
        case 1:
            std::cout << "Obliczanie pola przez podanie boku i wysokosci." << std::endl;
        bok11:
            std::cout << "Dlugosc boku:\n";
            std::cin >> a;
            if (a <= 0 ){
                std::cout << "Podano nieprawidlowa dlugosc. Sprobuj ponownie." << std::endl;
                goto bok11;
            }
        wysokosc11:
            std::cout << "Dlugosc wysokosci:\n";
            std::cin >> h;
            if (h <= 0 ){
                std::cout << "Podano nieprawidlowa dlugosc. Sprobuj ponownie." << std::endl;
                goto wysokosc11;
            }
            area = triangleArea1(a, h);
            break;

        case 2:
        triangle2:
            std::cout << "Obliczanie pola przez podanie dlugosci wszystkich bokow." << std::endl;
        bok21:
            std::cout << "Dlugosc pierwszego boku:\n";
            std::cin >> a;
            if (a <= 0 ){
                std::cout << "Podano nieprawidlowa dlugosc. Sprobuj ponownie." << std::endl;
                goto bok21;
            }
        bok22:
            std::cout << "Dlugosc drugiego boku:\n";
            std::cin >> b;
            if (b <= 0 ){
                std::cout << "Podano nieprawidlowa dlugosc. Sprobuj ponownie." << std::endl;
                goto bok22;
            }
        bok23:
            std::cout << "Dlugosc trzeciego boku:\n";
            std::cin >> c;
            if (c <= 0 ){
                std::cout << "Podano nieprawidlowa dlugosc. Sprobuj ponownie." << std::endl;
                goto bok23;
            }

            if(does_triangle_exist(a,b,c) && does_triangle_exist(c,a,b) && does_triangle_exist(b,c,a)) {
                area = triangleArea2(a, b, c);
            }
            else {
                std::cout << "Podano nieprawidlowe dlugosci w trojkacie. Trojkat nie istnieje.\n"
                             "Sprobuj jeszcze raz" << std::endl;
                goto triangle2;
            }
            break;

        case 3:
            std::cout << "Obliczanie pola przez podanie dlugosci dwoch bokow i kata pomiedzy nimi." << std::endl;
        bok31:
            std::cout << "Dlugosc pierwszego boku:\n";
            std::cin >> a;
            if (a <= 0 ){
                std::cout << "Podano nieprawidlowa dlugosc. Sprobuj ponownie." << std::endl;
                goto bok31;
            }
        bok32:
            std::cout << "Dlugosc drugiego boku:\n";
            std::cin >> b;
            if (b <= 0 ){
                std::cout << "Podano nieprawidlowa dlugosc. Sprobuj ponownie." << std::endl;
                goto bok32;
            }
        miara:
            std::cout << "Miara kata:\n";
            std::cin >> angle;
            if ((angle <= 0) || (angle > 180)){
                std::cout << "Podano nieprawidlowa miare. Sprobuj ponownie." << std::endl;
                goto miara;
            }

            area = triangleArea3(a, b, angle);
            break;
        default:
            std::cout << "Wybrano nieprawidlowa operacje" << std::endl;
            //blad();
            goto triangle;
    }

    std::cout << "Pole trojkata wynosi: " << area << std::endl;
}

double rectangularArea(double a, double b){
    return a * b;
}

void rectangular(){
    double a;
    double b;
    double area;
    std::cout << "Podaj dlugosci bokow prostokata: " << std::endl;
    bok1:
    std::cout << "Dlugosc pierwszego boku:\n";
    std::cin >> a;
    if (a <= 0 ){
        std::cout << "Podano nieprawidlowa dlugosc. Sprobuj ponownie." << std::endl;
        goto bok1;
    }
    bok2:
    std::cout << "Dlugosc drugiego boku:\n";
    std::cin >> b;
    if (b <= 0 ){
        std::cout << "Podano nieprawidlowa dlugosc. Sprobuj ponownie." << std::endl;
        goto bok2;
    }
    area = rectangularArea(a, b);
    std::cout << "Pole prostokatu wynosi: " << area << std::endl;
}

double diamondArea1(double a, double h){
    return a * h;
}

double diamondArea2(double e, double f){
    return e * f / 2;
}

void diamond(){
    diamond:
    std::cout << "Wybierz jakim sposobem chcialbys obliczyc pole trapezu\n1 - dlugosc boku i wysokosci na niej opuszczonej\n"
                 "2 - znane sa dlugosci przekatnych rombu" << std::endl;

    int mark;
    std::cout << "Wybierz cyfre:\n";
    std::cin >> mark;

    double a, h;
    double area;

    switch( mark ){
        case 1:
            std::cout << "Obliczanie pola przez podanie boku i wysokosci." << std::endl;
        bok11:
            std::cout << "Dlugosc boku:\n";
            std::cin >> a;
            if (a <= 0 ){
                std::cout << "Podano nieprawidlowa dlugosc. Sprobuj ponownie." << std::endl;
                goto bok11;
            }
        wysokosc11:
            std::cout << "Dlugosc wysokosci:\n";
            std::cin >> h;
            if (h <= 0 ){
                std::cout << "Podano nieprawidlowa dlugosc. Sprobuj ponownie." << std::endl;
                goto wysokosc11;
            }
            area = diamondArea1(a, h);
            break;

        case 2:
            std::cout << "Obliczanie pola przez podanie dlugosci przekatnych." << std::endl;
        bok21:
            std::cout << "Dlugosc pierwszej przekatnej:\n";
            std::cin >> a;
            if (a <= 0 ){
                std::cout << "Podano nieprawidlowa dlugosc. Sprobuj ponownie." << std::endl;
                goto bok21;
            }
        bok22:
            std::cout << "Dlugosc drugiej przekatnej:\n";
            std::cin >> h;
            if (h <= 0 ){
                std::cout << "Podano nieprawidlowa dlugosc. Sprobuj ponownie." << std::endl;
                goto bok22;
            }
            area = diamondArea2(a, h);
            break;

        default:
            std::cout << "Wybrano nieprawidlowa operacje" << std::endl;
            //blad();
            goto diamond;
    }
    std::cout << "Pole rombu wynosi: " << area << std::endl;
}

double trapezeArea(double a, double b, double h){
    return (a + b) * h / 2;
}

void trapeze(){
    double a;
    double b;
    double h;
    double area;
    std::cout << "Podaj dlugosci podstaw trapezu: " << std::endl;
    bok1:
    std::cout << "Dlugosc pierwszej podstawy:\n";
    std::cin >> a;
    if (a <= 0 ){
        std::cout << "Podano nieprawidlowa dlugosc. Sprobuj ponownie." << std::endl;
        goto bok1;
    }
    bok2:
    std::cout << "Dlugosc drugiej podstawy:\n";
    std::cin >> b;
    if (b <= 0 ){
        std::cout << "Podano nieprawidlowa dlugosc. Sprobuj ponownie." << std::endl;
        goto bok2;
    }
    wysokosc:
    std::cout << "Dlugosc wysokosci:\n";
    std::cin >> h;
    if (h <= 0 ){
        std::cout << "Podano nieprawidlowa dlugosc. Sprobuj ponownie." << std::endl;
        goto wysokosc;
    }
    area = trapezeArea(a, b, h);
    std::cout << "Pole trapezu wynosi: " << area << std::endl;
}

void area(){
    area:
    std::cout <<"Wybierz dzialanie programu:\nP obliczanie pola prostokata\nT obliczanie pola trojkata\nR obliczanie pola rombu\nN obliczanie pola trapezu" << std::endl;

    char mark;
    std::cin >> mark;
    switch( std::tolower(mark) ){
        case 'p':
            rectangular();
            break;
        case 't':
            triangle();
            break;
        case 'r':
            diamond();
            break;
        case 'n':
            trapeze();
            break;
        default:
            std::cout << "Wybrano nieprawidlowa operacje" << std::endl;
            //blad();
            goto area;
    }
}