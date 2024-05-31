#include "accessory.hpp"

#include <algorithm>

void clear(){
    for (int i = 0; i < 25; i++) {
        std::cout << std::endl;
    }
}

void mistake() {
    std::cout << "Nie znana komenda \nSprobuj jeszcze raz" << std::endl;
}

void mistake_value(){
    std::cout << "Podano nieprawidlowa wartosc. Sprobuj ponownie." << std::endl;
}

int repeat() {
    char con;
    std::cout << "Chcesz kontynuowac? [T/N]" << std::endl;
    std::cin >> con;
    return (std::tolower(con) == 'n') ? 0 : 1;
}

std::string lower(std::string word){
    std::transform(word.begin(), word.end(), word.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return word;
}
