#include <iostream>
#include "Linear_system.h"

using namespace std;

int main() {
    cout << "Test: Solve Ax = b" << endl;

    // declare Matrix A (2x2)
    Matrix A(2, 2);
    A(1,1) = 3; A(1,2) = 2;
    A(2,1) = 1; A(2,2) = 2;

    // declare vector b (2x1)
    Vector b(2);
    b[0] = 5;
    b[1] = 5;

    //create linear system 
    Linear_system lin_sys(A, b);

    lin_sys.print();

    // slove linear system
    Vector x = lin_sys.solve();

    cout << "Solution x:" << endl;
    x.print();

    return 0;
}

