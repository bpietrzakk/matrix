#include "matrix.h"

// default constructor creates empty matrix
matrix::matrix() {
    rows = 0;
    columns = 0;
    std::cout << "Empty matrix created." << std::endl;
}

// Constructor initializing a matrix with the given size, filled with the specified value
matrix::matrix(int r, int c, double value) {
    rows = r;
    columns = c;
    data = std::vector<std::vector<double>>(r, std::vector<double>(c, value));
    std::cout << "Created matrix " << r << "x" << c << " filled with " << value << std::endl;
}

// constructor accepting a pre-defined vector
matrix::matrix(std::vector<std::vector<double>> &d)
    : rows(d.size()), columns(d.empty() ? 0 : d[0].size()), data(d) {}

void matrix::print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

matrix matrix::transposition() {
    // new data with changed columns with rows 
    //std::vector<std::vector<double>> newdata(columns, std::vector<double>(rows, 0));

    matrix t(columns, rows, 0); // instead of rows columns etc

    for (size_t r = 0; r < rows; r++){
        for (size_t c = 0; c < columns; c++) {
            t.data[c][r] = data[r][c];
        }
    }

    return t;
}

matrix matrix::addition(matrix &m) {
    if (rows != m.rows || columns != m.columns) {
        throw std::invalid_argument("incompatible matrix dimensions");
    }

    matrix t(rows, columns, 0);
    for (size_t r = 0; r < rows; r++){
        for (size_t c = 0; c < columns; c++) {
            t.data[r][c] = data[r][c] + m.data[r][c];
        }
    }

    return t;
}

matrix matrix::subtraction(matrix &m) {
    if (rows != m.rows || columns != m.columns) {
        throw std::invalid_argument("incompatible matrix dimensions");
    }

    matrix t(rows, columns, 0);
    for (size_t r = 0; r < rows; r++){
        for (size_t c = 0; c < columns; c++) {
            t.data[r][c] = data[r][c] - m.data[r][c];
        }
    }

    return t;
}

matrix matrix::multiplication(matrix &m) {
    if (columns != m.getRows()) {
        throw std::invalid_argument("incompatible matrix dimensions");
    }

    matrix result(rows, m.getColumns(), 0);

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < m.getColumns(); j++) {
            for (size_t k = 0; k < columns; k++) {
                result.data[i][j] += (data[i][k] * m.data[k][j]);
            }
        }
    }
    return result;
}

matrix matrix::e_w_multiplication (matrix &m) {
    if (rows != m.rows || columns != m.columns) {
        throw std::invalid_argument("incompatible matrix dimensions");
    }

    matrix result(rows, columns, 0);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result.data[i][j] = (data[i][j] * m.data[i][j]);
        }
    }

    return result;
}

double matrix::determinant() {
    // TO DO

    // reducing matrix to echelon form
}


int main() {
    std::vector<std::vector<double>> matrixData = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
    };
    matrix m(matrixData);
    // m.print();
    // m = m.transposition();
    // m.print();

    // matrix a(3, 9, 10);
    // matrix b(3, 9, 5);

    // a.print();
    // //a = a.addition(b);
    // a = a.subtraction(b);
    // a.print();
    
    std::vector<std::vector<double>> dataA {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    matrix a(dataA);
    a.print();

    std::vector<std::vector<double>> dataB {
        {3, 4, 5},
        {6, 7, 8},
        {9, 10, 11},
    };
    matrix b(dataB);
    b.print();
    
    matrix c = a.e_w_multiplication(b);
    c.print();
    return 0;
}