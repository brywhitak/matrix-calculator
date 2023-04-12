/**
 * @file matrix.hpp
 *
 * A simple matrix class definition.
 *
 * @author Bryant Whitaker, brywhit@bgsu.edu
 */

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>

class Matrix {
    public:
        // default constructor
        Matrix();

        // secondary constructor
        Matrix(int rows, int cols);

        // copy constructor
        Matrix(std::vector<std::vector<int>> matrix, int rows, int cols);

        // copy assignment operator=
        Matrix & operator=(Matrix & rhs);
        
        // get and print functions
        Matrix get_matrix() { return Matrix(matrix, rows, cols); }
        void print_matrix() const;
        
        // allow MatrixCalculator to access private of Matrix
        friend class MatrixCalculator;
    private:
        std::vector<std::vector<int>> matrix;
        int rows;
        int cols;
};
#endif