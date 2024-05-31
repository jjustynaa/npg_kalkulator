#include "trigonometric.hpp"
#include "accessory.hpp"

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

void cykl_o_tryg() {
    std::string choose;
    std::cout << "Chcesz skorzystać z funkcji cyklometrycznej czy trygonometrycznej" << std::endl;
    std::cin >> choose;
    if (choose.find("cyklome") != std::string::npos) {
        cykl();
    } else if (choose.find("trygono") != std::string::npos) {
        tryg();
    } else if (choose == "back"){

    }else{
        mistake();
        cykl_o_tryg();
    }
}

void tryg() {
    std::cout << "Podaj funkcje i liczbe" << std::endl;

    double num;

    std::string fun_tryg;

    std::cin >> fun_tryg >> num;

    std::string wyb;

    std::cout << "Wartość podajesz w radjanach czy stopniach?" << std::endl;

    std::cin >> wyb;

    if (wyb.find("stop") != std::string::npos) {
        num = num / 57.3;
    } else if (wyb.find("stop") == std::string::npos && wyb.find("radia") == std::string::npos) {
        mistake();
        tryg();
    }


    if (fun_tryg.find("sin") != std::string::npos) {
        std::cout << "Warotść sinusa podanego kąta wynosi " << sin(num) << std::endl;
    } else if (fun_tryg.find("cos") != std::string::npos) {
        std::cout << "Warotść cosinsusa podanego kąta wynosi " << cos(num) << std::endl;
    } else if (fun_tryg.find("tan") != std::string::npos) {
        std::cout << "Warotść tangensa podanego kąta wynosi " << tan(num) << std::endl;
    } else if (fun_tryg.find("ctag") != std::string::npos) {
        std::cout << "Warotść cotangensa podanego kąta wynosi " << 1 / tan(num) << std::endl;
    } else if (fun_tryg == "back"){

    } else {
        mistake();
        tryg();
    }
}

void cykl() {
    std::cout << "Podaj funkcje i liczbe" << std::endl;

    double num;

    std::string fun_cyk;

    std::cin >> fun_cyk >> num;

    if (fun_cyk.find("sin") != std::string::npos) {
        std::cout << "Warotść arcusasinusa podanego kąta wynosi " << std::fixed << std::setprecision(1)
                  << asin(num) * 57.3 << "°" << std::endl;
    } else if (fun_cyk.find("cos") != std::string::npos) {
        std::cout << "Warotść arcusacosinusa podanego kąta wynosi " << std::fixed << std::setprecision(1)
                  << acos(num) * 57.3 << "°" << std::endl;
    } else if (fun_cyk.find("tan") != std::string::npos) {
        std::cout << "Warotść arcusatangensa podanego kąta wynosi " << std::fixed << std::setprecision(1)
                  << atan(num) * 57.3 << "°" << std::endl;
    } else if (fun_cyk.find("ctag") != std::string::npos) {
        std::cout << "Warotść arcusacotangensa podanego kąta wynosi " << std::fixed << std::setprecision(1)
                  << M_PI / 2 - atan(num) * 57.3 << "°" << std::endl;
    } else if (fun_cyk == "back"){

    } else {
        mistake();
        cykl();
    }
}