#include "Non_square_system.h"
#include <cassert>

// Constructor: same as base class
Non_square_system::Non_square_system(const Matrix& A, const Vector& b)
    : Linear_system(A, b) {}

// Solve Ax = b using pseudo-inverse: x = A⁺ * b
Vector Non_square_system::solve() const {
    int rows = m_A.num_rows();
    int cols = m_A.num_cols();

    if (rows == cols) {
        // If square, defer to base class method
        return Linear_system::solve();
    }

    // Compute pseudo-inverse and solve
    Matrix A_pinv = m_A.pseudo_inverse();
    Vector x = A_pinv * m_b;

    return x;
}
