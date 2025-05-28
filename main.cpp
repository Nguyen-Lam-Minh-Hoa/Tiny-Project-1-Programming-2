/**
 * Nguyen Lam Minh Hoa - 10422030 - You should read all the lines before testing with this main.cpp file
 * WARNING: This file is only a quick demo.
 * Please use the corresponding test files inside the "test/" directory
 * for proper evaluation (e.g., test_matrix.cpp, test_vector.cpp, ...).
 * Each test file is written for a specific development stage as required by the assignment.
 */

#include <iostream>
#include "Vector.h"
#include "Matrix.h"

using namespace std;

int main() {
    cout << "Quick Demo: Vector + Matrix Basic Test " << endl;

    // Vector test
    Vector v1(3), v2(3);
    v1[0] = 1; v1[1] = 2; v1[2] = 3;
    v2[0] = 4; v2[1] = 5; v2[2] = 6;

    Vector sum = v1 + v2;
    cout << "v1 + v2 = ";
    sum.print();

    // Matrix test
    Matrix A(2, 2);
    A(1,1) = 1; A(1,2) = 2;
    A(2,1) = 3; A(2,2) = 4;

    Matrix B = A * 2;
    cout << "A * 2 = " << endl;
    B.print();

    return 0;
}


