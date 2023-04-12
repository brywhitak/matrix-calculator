/**
 * @file matrix_driver.cpp
 *
 * A simple driver for the matrix calculator class.
 *
 * @author Bryant Whitaker, brywhit@bgsu.edu
 */

#include "matrix_calculator.hpp"
#include "matrix.hpp"

int main() {
    int choice;
    int rows1;
    int cols1;
    int rows2;
    int cols2;

    std::cout << "Welcome! Press any of the following buttons to start calculations:\n";
    std::cout << "1.   Addition\n";
    std::cout << "2.   Subtraction\n";
    std::cout << "3.   Multiplication\n";
    std::cout << "4.   Find the determinant\n";
    std::cout << "5.   Find the inverse matrix\n";
    std::cout << "6.   Quit\n";
    std::cout << std::flush;
    do {
        std::cout << "Enter user choice now: \n";
        std::cin >> choice;
        if (choice > 6 || choice < 1) {
            std::cout << "Incorrect input.\n";
        }
    } while (choice > 6 || choice < 1);

    std::cout << "Enter number of rows for matrix 1: ";
    std::cin >> rows1;
    std::cout << "Enter number of columns for matrix 1: ";
    std::cin >> cols1;
    Matrix userInputMatrix1 = Matrix(rows1, cols1);
    std::cout << "Matrix 1:" << std::endl;
    userInputMatrix1.print_matrix();
    std::cout << "Enter number of rows for matrix 2: ";
    std::cin >> rows2;
    std::cout << "Enter number of columns for matrix 2: ";
    std::cin >> cols2;
    Matrix userInputMatrix2 = Matrix(rows2, cols2);
    std::cout << "Matrix 2:" << std::endl;
    userInputMatrix2.print_matrix();
    
    MatrixCalculator currentCalc = MatrixCalculator(userInputMatrix1);

    switch (choice) {
        case 1:
            if (rows1 == rows2 && cols1 == cols2) {
                std::cout << "You selected addition. Performing addition now...\n";
                std::cout << "Displaying new matrix:" << std::endl;
                currentCalc.add(userInputMatrix2).print_matrix();
            }
            else {
                std::cout << "Invalid operation: matrices must have equivalent dimensions." << std::endl;
            }
            break;
        case 2:
            if (rows1 == rows2 && cols1 == cols2) {
                std::cout << "You selected subtraction. Performing subtraction now...\n";
                std::cout << "Displaying new matrix:" << std::endl;
                currentCalc.subtract(userInputMatrix2).print_matrix();
            }
            else {
                std::cout << "Invalid operation: matrices must have equivalent dimensions." << std::endl;
            }
            break;
        default:
            std::cout << "Error in selection. Quitting..." << std::endl;
            return -1;
    }
    
    return 0;
}