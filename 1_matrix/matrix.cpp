#include "matrix.h"
// #include <iostream>

using namespace std;


// Default Constructor
Matrix:: Matrix(){
    rowSize = 1;
    colSize = 1;
    data.resize(1, std::vector<int>(1,0));
}

// Set initial matrix
Matrix::Matrix(int rowSize, int colSize) : rowSize(rowSize), colSize(colSize), errorCode(NoError){
    if (rowSize <= 0 || colSize <= 0) {
        errorCode = InvalidDimension;
        return;
    }
    data.resize(rowSize, std::vector<int>(colSize, 0));
}



void Matrix::set(int row, int col, int value){
    if (row >= 0 && row < rowSize && col >= 0 && col < colSize){
        data[row][col] = value;
    }
    else{
        errorCode = IndexOutOfRange;
        return ;
    }

}
// Get a number
int Matrix::get(int row, int col){
    if (row < 0 || row >= rowSize || col < 0 || col >= colSize){
        errorCode = IndexOutOfRange;
        return -1;
    }
    return data[row][col];
}

// Add two matrixs
Matrix Matrix::add(const Matrix& other) const{
    if (rowSize != other.rowSize || colSize != other.colSize){
        Matrix result;
        result.errorCode = DimensionMismatch;
        return result;
    }
    Matrix result(rowSize, colSize);
    for (int i = 0; i < rowSize; ++i) {
        for (int j = 0; j < colSize; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    // result.errorCode = NoError;
    return result;

}

// Multiple two matrixs
Matrix Matrix::mul(const Matrix& other) const{
    if (colSize != other.rowSize){
        Matrix result;
        result.errorCode = DimensionMismatch;
        return result;
    }
    Matrix result(rowSize, other.colSize);
    const int BLOCK_SIZE = 32; // 分块大小，可根据实际情况调整

    for (int ii = 0; ii < rowSize; ii += BLOCK_SIZE) {
        for (int jj = 0; jj < other.colSize; jj += BLOCK_SIZE) {
            for (int kk = 0; kk < colSize; kk += BLOCK_SIZE) {
                // 计算每个块的边界
                int i_end = std::min(ii + BLOCK_SIZE, rowSize);
                int j_end = std::min(jj + BLOCK_SIZE, other.colSize);
                int k_end = std::min(kk + BLOCK_SIZE, colSize);

                for (int i = ii; i < i_end; ++i) {
                    for (int j = jj; j < j_end; ++j) {
                        for (int k = kk; k < k_end; ++k) {
                            result.data[i][j] += data[i][k] * other.data[k][j];
                        }
                    }
                }
            }
        }
    }
    return result;
}

// translate numbers to matrix
std::string Matrix::toString() const{
    std::ostringstream oss;
    for (int i = 0; i < rowSize; ++i) {
        for (int j = 0; j < colSize; ++j) {
            oss << data[i][j];
            if (j < colSize - 1) {
                oss << " ";
            }
        }
        oss << "\n";
    }
    return oss.str();

}

// Get the errorcode
ErrorCode Matrix::getErrorCode() const{
    return errorCode;
}

Matrix operator+(const Matrix& m1, const Matrix& m2){
    return m1.add(m2);
}

Matrix operator*(const Matrix& m1, const Matrix& m2){
    return  m1.mul(m2);
}

std::ostream& operator<<(std::ostream& os, const Matrix& mat) {
    os << mat.toString();
    return os;
}