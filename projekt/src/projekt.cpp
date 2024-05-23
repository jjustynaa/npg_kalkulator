//
// Created by Marek Generowicz on 27/04/2024.
//
#include "projekt.hpp"

double potegowanie (double liczba, int potega){
    double wynik = 1.0;
    if (potega < 0){
        for (int i = 0; potega < i; i++){
            wynik *= liczba;
        }
    }
    else if (potega == 0){
        wynik = 1.0;
    }
    else {
        for (int i = 0; potega < i; i++) {
            wynik /= liczba;
        }
    }
return wynik;
}

double pierwiastkowanie(double liczba, int stopien){
    if (liczba < 0 && (stopien % 2) == 0 ) {
        return NAN;
    }

    double wynik = liczba / 2.0;
    double przyblizenie = 0.00001;

    while (std::abs(std::pow(wynik, stopien) - liczba) > przyblizenie) {
    wynik = ((stopien - 1.0) * wynik + liczba / std::pow(wynik, stopien - 1.0)) / stopien;
    }

    return wynik;
}

void kalk_poteg (){
    kalk_poteg:
    std::cout <<"Wprowadz co chcesz zrobić\n* - potegowanie\ns - pierwiastkowanie" << std::endl;

    char znak;
    std::cin >> znak;
    switch(znak){
        case '*':
            std::cout << "Podaj wartość jaką chcesz podnieść do potęgi" << std::endl;
            double liczba;
            std::cin >> liczba;
            std::cout << "Podaj stopień do jakiego chcesz podnieść wcześniejszą wartość" << std::endl;
            int stopien;
            std::cin >> stopien;
            std::cout << potegowanie(liczba, stopien) << std::endl;
            break;

        case 's':
            std::cout << "Podaj wartość jaką chcesz pierwiastkowac" << std::endl;
            double wartosc;
            std::cin >> wartosc;
            std::cout << "Podaj stopień piewiastka" << std::endl;
            int pierw;
            std::cin >> pierw;
            std::cout << pierwiastkowanie(wartosc, pierw) << std::endl;
            break;

        default:
            std::cout << "Nie znana komenda \nspróbuj jeszcze raz" << std::endl;
            goto kalk_poteg;
    }
}

double addition(double num1, double num2) {
    return num1 + num2;
}

double subtraction(double num1, double num2) {
    return num1 - num2;
}

double division(double num1, double num2) {
    return num1 / num2;
}

double multiplication(double num1, double num2) {
    return num1 * num2;
}

double exponential(double num1, double num2) {
    return pow(num1, num2);
}

int modulo(int num1, int num2) {
    return num1 % num2;
}

std::vector<std::vector<int>> createMatrix(std::size_t rows, std::size_t col) {
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(col));

    for(std::size_t i = 0; i < rows; i++)
        for(std::size_t j = 0; j < col; j++)
            std::cin >> matrix[i][j];

    return matrix;
}

