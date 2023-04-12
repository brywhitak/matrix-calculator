/**
 * @file matrix_driver.cpp
 *
 * A simple driver for the matrix calculator class.
 *
 * @author Bryant Whitaker, brywhit@bgsu.edu
 */

#include "matrix_calculator.hpp"
#include "matrix.hpp"
#include <string>
#include <cctype>

void print_menu(int &);

int main() {
    // declare variables
    int choice, lhs, rhs, numMatrices = 0;
    bool done = false;
    std::string userInput;
    char userChoice;
    
    while (!done) {
        // print out menu
        print_menu(choice);
    
        MatrixCalculator currentCalc = MatrixCalculator();

        switch (choice) {
            case 1:
                std::cout << "You selected adding a matrix. Adding matrix now..." << std::endl;
                currentCalc.add_matrix();
                std::cout << "Input matrix at position " << numMatrices++ << std::endl;
                break;
            case 2:
                std::cout << "You selected addition. Which two matrices would you like to add?\n";
                std::cout << "Left hand side: ";
                std::cin >> lhs;
                std::cout << "Right hand side: ";
                std::cin >> rhs;
                std::cout << "Performing addition and displaying the matrix..." << std::endl;
                currentCalc.set_current_matrix(lhs);
                currentCalc.add(currentCalc.get_matrix(rhs)).print_matrix();
                break;
            case 3:
                std::cout << "You selected subtraction. Which two matrices would you like to add?\n";
                std::cout << "Left hand side:";
                std::cin >> lhs;
                std::cout << "Right hand side:";
                std::cin >> rhs;
                std::cout << "Performing subtraction and displaying the matrix..." << std::endl;
                currentCalc.set_current_matrix(lhs);
                currentCalc.subtract(currentCalc.get_matrix(rhs)).print_matrix();
                break;
            case 7: 
                std::cout << "You selected quit. Quitting now..." << std::endl;
                done = true;
                break;
            default:
                std::cout << "Error in selection." << std::endl;
            }
        // possible tech debt, look at this later
        if (!done) {
            std::cout << "Would you like to continue? Enter (y/N): ";
            do {
                std::cin >> userInput;
                userChoice = std::toupper(userInput[0]);
                if (userChoice == 'Y' || userChoice == 'N') {
                    if (userChoice == 'N') {
                        done = true;
                    }
                } else {
                    std::cout << "Incorrect input. Please enter (y/N): ";
                }

            } while (userChoice != 'Y' && userChoice != 'N');
        }
    }
    
    return 0;
}

void print_menu(int & choice) {
        std::cout << "Welcome! Press any of the following buttons to start calculations:\n";
        std::cout << "1.   Add matrices to the calculator\n";
        std::cout << "2.   Addition\n";
        std::cout << "3.   Subtraction\n";
        std::cout << "4.   Multiplication\n";
        std::cout << "5.   Find the determinant\n";
        std::cout << "6.   Find the inverse matrix\n";
        std::cout << "7.   Quit\n";
        std::cout << std::flush;
        do {
            std::cout << "Enter user choice now: \n";
            std::cin >> choice;
            if (choice > 7 || choice < 1) {
                std::cout << "Incorrect input.\n";
            }
        } while (choice > 7 || choice < 1);
}