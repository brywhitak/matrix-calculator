/**
 * @file matrix_calculator.hpp
 *
 * A simple matrix calculator class definition.
 *
 * @author Bryant Whitaker, brywhit@bgsu.edu
 */

#ifndef MATRIX_CALCULATOR_HPP
#define MATRIX_CALCULATOR_HPP

#include "matrix.hpp"
#include <cctype>

class MatrixCalculator {
    public:
        // default constructor
        MatrixCalculator();

        // add a matrix to the vector
        void add_matrix();

        // add matrix after calculation
        void add_matrix(Matrix& matrix);

        // return a matrix within the vector
        Matrix get_matrix(int index) {
            return matrix_vector[index];
        }

        // set current matrix
        void set_current_matrix(int index) {
            current_matrix = matrix_vector[index];
        }
        
        // get number of matrices
        int get_num_matrices() {
            return num_matrices;
        }

        // matrix operations
        Matrix add(const Matrix& rhs);
        Matrix subtract(const Matrix& rhs);
        Matrix multiply(const Matrix& rhs);
        int determinant(const Matrix& input);
        Matrix inverse_matrix(Matrix& normal);
    private:
        std::vector<Matrix> matrix_vector;
        Matrix current_matrix;
        int num_calculations;
        int num_matrices;
};
#endif