void showMatrix(std::vector<std::vector<int>> matrix, std::size_t rows, std::size_t col) {
    std::cout << "[" << std::endl;
    for(std::size_t i = 0; i < rows; i++) {
        for (std::size_t j = 0; j < col; j++)
            std::cout << std::setw(3) << matrix[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << "]" << std::endl;
}

void addMatrix(){
    std::size_t rows;
    std::size_t col;
    std::cout <<"Podaj rozmiar wierszy:\n";
    std::cin >> rows;
    std::cout <<"Podaj rozmiar kolumn:\n";
    std::cin >> col;

    std::cout <<"\nWpisywanie wartosci do pierwszej macierzy:\n";
    std::vector<std::vector<int>> matrix1 = createMatrix(rows, col);
    std::cout <<"\nWpisywanie wartosci do drugiej macierzy:\n";
    std::vector<std::vector<int>> matrix2 = createMatrix(rows, col);

    std::vector<std::vector<int>> new_matrix (rows, std::vector<int>(col));
    for(std::size_t i = 0; i < rows; i++)
        for(std::size_t j = 0; j < col; j++)
            new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];

    std::cout << "\nWynik wykonanego dzialania:\n";
    showMatrix(new_matrix ,rows ,col);
}

void substractMatrix(){
    std::size_t rows;
    std::size_t col;
    std::cout <<"Podaj rozmiar wierszy:\n";
    std::cin >> rows;
    std::cout <<"Podaj rozmiar kolumn:\n";
    std::cin >> col;
    std::cout << "Pamietaj zeby podac macierze w odpowiedniej kolejnosci, odejmowanie nie jest dzialaniem przemiennym" << std::endl;

    std::cout <<"\nWpisywanie wartosci do pierwszej macierzy:\n";
    std::vector<std::vector<int>> matrix1 = createMatrix(rows, col);
    std::cout <<"\nWpisywanie wartosci do drugiej macierzy:\n";
    std::vector<std::vector<int>> matrix2 = createMatrix(rows, col);

    std::vector<std::vector<int>> new_matrix (rows, std::vector<int>(col));
    for(std::size_t i = 0; i < rows; i++)
        for(std::size_t j = 0; j < col; j++)
            new_matrix[i][j] = matrix1[i][j] - matrix2[i][j];

    std::cout << "\nWynik wykonanego dzialania:\n";
    showMatrix(new_matrix ,rows ,col);
}

void multiMatrix(){
    std::cout << "Pamietaj ze rozmiar wierszy pierwszej macierzy = rozmiar kolumn drugiej macierzy\n oraz rozmiar kolumn pierwszej macierzy = rozmiar wierszy drugiej macierzy" << std::endl;
    std::size_t rows1;
    std::size_t col1;
    std::size_t rows2;
    std::size_t col2;
    std::cout <<"Podaj rozmiar wierszy pierwszej macierzy:\n";
    std::cin >> rows1;
    col2 = rows1;
    std::cout <<"Podaj rozmiar kolumn pierwszej macierzy:\n";
    std::cin >> col1;
    rows2 = col1;

    std::cout <<"\nWpisywanie wartosci do pierwszej macierzy:\n";
    std::vector<std::vector<int>> matrix1 = createMatrix(rows1, col1);
    std::cout <<"\nWpisywanie wartosci do drugiej macierzy:\n";
    std::vector<std::vector<int>> matrix2 = createMatrix(rows2, col2);

    std::vector<std::vector<int>> new_matrix (rows1, std::vector<int>(col2));
    for(std::size_t i = 0; i < rows1; i++){
        for(std::size_t j = 0; j<col2; j++){
            new_matrix[i][j] = 0;
            for(std::size_t k = 0; k < rows2; k++){
                new_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    std::cout << "\nWynik wykonanego dzialania:\n";
    showMatrix(new_matrix ,rows1 ,col2);
}

void matrix() {
    matrix:
    std::cout <<"Wybierz dzialanie programu:\n+ dodawanie macierzy\n- odejmowanie macierzy\n* mnozenie macierzy" << std::endl;

    char mark;
    std::cin >> mark;
    switch(mark){
        case '+':
            addMatrix();
            break;
        case '-':
            substractMatrix();
            break;
        case '*':
            multiMatrix();
            break;
        default:
            std::cout << "Nie znana komenda \nspróbuj jeszcze raz" << std::endl;
            goto matrix;
    }
}

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
        std::cout << "Funkcja nie znana spróbuj jeszcze raz" << std::endl;
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
        std::cout << "Nieznana komenda spróbuj jeszcze raz" << std::endl;
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
        std::cout << "Nieznane polecenie, spróbuj jeszcze raz" << std::endl;
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
        std::cout << "Nieznane polecenie, spróbuj jeszcze raz" << std::endl;
        cykl();
    }
}




void print_zao(){
    double num;
    int m_p_p;
    std::cin >> num >> m_p_p;
    std::cout << "Liczba po zaokrągleniu wynosi: " << std::fixed << std::setprecision(m_p_p) << num << std::endl;
}

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
        Complex sqrt_delta = delta.sqrt();
        // Oblicz pierwiastki równania
        Complex minus_b = inerface_complex(b);
        Complex x1 = (minus_b + sqrt_delta) / (two * a);
        Complex x2 = (minus_b - sqrt_delta) / (two * a);
        std::cout << "x1 = " << x1.Re << " + " << x1.Im << "i";
        std::cout << " x2 = " << x2.Re << " + " << x2.Im << "i" << std::endl;
    }
}

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

void print_complex(Complex cpx){
    if (cpx.Phi != 7321) {
        std::cout << std::fixed << std::setprecision(3) << cpx.Re << " + i" << cpx.Im << "\ncos(" << cpx.Phi << ") + isin(" << cpx.Phi << ")" << std::endl;
    } else
        std::cout << "Niezdefiniowano";
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
            print_complex(add_complex(comp_1, comp_2));
        } else if (oper == 3){
            print_complex(sub_complex(comp_1, comp_2));
        } else if (oper == 4){
            print_complex(multi_complex(comp_1, comp_2));
        } else if (oper == 5){
            print_complex(div_complex(comp_1, comp_2));
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

bool does_triangle_exist(double a, double b, double c){
    if (a + b > c) return true;
    return false;
}

void triangle(){
    triangle:
    std::cout << "Wybierz jakim sposobem chcialbys obliczyc pole trojkata\n1 - dlugosc boku i wysokosci na niej opuszczonej\n"
                 "2 - znane sa wszystkie dlugosci bokow trojkata\n3 - posiadamy dlugosci dwoch bokow i miare kata pomiedzy nimi" << std::endl;
    int mark;
    std::cout << "Wybierz cyfre:\n";
    std::cin >> mark;

    double a, b, c, h, p, angle;
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
            area = a * h / 2;
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
                p = (a + b + c) / 2;
                area = sqrt(p * (p - a) * (p - b) * (p - c));
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

            area = a * b * sin(angle) / 2;
            break;
        default:
            std::cout << "Wybrano nieprawidlowa operacje" << std::endl;
            //blad();
            goto triangle;
    }

    std::cout << "Pole trojkata wynosi: " << area << std::endl;
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
    area = a * b;
    std::cout << "Pole prostokatu wynosi: " << area << std::endl;
}

void area(){
    area:
    std::cout <<"Wybierz dzialanie programu:\nP obliczanie pola prostokata\nT obliczanie pola trojkata" << std::endl;

    char mark;
    std::cin >> mark;
    switch( std::tolower(mark) ){
        case 'p':
            rectangular();
            break;
        case 't':
            triangle();
            break;
        default:
            std::cout << "Wybrano nieprawidlowa operacje" << std::endl;
            //blad();
            goto area;
    }
}
