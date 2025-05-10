#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <string>
#include <sstream>
#include <vector>


enum ErrorCode {
    NoError,
    IndexOutOfRange,
    DimensionMismatch,
    InvalidDimension
};

class Matrix {


public:
    Matrix();
    Matrix(int rowSize, int colSize);

    void set(int row, int col, int value);
    int get(int row, int col);

    Matrix add(const Matrix& other) const;
    Matrix mul(const Matrix& other) const;

    std::string toString() const;

    ErrorCode getErrorCode() const;


private:
    // add member functions/variables here
    std::vector<std::vector<int>> data;
    int rowSize;
    int colSize;
    ErrorCode errorCode = NoError;
};


Matrix operator+(const Matrix& m1, const Matrix& m2);
// Matrix operator-(const Matrix& m1, const Matrix& m2);
Matrix operator*(const Matrix& m1, const Matrix& m2);

std::ostream& operator<<(std::ostream& os, const Matrix& mat);


#endif // MATRIX_H_INCLUDED
