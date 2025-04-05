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

        // TRANSPOSITION
        matrix transposition();

        // ADDITION
        matrix addition(matrix &m);

        // SUBTRACTION
        matrix subtraction(matrix &m); // return matrix t = oryginal - m

        // MULTIPLICATION
        matrix multiplication (matrix &m);

        // ELEMENT-WISE MULTIPLICATION
        matrix e_w_multiplication (matrix &m);

        // DETERMINANT
        double determinant(); // TO DO
};


#endif // MATRIX_H