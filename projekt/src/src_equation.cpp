#include "equation.hpp"

#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>

void kwadratowa(double a, double b, double c){
    if(a == 0){
        std::cout << "Wspolczynnik przy x^2 nie moze byc zerem"<< std::endl;
    }
    double delta = b * b - 4 * a * c;
    if(delta > 0){
        double x1 = (sqrt(delta) - b) / (2 * a);
        double x2 = (- sqrt(delta) - b) / (2 * a);
        std::cout<< "x1 = "<< x1 << " x2 = "<< x2 << std::endl;
    } else if (delta == 0){
        double x = (- b) / (2 * a);
        std::cout << "Podwojne miejsce zerowe x0 = "<< x << std::endl;
    } else{
        std::cout<< "Brak rzeczywistych pierwiastkow, ale sa zespolone" << std::endl;
        double pierwiastek_z_delty_zespolony = sqrt(sqrt(delta * delta));
        std::cout << "x1 = " << -b/(2 * a) << " + " << pierwiastek_z_delty_zespolony/(2 * a) << "i, x2 = " << -b/(2 * a) << " - " << pierwiastek_z_delty_zespolony/(2 * a) << "i" << std::endl;
    }
}

void kwadratowa(Complex a, Complex b, Complex c){
    if (a.cpx_lg() == 0){
        std::cout << "Wspolczynnik a nie moze byc zerem"<< std::endl;
    } else {
        Complex four(4, 0); // 4 jako liczba zespolona
        Complex two(2, 0); // 2 jako liczba zespolona
        //liczenie delty
        Complex delta = (b * b) - (four * a * c);
        Complex sqrt_delta = sqrt(delta);
        // Oblicz pierwiastki równania
        Complex minus_b = inerface_complex(b);
        Complex x1 = (minus_b + sqrt_delta) / (two * a);
        Complex x2 = (minus_b - sqrt_delta) / (two * a);
        std::cout << "x1 = " << x1.Re << " + " << x1.Im << "i";
        std::cout << " x2 = " << x2.Re << " + " << x2.Im << "i" << std::endl;
    }
}

std::vector<double> solveCubic(double a, double b, double c, double d) {
    std::vector<double> roots;

    if (a == 0) {
        throw std::invalid_argument("To nie jest rownanie trzeciego stopnia");
    }

    // Reduce the cubic equation to the form t^3 + pt + q = 0
    double p = (3 * a * c - b * b) / (3 * a * a);
    double q = (2 * b * b * b - 9 * a * b * c + 27 * a * a * d) / (27 * a * a * a);

    // Calculate the discriminant
    double discriminant = pow(q / 2, 2) + pow(p / 3, 3);

    if (discriminant > 0) {
        // One real root and two complex conjugate roots
        double u = cbrt(-q / 2 + sqrt(discriminant));
        double v = cbrt(-q / 2 - sqrt(discriminant));
        roots.push_back(u + v - b / (3 * a));
    } else if (discriminant == 0) {
        // Three real roots, at least two are equal
        double u = cbrt(-q / 2);
        roots.push_back(2 * u - b / (3 * a));
        roots.push_back(-u - b / (3 * a));
    } else {
        // Three distinct real roots
        double r = sqrt(-pow(p / 3, 3));
        double phi = acos(-q / (2 * r));
        double r_cbrt = cbrt(r);

        roots.push_back(2 * r_cbrt * cos(phi / 3) - b / (3 * a));
        roots.push_back(2 * r_cbrt * cos((phi + 2 * M_PI) / 3) - b / (3 * a));
        roots.push_back(2 * r_cbrt * cos((phi + 4 * M_PI) / 3) - b / (3 * a));
    }

    return roots;
}

void equation(){
    char choice;
    std::cout << "Wybierz typ rownania: (1) kwadratowe, (2) szescienne: ";
    std::cin >> choice;
    if (choice == '1') {
        double a, b, c;
        std::cout << "Rownanie ma postac ax^2 + bx + c\nPodaj wspolczynniki a, b, c: ";
        std::cin >> a >> b >> c;
        kwadratowa(a, b, c);
    } else if (choice == '2') {
        double a, b, c, d;
        std::cout << "Rownanie ma postac ax^3 + bx^2 + cx + d\nPodaj wspolczynniki a, b, c, d: ";
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
        std::cout << "Nie znana komenda \nsprobuj jeszcze raz" << std::endl;
    }
}