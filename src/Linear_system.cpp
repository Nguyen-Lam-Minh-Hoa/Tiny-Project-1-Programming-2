#include "Linear_system.h"
#include <cassert>

// Constructor
Linear_system::Linear_system(const Matrix& A, const Vector& b) : m_A(A), m_b(b) {
    assert(A.num_rows() == b.size()); // Ax = b must be valid
}

// Solve the system of equations using the formula: x = A⁻¹ * b
Vector Linear_system::solve() const {
    // Ensure A is square
    assert(m_A.num_rows() == m_A.num_cols());

    Matrix A_inv = m_A.inverse();
    Vector x = A_inv * m_b;
    return x;
}

// Print the system of equations as matrix A and vector b
void Linear_system::print() const {
    cout << "System Ax = b:" << endl;
    cout << "A = " << endl;
    m_A.print();
    cout << "b = ";
    m_b.print();
}
