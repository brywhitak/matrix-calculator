/**
 * @file matrix_calculator.cpp
 *
 * A simple matrix calculator implementation.
 *
 * @author Bryant Whitaker, brywhit@bgsu.edu
 */

#include "matrix_calculator.hpp"

// constructor for MatrixCalculator
MatrixCalculator::MatrixCalculator() : matrix_vector(std::vector<Matrix>()), current_matrix(Matrix()), num_calculations(0) {
}

// add a matrix to the matrix_vector
void MatrixCalculator::add_matrix() {
    int rows, cols;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;
    Matrix new_matrix = Matrix(rows, cols);
    matrix_vector.push_back(new_matrix);
}

// add two matrices together
Matrix MatrixCalculator::add(const Matrix& rhs) {
    Matrix finalMatrix = Matrix();
    std::vector<int> tempVec;
    int rowSize = current_matrix.get_matrix().matrix.size();
    finalMatrix.rows = rhs.rows;
    finalMatrix.cols = rhs.cols;
    int temp;
    for (int i = 0; i < rowSize; ++i) {
        for (int j = 0; j < current_matrix.get_matrix().matrix[i].size(); ++j) {
            temp = current_matrix.matrix[i][j] + rhs.matrix[i][j];
            tempVec.push_back(temp);
        }
        finalMatrix.matrix.push_back(tempVec);
        tempVec = {};
    }
    return finalMatrix;
}

// subtract two matrices
Matrix MatrixCalculator::subtract(const Matrix& rhs) {
    Matrix finalMatrix = Matrix();
    std::vector<int> tempVec;
    finalMatrix.rows = rhs.rows;
    finalMatrix.cols = rhs.cols;
    int temp;
    for (int i = 0; i < rhs.rows; ++i) {
        for (int j = 0; j < rhs.cols; ++j) {
            temp = current_matrix.matrix[i][j] - rhs.matrix[i][j];
            tempVec.push_back(temp);
        }
        finalMatrix.matrix.push_back(tempVec);
        tempVec = {};
    }
    return finalMatrix;
}

// not working, look at later
// multiply two matrices
Matrix MatrixCalculator::multiply(const Matrix& rhs) {
    Matrix finalMatrix = Matrix();
    std::vector<int> tempVec;
    finalMatrix.rows = rhs.rows;
    finalMatrix.cols = rhs.cols;
    int temp = 0;
    for (int i = 0; i < current_matrix.rows; ++i) {
        for (int j = 0; j < rhs.cols; ++j) {
            temp += current_matrix.matrix[i][j] * rhs.matrix[j][i];
            tempVec.push_back(temp);
        }
        finalMatrix.matrix.push_back(tempVec);
        tempVec = {};
    }
    return finalMatrix;
}