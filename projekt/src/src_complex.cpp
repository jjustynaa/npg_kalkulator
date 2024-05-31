#include "complex.hpp"

double Complex::clasic_to_tryg() const {
    if (Im >= 0 && cpx_lg() != 0) {
        return acos(Re / cpx_lg());
    } else if (Im < 0) {
        return -acos(Re / cpx_lg());
    } else if (cpx_lg() == 0) {
        return 7312;
    }
    return 7312;
}

Complex inerface_complex(Complex& cpx){
    Complex cpx_int(cpx.Re, -cpx.Im);
    return cpx_int;
}

void print_complex(Complex cpx){
    if (cpx.Phi != 7321) {
        std::cout << std::fixed << std::setprecision(3) << cpx.Re << " + i" << cpx.Im << "\ncos(" << cpx.Phi << ") + isin(" << cpx.Phi << ")" << std::endl;
    } else
        std::cout << "Niezdefiniowano";
}

Complex sqrt(Complex& cpx){
    std::complex<double> cpx_pr = std::sqrt(std::complex<double>(cpx.Re, cpx.Im));
    Complex cpx_1(real(cpx_pr), imag(cpx_pr));
    return cpx_1;
}

void complex_choice(){
    char oper;
    std::vector<double> tym_kont;
    std::cout << "Możliwe operacje do wykonania:\n1. Przekształcenie liczby zespolonej z postaci trygonometrycznej do postaci kanoniczej i na odwrót\n"
                 "2. Dodawanie liczb zespolonych\n3. Odejmowanie liczb zespolonych\n4. Mnożenie liczb zespolonych\n5. Dzielenie liczb zespolonych\n"
                 "6. Znajdowanie liczby sprzeżonej\n 7.Obliczanie długości liczby zespolonej\n\nKtórą z operacji chcesz wykonać?" << std::endl;
    std::cin >> oper;
    if (oper == 1){
        double re;
        double im;
        std::cout << "Podaj liczbe zespoloną" << std::endl;
        std::cin >> re;
        std::cin >> im;
        if (im != 0) {
            Complex zes(re, im);
            print_complex(zes);
        } else {
            re = re * M_PI / 180;
            Complex zes(re);
            print_complex(zes);
        }
    } else if (oper == 2 || oper == 3 || oper == 4 || oper == 5){
        std::cout << "Podaj liczby zespolone" << std::endl;
        double re_1, im_1, re_2, im_2;
        std::cin >> re_1;
        std::cin >> im_1;
        std::cin >> re_2;
        std::cin >> im_2;
        Complex comp_1(re_1, im_1);
        Complex comp_2(re_2, im_1);
        if (oper == 2){
            print_complex(comp_1 + comp_2);
        } else if (oper == 3){
            print_complex(comp_1 - comp_2);
        } else if (oper == 4){
            print_complex(comp_1 * comp_2);
        } else if (oper == 5){
            print_complex(comp_1 / comp_2);
        }
    } else if (oper == 6 || oper == 7){
        double re;
        double im;
        std::cout << "Podaj liczby zespolone" << std::endl;
        std::cin >> re;
        std::cin >> im;
        Complex comple(re, im);
        if (oper == 6){
            print_complex(inerface_complex(comple));
        } else{
            std::cout << comple.cpx_lg();
        }
    } else {
        char wyb;
        std::cout << "Nie zdefiniowano, chcesz wrócić do menu [T/N]" << std::endl;
        std::cin >> wyb;
        if (wyb == 'N'){
            complex_choice();
        }
    }
}