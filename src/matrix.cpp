/**
 * @file matrix.cpp
 *
 * A simple matrix class implementation.
 *
 * @author Bryant Whitaker, brywhit@bgsu.edu
 */

#include "matrix.hpp"

Matrix::Matrix() : rows(MAX_SIZE), cols(MAX_SIZE) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Enter number: ";
            std::cin >> matrix[i][j];
        }
    }
}

Matrix & Matrix::operator=(Matrix & rhs) {
    std::swap(this->matrix, rhs.matrix);
    rows = rhs.rows;
    cols = rhs.cols;
    return *this;
}

Matrix::Matrix(int in[MAX_SIZE][MAX_SIZE], int rows, int cols) : rows(rows), cols(cols) {
    for (int i = 0; i < MAX_SIZE; ++i) {
        for (int j = 0; j < MAX_SIZE; ++j) {
            matrix[i][j] = in[i][j];
        }
    }
}

void Matrix::print_matrix() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}