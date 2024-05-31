#ifndef PROJEKT_MATRIX_HPP
#define PROJEKT_MATRIX_HPP

#include <vector>

//matrix
std::vector<std::vector<int>> createMatrix(std::size_t rows, std::size_t col);
void showMatrix(std::vector<std::vector<int>> matrix, std::size_t rows, std::size_t col);
std::vector<std::vector<int>> addMatrix (std::vector<std::vector<int>> matrix1, std::vector<std::vector<int>> matrix2, std::size_t rows, std::size_t col);
void addMatrix_user();
std::vector<std::vector<int>> substractMatrix (std::vector<std::vector<int>> matrix1, std::vector<std::vector<int>> matrix2, std::size_t rows, std::size_t col);
void substractMatrix_user();
std::vector<std::vector<int>> multiMatrix(std::vector<std::vector<int>> matrix1, std::vector<std::vector<int>> matrix2, std::size_t rows1, std::size_t rows2, std::size_t col2);
void multiMatrix_user();
bool sq_matrix(std::vector<std::vector<int>> Matrix);
std::vector<std::vector<int>> Matrix_cutter(const std::vector<std::vector<int>>& Matrix, std::size_t row_to_cut, std::size_t col_to_cut);
int determinant(const std::vector<std::vector<int>>& Matrix);
void determinat_str();
void matrix();

#endif //PROJEKT_MATRIX_HPP
