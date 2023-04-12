/**
 * @file matrix_calculator.cpp
 *
 * A simple matrix calculator implementation.
 *
 * @author Bryant Whitaker, brywhit@bgsu.edu
 */

#include "matrix_calculator.hpp"

MatrixCalculator::MatrixCalculator() {
    current_matrix = Matrix();
    num_calculations = 0;
}

MatrixCalculator::MatrixCalculator(Matrix current) {
    current_matrix = current;
    num_calculations = 0;
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
