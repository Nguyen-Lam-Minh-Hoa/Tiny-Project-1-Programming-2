#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "Vector.h" // use for matrix multiplication by vector

using namespace std;

class Matrix {
private:
    int m_num_rows;
    int m_num_cols;
    double** m_data;

public:
    Matrix(); // default constructor fix bug 7 part B s7 (24/05/2025)

    // Constructor: initialize matrix of size rows x cols, all elements = 0
    Matrix(int rows, int cols);

    // Copy constructor
    Matrix(const Matrix& other);

    // Destructor: frees memory
    ~Matrix();

    // Get the number of rows and columns
    int num_rows() const;
    int num_cols() const;

    // Access element (i,j), with index starting from 1
    double& operator()(int i, int j);              // to assign
    double operator()(int i, int j) const;         // to read

    // Assignment Operator
    Matrix& operator=(const Matrix& other);

    // Addition, subtraction, multiplication operators
    Matrix operator+(const Matrix& other) const;    
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;      // Matrix × matrix (Multiply this matrix with another matrix) 21/05/2025 s3
    Vector operator*(const Vector& vec) const;        // Matrix × vector (Multiply this matrix with a vector) 21/05/2025 s3
    Matrix operator*(double scalar) const;            // Matrix × scalar

    // Utility function
    void print() const;

    // Calculate determinant (only for square matrices) 21/05/2025 s3
    double determinant() const;

    // Matrix Inverse (Compute the inverse of a square matrix using Gauss-Jordan elimination) 21/05/2025 s3
    Matrix inverse() const;

    // Calculating pseudo-inverse (Moore-Penrose) (final in s3)
    Matrix pseudo_inverse() const;

    // Add tranpose matrix to fix bug 6 s7 part B 924/05/2025)
    Matrix transpose() const;
};

#endif
