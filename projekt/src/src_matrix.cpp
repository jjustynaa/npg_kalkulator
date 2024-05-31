#include "matrix.hpp"

//funkcja tworzaca macierz o okreslonym rozmarze
std::vector<std::vector<int>> createMatrix(std::size_t rows, std::size_t col) {
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(col));

    for(std::size_t i = 0; i < rows; i++)
        for(std::size_t j = 0; j < col; j++) {
            std::cout << "[ " << i+1 << ", " << j+1 << "]:";
            std::cin >> matrix[i][j];
        }

    return matrix;
}

//funkcja pokazujaca na ekran macierz wynikowa
void showMatrix(std::vector<std::vector<int>> matrix, std::size_t rows, std::size_t col) {
    std::cout << "[" << std::endl;
    for(std::size_t i = 0; i < rows; i++) {
        for (std::size_t j = 0; j < col; j++)
            std::cout << std::setw(3) << matrix[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << "]" << std::endl;
}

//funkcja dodajaca macierze
std::vector<std::vector<int>> addMatrix (std::vector<std::vector<int>> matrix1, std::vector<std::vector<int>> matrix2, std::size_t rows, std::size_t col){
    std::vector<std::vector<int>> new_matrix (rows, std::vector<int>(col));
    for(std::size_t i = 0; i < rows; i++)
        for(std::size_t j = 0; j < col; j++)
            new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
    return new_matrix;
}

void addMatrix_user(){
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
    new_matrix = addMatrix(matrix1, matrix2, rows, col);

    std::cout << "\nWynik wykonanego dzialania:\n";
    showMatrix(new_matrix ,rows ,col);
}

//funkcja odejmujaca macierze
std::vector<std::vector<int>> substractMatrix (std::vector<std::vector<int>> matrix1, std::vector<std::vector<int>> matrix2, std::size_t rows, std::size_t col){
    std::vector<std::vector<int>> new_matrix (rows, std::vector<int>(col));
    for(std::size_t i = 0; i < rows; i++)
        for(std::size_t j = 0; j < col; j++)
            new_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
    return new_matrix;
}

void substractMatrix_user(){
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
    new_matrix = substractMatrix(matrix1, matrix2, rows, col);

    std::cout << "\nWynik wykonanego dzialania:\n";
    showMatrix(new_matrix ,rows ,col);
}

//funkcja mnozaca macierze
std::vector<std::vector<int>> multiMatrix(std::vector<std::vector<int>> matrix1, std::vector<std::vector<int>> matrix2, std::size_t rows1, std::size_t rows2, std::size_t col2){
    std::vector<std::vector<int>> new_matrix (rows1, std::vector<int>(col2));
    for(std::size_t i = 0; i < rows1; i++){
        for(std::size_t j = 0; j < col2; j++){
            new_matrix[i][j] = 0;
            for(std::size_t k = 0; k < rows2; k++){
                new_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return new_matrix;
}

void multiMatrix_user(){
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
    new_matrix = multiMatrix(matrix1, matrix2, rows1, rows2, col2);

    std::cout << "\nWynik wykonanego dzialania:\n";
    showMatrix(new_matrix ,rows1 ,col2);
}

//wyznaczniki macierzy
//funkcja sprawdzająca czy macierz jest kwadratowa
bool sq_matrix(std::vector<std::vector<int>> Matrix){
    if (Matrix.size() == Matrix[0].size()) {
        return true;
    }else {
        return false;
    }}

//funkcja zmniejszająca macierz
std::vector<std::vector<int>> Matrix_cutter(const std::vector<std::vector<int>>& Matrix, std::size_t row_to_cut, std::size_t col_to_cut){
    std::vector<std::vector<int>> Cutted_Matrix;
    for(std::size_t i = 0; i < Matrix.size(); i++){
        if (i != row_to_cut - 1){
            std::vector<int> row;
            for (std::size_t j = 0; j < Matrix[0].size(); j++){
                if (j != col_to_cut - 1){
                    row.push_back(Matrix[i][j]);
                }
            }
            Cutted_Matrix.push_back(row);
        }
    }
    return Cutted_Matrix;
}

//funckaj licząca wartość wyznacznika
int determinant(const std::vector<std::vector<int>>& Matrix){
    if (Matrix.size() == 1){
        return Matrix[0][0];
    } else if (Matrix.size() == 2) {
        return Matrix[0][0] * Matrix[1][1] - Matrix[0][1] * Matrix[1][0];
    } else {
        int deter = 0;
        for (std::size_t i = 0; i < Matrix.size(); ++i) {
            std::vector<std::vector<int>> subMatrix = Matrix_cutter(Matrix, 1, i+1);
            deter += (i % 2 == 0 ? 1 : -1) * Matrix[0][i] * determinant(subMatrix);
        }
        return deter;
    }
}

//funkcja do opisu do wyznacznika
void determinat_str(){
    std::size_t  r;
    std::size_t  k;
    std::cout << "Podaj liczbę wierszy i kolumn" << std::endl;
    std::cin >> r;
    std::cin >> k;
    std::vector<std::vector<int>> Matrix = createMatrix(r,k);
    if(sq_matrix(Matrix)){
        std::cout << "Wyznacznik macierzy:" << std::endl;
        showMatrix(Matrix, Matrix.size(), Matrix[0].size());
        std::cout << "Wynosi: " << determinant(Matrix) << std::endl;
    }else{
        std::cout << "Nie można policzyć wyznacznika ponieważ macierz nie jest macierzą kwadratową" << std::endl;
    }
}

//menu funkcji macierz
void matrix() {
    matrix:
    std::cout <<"Wybierz dzialanie programu:\n+ dodawanie macierzy\n- odejmowanie macierzy\n* mnozenie macierzy\n| wyznacznik macierzy" << std::endl;

    char mark;
    std::cin >> mark;
    switch(mark){
        case '+':
            addMatrix_user();
            break;
        case '-':
            substractMatrix_user();
            break;
        case '*':
            multiMatrix_user();
            break;
        case '|':
            determinat_str();
            break;
        default:
            std::cout << "Nie znana komenda \nspróbuj jeszcze raz" << std::endl;
            goto matrix;
    }
}