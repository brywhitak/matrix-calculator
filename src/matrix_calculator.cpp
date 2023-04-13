/**
 * @file matrix_calculator.cpp
 *
 * A simple matrix calculator implementation.
 *
 * @author Bryant Whitaker, brywhit@bgsu.edu
 */

#include "matrix_calculator.hpp"

// constructor for MatrixCalculator
MatrixCalculator::MatrixCalculator() : matrix_vector(std::vector<Matrix>()), current_matrix(Matrix()), num_calculations(0), num_matrices(0) {
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
    ++num_matrices;
}

// add a matrix to the matrix_vector after a calculation
void MatrixCalculator::add_matrix(Matrix& matrix) {
    char choice;

    std::cout << "Would you like to save this matrix? (y/N): ";
    std::cin >> choice;
    choice = toupper(choice);
    while(choice != 'Y' && choice != 'N') {
        std::cout << "Invalid input. Please enter 'y' or 'n': ";
        std::cin >> choice;
        choice = toupper(choice);
    }

    if (choice == 'Y') {
        matrix_vector.push_back(matrix);
        ++num_matrices;
        std::cout << "Input matrix at position " << num_matrices << std::endl;
    }
}

// add two matrices together
Matrix MatrixCalculator::add(const Matrix& rhs) {
    Matrix finalMatrix = Matrix();
    finalMatrix.rows = rhs.rows;
    finalMatrix.cols = rhs.cols;
    
    std::cout << matrix_vector.size() << std::endl;
    // perform addition
    for (int i = 0; i < rhs.rows; ++i) {
        std::vector<int> tempVec = {};
        for (int j = 0; j < rhs.cols; ++j) {
            int temp = current_matrix.matrix[i][j] + rhs.matrix[i][j];
            tempVec.push_back(temp);
        }
        finalMatrix.matrix.push_back(tempVec);
    }
    add_matrix(finalMatrix);
    finalMatrix.print_matrix();

    return finalMatrix;
}

// subtract two matrices
Matrix MatrixCalculator::subtract(const Matrix& rhs) {
    Matrix finalMatrix = Matrix();
    finalMatrix.rows = rhs.rows;
    finalMatrix.cols = rhs.cols;

    // perform subtraction
    for (int i = 0; i < rhs.rows; ++i) {
        std::vector<int> tempVec = {};
        for (int j = 0; j < rhs.cols; ++j) {
            int temp = current_matrix.matrix[i][j] - rhs.matrix[i][j];
            tempVec.push_back(temp);
        }
        finalMatrix.matrix.push_back(tempVec);
    }
    add_matrix(finalMatrix);
    finalMatrix.print_matrix();

    return finalMatrix;
}

// multiply two matrices
Matrix MatrixCalculator::multiply(const Matrix& rhs) {
    Matrix finalMatrix = Matrix();
    finalMatrix.rows = current_matrix.rows;
    finalMatrix.cols = rhs.cols;

    // perform multiplication
    for (int i = 0; i < current_matrix.rows; ++i) {
        std::vector<int> row = current_matrix.matrix[i];
        std::vector<int> result_row = {};
        for (int j = 0; j < rhs.cols; ++j) {
            int temp = 0;
            for (int k = 0; k < rhs.cols; ++k) {
                temp += row[k] * rhs.matrix[k][j];
            }
            result_row.push_back(temp);
        }
        finalMatrix.matrix.push_back(result_row);
    }
    add_matrix(finalMatrix);
    finalMatrix.print_matrix();

    return finalMatrix;
}