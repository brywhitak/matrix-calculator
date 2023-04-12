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
#include <vector>

class MatrixCalculator {
    public:
        // default constructor
        MatrixCalculator();

        //copy constructor
        MatrixCalculator(Matrix current);

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
};
#endif