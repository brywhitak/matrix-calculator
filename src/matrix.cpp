/**
 * @file matrix.cpp
 *
 * A simple matrix class implementation.
 *
 * @author Bryant Whitaker, brywhit@bgsu.edu
 */

#include "matrix.hpp"

// matrix default constructor
Matrix::Matrix() : rows(0), cols(0) {
    matrix = std::vector<std::vector<int>>();
}

// matrix constructor with rows and columns settings that allows for user input
Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    std::vector<int> tempVec;
    int temp;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Enter number: ";
            std::cin >> temp;
            tempVec.push_back(temp);
        }
        matrix.push_back(tempVec);
        tempVec = {};
    }
}

// operator= overload
Matrix & Matrix::operator=(Matrix & rhs) {
    std::swap(this->matrix, rhs.matrix);
    rows = rhs.rows;
    cols = rhs.cols;
    return *this;
}

// matrix copy constructor
Matrix::Matrix(std::vector<std::vector<int>> matrix, int rows, int cols) : matrix(matrix), rows(rows), cols(cols) {
}

// print function for Matrix
void Matrix::print_matrix() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}