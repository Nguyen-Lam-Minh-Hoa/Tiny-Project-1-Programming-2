#include "Pos_sym_lin_system.h"
#include <cassert>
#include <cmath>

// Constructor: pass A and b to base class constructor
Pos_sym_lin_system::Pos_sym_lin_system(const Matrix& A, const Vector& b)
    : Linear_system(A, b) {}

// Check if matrix A is symmetric (A^T = A)
bool Pos_sym_lin_system::is_symmetric() const {
    const Matrix& A = m_A;  // inherited protected member
    int n = A.num_rows();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (std::fabs(A(i, j) - A(j, i)) > 1e-6)
                return false;
    return true;
}

// Check if matrix A is positive definite using leading principal minors
bool Pos_sym_lin_system::is_positive_definite() const {
    const Matrix& A = m_A;
    int n = A.num_rows();

    for (int k = 1; k <= n; ++k) {
        // Create top-left k×k submatrix
        Matrix sub_A(k, k);
        for (int i = 1; i <= k; ++i)
            for (int j = 1; j <= k; ++j)
                sub_A(i, j) = A(i, j);

        if (sub_A.determinant() <= 0.0)
            return false;
    }

    return true;
}

// Override solve(): check if A is symmetric positive definite
Vector Pos_sym_lin_system::solve() const {
    assert(m_A.num_rows() == m_A.num_cols());

    if (!is_symmetric()) {
        throw std::runtime_error("Matrix A is not symmetric.");
    }

    if (!is_positive_definite()) {
        throw std::runtime_error("Matrix A is not positive definite.");
    }

    // If valid, solve using base class method
    return Linear_system::solve();
}
