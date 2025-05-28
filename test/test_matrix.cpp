#include <iostream>
#include <cmath>          // for fabs in comparisons
#include "Matrix.h"
#include "Vector.h"

using namespace std;

// Helper function to compare two matrices
bool matrices_are_equal(const Matrix& A, const Matrix& B, double tol = 1e-6) {
    if (A.num_rows() != B.num_rows() || A.num_cols() != B.num_cols())
        return false;

    for (int i = 1; i <= A.num_rows(); ++i)
        for (int j = 1; j <= A.num_cols(); ++j)
            if (fabs(A(i, j) - B(i, j)) > tol)
                return false;

    return true;
}

int main() {
    // ===== Test 1: Basic operators + - * (scalar) =====
    Matrix A(2, 2);
    A(1,1) = 1; A(1,2) = 2;
    A(2,1) = 3; A(2,2) = 4;

    Matrix B = A * 2.0;
    Matrix C = A + B;
    Matrix D = C - A;

    cout << "Test 1 - Matrix C (A + B):" << endl;
    C.print();

    cout << "Test 1 - Matrix D (C - A):" << endl;
    D.print();

    // ===== Test 2: Matrix * Matrix =====
    Matrix M1(2, 3);
    M1(1,1) = 1; M1(1,2) = 2; M1(1,3) = 3;
    M1(2,1) = 4; M1(2,2) = 5; M1(2,3) = 6;

    Matrix M2(3, 2);
    M2(1,1) = 7; M2(1,2) = 8;
    M2(2,1) = 9; M2(2,2) = 10;
    M2(3,1) = 11; M2(3,2) = 12;

    Matrix M3 = M1 * M2;

    cout << "Test 2 - M1 * M2:" << endl;
    M3.print();

    // ===== Test 3: Matrix * Vector =====
    Vector v(3);
    v[0] = 1; v[1] = 0; v[2] = -1;

    Vector result = M1 * v;
    cout << "Test 3 - M1 * v:" << endl;
    result.print();

    // ===== Test 4: Determinant =====
    Matrix M4(3, 3);
    M4(1,1) = 6; M4(1,2) = 1; M4(1,3) = 1;
    M4(2,1) = 4; M4(2,2) = -2; M4(2,3) = 5;
    M4(3,1) = 2; M4(3,2) = 8; M4(3,3) = 7;

    double det = M4.determinant();
    cout << "Test 4 - Determinant of M4: " << det << endl;

    // ===== Test 5: Inverse =====
    Matrix M5(2, 2);
    M5(1,1) = 4; M5(1,2) = 7;
    M5(2,1) = 2; M5(2,2) = 6;

    Matrix M5_inv = M5.inverse();
    cout << "Test 5 - Inverse of M5:" << endl;
    M5_inv.print();

    // ===== Test 6: Pseudo-inverse =====
    Matrix M6(3, 2);
    M6(1,1) = 1; M6(1,2) = 2;
    M6(2,1) = 3; M6(2,2) = 4;
    M6(3,1) = 5; M6(3,2) = 6;

    Matrix M6_pinv = M6.pseudo_inverse();
    cout << "Test 6 - Pseudo-inverse of M6:" << endl;
    M6_pinv.print();

    return 0;
}
