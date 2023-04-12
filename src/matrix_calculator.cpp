/**
 * @file matrix_calculator.cpp
 *
 * A simple matrix calculator implementation.
 *
 * @author Bryant Whitaker, brywhit@bgsu.edu
 */

#include "matrix_calculator.hpp"

MatrixCalculator::MatrixCalculator() : matrix_vector(std::vector<Matrix>()), current_matrix(Matrix()), num_calculations(0) {
}

void MatrixCalculator::add_matrix() {
    int rows, cols;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;
    Matrix new_matrix = Matrix(rows, cols);
    matrix_vector.push_back(new_matrix);
}

Matrix MatrixCalculator::add(const Matrix& rhs) {
    Matrix finalMatrix = Matrix();
    finalMatrix.rows = rhs.rows;
    finalMatrix.cols = rhs.cols;
    for (int i = 0; i < rhs.rows; ++i) {
        for (int j = 0; j < rhs.cols; ++j) {
            finalMatrix.matrix[i][j] = current_matrix.matrix[i][j] + rhs.matrix[i][j];
        }
    }
    return finalMatrix;
}

Matrix MatrixCalculator::subtract(const Matrix& rhs) {
    Matrix finalMatrix = Matrix();
    finalMatrix.rows = rhs.rows;
    finalMatrix.cols = rhs.cols;
    for (int i = 0; i < rhs.rows; ++i) {
        for (int j = 0; j < rhs.cols; ++j) {
            finalMatrix.matrix[i][j] = current_matrix.matrix[i][j] - rhs.matrix[i][j];
        }
    }
    return finalMatrix;
}
