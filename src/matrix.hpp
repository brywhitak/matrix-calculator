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

const int MAX_SIZE = 64;

class Matrix {
    public:
        // default constructor
        Matrix();

        // secondary constructor
        Matrix(int rows, int cols);

        // copy constructor
        Matrix(int in[MAX_SIZE][MAX_SIZE], int rows, int cols);
        
        // get and print functions
        Matrix get_matrix() { return Matrix(matrix, rows, cols); }
        void print_matrix();
        
        // allow MatrixCalculator to access private of Matrix
        friend class MatrixCalculator;
    private:
        int matrix[MAX_SIZE][MAX_SIZE];
        int rows;
        int cols;
};
#endif