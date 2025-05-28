#include <iostream>
#include "Pos_sym_lin_system.h"

using namespace std;

int main() {
    //CASE 1: Valid matrix
    cout << "\nCase 1: Symmetric & Positive Definite." << endl;

    Matrix A(2, 2);
    A(1,1) = 2; A(1,2) = 1;
    A(2,1) = 1; A(2,2) = 2;

    Vector b(2);
    b[0] = 3;
    b[1] = 3;

    Pos_sym_lin_system sys1(A, b);
    sys1.print();

    try {
        Vector x = sys1.solve();
        cout << "Solution x:" << endl;
        x.print();
    } 
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    //CASE 2: not symmetric
    cout << "\nCase 2: NOT symmetric." << endl;

    Matrix B(2, 2);
    B(1,1) = 1; B(1,2) = 2;
    B(2,1) = 3; B(2,2) = 4;

    Vector b2(2);
    b2[0] = 5;
    b2[1] = 6;

    Pos_sym_lin_system sys2(B, b2);
    sys2.print();

    try {
        Vector x2 = sys2.solve();
        x2.print();
    } 
    catch (const exception& e) {
        cerr << "Expected error (not symmetric): " << e.what() << endl;
    }

    //Case 3: symmetric but not positive definite
    cout << "\nCase 3: Symmetric but NOT Positive Definite." << endl;

    Matrix C(2, 2);
    C(1,1) = 0; C(1,2) = 0;
    C(2,1) = 0; C(2,2) = -1;

    Vector b3(2);
    b3[0] = 1;
    b3[1] = 2;

    Pos_sym_lin_system sys3(C, b3);
    sys3.print();

    try {
        Vector x3 = sys3.solve();
        x3.print();
    } 
    catch (const exception& e) {
        cerr << "Expected error (not positive definite): " << e.what() << endl;
    }

    return 0;
}

