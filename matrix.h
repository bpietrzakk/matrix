#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <cmath>

class matrix {
    private:
        int rows, columns; // wiersze i kolumny macierzy 

        std::vector<std::vector<double>> data; // macierz
    public:
        // CONSTRUCTORS:
        matrix(); // default

        matrix(int r, int c, double value); // size and value

        matrix(std::vector<std::vector<double>> &d); // takes a ready vector

        // GETTERS:
        int getRows() { return rows; };
        int getColumns() { return columns; };
        std::vector<std::vector<double>> getData() { return data; };

        // display matrix
        void print();

        // TRANSPOSITION transpozycja
        matrix transposition();

        // ADDITION dodawanie
        matrix addition(matrix &m);

        // SUBTRACTION odejmowanie
        matrix subtraction(matrix &m); // return matrix t = oryginal - m

        // MULTIPLICATION
        matrix multiplication (matrix &m);

        // ELEMENT-WISE MULTIPLICATION
        matrix e_w_multiplication (matrix &m);

        // DETERMINANT
        double determinant();

        // OVERLOADING OPERATORS
        matrix operator+(matrix &right) {
            return addition(right);
        }

        matrix operator*(matrix &right) { 
            return multiplication(right);
        }

        matrix operator-(matrix &right) {
            return subtraction(right);
        }

        
        // +

};


#endif // MATRIX_H