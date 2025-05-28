#ifndef LINEAR_SYSTEM_H
#define LINEAR_SYSTEM_H

#include "Matrix.h"
#include "Vector.h"
#include <iostream>

using namespace std;

class Linear_system {
protected: // change private to protected, fix bug 4 s5: 23/05/2025
    Matrix m_A;  // coefficient matrix
    Vector m_b;  // constant vector

public:
    // Constructor: accepts matrix A and vector b
    Linear_system(const Matrix& A, const Vector& b);

    // Solve the linear system Ax = b
    virtual Vector solve() const; // add virtual to fix bug 4 s5: 23/05/2025

    // Print the system
    void print() const;
};

#endif
