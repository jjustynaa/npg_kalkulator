//
// Created by Marek Generowicz on 27/04/2024.
//
#include "projekt.hpp"

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

std::vector<double> kwadratowa(double a, double b, double c){
    if(a == 0){
        std::cout << "Wspolczynnik przy x^2 nie moze byc zerem"<< std::endl;
        return {};
    }
    double delta = b * b - 4 * a * c;
    if(delta > 0){
        double x1 = (sqrt(delta) - b) / (2 * a);
        double x2 = (- sqrt(delta) - b) / (2 * a);
        return std::vector<double> {x1, x2};
    } else if (delta == 0){
        double x = (- b) / (2 * a);
        return std::vector<double> {x};
    } else{
        std::cout<< "Brak rzeczywistych pierwiastkow" << std::endl;
        return {};
    }
}

